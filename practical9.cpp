//Write a C++ program to use a height balance tree (AVL) and provide 
//a facility for adding new keywords and its meanings in a dictionary 
//and displaying them in any order.
#include <iostream>
#include <string>
using namespace std;

class AVLNode {
public:
    string keyword;
    string meaning;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(string key, string mean) : keyword(key), meaning(mean), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
private:
    AVLNode* root;

    int height(AVLNode* node) {
        if (node == nullptr) return 0;
        return node->height;
    }

    int balanceFactor(AVLNode* node) {
        if (node == nullptr) return 0;
        return height(node->left) - height(node->right);
    }

    AVLNode* rightRotate(AVLNode* y) {
        AVLNode* x = y->left;
        AVLNode* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }

    AVLNode* leftRotate(AVLNode* x) {
        AVLNode* y = x->right;
        AVLNode* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }

    AVLNode* insertNode(AVLNode* node, string key, string mean) {
        if (node == nullptr) return new AVLNode(key, mean);

        if (key < node->keyword)
            node->left = insertNode(node->left, key, mean);
        else if (key > node->keyword)
            node->right = insertNode(node->right, key, mean);
        else // Duplicate keys not allowed
            return node;

        node->height = 1 + max(height(node->left), height(node->right));

        int balance = balanceFactor(node);

        // Left Left Case
        if (balance > 1 && key < node->left->keyword)
            return rightRotate(node);

        // Right Right Case
        if (balance < -1 && key > node->right->keyword)
            return leftRotate(node);

        // Left Right Case
        if (balance > 1 && key > node->left->keyword) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && key < node->right->keyword) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void inorderTraversal(AVLNode* root) {
        if (root != nullptr) {
            inorderTraversal(root->left);
            cout << root->keyword << " : " << root->meaning << endl;
            inorderTraversal(root->right);
        }
    }

public:
    AVLTree() : root(nullptr) {}

    void insert(string key, string meaning) {
        root = insertNode(root, key, meaning);
    }

    void displayDictionary() {
        inorderTraversal(root);
    }
};

int main() {
    AVLTree dictionary;
    dictionary.insert("apple", "A fruit");
    dictionary.insert("banana", "A fruit");
    dictionary.insert("carrot", "A vegetable");
    dictionary.insert("zebra", "An animal");

    cout << "Dictionary:" << endl;
    dictionary.displayDictionary();

    return 0;
}
