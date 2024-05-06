//Write a C++ program to represent a given graph using adjacency 
//matrix/list to perform DFS and using adjacency list to perform BFS. 
//(Use the map of the area around the college as a graph ) 
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class graph {
public:
    int data;
    graph* next;
};

graph* adj_list[100];

void add_vertex(int data) {
    graph* newnode = new graph();
    newnode->data = data;
    newnode->next = NULL;
    adj_list[data] = newnode;
}

void add_edges(int vertex1, int vertex2, bool isdirected) {
    graph* newnode1 = new graph();
    newnode1->data = vertex2;
    newnode1->next = adj_list[vertex1]->next;
    adj_list[vertex1]->next = newnode1;

    if (!isdirected) {
        graph* newnode2 = new graph();
        newnode2->data = vertex1;
        newnode2->next = adj_list[vertex2]->next;
        adj_list[vertex2]->next = newnode2;
    }
}

// Depth-First Search (DFS) traversal
void DFS(int start) {
    bool visited[100] = { false };
    stack<int> stk;
    stk.push(start);

    while (!stk.empty()) {
        int current = stk.top();
        stk.pop();

        if (!visited[current]) {
            visited[current] = true;
            cout << current << " ";

            graph* node = adj_list[current]->next;
            while (node != NULL) {
                stk.push(node->data);
                node = node->next;
            }
        }
    }
}

// Breadth-First Search (BFS) traversal
void BFS(int start) {
    bool visited[100] = { false };
    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if (!visited[current]) {
            visited[current] = true;
            cout << current << " ";

            graph* node = adj_list[current]->next;
            while (node != NULL) {
                q.push(node->data);
                node = node->next;
            }
        }
    }
}

int main() {
    // Example usage:
    add_vertex(0);
    add_vertex(1);
    add_vertex(2);
    add_vertex(3);

    add_edges(0, 1, false);
    add_edges(0, 2, false);
    add_edges(1, 3, false);
    add_edges(2, 3, false);

    cout << "DFS traversal: ";
    DFS(0);
    cout << endl;

    cout << "BFS traversal: ";
    BFS(0);
    cout << endl;

    return 0;
}
