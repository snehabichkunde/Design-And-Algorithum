#include <iostream>
#include <list>

using namespace std;

class Graph {
private:
    int vertices;
    list<int>* adjacencyList;

public:
    Graph(int V) : vertices(V) {
        adjacencyList = new list<int>[V];
    }

    void addEdge(int v, int w) {
        adjacencyList[v].push_back(w);
        adjacencyList[w].push_back(v); 
    }

    void printGraph() {
        for (int v = 0; v < vertices; ++v) {
            cout << "Adjacency list of vertex " << v << ": ";
            for (const auto& neighbor : adjacencyList[v]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }

    ~Graph() {
        delete[] adjacencyList;
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.printGraph();

    return 0;
}
