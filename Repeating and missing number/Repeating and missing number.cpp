#include<bits/stdc++.h>
#include<vector>
#include<stdio.h>
#include<conio.h>
#include<iostream>

using namespace std;

vector<int> findMissingRepeatingNumbers(vector<int> a) {

	int n = a.size();
	int hash[n + 1] = { 0 };

	for (int i = 0; i < n; i++) {
		hash[a[i]]++;
	}

	int repeating = -1, missing = -1;

	for (int i = 0; i <= n; i++) {
		if (hash[i] == 2) repeating = i;
		else if (hash[i] == 0) missing = i;

		if (repeating != -1 && missing != -1) {
			break;
		}
	}

	return { repeating , missing };


}

int main()
{
	vector<int> a = { 3, 1, 2, 5, 4, 6, 7, 5 };
	vector<int> ans = findMissingRepeatingNumbers(a);
	cout << "The repeating and missing numbers are: {"
		<< ans[0] << ", " << ans[1] << "}\n";
	return 0;
}