#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int vertices;
    cout << "Enter the number of vertices in the graph: ";
    cin >> vertices;

    vector<vector<int>> adjacencyMatrix(vertices, vector<int>(vertices, 0));

    cout << "Enter the adjacency matrix:" << endl;
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            cin >> adjacencyMatrix[i][j];
        }
    }

    cout << "Edge Listing:" << endl;
    for (int i = 0; i < vertices; i++)
    {
        for (int j = i + 1; j < vertices; j++)
        {
            if (adjacencyMatrix[i][j] == 1)
            {
                cout << "Edge: " << i << " - " << j << endl;
            }
        }
    }

    return 0;
}
