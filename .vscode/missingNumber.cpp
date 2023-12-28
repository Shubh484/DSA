#include <iostream>
#include <vector>

using namespace std;

int missingNumber(vector<int>& a,int n){

    // sum of all elements
    int sum = (n*(n+1))/2;

    int sum2 = 0;

    // sum of elements in array
    for(int i=0;i<n-1;i++){
        sum2+=a[i];
    }

    int missing_number = sum - sum2;
    return missing_number;
}

int main()
{
    int N = 5;
    vector<int> a = {1, 2, 4, 5};
    int ans = missingNumber(a, N);
    cout << "The missing number is: " << ans << endl;
    return 0;
}