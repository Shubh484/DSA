// Dutch National Flag Algorithm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

void SortArray(vector<int>& arr) {

    int n = arr.size();

    int low = 0, mid = 0, high = n - 1;

    while (mid <= high) {

        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }

        else if (arr[mid] == 1) {
            mid++;
        }
        else {
            swap(arr[mid], arr[high]);
            high--;
        }

    }
}

int main()
{
    vector<int> arr = { 0,2,2,2,2,0,1,0,1,2,2,1,1,0,0};

    SortArray(arr);

    cout<< "Array after sorting" << endl;

    for (auto iter : arr) {
        cout << iter << " ";
    }

    return 0;
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
