#include <iostream>
#include <list>
#include <unordered_map>
#include <queue>
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

    //               from           to  weight         
    // unordered_map<int, list<pair<int, int>>> adjList;

    void topologicalSort(){
        unordered_map<int,bool> visited;
        unordered_map<int, int> indegree;
        queue<int>q;

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

            cout<<front<<" ";
            q.pop();
        }
    }

    
};

int main() {

    Graph g;

    // g.insertNode(0,1,1,1);
    // g.insertNode(0,3,1,1);
    // g.insertNode(1,2,1,1);
    // g.insertNode(4,3,1,1);
    // g.insertNode(4,5,1,1);
    // g.insertNode(2,5,1,1);



    // g.insertNode(1,0,1,1);
    // g.insertNode(2,0,1,1);
    // g.insertNode(3,0,1,1);


    g.insertNode(5,0,1,1);
    g.insertNode(5,2,1,1);
    g.insertNode(4,0,1,1);
    g.insertNode(4,1,1,1);
    g.insertNode(1,3,1,1);
    g.insertNode(2,3,1,1);

    g.printAdjList();

    cout<<endl;
    cout<<"Topological Sort: ";
    g.topologicalSort();

    return 0;
}