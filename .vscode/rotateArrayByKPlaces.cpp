#include <iostream>
#include <vector>

using namespace std;

void Reverse(vector<int> &arr,int start,int end){

    while(start <= end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void rotateToRight(vector<int> &arr,int n,int k){

    // To rotate right

   // Reverse first n-k elements
  Reverse(arr, 0, n - k - 1);
  // Reverse last k elements
  Reverse(arr, n - k, n - 1);
  // Reverse whole array
  Reverse(arr, 0, n - 1);

    // To Rotate  left

    /*
      // Reverse first k elements
  Reverse(arr, 0, k - 1);
  // Reverse last n-k elements
  Reverse(arr, k, n - 1);
  // Reverse whole array
  Reverse(arr, 0, n - 1);

    */

}

int main(){
    vector<int> arr  = {1,2,3,4,5,6,7};
    int n = arr.size();
    int k = 2;

    rotateToRight(arr,n,k);

    cout<< "After rotating k elements to right"<<endl;

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
    
}