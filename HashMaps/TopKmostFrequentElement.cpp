/*------------We have to output elements in decreasing frequency till we reach 
(k+1)th distinct elements. -----------------------*/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
     int n, k;
     cin>>n>>k;

     int a[n];

     for (int i = 0; i < n; i++)
     {
        cin>>a[i];
     }
     
    map<int, int> freq;

    for (int i = 0; i < n; i++)
    {
       
        if(freq[a[i]] == 0 && freq.size() == k){
            break;
        }

        freq[a[i]]++;

    }

    map <int, int> :: iterator it;
    vector<pair<int,int>> ans;

    for (it = freq.begin(); it!= freq.end(); it++)
    {
        if(it->second!= 0){
            pair<int,int> p;
            p.first = it->second;
        }

    }
    sort (ans.begin(), ans.end(), greater<pair<int,int>>());
    vector<pair<int,int>> :: iterator it1;    

    for(it1 = ans.begin(); it1!=ans.end(); it1++)
    cout << it1->second <<" "<<it1->first << endl;
    
    return 0;
}