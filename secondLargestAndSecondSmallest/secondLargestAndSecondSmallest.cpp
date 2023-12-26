// secondLargestAndSecondSmallest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

int secondSmallest(vector<int>& arr, int n) {

	int small = INT_MAX;
	int second_smallest = INT_MAX;

	if (n < 2) return -1;

	for (int i = 0; i < n; i++) {
		if (arr[i] < small) {
			second_smallest = small;
			small = arr[i];
		}
		else if(arr[i] < second_smallest && arr[i]!=small) {
			second_smallest = arr[i];
		}
	}
	return second_smallest;
}
int secondLargest(vector<int>& arr, int n) {
	int large = INT_MIN;
	int second_largest = INT_MIN;

	if (n < 2) return -1;

	for (int i = 0; i < n; i++) {
		if (arr[i] > large) {
			second_largest = large;
			large = arr[i];
		}
		else if (arr[i] < second_largest && arr[i] != large) {
			second_largest = arr[i];
		}
	}
	return second_largest;

}


int main()
{
	vector<int> arr{1,2,4,7,7,5};

	int n = sizeof(arr);

	int sS = secondSmallest(arr, n);
	int sL = secondLargest(arr, n);

	cout << "Second Smallest:" << sS;
	cout << "second Largest:" << sL;

}

