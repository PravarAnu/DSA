#include <iostream>
#include <list>
#include <unordered_map>
#include <queue>
#include <algorithm>
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
};

int main() {

    Graph g;

    g.insertNode(0, 1, 5, 1);
    g.insertNode(0, 2, 3, 1);
    g.insertNode(1, 2, 2, 1);
    g.insertNode(1, 3, 6, 1);
    g.insertNode(2, 3, 7, 1);
    g.insertNode(2, 4, 4, 1);
    g.insertNode(2, 5, 2, 1);
    g.insertNode(3, 4, -1, 1);
    g.insertNode(4, 5, -2, 1);

    vector<int> ans = g.singleSrcShortestPath(1);

    for(auto i: ans){
        cout<< i << " ";
    }

    return 0;
}