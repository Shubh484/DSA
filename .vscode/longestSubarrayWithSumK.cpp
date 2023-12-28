// Problem Statement: Given an array and a sum k, we need to print the length of the longest subarray that sums to k.

#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Approach - Brute Force

// int getLongestSubarray(vector<int>& a, long long k) {
//     int n = a.size(); // size of the array.

//     int len = 0;
//     for (int i = 0; i < n; i++) { // starting index
//         for (int j = i; j < n; j++) { // ending index
//             // add all the elements of
//             // subarray = a[i...j]:
//             long long s = 0;
//             for (int K = i; K <= j; K++) {
//                 s += a[K];
//             }

//             if (s == k)
//                 len = max(len, j - i + 1);
//         }
//     }
//     return len;
// }

// Approach - using hashing (Better approach)

int getLongestSubarray(vector<int> &a, long long k){
    int n = a.size();

    map<long long, int> preSumMap;
    long long sum = 0;
    int maxLen = 0;

    for(int i = 0;i<n;i++){
        // calculate prefix sum till index i
        sum += a[i];

        // if sum = k, update the maxLen
        if(sum == k){
            maxLen = max(maxLen,i+1);
        }

        // calculate the sum of remaining part
        long long rem = sum - k;

        // calculate the length and update maxLen
        if(preSumMap.find(rem) != preSumMap.end()){
            int len = i - preSumMap[rem];
            maxLen = max(maxLen,len);
        }

        // Finally, update the map checking the conditions
        if(preSumMap.find(sum) == preSumMap.end()){
            preSumMap[sum] = i;
        }
    }

    return maxLen;
}

// Approach - Two pointers (optimal approach)

// int getLongestSubarray(vector<int>& a, long long k) {
//     int n = a.size(); // size of the array.

//     int left = 0, right = 0; // 2 pointers
//     long long sum = a[0];
//     int maxLen = 0;
//     while (right < n) {
//         // if sum > k, reduce the subarray from left
//         // until sum becomes less or equal to k:
//         while (left <= right && sum > k) {
//             sum -= a[left];
//             left++;
//         }

//         // if sum = k, update the maxLen i.e. answer:
//         if (sum == k) {
//             maxLen = max(maxLen, right - left + 1);
//         }

//         // Move forward thw right pointer:
//         right++;
//         if (right < n) sum += a[right];
//     }

//     return maxLen;
// }

int main()
{
    vector<int> a = {2, 3, 5, 1, 9};
    long long k = 10;
    int len = getLongestSubarray(a, k);
    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}