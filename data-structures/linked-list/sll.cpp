#include <iostream>
using namespace std;

class SLLNode {
    public:
        int data;
        SLLNode* next;

        SLLNode(int data, SLLNode* next=nullptr) {
            this->data = data;
            this->next = next;
        }
};

class SinglyLinkedList {
    private:
        SLLNode* head;
    public:
        SinglyLinkedList() {
            this->head = nullptr;
        }

        SinglyLinkedList(SLLNode* head) {
            this->head = head;
        }

        ~SinglyLinkedList() {
            while(head!=nullptr){
                SLLNode* temp = head->next;
                delete head;
                head = temp;
            }
        }

        int numberOfNodes() {
            if(head==nullptr){
                return 0;
            } else {
                int count = 0;
                SLLNode* temp = head;
                while(temp!=nullptr) {
                    count+=1;
                    temp = temp->next;
                }
                return count;
            }
        }

        void append(int data) {
            if(head==nullptr) {
                head = new SLLNode(data);
            } else {
                SLLNode* temp = head;
                while(temp->next!=nullptr){
                    temp = temp->next;
                }
                temp->next = new SLLNode(data);
            }
        }

        void insertAtBeginning(int data){
            SLLNode* newNode = new SLLNode(data);
            newNode->next = head;
            head = newNode;                
        }

        void traverse() {
            SLLNode* temp = head;
            while(temp!=nullptr) {
                cout<<temp->data<<"->";
                temp = temp->next;
            }
            cout<<"NULL"<<endl;
        }
};

int main() {
    SinglyLinkedList sll;
    sll.append(1);
    sll.append(500);
    sll.traverse();
    sll.insertAtBeginning(5000);
    sll.traverse();
    cout<<"\nTOTAL NODES: "<<sll.numberOfNodes();
    return 0;
}
