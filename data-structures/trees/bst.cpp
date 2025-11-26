#include <iostream>
#include <stack>
using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;

	Node(int data, Node* left = nullptr, Node* right = nullptr) {
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
		root = nullptr;
	}

	~BinarySearchTree() {
		destroyTree(root);
	}

	void destroyTree(Node* node) {
		if (node == nullptr) return;
		destroyTree(node->left);
		destroyTree(node->right);
		delete node;
	}

	Node* getRoot() {
		return root;
	}

    Node* findMin(Node* node) {
        while(node->left!=nullptr) node = node->left;
        return node;
    }

    Node* findMax(Node* node) {
        while(node->right) node = node->right;
        return node;
    }


	Node* deleteNode(int data, Node* node=nullptr) {
		if (node == nullptr) node = root;
        if(node == nullptr) return nullptr;

		if (data < node->data)
			node->left = deleteNode(data, node->left);
		else if (data > node->data)
			node->right = deleteNode(data, node->right);
		else {
            // BOTH CHILDREN - NULL
			if (node->left == nullptr && node->right == nullptr) {
				delete node;
				return nullptr;
			}
            // ONE CHILDREN - NULL
			if (node->left == nullptr) {
				Node* temp = node->right;
				delete node;
				return temp;
			}
			if (node->right == nullptr) {
				Node* temp = node->left;
				delete node;
				return temp;
			}
            // TWO NON-NULL CHILDREN
            Node* inOrderSuccessor = findMin(node->right);
            node->data = inOrderSuccessor->data;
            node->right = deleteNode(inOrderSuccessor->data, node->right);
		}

		return node;
	}

	bool search(int data, Node* node) {
		if (node == nullptr) return false;
        if (data < node->data)
            return search(data, node->left);
        else if (data > node->data)
            return search(data, node->right);
        else
            return true;
	}

	bool search(int data) {
		return search(data, root);
	}

    void preOrderIterative() {
        if(root==nullptr) return;
        stack<Node*> s;
        s.push(root);
        while(!s.empty()) {
            Node* toppest = s.top();
            cout<<toppest->data<<"->";
            s.pop();
            if(toppest->right)
                s.push(toppest->right);
            if(toppest->left)
                s.push(toppest->left);
        }
        cout<<"END"<<endl;
    }

    void postOrderIterative() {
        if(root==nullptr) return;
        stack<Node*> s;
        s.push(root);
        while(!s.empty()) {
        }
        cout<<"END"<<endl;
    }

	void inOrder(Node* node) {
		if (node == nullptr) return;
		inOrder(node->left);
		cout << node->data << "->";
		inOrder(node->right);
	}

	void preOrder(Node* node) {
		if (node == nullptr) return;
		cout << node->data << "->";
		preOrder(node->left);
		preOrder(node->right);
	}

	void postOrder(Node* node) {
		if (node == nullptr) return;
		postOrder(node->left);
		postOrder(node->right);
		cout << node->data << "->";
	}

	void traverse() {
		cout << "IN-ORDER: ";
		inOrder(root);
		cout << "END\n";
		cout << "PRE-ORDER: ";
		preOrder(root);
		cout << "END\n";
		cout << "POST-ORDER: ";
		postOrder(root);
		cout << "END\n";
	}

	void insert(int data, Node* node) {
		if (data <= node->data) {
			if (node->left == nullptr)
				node->left = new Node(data);
			else
				insert(data, node->left);
		} else {
			if (node->right == nullptr)
				node->right = new Node(data);
			else
				insert(data, node->right);
		}
	}

	void addNode(int data) {
		if (root == nullptr)
			root = new Node(data);
		else
			insert(data, root);
	}
};

int main() {
	BinarySearchTree bst;
	bst.addNode(1);
	bst.addNode(90);
	bst.addNode(2);
	bst.addNode(43);
	bst.addNode(5);
	cout << bst.search(4) << endl;
	cout << bst.search(90) << endl;
	bst.traverse();
    bst.deleteNode(43);
	bst.traverse();
    bst.preOrderIterative();
	return 0;
}
