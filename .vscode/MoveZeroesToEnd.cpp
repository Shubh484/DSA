#include <iostream>
#include <vector>

using namespace std;

void MoveZeroes(vector<int> &arr,int n){
   int j = -1;
    //place the pointer j:
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            j = i;
            break;
        }
    }

    //no non-zero elements:
    if (j == -1) return;

    //Move the pointers i and j
    //and swap accordingly:
    for (int i = j + 1; i < n; i++) {
        if (arr[i] != 0) {
            swap(arr[i], arr[j]);
            j++;
        }
    }
}

int main(){
    vector<int> arr = {1,0,5,2,6,6,0,2};

    int n = arr.size();

    MoveZeroes(arr,n);

    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}