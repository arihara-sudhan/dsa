#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class SparseArrayTwoArrays {
    vector<int> indexes;
    vector<int> values;

public:
    void insert(int index, int value) {
        auto pos = lower_bound(indexes.begin(), indexes.end(), index) - indexes.begin();
        indexes.insert(indexes.begin() + pos, index);
        values.insert(values.begin() + pos, value);
    }

    int get(int index) {
        auto it = lower_bound(indexes.begin(), indexes.end(), index);
        if (it != indexes.end() && *it == index)
            return values[it - indexes.begin()];
        return 0;
    }

    void print() {
        for (size_t i = 0; i < indexes.size(); i++)
            cout << "Index: " << indexes[i] << ", Value: " << values[i] << endl;
    }
};

int main() {
    SparseArrayTwoArrays arr;
    arr.insert(5, 100);
    arr.insert(2, 50);
    cout << "Value at index 2: " << arr.get(2) << endl;
    arr.print();
}
