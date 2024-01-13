#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    // Create a dummy node to handle edge cases where the head needs to be deleted
    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    ListNode* slow = dummy;
    ListNode* fast = dummy;

    // Move fast pointer n+1 steps ahead
    for (int i = 0; i <= n; ++i) {
        if (fast == nullptr) {
            // Edge case: n is greater than the length of the linked list
            delete dummy;
            return head;
        }
        fast = fast->next;
    }

    // Move both pointers until fast reaches the end
    while (fast != nullptr) {
        slow = slow->next;
        fast = fast->next;
    }

    // Delete the Nth node from the end
    ListNode* temp = slow->next;
    slow->next = slow->next->next;
    delete temp;

    // Update head if the dummy was used
    head = dummy->next;
    delete dummy;

    return head;
}

// Function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Example usage:
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int n = 2;

    cout << "Original Linked List: ";
    printList(head);

    head = removeNthFromEnd(head, n);

    cout << "Modified Linked List after removing the " << n << "th node from the end: ";
    printList(head);

    // Free allocated memory
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
