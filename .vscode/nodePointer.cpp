// Understanding the difference between Node and Node*: A node refers to the structure that contains data and the pointer to the next node. In contrast, Node* (Node pointer) specifically denotes a pointer variable that stores the address of the Node it is pointing to.

#include <iostream>
#include <vector>

using namespace std;

class Node {
    public:
        int data;         // Data stored in the node
        Node* next;       // Pointer to the next node in the linked list
        // Constructors
        Node(int data1, Node* next1) {
            data = data1;
            next = next1;
        }
        // Constructor
        Node(int data1) {
            data = data1;
            next = nullptr;
        }
};
int main() {
    vector<int> arr = {2, 5, 8, 7};
    // Create a Node 'x' with the first element of the vector and a null next reference
    Node x = Node(arr[0], nullptr);
    // Create a pointer 'y' pointing to the Node 'x'
    Node* y = &x;
    // Print the memory address of the Node 'x' using the pointer 'y'
    cout << y << '\n';
}