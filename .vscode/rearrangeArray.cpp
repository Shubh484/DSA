// There’s an array ‘A’ of size ‘N’ with an equal number of positive and negative elements. Without altering the relative order of positive and negative elements, you must return an array of alternately positive and negative values.

// Note: Start the array with positive elements.
#include <iostream>
#include <vector>

using namespace std;

// Approach - Brute Force

// vector<int> RearrangebySign(vector<int> &A, int n){
//      // Define 2 vectors, one for storing positive 
//   // and other for negative elements of the array.

//   vector<int> pos ;
//   vector<int> neg;

//   for(int i=0;i<n;i++){
//     if(A[i]>0){
//         pos.push_back(A[i]);
//     }
//     else{
//         neg.push_back(A[i]);
//     }
//   }

//   for(int i =0 ;i<n/2;i++){
//     A[2*i] = pos[i];
//     A[2*i + 1] = neg[i];
// }
// return A;
// }

// Approach - optimal approach

vector<int> RearrangebySign(vector<int> &A , int n){
     // Define array for storing the ans separately.
    vector<int> ans(n,0);

    // positive elements start from 0 and negative from 1.

    int posIndex = 0, negIndex = 1;

    for(int i = 0;i<n;i++){
         // Fill negative elements in odd indices and inc by 2.
         if(A[i] < 0){
            ans[negIndex] = A[i];
            negIndex+=2;
         }
         // Fill positive elements in even indices and inc by 2.
         else{
            ans[posIndex] = A[i];
            posIndex+=2;
         }
    }
    return ans;
}



int main() {
    
  // Array Initialisation.
  int n = 4;
  vector<int> A {1,2,-4,-5};

  vector<int> ans = RearrangebySign(A,n);
  
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }

  return 0;
}