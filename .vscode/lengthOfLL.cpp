// Find length of the linked list

#include <iostream>

using namespace std;

class Node{
    public:
        int data;
        Node *next;

    Node():data(0),next(nullptr){}   // Similar to Node(){ this->data = data; next = nullptr;}
    Node(int data): data(data),next(nullptr){}    
};

class LinkedList{
    public:
        Node *head;
    LinkedList(){
         this->head = nullptr;
    }

   Node *insertAtBeginning(int data){
        Node *new_node = new Node(data);
        new_node->next = head;
        head = new_node;
        return head;
    }
};

int LLlength(Node* head){
    Node *temp = head;
    int cnt = 0;
    while(temp != nullptr){
        cnt++;
        temp = temp->next;
    }
    return cnt;
}



int main(){

    Node* head = nullptr;
    LinkedList LinkedList;

    head  = LinkedList.insertAtBeginning(8);
    head  = LinkedList.insertAtBeginning(12);
    head  = LinkedList.insertAtBeginning(16);
    head  = LinkedList.insertAtBeginning(20);
    head  = LinkedList.insertAtBeginning(24);
    head  = LinkedList.insertAtBeginning(24);


    int length = LLlength(head);
    cout<<length;

    return 0;
}