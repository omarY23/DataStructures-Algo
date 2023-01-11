#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int getSubarrayCount(int arr[], int n){

    map<int, int> m;
    m.insert({0,1});

    int i=-1;
    int sum=0,count=0;
             
    while(i<n-1){

        i++;
        sum += arr[i];
        auto id = m.find(sum);

        if(id != m.end()){
            count += (id->second);
            id->second++;
        }

        else{
            m.insert({sum, 1});
        }
        
    }
    return count;

}

// 2 8 -3 -5 2 -4 6 1 2 1 -3 4

int main(){

    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
      int  ans = getSubarrayCount(arr, n);
      cout<<ans;

      return 0;
}