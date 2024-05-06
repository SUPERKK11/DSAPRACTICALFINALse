//Write a c++ program to perform the following operations:  
//I. Insert new node 
//II. Find the number of nodes in longest path from root. 
//III. Minimum data value found in the tree. 
//IV. Change a tree so that the roles of the left and right pointers are 
 //swapped at every node. 
//V. Search a value. 
#include <iostream>
using namespace std;

const int MAX_INT = 2147483647; // Maximum integer value

// Class representing a node in the binary tree
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to insert a new node into the binary tree
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

// Function to find the number of nodes in the longest path from root
int longestPath(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    int leftDepth = longestPath(root->left);
    int rightDepth = longestPath(root->right);
    return 1 + max(leftDepth, rightDepth);
}

// Function to find the minimum data value in the tree
int minimumValue(Node* root) {
    if (root == nullptr) {
        return MAX_INT;
    }
    int minValue = root->data;
    int leftMin = minimumValue(root->left);
    int rightMin = minimumValue(root->right);
    if (leftMin < minValue) {
        minValue = leftMin;
    }
    if (rightMin < minValue) {
        minValue = rightMin;
    }
    return minValue;
}

// Function to swap the roles of left and right pointers at every node
Node* swapRoles(Node* root) {
    if (root == nullptr) {
        return nullptr;
    }
    Node* temp = root->left;
    root->left = swapRoles(root->right);
    root->right = swapRoles(temp);
    return root;
}

// Function to search for a value in the tree
bool search(Node* root, int value) {
    if (root == nullptr) {
        return false;
    }
    if (root->data == value) {
        return true;
    }
    if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

int main() {
    Node* root = nullptr;

    // Inserting new nodes
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    // I. Insert new node
    root = insert(root, 55);

    // II. Find the number of nodes in longest path from root
    cout << "Number of nodes in longest path from root: " << longestPath(root) << endl;

    // III. Minimum data value found in the tree
    cout << "Minimum data value found in the tree: " << minimumValue(root) << endl;

    // IV. Change a tree so that the roles of the left and right pointers are swapped at every node
    root = swapRoles(root);

    // V. Search a value
    int value = 55;
    cout << "Search for value " << value << ": " << (search(root, value) ? "Found" : "Not found") << endl;

    return 0;
}
