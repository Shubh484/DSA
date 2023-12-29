// Problem Statement: Given an array of N integers, write a program to return an element that occurs more than N/2 times in the given array. You may consider that such an element always exists in the array.

#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Approach - using Hashmap

// int majorityElement(vector<int> &arr){

//     int n  = arr.size();
//     map<int,int> mpp;

//     for(int i=0;i<n;i++)
//     {
//         mpp[arr[i]]++;
//     }
//     for(auto it : mpp){
//         if(it.second > n/2){
//             return it.first;
//         }
//     }
//     return -1;
// }

// Approach - Moore's Voting Algorithm( Optimal approach)

int majorityElement(vector<int> v) {

    //size of the given array:
    int n = v.size();
    int cnt = 0; // count
    int el; // Element

    //applying the algorithm:
    for (int i = 0; i < n; i++) {
        if (cnt == 0) {
            cnt = 1;
            el = v[i];
        }
        else if (el == v[i]) cnt++;
        else cnt--;
    }

    //checking if the stored element
    // is the majority element:
    int cnt1 = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == el) cnt1++;
    }

    if (cnt1 > (n / 2)) return el;
    return -1;
}

int main()
{
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2,3,3,3,3,3,3,3,3,3,3};
    int ans = majorityElement(arr);
    cout << "The majority element is: " << ans << endl;
    return 0;
}