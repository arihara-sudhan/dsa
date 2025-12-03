#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class MinHeap {
private:
    vector<int> heap;
    // HEAPIFY-UP: AFTER INSERTING
    void heapifyUp(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (heap[parent] > heap[i]) {
                swap(heap[parent], heap[i]);
                i = parent;
            } else {
                break;
            }
        }
    }
    // HEAPIFY-DOWN: AFTER DELETION
    void heapifyDown(int i) {
        int n = heap.size();
        while (true) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int smallest = i;
            if (left < n && heap[left] < heap[smallest])
                smallest = left;
            if (right < n && heap[right] < heap[smallest])
                smallest = right;
            if (smallest != i) {
                swap(heap[i], heap[smallest]);
                i = smallest;
            } else {
                break;
            }
        }
    }

public:
    // Insert a new element
    void insert(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }
    // Get smallest element
    int getMin() {
        if (heap.empty())
            throw runtime_error("Heap is empty");
        return heap[0];
    }
    // Remove and return smallest element
    int extractMin() {
        if (heap.empty())
            throw runtime_error("Heap is empty");
        int minVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty())
            heapifyDown(0);
        return minVal;
    }
    // Print heap as array
    void printHeap() {
        for (int x : heap) cout << x << " ";
        cout << endl;
    }
};

int main() {
    MinHeap h;
    h.insert(10);
    h.insert(4);
    h.insert(15);
    h.insert(20);
    h.insert(8);
    h.insert(2);
    cout << "Heap elements: ";
    h.printHeap();
    cout << "Minimum: " << h.getMin() << endl;
    cout << "Extracting minimum: " << h.extractMin() << endl;
    cout << "Heap after extract: ";
    h.printHeap();
    return 0;
}
