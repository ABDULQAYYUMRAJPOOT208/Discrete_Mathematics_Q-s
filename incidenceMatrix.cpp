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

    vector<vector<int>> incidenceMatrix(vertices, vector<int>(edges, 0));

    cout << "Enter edges (source destination frequency) one by one:" << endl;
    for (int i = 0; i < edges; i++)
    {
        int source, destination, frequency;
        cout << "Enter source edge: ";
        cin >> source;
        cout << "Enter destination edge: ";
        cin >> destination;
        cout << "Enter frequency: ";
        cin >> frequency;

        incidenceMatrix[source][i] = frequency;
        incidenceMatrix[destination][i] = frequency;
    }

    cout << "Incidence Matrix:" << endl;
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < edges; j++)
        {
            cout << incidenceMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
