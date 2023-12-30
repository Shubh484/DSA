// Problem Statement: Given an array Arr[] of integers, rearrange the numbers of the given array into the lexicographically next greater permutation of numbers.

// If such an arrangement is not possible, it must rearrange to the lowest possible order (i.e., sorted in ascending order).

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> nextGreaterPermutation(vector<int> &A){
    int n = A.size();

    // Step 1: Find the break point
    int ind = -1;
    for(int i = n-2 ; i>=0; i--){
        if(A[i] < A[i+1]){
            // index i the break point
            ind = i;
            break;
        }
    }

    // if break point does not exist 
    if(ind == -1){
        reverse(A.begin(),A.end());
        return A;
    }


  // Step 2: Find the next greater element
    //         and swap it with arr[ind]:
    for (int i = n - 1; i > ind; i--) {
        if (A[i] > A[ind]) {
            swap(A[i], A[ind]);
            break;
        }
    }

    // Step 3: reverse the right half:
    reverse(A.begin() + ind + 1, A.end());

    return A;

}
int main()
{
    vector<int> A = {2, 1, 5, 4, 3, 0, 0};
    vector<int> ans = nextGreaterPermutation(A);

    cout << "The next permutation is: [";
    for (auto it : ans) {
        cout << it << " ";
    }
    cout << "]";
    return 0;
}