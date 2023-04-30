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

    bool cycleDetectionUsingBFS(int src, unordered_map<int, bool> &visited,
                                unordered_map<int, int> &parents) {

        queue<int> q;

        q.push(src);
        visited[src] = true;
        parents[src] = -1;

        while (!q.empty()) {
            int from = q.front();

            for (auto i : adjList[from]) {
                int to = i.first;

                if (!visited[to]) {
                    q.push(to);
                    visited[to] = true;
                    parents[to] = from;
                } else if (visited[to] == true && parents[from] != to) {
                    return true;
                }
            }
            q.pop();
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
    unordered_map<int, int> parents;

    cout << g.cycleDetectionUsingBFS(1, visited, parents);

    return 0;
}