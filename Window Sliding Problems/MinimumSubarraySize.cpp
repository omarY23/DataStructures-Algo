/*Find the minimum subarray length for which the sum of elements of the
 subarray is great than a given value------------------->
*/

#include <bits/stdc++.h>
using namespace std;

int minSubArrayLength(int arr[], int n, int x){

    int sum= 0, ans=0, front=0;
    for (int i = 0; i < n; i++)
    {
        if(sum < x){
            sum += arr[i];
            ans++;            
        }

        else{
            sum -= arr[front];
            front++;
            if(sum > x){
                ans--;
            }
            
        }

    }
    return ans;

}

int main(){

    int arr[] = {4, 3, 8, 9, 2};
    int n = 5;
    int x =10;
    int ans = minSubArrayLength(arr, n, x);

    cout<<ans<<endl;
    return 0;
}