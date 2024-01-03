// Creating linked list

#include <iostream>
#include <vector>

using namespace std;

class Node{
    public: // acsess modifier
    int data;  // the data value
    Node* next; // the pointer to the next value

    public:
    // constructor
    Node( int data1, Node* next1){
        data = data1;  // Initialize data with the provided value
        next = next1;  // Initailize next with provided
    }

    Node(int data1){
        data = data1;  // Initialize data with the provided value
        next = nullptr;  // Initialize next as null since it's the end of the list
    }
};

int main(){
    vector<int> arr = {2,5,8,7};
    Node* y = new Node(arr[0]);
    cout<<y<<endl;  // returns the memory value
    cout<<y->data<<endl; // returns the data stored at that memory point
}
