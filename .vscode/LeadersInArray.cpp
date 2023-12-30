// Problem Statement: Given an array, print all the elements which are leaders. A Leader is an element that is greater than all of the elements on its right side in the array.

#include <iostream>
#include <vector>

using namespace std;

// Approach - Brute Force

// vector<int> printLeaders(int arr[], int n) {

//   vector<int> ans;
  
//   for (int i = 0; i < n; i++) {
//     bool leader = true;

//     //Checking whether arr[i] is greater than all 
//     //the elements in its right side
//     for (int j = i + 1; j < n; j++)
//       if (arr[j] > arr[i]) {
          
//         // If any element found is greater than current leader
//         // curr element is not the leader.
//         leader = false;
//         break;
//       }

//     // Push all the leaders in ans array.
//     if (leader)
//     ans.push_back(arr[i]);

//   }
  
//   return ans;
// }

// Approach - Optimal approach
vector<int> printLeaders(int arr[],int n){

    vector<int> ans;
    // Last element of an array is always a leader,
    // push into ans array.
    ans.push_back(arr[n-1]);
    int max = arr[n-1];

     // Start checking from the end whether a number is greater
    // than max no. from right, hence leader.

    for(int i = n-2; i>=0;i--){
        if(arr[i]>max){
            ans.push_back(arr[i]);
            max = arr[i];
        }
    }
    return ans;
}

int main() {
    
  // Array Initialization.
  int n = 6;
  int arr[] = {10, 22, 12, 3, 0, 6};

  vector<int> ans = printLeaders(arr,n);
  
  for(int i = 0;i<ans.size();i++){
      
      cout<<ans[i]<<" ";
  }
  
  cout<<endl;
  return 0;
}