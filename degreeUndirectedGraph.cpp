#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int vertex, edges;
    cout << "Enter the number of vertices in the graph: ";
    cin >> vertex;

    cout << "Enter the number of edges in the graph: ";
    cin >> edges;

    vector<int> degree(vertex, 0);

    cout << "Enter edges (source destination) one by one:" << endl;
    for (int i = 0; i < edges; i++)
    {
        int source, destination;
        cout << "Enter source edge: ";
        cin >> source;
        cout << "Enter destination edge: ";
        cin >> destination;

        degree[source]++;
        degree[destination]++;
    }

    for (int i = 0; i < vertex; i++)
    {
        cout << "Degree of vertex " << i << " is: " << degree[i] << endl;
    }

    return 0;
}
