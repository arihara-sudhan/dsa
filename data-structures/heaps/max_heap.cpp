#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;
    // HEAPIFY-UP: AFTER INSERTING
    void heapifyUp(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (heap[parent] < heap[i]) {
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
            int largest = i;
            if (left < n && heap[left] > heap[largest])
                largest = left;
            if (right < n && heap[right] > heap[largest])
                largest = right;
            if (largest != i) {
                swap(heap[i], heap[largest]);
                i = largest;
            } else {
                break;
            }
        }
    }
public:
    void insert(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }
    int getMax() {
        if (heap.empty())
            throw runtime_error("Heap is empty");
        return heap[0];
    }
    int extractMax() {
        if (heap.empty())
            throw runtime_error("Heap is empty");
        int maxVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty())
            heapifyDown(0);
        return maxVal;
    }
    void printHeap() {
        for (int x : heap) cout << x << " ";
        cout << endl;
    }
};
int main() {
    MaxHeap h;
    h.insert(10);
    h.insert(4);
    h.insert(15);
    h.insert(20);
    h.insert(8);
    h.insert(2);
    cout << "Heap elements: ";
    h.printHeap();
    cout << "Maximum: " << h.getMax() << endl;
    cout << "Extracting maximum: " << h.extractMax() << endl;
    cout << "Heap after extract: ";
    h.printHeap();
    return 0;
}
