/*Represent a given graph using adjacency matrix/list to perform DFS and using adjacency list to perform BFS. Use the map of the area around the college as the graph. Identify the prominent landmarks as nodes and perform DFS and BFS on that.*/

#include <iostream>
#include <cstdio>
using namespace std;
const int MAX = 20;
int adjList[MAX];
int adj[MAX][MAX];
bool visited[MAX];
int nV, nE;

void DFS(int node) {
    bool visited[MAX] = { false };
    int stack[MAX], top = -1;
    stack[++top] = node;
    while (top >= 0) {
        int cur = stack[top--];
        if (!visited[cur]) {
            visited[cur] = true;
            cout << cur << " ";
            for (int i = nV - 1; i >= 0; i--) {
                if (adj[cur][i] && !visited[i]) {
                    stack[++top] = i;
                }
            }
        }
    }
}

void BFS(int start) {
    bool visited[MAX] = { false };
    int queue[MAX], front = 0, rear = 0;
    visited[start] = true;
    queue[rear++] = start;
    while (front < rear) {
        int node = queue[front++];
        cout << node << " ";
        for (int i = 0; i < adjList[node]; i++) {
            if (!visited[adj[node][i]]) {
                visited[adj[node][i]] = true;
                queue[rear++] = adj[node][i];
            }
        }
    }
}

int main() {
    cout << "Enter the number of vertices and edges in the graph: ";
    cin >> nV >> nE;

    // Initialize adjacency matrix
    for (int i = 0; i < nE; i++) {
        int u, v;
        cout << "Enter an edge: ";
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    // Initialize adjacency list
    for (int i = 0; i < nV; i++) {
        adjList[i] = 0;
        for (int j = 0; j < nV; j++) {
            if (adj[i][j]) {
                adjList[i]++;
            }
        }
    }

    // DFS starting from node 0
    cout << "DFS traversal starting from node 0: ";
    DFS(0);
    cout << endl;

    // Perform BFS starting from node 0
    cout << "BFS traversal starting from node 0: ";
    BFS(0);
    cout << endl;

    return 0;
}
