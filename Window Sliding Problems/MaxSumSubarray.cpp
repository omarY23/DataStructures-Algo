// Calculation the maximum possible sum of subarray using window sliding algorithm  ------------>

#include <iostream>
using namespace std;

void maxSumSubarray(int arr[], int n, int k, int x){

    int sum = 0, ans= 0;
    for (int  i = 0; i < k; i++)
    {
        sum +=arr[i]; 
    }
    
    if(sum < x){
        ans = sum;
    }

    for (int i = k; i < n; i++)
    {
        sum = sum - arr[i-k];
        sum = sum + arr[i];

        if(sum<x){
            ans =  max(sum, ans);

        }
    }
    cout<<ans<<endl;   


}

int main() {
int arr[] = {7, 5, 4, 6, 8, 9};
int k = 3;
int x = 20;
int n = 6;
maxSumSubarray(arr, n, k, x);
return 0;
}