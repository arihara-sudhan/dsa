#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data, Node* left=nullptr, Node* right=nullptr) {
            this->data = data;
            this->left = left;
            this->right = right;
        }
};

class BinarySearchTree {
    private:
        Node* root;
    public:
        BinarySearchTree() {
            this->root = nullptr;
        }

        ~BinarySearchTree() {
            destroyTree(root);
        }

        void destroyTree(Node* node) {
            if(node==nullptr) return;
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
         
        bool search(int data, Node* node) {
            if(node==nullptr) return false;
            if(node->data<data)
                return search(data, node->right);
            else if(node->data>data)
                return search(data, node->left);
            return true;
        }

        bool search(int data) {
            return search(data, root);
        }

        void inOrder(Node* node) {
            if(node==nullptr) return;
            inOrder(node->left);
            cout<<node->data<<"->";
            inOrder(node->right);
        }
        
        void preOrder(Node* node) {
            if(node==nullptr) return;
            cout<<node->data<<"->";
            preOrder(node->left);
            preOrder(node->right);
        }

        void postOrder(Node* node) {
            if(node==nullptr) return;
            postOrder(node->left);
            postOrder(node->right);
            cout<<node->data<<"->";
        }

        void traverse() {
            cout<<"IN-ORDER: ";
            inOrder(root);
            cout<<"END"<<endl;
            cout<<"PRE-ORDER: ";
            preOrder(root);
            cout<<"END"<<endl;
            cout<<"POST-ORDER: ";
            postOrder(root);
            cout<<"END"<<endl;
        }

        void insert(int data, Node* node) {
            if(node->data >= data) {
                if(node->left==nullptr)
                    node->left = new Node(data);
                else
                    insert(data, node->left);
            } else {
                if(node->right==nullptr)
                    node->right = new Node(data);
                else
                    insert(data, node->right);
            }
        }

        void addNode(int data) {
            if(root==nullptr) {
                root = new Node(data);
            } else {
                insert(data, root);
            }
        }
};

int main() {
    BinarySearchTree bst;
    bst.addNode(1);
    bst.addNode(2);
    bst.addNode(3);
    bst.addNode(4);
    bst.addNode(5);
    cout<<bst.search(4)<<endl;
    cout<<bst.search(6)<<endl;
    bst.traverse();
    return 0;
}
