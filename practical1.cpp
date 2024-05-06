//Write a C++ program to implement a hash table that handles 
//collisions using linear probing. (Consider telephone book database of 
//N clients.). 
#include<iostream>
using namespace std;

class person {
public:
    long long int phonenumber;
    string name;
};

person hashtable[10];

class linearprobing {
public:

    void insert(long long int phonenumber, string name) {
        int hash_index = phonenumber % 10;
        int original_index = hash_index;
        while (hashtable[hash_index].phonenumber != 0 && hashtable[hash_index].phonenumber != -1) {
            hash_index = (hash_index + 1) % 10;
            if (hash_index == original_index) {
                cout << "Hash Table is full. Cannot insert " << name << endl;
                return;
            }
        }
        hashtable[hash_index].phonenumber = phonenumber;
        hashtable[hash_index].name = name;
    }

    void search(long long int phonenumber) {
        int hash_index = phonenumber % 10;
        int original_index = hash_index;
        while (hashtable[hash_index].phonenumber != phonenumber && hashtable[hash_index].phonenumber != 0 && hashtable[hash_index].phonenumber != -1) {
            hash_index = (hash_index + 1) % 10;
            if (hash_index == original_index) {
                cout << "Person with phone number " << phonenumber << " not found." << endl;
                return;
            }
        }
        if (hashtable[hash_index].phonenumber == phonenumber)
            cout << hashtable[hash_index].name << " found at index " << hash_index << endl;
        else
            cout << "Person with phone number " << phonenumber << " not found." << endl;
    }

    void deletee(long long int phonenumber) {
        int hash_index = phonenumber % 10;
        int original_index = hash_index;
        while (hashtable[hash_index].phonenumber != phonenumber && hashtable[hash_index].phonenumber != 0 && hashtable[hash_index].phonenumber != -1) {
            hash_index = (hash_index + 1) % 10;
            if (hash_index == original_index) {
                cout << "Person with phone number " << phonenumber << " not found." << endl;
                return;
            }
        }
        if (hashtable[hash_index].phonenumber == phonenumber) {
            cout << hashtable[hash_index].name << " is deleted from the hash table." << endl;
            hashtable[hash_index].phonenumber = -1; // Marking as deleted
            hashtable[hash_index].name = "";
        } else {
            cout << "Person with phone number " << phonenumber << " not found." << endl;
        }
    }

    void modify(long long int phonenumber, long long int newphonenumber) {
        int hash_index = phonenumber % 10;
        int original_index = hash_index;
        while (hashtable[hash_index].phonenumber != phonenumber && hashtable[hash_index].phonenumber != 0 && hashtable[hash_index].phonenumber != -1) {
            hash_index = (hash_index + 1) % 10;
            if (hash_index == original_index) {
                cout << "Person with phone number " << phonenumber << " not found." << endl;
                return;
            }
        }
        if (hashtable[hash_index].phonenumber == phonenumber) {
            hashtable[hash_index].phonenumber = newphonenumber;
            cout << "Phone number modified successfully." << endl;
        } else {
            cout << "Person with phone number " << phonenumber << " not found." << endl;
        }
    }

    void display() {
        cout << "_____________________------Display--------_____________________" << endl;
        for (int i = 0; i < 10; i++) {
            if (hashtable[i].phonenumber != 0 && hashtable[i].phonenumber != -1) {
                cout << hashtable[i].name << "--phonenumber->" << hashtable[i].phonenumber << endl;
            }
        }
    }
};

int main() {
    linearprobing lp;
    lp.insert(12, "kashyap");
    lp.insert(23, "Alice");
    lp.insert(35, "Bob");
    lp.insert(47, "Charlie");
    lp.insert(59, "David");
    lp.insert(71, "Eva");

    lp.display();

    lp.search(35);
    lp.search(99);

    lp.deletee(35);
    lp.deletee(99);

    lp.modify(23, 123);
    lp.modify(99, 456);

    lp.display();
    return 0;
}
