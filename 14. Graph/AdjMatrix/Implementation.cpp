#include <iostream>
#include <map>

using namespace std;

class Graph {
    bool **adjMatrix;
    int numVertices;

  public:
    Graph(int v) {
        this->numVertices = v;
        adjMatrix = new bool *[numVertices];
        for (int i = 0; i < numVertices; i++) {
            adjMatrix[i] = new bool[numVertices];
            for (int j = 0; j < numVertices; j++) {
                adjMatrix[i][j] = false;
            }
        }
    }

    void add(int v1, int v2, bool directed) {
        adjMatrix[v1][v2] = true;
        if (!directed) {
            adjMatrix[v2][v1] = true;
        }
    }

    void print() {

        // For visual(start)
        cout << "    ";
        for (int k = 0; k < numVertices; k++) {
            cout << k << " ";
        }
        cout << endl;
        cout << "    ";
        for (int k = 0; k < numVertices; k++) {
            cout << "--";
        }
        cout << endl;
        // For visual(end);

        // Main code for printing
        for (int i = 0; i < numVertices; i++) {

            cout << i << " : ";
            for (int j = 0; j < numVertices; j++)
                cout << adjMatrix[i][j] << " ";
            cout << endl;
        }
    }

    ~Graph() {
        for (int i = 0; i < numVertices; i++) {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
    }
};

int main() {

    Graph *g = new Graph(5);
    g->add(1, 2, 0);
    g->add(1, 3, 0);
    g->add(1, 0, 0);
    g->add(2, 3, 0);
    g->add(3, 4, 0);
    g->add(4, 0, 0);

    g->print();

    return 0;
}
