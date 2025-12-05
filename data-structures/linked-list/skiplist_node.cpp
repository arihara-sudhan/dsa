#include <iostream>

class SLNode {
    public:
    int key;
    int height;
    SLNode** forward;

    SLNode(int key, int height) {
        this->height = height;
        this->key = key;
        forward = new SLNode*[height+1];
        for(int i=0; i<=height; i++) {
            forward[i] = nullptr;
        }
    }
};

int main() {

    SLNode* n10 = new SLNode(10, 1);
    SLNode* n20 = new SLNode(20, 2);
    /*
        Level 2: header -> n20 -> nullptr
        Level 1: header -> n10 -> n20 -> nullptr
        Level 0: header -> n10 -> n20 -> nullptr
    */
    SLNode* header = new SLNode(-1, 2);
    header->forward[0] = n10;
    n10->forward[0] = n20;
    n20->forward[0] = nullptr;

    header->forward[1] = n10;
    n10->forward[1] = n20;
    n20->forward[1] = nullptr;

    header->forward[2] = n20;
    n20->forward[1] = nullptr;

    return 0;
}
