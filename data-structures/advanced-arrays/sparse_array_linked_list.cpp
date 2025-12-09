#include <iostream>
using namespace std;

struct Node {
    int index;
    int value;
    Node* next;
    Node(int i, int v) : index(i), value(v), next(nullptr) {}
};

class SparseArrayLinkedList {
    Node* head;

public:
    SparseArrayLinkedList() : head(nullptr) {}

    void insert(int index, int value) {
        Node* newNode = new Node(index, value);
        newNode->next = head;
        head = newNode;
    }

    int get(int index) {
        Node* temp = head;
        while (temp) {
            if (temp->index == index) return temp->value;
            temp = temp->next;
        }
        return 0;
    }

    void print() {
        Node* temp = head;
        while (temp) {
            cout << "Index: " << temp->index << ", Value: " << temp->value << endl;
            temp = temp->next;
        }
    }
};

int main() {
    SparseArrayLinkedList arr;
    arr.insert(1, 10);
    arr.insert(4, 50);
    cout << "Value at index 1: " << arr.get(1) << endl;
    arr.print();
}
