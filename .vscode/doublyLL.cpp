#include <iostream>
#include <vector>

using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node *prev;

    Node():data(0),next(nullptr),prev(nullptr){}
    Node(int data):data(data),next(nullptr),prev(nullptr){}
    Node(int data,Node *next):data(data),next(next),prev(nullptr){}
    Node(int data,Node *next,Node *prev):data(data),next(next),prev(prev){}
};

class LinkedList{
    public:
    Node *head;
    LinkedList(){
        this->head = nullptr;
    }
};
Node *convertArr2DLL(vector<int> arr){
    Node *head = new Node(arr[0]);

    Node *prev = head;

    for(int i = 1; i<arr.size();i++){
        Node *temp = new Node(arr[i],nullptr,prev);

        prev->next = temp;
        
        prev = temp;
    }
    return head;
}

void Print(Node *head){
    while(head != nullptr){
        cout<< head->data<<" ";
        head = head->next;
    }
}

Node *insertAtTail(Node *head, int k){
    Node *new_node = new Node(k);

    if(head == nullptr){
        return new_node;
    }

    Node *tail = head;

    while(tail->next != nullptr){
        tail = tail->next;
    }

    tail->next = new_node;
    new_node->prev = tail;

    return head;
}

int main(){
    vector<int> arr{2,4,6,8,10};

    Node *head = convertArr2DLL(arr);

    Print(head);

    head = insertAtTail(head,12);

    cout<<endl;

    Print(head);

    return 0;
}