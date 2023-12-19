// stock buy and sell.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int Stock(vector<int>& arr) {

    int n = arr.size();
    int max_pro = 0;
    int min_price = INT_MAX;

    for (int i = 0; i < n; i++) {

        min_price = min(min_price, arr[i]);
        max_pro = max(max_pro, arr[i] - min_price);
    }

    return max_pro;
}

int main()
{
    vector<int> arr = {8,4,2,5,1,1,6,12,2,6,48};

    int maxpro = Stock(arr);

    cout << maxpro;


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
