#include <iostream>
#include <list>
#include <queue>
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

    bool
    cycleDetectionUsingDFSInDirected(int src, unordered_map<int, bool> &visited,
                                     unordered_map<int, bool> &dfsVisited) {

        visited[src] = true;
        dfsVisited[src] = true;

        for (auto i : adjList[src]) {
            if (!visited[i.first]) {
                bool check = cycleDetectionUsingDFSInDirected(i.first, visited,
                                                              dfsVisited);

                if (check) {
                    return true;
                }
            } else if (visited[i.first] == true &&
                       dfsVisited[i.first] == true) {
                return true;
            }
        }

        dfsVisited[src] = false;

        return false;
    }
};

int main() {

    Graph g;

    g.insertNode(1, 2, 1, 1);
    g.insertNode(2, 3, 1, 1);
    g.insertNode(2, 4, 1, 1);
    g.insertNode(3, 7, 1, 1);
    g.insertNode(3, 8, 1, 1);
    g.insertNode(4, 5, 1, 1);
    g.insertNode(5, 6, 1, 1);
    g.insertNode(6, 4, 1, 1);
    g.insertNode(8, 7, 1, 1);

    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;

    cout << g.cycleDetectionUsingDFSInDirected(1, visited, dfsVisited);

    return 0;
}