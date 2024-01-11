// starting point in Linked List

#include <iostream>
#include <unordered_set>

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

void insertNode(node* &head,int val) {
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

void createCycle(node* &head,int pos) {
    node* ptr = head;
    node* temp = head;
    int cnt = 0;
    while(temp->next != nullptr) {
        if(cnt != pos) {
            ++cnt;
            ptr = ptr->next;
        } 
        temp = temp->next;
    }
    temp->next = ptr;
}
 
// Approach - Brute force

// node* detectCycle(node* head) {
//     unordered_set<node*> st;
//     while(head != nullptr) {
//         if(st.find(head) != st.end()) return head;
//         st.insert(head);
//         head = head->next;
//     }
//     return nullptr;
// }

// Approach - Optimal approach ( using slow and fast pointer)

node* detectCycle(node* head) {
    if(head == NULL||head->next == NULL) return NULL;
        
    node* fast = head;
    node* slow = head;
    node* entry = head;
        
    while(fast->next != NULL&&fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
            
        if(slow == fast) {
            while(slow != entry) {
                slow = slow->next;
                entry = entry->next;
            }
            return slow;
        }
    }
    return NULL;
}

int main() {
    node* head = nullptr;
    
    insertNode(head,1);
    insertNode(head,2);
    insertNode(head,3);
    insertNode(head,4);
    insertNode(head,3);
    insertNode(head,6);
    insertNode(head,10);
    
    createCycle(head,2);
    
    node* nodeRecieve = detectCycle(head);
    if(nodeRecieve == nullptr) cout<<"No cycle";
    else {
        node* temp = head;
        int pos = 0;
        while(temp!=nodeRecieve) {
            ++pos;
            temp = temp->next;
        }
        cout<<"Tail connects at pos "<<pos<<endl;
    }
    
    return 0;
}