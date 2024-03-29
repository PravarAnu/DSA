#include <iostream>
#include <map>
#include <list>
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

    return 0;
}