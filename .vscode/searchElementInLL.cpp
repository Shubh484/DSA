// To search an element in the linked list

#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node():data(0),next(nullptr){}
    Node(int data):data(data),next(nullptr){}
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

string search(Node *head, int ele){
    Node *temp = head;

    while(temp!=nullptr){
        if(temp->data == ele){
            return "found";
        }
        temp = temp->next;
    }
    return "not found";
}

int main(){
    Node *head = nullptr;

    LinkedList LinkedList;

    head = LinkedList.insertAtBeginning(8);
    head = LinkedList.insertAtBeginning(12);
    head = LinkedList.insertAtBeginning(14);
    head = LinkedList.insertAtBeginning(33);
    head = LinkedList.insertAtBeginning(45);
    head = LinkedList.insertAtBeginning(12);
    head = LinkedList.insertAtBeginning(0);

    string result = search(head,45);

    cout<<result<<endl;

    return 0;
}