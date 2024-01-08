#include <iostream>
#include <stack>

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
    LinkedList(): head(nullptr){}

    Node* insertAtBeginning(int newData){
        Node *newNode = new Node(newData);
        newNode->next = head;
        head = newNode;
        return head;
    }
};

// Approach - brute force ( using stack )

// Node* reverseLinkedList(Node *head){
//     // create a temporary pointer to traverse the linked list
//     Node *temp = head;

//     // create a stack to temporarly store the data values
//     stack<int> st;

//     // push the value of linked list in the stack
//     while(temp != nullptr){
//         st.push(temp->data);
//         temp = temp->next;
//     }

//     // reset the temporary pointer to the head of linked list

//     temp = head;

//     // pop values from the stack and update the linked list

//     while(temp != nullptr){
//         temp->data = st.top();

//         st.pop();

//         temp = temp->next;
//     }

//     return head;
// }

// Approach - Optimal approach ( Reverse links in place through iteration)

// Node* reverseLinkedList(Node *head){
//     Node *temp = head;

//     Node *prev = nullptr;

//     while( temp != nullptr){
//         Node *front = temp->next;
//         temp->next = prev;
//         prev = temp;
//         temp = front;
//     }
//     return prev;
// }

// Approach - Optimal approach ( using recursion )

Node* reverseLinkedList(Node* head) {
    // Base case:
    // If the linked list is empty or has only one node,
    // return the head as it is already reversed.
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    // Recursive step:
    // Reverse the linked list starting 
    // from the second node (head->next).
    Node* newHead = reverseLinkedList(head->next);
    
    // Save a reference to the node following
    // the current 'head' node.
    Node* front = head->next;
    
    // Make the 'front' node point to the current
    // 'head' node in the reversed order.
    front->next = head;
    
    // Break the link from the current 'head' node
    // to the 'front' node to avoid cycles.
    head->next = NULL;
    
    // Return the 'newHead,' which is the new
    // head of the reversed linked list.
    return newHead;
}


void printLinkedList(Node *head){
    Node *temp = head;
    while(temp != nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    Node *head = nullptr;

    LinkedList LL;

    head = LL.insertAtBeginning(1);
    head = LL.insertAtBeginning(2);
    head = LL.insertAtBeginning(3);
    head = LL.insertAtBeginning(4);
    head = LL.insertAtBeginning(5);

    printLinkedList(head);

    head = reverseLinkedList(head);

    printLinkedList(head);

    return 0;
}