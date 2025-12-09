#include <iostream>
#include <vector>
using namespace std;

class CSRMatrix {
    vector<int> values;       // non-zero values
    vector<int> colIndex;     // column indexes of non-zero values
    vector<int> rowPtr;       // row pointers

public:
    CSRMatrix(int rows) {
        rowPtr.resize(rows + 1, 0);
    }

    void build(const vector<vector<int>> &mat) {
        int rows = mat.size();
        for (int i = 0; i < rows; i++) {
            rowPtr[i] = values.size();
            for (int j = 0; j < mat[i].size(); j++) {
                if (mat[i][j] != 0) {
                    values.push_back(mat[i][j]);
                    colIndex.push_back(j);
                }
            }
        }
        rowPtr[rows] = values.size();
    }

    int get(int r, int c) {
        for (int i = rowPtr[r]; i < rowPtr[r + 1]; i++) {
            if (colIndex[i] == c) return values[i];
        }
        return 0;
    }

    void print() {
        cout << "Values: ";
        for (auto v : values) cout << v << " ";
        cout << "\nColumn Index: ";
        for (auto c : colIndex) cout << c << " ";
        cout << "\nRow Ptr: ";
        for (auto r : rowPtr) cout << r << " ";
        cout << endl;
    }
};

int main() {
    vector<vector<int>> mat = {
        {1, 0, 0, 0},
        {0, 0, 2, 0},
        {0, 3, 0, 0}
    };

    CSRMatrix csr(3);
    csr.build(mat);
    csr.print();
    cout << "Value at (2,1): " << csr.get(2,1) << endl;
}
