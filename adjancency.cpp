#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int vertices, edges;
    cout << "Enter the number of vertices in the graph: ";
    cin >> vertices;

    cout << "Enter the number of edges in the graph: ";
    cin >> edges;

    vector<vector<int>> adjacencyMatrix(vertices, vector<int>(vertices, 0));

    cout << "Enter edges (source destination) one by one:" << endl;
    for (int i = 0; i < edges; i++)
    {
        int source, destination;
        cout << "Enter source edge: ";
        cin >> source;
        cout << "Enter destination edge: ";
        cin >> destination;

        adjacencyMatrix[source][destination] = 1;
        adjacencyMatrix[destination][source] = 1;
    }

    cout << "Adjacency Matrix:" << endl;
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            cout << adjacencyMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
