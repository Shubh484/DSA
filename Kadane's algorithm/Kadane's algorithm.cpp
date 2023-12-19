// Kadane's algorithm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>

using namespace std;

long long MaxSubarraySum(int arr[], int n) {
    long long maxi = LONG_MIN;
    long long sum = 0;

    for (int i = 0; i < n; i++) {

        sum += arr[i];

        if (sum > maxi) {
            maxi = sum;
        }
        if (sum < 0) {
            sum = 0;
        }
    }

    return maxi;


}

int main()
{
    int arr[] = { 7,-6,-5,-4,3,3,-8,5,8,-16,5,9,-7 };
    int n = sizeof(arr) / sizeof(arr[0]);
    long long MaxSum = MaxSubarraySum(arr,n);
    cout << "The Maximum Subarray Sum is:" << MaxSum;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
