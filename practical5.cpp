//Write a C++ program to convert given binary tree into threaded 
//binary tree. Analyze time and space complexity of the algorithm.
#include <iostream>
#include <stack>
using namespace std;

// Class representing a node in the binary tree
class Node {
public:
    int data;
    Node* left;
    Node* right;
    bool threaded; // Flag to indicate if right pointer is threaded
    Node* successor; // Pointer to inorder successor

    // Constructor to initialize node with given value
    Node(int value) : data(value), left(nullptr), right(nullptr), threaded(false), successor(nullptr) {}
};

// Class representing a threaded binary tree
class ThreadedBinaryTree {
private:
    Node* root;

    // Helper function to perform inorder traversal and set threaded pointers
    void threadedInorder(Node* node, stack<Node*>& inorderStack) {
        if (node == nullptr) {
            return;
        }

        // Traverse left subtree
        threadedInorder(node->left, inorderStack);

        // Visit the current node
        while (!inorderStack.empty() && inorderStack.top()->right == nullptr) {
            inorderStack.top()->threaded = true;
            inorderStack.top()->successor = node;
            inorderStack.pop();
        }

        // Set right pointer and push current node to stack
        if (!inorderStack.empty()) {
            node->right = inorderStack.top()->right;
            inorderStack.pop();
        }
        inorderStack.push(node);

        // Traverse right subtree
        threadedInorder(node->right, inorderStack);
    }

public:
    // Constructor to initialize an empty binary tree
    ThreadedBinaryTree() : root(nullptr) {}

    // Function to insert a new node into the binary tree
    void insert(int value) {
        root = insert(root, value);
    }

    // Helper function to insert a new node recursively
    Node* insert(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        if (value < node->data) {
            node->left = insert(node->left, value);
        } else {
            node->right = insert(node->right, value);
        }
        return node;
    }

    // Function to convert the binary tree into a threaded binary tree
    void convertToThreadedBinaryTree() {
        stack<Node*> inorderStack;
        threadedInorder(root, inorderStack);
    }

    // Function to perform inorder traversal using threaded pointers
    void threadedInorderTraversal() {
        Node* current = root;

        // Find the leftmost node
        while (current != nullptr && current->left != nullptr) {
            current = current->left;
        }

        // Traverse the threaded binary tree
        while (current != nullptr) {
            cout << current->data << " ";

            // Move to inorder successor using threaded pointer
            if (current->threaded) {
                current = current->successor;
            } else {
                // Move to the leftmost node in the right subtree
                current = current->right;
                while (current != nullptr && current->left != nullptr) {
                    current = current->left;
                }
            }
        }
    }
};

int main() {
    // Create a threaded binary tree object
    ThreadedBinaryTree tbt;

    // Inserting nodes into the binary tree
    tbt.insert(1);
    tbt.insert(2);
    tbt.insert(3);
    tbt.insert(4);
    tbt.insert(5);
    tbt.insert(6);
    tbt.insert(7);

    // Convert the binary tree to a threaded binary tree
    tbt.convertToThreadedBinaryTree();

    // Perform threaded inorder traversal
    cout << "Threaded Inorder Traversal: ";
    tbt.threadedInorderTraversal();
    cout << endl;

    return 0;
}
