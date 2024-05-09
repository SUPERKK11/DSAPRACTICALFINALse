// Write a C++ program to use a Heap data structure and read the marks 
//obtained by students of second year in an online examination of a 
//particular subject. Find out maximum and minimum marks obtained 
//in that subject.  Analyze the algorithm.
#include <iostream>
#include <vector>
using namespace std;

class Heap {
private:
    vector<int> heap;

    void heapifyUp(int index) {
        int parent = (index - 1) / 2;
        if (parent >= 0 && heap[index] > heap[parent]) {
            swap(heap[index], heap[parent]);
            heapifyUp(parent);
        }
    }

    void heapifyDown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;

        if (leftChild < heap.size() && heap[leftChild] > heap[largest]) {
            largest = leftChild;
        }

        if (rightChild < heap.size() && heap[rightChild] > heap[largest]) {
            largest = rightChild;
        }

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int extractMax() {
        if (heap.empty()) {
            return -1; // or any value to indicate empty heap
        }

        int maxElement = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return maxElement;
    }

    int getMax() {
        if (heap.empty()) {
            return -1; // or any value to indicate empty heap
        }
        return heap[0];
    }

    int getMin() {
        if (heap.empty()) {
            return -1; // or any value to indicate empty heap
        }

        int minElement = heap[0];
        for (int i = 1; i < heap.size(); ++i) {
            if (heap[i] < minElement) {
                minElement = heap[i];
            }
        }
        return minElement;
    }
};

int main() {
    Heap marksHeap;

    // Read marks obtained by students
    int numStudents;
    cout << "Enter the number of students: ";
    cin >> numStudents;

    cout << "Enter marks obtained by each student: ";
    for (int i = 0; i < numStudents; ++i) {
        int marks;
        cin >> marks;
        marksHeap.insert(marks);
    }

    // Find maximum and minimum marks
    int maxMarks = marksHeap.getMax();
    int minMarks = marksHeap.getMin();

    cout << "Maximum marks obtained: " << maxMarks << endl;
    cout << "Minimum marks obtained: " << minMarks << endl;

    return 0;
}
