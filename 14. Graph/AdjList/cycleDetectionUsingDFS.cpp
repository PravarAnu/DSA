#include <iostream>
#include <list>
#include <unordered_map>
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

    bool cycleDetectionUsingDFS(int src, int parent,
                                unordered_map<int, bool> &visited) {
        visited[src] = true;

        for (auto i : adjList[src]) {
            int val = i.first;

            if (!visited[val]) {
                bool ans = cycleDetectionUsingDFS(val, src, visited);

                if (ans)
                    return true;
            } else if (visited[val] == true && parent != val) {
                return true;
            }
        }
        return false;
    }
};

int main() {

    Graph g;
    /*
            1
           / \
          4---2---3
    */
    g.insertNode(1, 2);
    g.insertNode(1, 4);
    g.insertNode(2, 3);
    g.insertNode(2, 4);

    unordered_map<int, bool> visited;
    cout << g.cycleDetectionUsingDFS(1, -1, visited);

    return 0;
}