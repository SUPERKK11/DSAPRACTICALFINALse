//Write a C++ program to use adjacency list representation of the graph 
//or use adjacency matrix representation of the graph. The node can be 
//represented by airport name or name of the city and a flight can be 
//considered as a edge between the cities
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

// Function prototype
int hashFunc(string airport);

class graph {
public:
    string airport; // Representing the airport or city name
    graph* next;
};

graph* adj_list[100];

void add_vertex(string airport) {
    graph* newnode = new graph();
    newnode->airport = airport;
    newnode->next = NULL;
    adj_list[hashFunc(airport)] = newnode;
}

void add_edges(string source, string destination, bool is_directed) {
    graph* newnode1 = new graph();
    newnode1->airport = destination;
    newnode1->next = adj_list[hashFunc(source)]->next;
    adj_list[hashFunc(source)]->next = newnode1;

    if (!is_directed) {
        graph* newnode2 = new graph();
        newnode2->airport = source;
        newnode2->next = adj_list[hashFunc(destination)]->next;
        adj_list[hashFunc(destination)]->next = newnode2;
    }
}

void DFS(string start) {
    bool visited[100] = { false };
    stack<string> stk;
    stk.push(start);

    while (!stk.empty()) {
        string current = stk.top();
        stk.pop();

        if (!visited[hashFunc(current)]) {
            visited[hashFunc(current)] = true;
            cout << current << " ";

            graph* node = adj_list[hashFunc(current)]->next;
            while (node != NULL) {
                stk.push(node->airport);
                node = node->next;
            }
        }
    }
}

void BFS(string start) {
    bool visited[100] = { false };
    queue<string> q;
    q.push(start);

    while (!q.empty()) {
        string current = q.front();
        q.pop();

        if (!visited[hashFunc(current)]) {
            visited[hashFunc(current)] = true;
            cout << current << " ";

            graph* node = adj_list[hashFunc(current)]->next;
            while (node != NULL) {
                q.push(node->airport);
                node = node->next;
            }
        }
    }
}

// Hash function to convert string to integer index
int hashFunc(string airport) {
    int sum = 0;
    for (char c : airport) {
        sum += c;
    }
    return sum % 100; // Modulo to fit within array size
}

int main() {
    // Example usage:
    add_vertex("New York");
    add_vertex("Los Angeles");
    add_vertex("Chicago");
    add_vertex("Dallas");

    add_edges("New York", "Los Angeles", false);
    add_edges("New York", "Chicago", false);
    add_edges("Los Angeles", "Chicago", false);
    add_edges("Los Angeles", "Dallas", false);
    add_edges("Chicago", "Dallas", false);

    cout << "DFS traversal: ";
    DFS("New York");
    cout << endl;

    cout << "BFS traversal: ";
    BFS("New York");
    cout << endl;

    return 0;
}
