#include <iostream>
#include <vector>
using namespace std;

struct Pair {
    int index;
    int value;
};

class SparseArrayList {
    vector<Pair> data;

public:
    void insert(int index, int value) {
        data.push_back({index, value});
    }

    int get(int index) {
        for (auto &p : data) {
            if (p.index == index) return p.value;
        }
        return 0;
    }

    void print() {
        for (auto &p : data)
            cout << "Index: " << p.index << ", Value: " << p.value << endl;
    }
};

int main() {
    SparseArrayList arr;
    arr.insert(2, 10);
    arr.insert(5, 20);
    cout << "Value at index 2: " << arr.get(2) << endl;
    cout << "Value at index 3: " << arr.get(3) << endl;
    arr.print();
}
