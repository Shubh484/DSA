#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int> &arr,int n){
    int i = 0;
    for(int j =1;j<n;j++){
        if(arr[i]!=arr[j]){
            i++;
            arr[i] = arr[j];
        }
    }
    return i+1;
}

int main(){
    vector<int> arr{12,17,17,17,44,57,82,82,97,99};

    int n = arr.size();

    int k = removeDuplicates(arr,n);

    for(int i = 0;i<k;i++){
        cout<<arr[i]<<" ";
    }
}