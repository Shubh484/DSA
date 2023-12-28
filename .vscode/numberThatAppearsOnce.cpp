// Problem Statement: Given a non-empty array of integers arr, every element appears twice except for one. Find that single one.

#include <iostream>
#include <vector>

using namespace std;

// Approach - using hashing (array hashing)

int getSingleElement(vector<int> &arr){

    int n = arr.size();
    int maxi = arr[0];
    for(int i=0;i<n;i++){
        maxi = max(maxi,arr[i]);
    }

  // Declare hash array of size maxi + 1
  // And hash the given array
    vector<int> hash(maxi+1,0);
    for(int i=0;i<n;i++){
        hash[arr[i]]++;
    }

      for(int i=0;i<n;i++){
       if(hash[arr[i]]==1){
        return arr[i];
       }
    }

    return -1;

}

// Approach - Hashing using the map data structure

// int getSingleElement(vector<int> &arr) {

//     //size of the array:
//     int n = arr.size();

//     // Declare the hashmap.
//     // And hash the given array:
//     map<int, int> mpp;
//     for (int i = 0; i < n; i++) {
//         mpp[arr[i]]++;
//     }

//     //Find the single element and return the answer:
//     for (auto it : mpp) {
//         if (it.second == 1)
//             return it.first;
//     }

//     //This line will never execute
//     //if the array contains a single element.
//     return -1;
// }

// Approach - using XOR (optimal approach)

// XOR of two same numbers is always 0 i.e. a ^ a = 0. ←Property 1.
// XOR of a number with 0 will result in the number itself i.e. 0 ^ a = a.  ←Property 2

// int getSingleElement(vector<int> &arr) {
//     //size of the array:
//     int n = arr.size();

//     // XOR all the elements:
//     int xorr = 0;
//     for (int i = 0; i < n; i++) {
//         xorr = xorr ^ arr[i];
//     }
//     return xorr;
// }

int main()
{
    vector<int> arr = {4, 1, 2, 1, 2};
    int ans = getSingleElement(arr);
    cout << "The single element is: " << ans << endl;
    return 0;
}