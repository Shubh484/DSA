#include <iostream>
#include <vector>

using namespace std;

void sortArray(vector<int> &arr, int n){
    int mid =0 , low = 0, high = n-1;

    while(mid<=high){
        if(arr[mid] == 0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else{
            swap(arr[mid],arr[high]);
            high--;
        }
    }
}

int main()
{
    vector<int> arr = {0, 2, 1, 2, 0, 1,0,1};
    int n = arr.size();
    sortArray(arr, n);
    cout << "After sorting:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}