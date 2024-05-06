//Write a C++ program to Implement all the functions of a dictionary 
//(ADT) using hashing and handle collisions using chaining. 
#include <iostream>
#include <list>
#include <string>
using namespace std;

// Class representing a key-value pair
class KeyValuePair {
public:
    string key;
    string value;

    KeyValuePair(string key, string value) {
        this->key = key;
        this->value = value;
    }
};

// Class representing a dictionary using hashing with chaining
class Dictionary {
private:
    static const int SIZE = 10; // Size of the hash table
    list<KeyValuePair> hashTable[SIZE]; // Array of lists to store key-value pairs

    // Hash function to calculate the index
    int hash(string key) {
        int sum = 0;
        for (char ch : key) {
            sum += ch;
        }
        return sum % SIZE;
    }

public:
    // Function to insert a key-value pair into the dictionary
    void insert(string key, string value) {
        int index = hash(key);
        hashTable[index].push_back(KeyValuePair(key, value));
    }

    // Function to search for a value given its key
    string search(string key) {
        int index = hash(key);
        for (auto& kvp : hashTable[index]) {
            if (kvp.key == key) {
                return kvp.value;
            }
        }
        return "Key not found";
    }

    // Function to delete a key-value pair given its key
    void remove(string key) {
        int index = hash(key);
        for (auto it = hashTable[index].begin(); it != hashTable[index].end(); ++it) {
            if (it->key == key) {
                hashTable[index].erase(it);
                return;
            }
        }
    }

    // Function to display all key-value pairs in the dictionary
    void display() {
        cout << "Dictionary:" << endl;
        for (int i = 0; i < SIZE; ++i) {
            for (auto& kvp : hashTable[i]) {
                cout << kvp.key << ": " << kvp.value << endl;
            }
        }
    }
};

int main() {
    Dictionary dict;

    // Inserting key-value pairs into the dictionary
    dict.insert("apple", "a fruit");
    dict.insert("banana", "a fruit");
    dict.insert("carrot", "a vegetable");
    dict.insert("dog", "an animal");

    // Displaying the dictionary
    dict.display();

    // Searching for a value given a key
    cout << "Value for 'banana': " << dict.search("banana") << endl;
    cout << "Value for 'elephant': " << dict.search("elephant") << endl;

    // Removing a key-value pair
    dict.remove("carrot");

    // Displaying the dictionary after removal
    dict.display();

    return 0;
}
