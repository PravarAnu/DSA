#include <iostream>
#include <map>
#include <list>
#include <queue>
using namespace std;

template<class T>
class Graph{
    public:
    map<T, list<T>> adjList;
    
    void add(T v1, T v2, bool directed){
        adjList[v1].push_back(v2);
        if(!directed){
            adjList[v2].push_back(v1);
        }
    }

    void print(){
        for(auto i:adjList){
            cout<<i.first<<" : ";
            for(auto j:i.second){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }

    void bfs(T src, map<T,bool> &visited){
        queue<T> q;
        q.push(src);
        visited[src] = true;

        while(!q.empty()){
            T item = q.front();
            cout<<item<<" ";
            q.pop();

            for(auto neighbour:adjList[item]){
                if(!visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
    }
};


int main() {
    Graph<int> *g = new Graph<int>();
    g->add(1,2,0);
    g->add(1,3,0);
    g->add(1,0,0);
    g->add(2,3,0);
    g->add(3,4,0);
    g->add(4,0,0);

    g->print();
    map<int, bool> visited;
    g->bfs(0,visited);

    return 0;
}