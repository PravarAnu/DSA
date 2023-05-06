#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

class Graph {
    unordered_map<int, vector<int>> adjList;
    unordered_map<int, vector<int>> adjListRev;
  public:
    void insertNode(int from, int to){
        adjList[from].push_back(to);
        adjListRev[to].push_back(from);
    }

    void dfs(int src, unordered_map<int,bool> &visited){
        visited[src] = true;

        cout<<src<<" ";
        for(auto i:adjListRev[src]){
            if(!visited[i]){
                dfs(i, visited);
            }
        }
    }

    void topoOrder(int src, unordered_map<int,bool> &visited, stack<int> &s){
        
        visited[src] = true;

        for(auto i:adjList[src]){
            if(!visited[i]){
                topoOrder(i, visited, s);
            }
        }
        
        s.push(src);
    }

    void kosaraju(int n){

        unordered_map<int, bool> visited;
        stack<int> s;

        int count = 0;

        for(int i=0; i<n; i++){
            if(!visited[i]){
                topoOrder(i, visited, s);
            }
        }

        for(auto i: visited){
            visited[i.first] = false;
        }

        cout<<"Strongly Connected Components: "<<endl;

        while(!s.empty()){
            int src = s.top();
            if(!visited[src]){
                dfs(src, visited);
                count++;
                cout<<endl;
            }

            s.pop();
        }


        cout<<"Total Numbers of Strongly Connected Components: "<< count;
    }

};

int main(){ 

    Graph g;

    // TEST CASE 1
    // g.insertNode(0,1);
    // g.insertNode(1,2);
    // g.insertNode(2,0);
    // g.insertNode(2,3);
    // g.insertNode(3,4);
    // g.kosaraju(5);


    // TEST CASE 2
    g.insertNode(0,1);
    g.insertNode(1,2);
    g.insertNode(2,0);
    g.insertNode(2,3);
    g.insertNode(3,4);
    g.insertNode(4,5);
    g.insertNode(4,7);
    g.insertNode(5,6);
    g.insertNode(6,7);
    g.insertNode(6,4);


    g.kosaraju(8);





    return 0; 
}