#include <iostream>
#include <list>
#include <unordered_map>
#include <set>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

class Graph {
    unordered_map<int, list<pair<int, int>>> adjList;

  public:
    void insertNode(int from, int to, int weight = 1, bool isDirected = false) {
        adjList[from].push_back({to, weight});

        if (!isDirected) {
            adjList[to].push_back({from, weight});
        }
    }

    void printAdjList() {
        for (auto i : adjList) {
            cout << i.first << "-> ";

            for (auto j : i.second) {
                cout << j.first << " ";
            }
            cout << endl;
        }
    }

    void bfs(int src, unordered_map<int, bool> &visited){
        queue<int> q;

        q.push(src);
        visited[src] = true;

        while(!q.empty()){
            int val = q.front();
            cout<<val<<" ";
            for(auto i: adjList[val]){
                if(!visited[i.first]){
                    q.push(i.first);
                    visited[i.first] = true;
                }
            }
            
            q.pop();
        }
    }

    void dfs(int src, unordered_map<int, bool> &visited){
        visited[src] = true;

        cout<<src<<" ";

        for(auto i: adjList[src]){
            if(!visited[i.first]){
                dfs(i.first, visited);
            }
        }
    }

    // unordered_map<int, list<pair<int, int>>> adjList;


    bool cycleDetectionUsingBFS(int src, unordered_map<int, bool> &visited, unordered_map<int, int> &parents){

        queue<int> q;

        q.push(src);
        visited[src] = true;
        parents[src] = -1;

        while(!q.empty()){
            int from = q.front();

            for(auto i: adjList[from]){
                int to = i.first;

                if(!visited[to]){
                    q.push(to);
                    visited[to] = true;
                    parents[to] = from;
                }
                else if(visited[to] == true && parents[from] != to){
                    return true;
                }
            }
            q.pop();
        }
        return false;
    }

    // unordered_map<int, list<pair<int, int>>> adjList;


    bool cycleDetectionUsingDFS(int src, int parent, unordered_map<int, bool> &visited){
        visited[src] = true;

        for(auto i: adjList[src]){
            int val = i.first;

            if(!visited[val]){
                bool ans = cycleDetectionUsingDFS(val, src, visited);

                if(ans) return true;
            }
            else if(visited[val] == true && parent != val){
                return true;
            }
        }
        return false;
    }


    bool cycleDetectionUsingDFSInDirected(int src, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited){

        visited[src] = true;
        dfsVisited[src] = true;

        for(auto i: adjList[src]){
            if(!visited[i.first]){
                bool check = cycleDetectionUsingDFSInDirected(i.first, visited, dfsVisited);

                if(check){
                    return true;
                }
            }else if(visited[i.first] == true && dfsVisited[i.first] == true){
                return true;
            }
        }

        dfsVisited[src] = false;

        return false;

    }
    //               from           to  weight         
    // unordered_map<int, list<pair<int, int>>> adjList;

    vector<int> topologicalSort(){
        unordered_map<int,bool> visited;
        unordered_map<int, int> indegree;
        queue<int>q;

        vector<int> ans;
        for(auto i: adjList){
            indegree[i.first] == 0;
        }


        for(auto i: adjList){
            for(auto j:i.second){
                indegree[j.first]++;
            }
        }

        for(auto i: indegree){
            if(i.second == 0){
                q.push(i.first);
                visited[i.first] = true;
            }
        }

        while(!q.empty()){
            int front = q.front();

            for(auto i:adjList[front]){
                indegree[i.first]--;

                if(indegree[i.first]==0 && visited[i.first] == false){
                    q.push(i.first);
                    visited[i.first] == true;
                }
            }

            ans.push_back(front);
            q.pop();
        }

        return ans;
    }

    void shortestPath(int src, int destination){
        unordered_map<int, bool> visited;
        unordered_map<int, int> parent;
        queue<int> q;
        
        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        while(!q.empty()){
            int front = q.front();

            for(auto i: adjList[front]){
                if(!visited[i.first]){
                    q.push(i.first);
                    parent[i.first] = front;
                    visited[i.first] = true;
                }
            }

            q.pop();
        }

        vector<int> ans;

        int start = destination;
        int end = src;
        ans.push_back(start);
        while(start != end){
            if(start == -1){
                break;
            }
            start = parent[start];
            ans.push_back(start);
        }


        reverse(ans.begin(), ans.end());

        for(auto i:ans){
            cout<<i<<" ";
        }
    }


    vector<int> singleSrcShortestPath(int src){
        vector<int> topologicalArr = topologicalSort();

        int topoSize = topologicalArr.size();
        vector<int> distance(topoSize, 10000);

        int findSrc = 0;

        for(int i = 0; i<topoSize; i++){
            if(topologicalArr[i] == src){
                findSrc = i;
                break;
            }
        }

        distance[src] = 0;

        for(int i=findSrc; i<topoSize; i++){

            for(auto j: adjList[topologicalArr[i]]){
                distance[j.first] = min(distance[j.first], distance[topologicalArr[i]]+j.second);
            }
        }

        return distance;
    }


    void dijkstra(int src, int n){
        set<pair<int, int>> minCost;
        vector<int> distance(n, INT_MAX);
        unordered_map<int, int> parent;
        unordered_map<int, bool> visited;

        for(int i=0; i<n; i++){
            distance[i] = INT_MAX;
        }

        distance[src] = 0;
        parent[src] = -1;
        // visited[src] = true;


        minCost.insert({0, src});

        while(!minCost.empty()){
            int cost = minCost.begin()->first;
            int path = minCost.begin()->second;
            minCost.erase(minCost.begin());

            for(auto i: adjList[path]){
                if(!visited[i.first]){

                    if((cost+i.second) < distance[i.first]){
                        distance[i.first] = cost+i.second;
                        parent[i.first] = path;
                    }

                    // visited[i.first] = true;
                    
                    minCost.insert({distance[i.first], i.first});
                }
            }

            visited[path] = true;
            
        }

        cout<<"Parent Array: "<<endl;
        for(auto i: parent){
            cout<<i.first<<" -> "<<i.second<<endl;
        }



        cout<<"Distance Array: "<<endl;
        for(auto i: distance){
            cout<<i<<endl;
        }
    }
};

int main() {

    Graph g;


    // g.insertNode(0,3,3);
    // g.insertNode(0,4,9);
    // g.insertNode(3,7,9);
    // g.insertNode(4,7,4);
    // g.insertNode(7,5,6);
    // g.insertNode(5,6,2);
    // g.insertNode(6,1,3);
    // g.insertNode(6,2,3);
    // g.insertNode(1,2,2);
    // g.insertNode(2,4,4);

    // g.insertNode(0,1,1);
    // g.insertNode(0,2,4);
    // g.insertNode(1,3,2);
    // g.insertNode(1,6,2);
    // g.insertNode(2,4,3);
    // g.insertNode(2,5,8);
    // g.insertNode(2,6,2);
    // g.insertNode(4,6,6);
    // g.insertNode(4,7,7);
    // g.insertNode(6,7,4);

    // g.insertNode(0,4,1);
    // g.insertNode(1,2,5);
    // g.insertNode(1,5,1);
    // g.insertNode(1,6,4);
    // g.insertNode(3,7,8);
    // g.insertNode(4,6,3);
    // g.insertNode(5,6,4);
    // g.insertNode(6,7,5);
    

    // g.insertNode(0,3,1,1);
    // g.insertNode(0,4,5,1);
    // g.insertNode(0,2,9,1);
    // g.insertNode(1,0,2,1);
    // g.insertNode(2,1,5,1);
    // g.insertNode(2,5,3,1);
    // g.insertNode(2,4,6,1);
    // g.insertNode(3,5,4,1);
    // g.insertNode(4,6,4,1);
    // g.insertNode(4,7,1,1);
    // g.insertNode(5,1,6,1);
    // g.insertNode(6,2,5,1);
    


    g.insertNode(0,1,6,1);
    g.insertNode(0,4,4,1);
    g.insertNode(1,3,8,1);
    g.insertNode(1,6,5,1);
    g.insertNode(2,0,9,1);
    g.insertNode(2,4,7,1);
    g.insertNode(3,5,3,1);
    g.insertNode(4,2,5,1);
    g.insertNode(5,6,5,1);
    g.insertNode(5,7,8,1);
    g.insertNode(6,5,4,1);
    g.insertNode(6,7,7,1);
    g.insertNode(7,5,4,1);




    g.dijkstra(0, 8);



    // g.insertNode(0, 1, 5, 1);
    // g.insertNode(0, 2, 3, 1);
    // g.insertNode(1, 2, 2, 1);
    // g.insertNode(1, 3, 6, 1);
    // g.insertNode(2, 3, 7, 1);
    // g.insertNode(2, 4, 4, 1);
    // g.insertNode(2, 5, 2, 1);
    // g.insertNode(3, 4, -1, 1);
    // g.insertNode(4, 5, -2, 1);

    // vector<int> ans = g.singleSrcShortestPath(1);

    // for(auto i: ans){
    //     cout<< i << " ";
    // }


    // g.insertNode(1,2,1);
    // g.insertNode(1,3,1);
    // g.insertNode(1,4,1);
    // g.insertNode(2,5,1);
    // g.insertNode(3,8,1);
    // g.insertNode(4,6,1);
    // g.insertNode(6,7,1);
    // g.insertNode(7,8,1);

    // g.shortestPath(1,8);



    // g.insertNode(0,1,1,1);
    // g.insertNode(0,3,1,1);
    // g.insertNode(1,2,1,1);
    // g.insertNode(4,3,1,1);
    // g.insertNode(4,5,1,1);
    // g.insertNode(2,5,1,1);



    // g.topologicalSort();


    /*
            1
           / \
          4---2---3
    */
    // g.insertNode(1, 2, 1, 1);
    // g.insertNode(2, 3, 1, 1);
    // g.insertNode(2, 4, 1, 1);
    // g.insertNode(4, 1, 1, 1);

    // g.insertNode(1,2, 1, 1);
    // g.insertNode(2,3, 1, 1);
    // // g.insertNode(2,4, 1, 1);
    // g.insertNode(3,7, 1, 1);
    // g.insertNode(3,8, 1, 1);
    // g.insertNode(4,5, 1, 1);
    // g.insertNode(5,6, 1, 1);
    // g.insertNode(6,4, 1, 1);
    // g.insertNode(8,7, 1, 1);

    // g.printAdjList();
    // unordered_map<int, bool> visited;
    // g.bfs(1, visited);

    // cout<<endl;
    // unordered_map<int, bool> visited2;
    // g.dfs(4, visited2);

    // unordered_map<int, bool> visited;
    // unordered_map<int, int> parents;

    // // cout<<g.cycleDetectionUsingBFS(1, visited, parents);

    // cout<<g.cycleDetectionUsingDFS(1,-1, visited);

    // unordered_map<int, bool> visited;
    // unordered_map<int, bool> dfsVisited;

    // cout<<g.cycleDetectionUsingDFSInDirected(1, visited, dfsVisited);


    return 0;
}