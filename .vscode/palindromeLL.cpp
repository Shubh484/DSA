#include <iostream>
#include <vector>


using namespace std;

class node {
    public:
        int num;
        node* next;
        node(int val) {
            num = val;
            next = nullptr;
        }
};

void insertNode(node*& head,int val) {
    node* newNode = new node(val);
    if(head == nullptr) {
        head = newNode;
        return;
    }
    
    node* temp = head;
    while(temp->next != nullptr) temp = temp->next;
    
    temp->next = newNode;
    return;
}

// Approach - Brute force

// bool isPalindrome(node* head) {
//     vector<int> arr;
//     while(head != nullptr) {
//         arr.push_back(head->num);
//         head = head->next;
//     }
//     for(int i=0;i<arr.size()/2;i++) 
//         if(arr[i] != arr[arr.size()-i-1]) return false;
//     return true;
// }

// Approach - optimal 

node* reverse(node* ptr) {
    node* pre=NULL;
    node* nex=NULL;
    while(ptr!=NULL) {
        nex = ptr->next;
        ptr->next = pre;
        pre=ptr;
        ptr=nex;
    }
    return pre;
}

bool isPalindrome(node* head) {
    if(head==NULL||head->next==NULL) return true;
        
    node* slow = head;
    node* fast = head;
        
    while(fast->next!=NULL&&fast->next->next!=NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
        
    slow->next = reverse(slow->next);
    slow = slow->next;
    node* dummy = head;
        
    while(slow!=NULL) {
        if(dummy->num != slow->num) return false;
        dummy = dummy->next;
        slow = slow->next;
    }
    return true;
}


int main() {
    node* head = nullptr;
    insertNode(head,1);
    insertNode(head,2);
    insertNode(head,3);
    insertNode(head,3);
    insertNode(head,2);
    insertNode(head,1);
    isPalindrome(head)? cout<<"True" : cout<<"False";
    return 0;
}