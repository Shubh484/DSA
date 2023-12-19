#include <iostream>
#include <vector>

using namespace std;

bool isSorted(vector<int> &arr,int n){
    for(int i = 1;i<n;i++){
        if(arr[i]<arr[i-1]){
            return false;
        }
    }
    return true;
}

int main(){
    vector<int> arr{22,67,102,111,432,222};
    int n = arr.size();

    bool flag = isSorted(arr,n);

    cout<<flag;
}