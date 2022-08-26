#include<iostream>
#include<vector>
#include<iomanip>
#include<list>
#include<map>

using namespace std;

char intToChar(int i);
int charToInt(char i);
void shortestDistance(vector<int> adjLists[], int s, int dest);

struct Graph
{
    map<int, bool> visited;
    map<int, list<int>> adjLists;

    void addEdge(int v, int w)
    {
        adjLists[v].push_back(w);
    }

    void DFS(int v)
    {
        visited[v] = true;
        cout << intToChar(v) << " ";

        list<int>::iterator i;
        for (i = adjLists[v].begin(); i != adjLists[v].end(); ++i)
            if (!visited[*i])
                DFS(*i);
    }
};

void add_edge(vector<int> adjLists[], int src, int dest)
{
    adjLists[src].push_back(dest);
    adjLists[dest].push_back(src);
}


bool BFS(vector<int> adjLists[], int src, int dest, int v, int pred[], int dist[])
{
    list<int> queue;
    bool visited[9];

    for (int i = 0; i < 9; i++) {
        visited[i] = false;
        dist[i] = INT_MAX;
        pred[i] = -1;
    }

    visited[src] = true;
    dist[src] = 0;
    queue.push_back(src);

    while (!queue.empty()) {
        int u = queue.front();
        queue.pop_front();
        for (int i = 0; i < adjLists[u].size(); i++) {
            if (visited[adjLists[u][i]] == false) {
                visited[adjLists[u][i]] = true;
                dist[adjLists[u][i]] = dist[u] + 1;
                pred[adjLists[u][i]] = u;
                queue.push_back(adjLists[u][i]);

                if (adjLists[u][i] == dest)
                    return true;
            }
        }
    }

    return false;
}

char intToChar(int i)
{
    if (i == 0)
        return 'A';
    else if (i == 1)
        return 'B';
    else if (i == 2)
        return 'C';
    else if (i == 3)
        return 'D';
    else if (i == 4)
        return 'E';
    else if (i == 5)
        return 'F';
    else if (i == 6)
        return 'G';
    else if (i == 7)
        return 'H';
    else
        return 'I';

}

int charToInt(char i)
{
    if (i == 'A')
        return 0;
    else if (i == 'B')
        return 1;
    else if (i == 'C')
        return 2;
    else if (i == 'D')
        return 3;
    else if (i == 'E')
        return 4;
    else if (i == 'F')
        return 5;
    else if (i == 'G')
        return 6;
    else if (i == 'H')
        return 7;
    else
        return 8;
}

void shortestDistance(vector<int> adjLists[], int s, int dest)
{
    int pred[9], dist[9];

    if (BFS(adjLists, s, dest, 8, pred, dist) == false) {
        cout << "Given source and destination"
            << " are not connected";
        return;
    }

    vector<int> path;
    int steps = dest;
    path.push_back(steps);
    while (pred[steps] != -1) {
        path.push_back(pred[steps]);
        steps = pred[steps];
    }

    cout << "Shortest path length is : "
        << dist[dest];

    cout << "\nPath is: ";
    for (int i = path.size() - 1; i >= 0; i--)
        cout << intToChar(path[i]) << " ";
    cout << endl;
}

int main()
{
    vector<int> adjLists[9];
    add_edge(adjLists, 0, 1);
    add_edge(adjLists, 0, 2);
    add_edge(adjLists, 0, 3);
    add_edge(adjLists, 1, 4);
    add_edge(adjLists, 2, 1);
    add_edge(adjLists, 2, 6);
    add_edge(adjLists, 3, 2);
    add_edge(adjLists, 3, 6);
    add_edge(adjLists, 4, 2);
    add_edge(adjLists, 4, 5);
    add_edge(adjLists, 5, 2);
    add_edge(adjLists, 5, 7);
    add_edge(adjLists, 6, 5);
    add_edge(adjLists, 6, 7);
    add_edge(adjLists, 6, 8);
    add_edge(adjLists, 7, 4);
    add_edge(adjLists, 7, 8);
    add_edge(adjLists, 8, 5);


    int input;
    while (1)
    {
        cout << setw(28) << "Choose?" << endl;
        cout << "Depth-First Search (0), Minimum Path Search(1)" << endl;
        cout << "Exit Program(3)" << endl << endl;
        cout << setw(25) << "MENU" << endl << endl;
        cin >> input;
        if (input == 0)
        {
            Graph g;
            g.addEdge(0, 1);
            g.addEdge(0, 2);
            g.addEdge(0, 3);
            g.addEdge(1, 4);
            g.addEdge(2, 1);
            g.addEdge(2, 6);
            g.addEdge(3, 2);
            g.addEdge(3, 6);
            g.addEdge(4, 2);
            g.addEdge(4, 5);
            g.addEdge(5, 2);
            g.addEdge(5, 7);
            g.addEdge(6, 5);
            g.addEdge(6, 7);
            g.addEdge(6, 8);
            g.addEdge(7, 4);
            g.addEdge(7, 8);
            g.addEdge(8, 5);
            char ch;
            cout << "Enter the starting vertex: ";
            cin >> ch;
            cout << "DFS: " << ch << endl;
            g.DFS(charToInt(ch));
        }
        else if (input == 1)
        {
            char start, end;
            cout << "Enter starting and ending vertices: ";
            cin >> start >> end;
            shortestDistance(adjLists, charToInt(start), charToInt(end));
        }
        else
            break;
    }

    return 0;
}