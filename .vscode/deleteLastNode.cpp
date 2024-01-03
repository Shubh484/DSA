#include <iostream>
#include <vector>

using namespace std;

class Node{
    public:
        int data;
        Node *next;
    Node(int value, Node *next1){
        data = value;
        next = next1;
    }    
    Node(int value){
        data = value;
    }
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

void PrintLinkedList(Node *head){
    Node *curr =head;

    for(;curr!=nullptr;curr=curr->next){
        cout<<curr->data<<" ";
    }
}

Node *deletingNodeAtEnd(Node *head){
   if(head == nullptr || head->next == nullptr){
    return nullptr;
   }

   Node *temp = head;

   while(temp->next->next != nullptr){
    temp = temp->next;
   }

   delete temp->next;

   temp->next = nullptr;

   return head;

}

int main(){
    Node *head = nullptr;
    LinkedList LinkedList;
    head = LinkedList.insertAtBeginning(32);
    head = LinkedList.insertAtBeginning(6);
    head = LinkedList.insertAtBeginning(7);
    head = LinkedList.insertAtBeginning(12);
    head = LinkedList.insertAtBeginning(14);

    PrintLinkedList(head);
    head = deletingNodeAtEnd(head);
    cout<<endl;
    PrintLinkedList(head);
    return 0;
}