#include <iostream>
#include <vector>

using namespace std;

void leftRotate(vector<int> &arr,int n){

    int temp = arr[0];

    for(int i=0;i<n-1;i++){
        arr[i] = arr[i+1];
    }
    arr[n-1] = temp;

    for(int i=0;i<n;i++){
        cout<<" "<<arr[i];
    }
}


int main(){
    vector<int> arr = {1,2,3,4,5};

    int n = arr.size();

    leftRotate(arr,n);
    return 0;
}