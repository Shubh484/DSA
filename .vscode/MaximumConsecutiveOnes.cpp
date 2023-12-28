#include <iostream>
#include <vector>

using namespace std;

int maxOnes(vector<int> &arr,int n){
    int count_one = 0;
    int max_ones = 0;

    for(int i=0;i<n;i++){
        if(arr[i]==1){
            count_one++;
             if(max_ones < count_one){
                max_ones = count_one;
            }
        }
        if(arr[i]!=1){
            count_one = 0;
        }
    }
    return max_ones;
}

// same approach

// int findMaxConsecutiveOnes(vector < int > & nums) {
//       int cnt = 0;
//       int maxi = 0;
//       for (int i = 0; i < nums.size(); i++) {
//         if (nums[i] == 1) {
//           cnt++;
//         } else {
//           cnt = 0;
//         }

//         maxi = max(maxi, cnt);
//       }
//       return maxi;
//     }

int main(){
    vector<int> arr = {1,1,0,1,1,1,1,1,0};

    int n = arr.size();

    int max = maxOnes(arr,n);

    cout<<max;

    return 0;
}