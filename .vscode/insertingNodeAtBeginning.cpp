#include <iostream>

using namespace std;

class ListNode{
    public:
      int val;
    ListNode *next;
    ListNode(int x){
        val = x;
        next = nullptr;
    }  
};

void PrintList(ListNode *head){  // Function to print Linked List
    ListNode *curr = head;

    for(;curr!=nullptr;curr = curr->next){
        cout<<curr->val<<"-->";
    }
    cout << "null" << endl;

}

ListNode *insertAtFirst(int value, ListNode *head){

    // Step1 : creating a new Node with the given val
    ListNode *newNode = new ListNode(value);

    // Step2 : Making next of newly created Node to point the head of LinkedList
    newNode->next = head;

    // Making the newly created Node as head
    head = newNode;
    return head;

}

int main(){
    ListNode *head = nullptr;  // head of the Linked List
  head = insertAtFirst(40, head);
  head = insertAtFirst(30, head);
  head = insertAtFirst(20, head);
  head = insertAtFirst(10, head);
  cout << "LinkedList before inserting 0 at beginning : " << endl;
  PrintList(head);
  head = insertAtFirst(0, head);
  cout << "LinkedList after inserting 0 at beginning : " << endl;
  PrintList(head);
  return 0;
}