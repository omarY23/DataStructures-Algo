/*-------When two or more sorted files are to be merged altogether to form a single file, 
the minimum computations are done to reach this file are known as Optimal Merge Pattern.*/


#include<bits/stdc++.h>
using namespace std;

int main(){

    int n; cin>>n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    
    priority_queue<int, vector<int>, greater<int>> minheap;

     for (int i = 0; i < n; i++)
    {
        minheap.push(v[i]);
    }

    int ans=0;
    while(minheap.size() > 1){

        int a = minheap.top();
        minheap.pop();

        int b = minheap.top();
        minheap.pop();

        ans += a+b;
        minheap.push(a+b);
    }

    cout<<ans;

    return 0;
}