#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isBipartite(vector<vector<int>> &graph, int start) {
    int vertex = graph.size();
    vector<int> color(vertex, -1);

    queue<int> q;
    q.push(start);
    color[start] = 0;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int neighbor : graph[current]) {
            if (color[neighbor] == -1) {
                color[neighbor] = 1 - color[current];
                q.push(neighbor);
            } else if (color[neighbor] == color[current]) {
                return false; // Graph is not bipartite
            }
        }
    }

    return true; // Graph is bipartite
}

int main() {
    int vertices, edges;
    cout << "Enter the number of vertices in the graph: ";
    cin >> vertices;

    cout << "Enter the number of edges in the graph: ";
    cin >> edges;

    vector<vector<int>> graph(vertices);

    cout << "Enter edges (source destination) one by one:" << endl;
    for (int i = 0; i < edges; i++) {
        int source, destination;
        cout << "Enter source edge: ";
        cin >> source;
        cout << "Enter destination edge: ";
        cin >> destination;

        graph[source].push_back(destination);
        graph[destination].push_back(source);
    }

    if (isBipartite(graph, 0)) {
        cout << "The graph is bipartite." << endl;
    } else {
        cout << "The graph is not bipartite." << endl;
    }

    return 0;
}
