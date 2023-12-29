// Problem Statement: Given an integer array arr, find the contiguous subarray (containing at least one number) which
// has the largest sum and returns its sum and prints the subarray.

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Approach - Better approach

// int maxSubarraySum(int arr[], int n) {
//     int maxi = INT_MIN; // maximum sum

//     for (int i = 0; i < n; i++) {
//         int sum = 0;
//         for (int j = i; j < n; j++) {
//             // current subarray = arr[i.....j]

//             //add the current element arr[j]
//             // to the sum i.e. sum of arr[i...j-1]
//             sum += arr[j];

//             maxi = max(maxi, sum); // getting the maximum
//         }
//     }

//     return maxi;
// }

// Approach kadane's algorithm (optimal approach)

int maxSubarraySum(int arr[], int n){
    long long maxi = LONG_MIN;
    long long sum = 0;

    for(int i = 0;i<n;i++){
        sum += arr[i];
    
    if(sum > maxi){
        maxi = sum;
    }

    // If sum < 0: discard the sum calculated

    if(sum < 0){
        sum = 0;
    }
}

  // To consider the sum of the empty subarray
    // uncomment the following check:

    //if (maxi < 0) maxi = 0;

    return maxi;
}

int main()
{
    int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int maxSum = maxSubarraySum(arr, n);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}