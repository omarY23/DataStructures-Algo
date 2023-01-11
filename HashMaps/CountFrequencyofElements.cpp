/*--------Counting frequency of all elements of an array using hashmaps------------*/

#include<iostream>
#include<vector>
#include<map>
using namespace std;

 int main(){
    int n;
    cin>>n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    
    map<int,int> freq;
    
    for (int i = 0; i < n; i++)
    {
        freq[a[i]]++;
    }
    
    //creating an iterator for a map
    map<int, int> :: iterator it;
    
    for (it = freq.begin(); it!= freq.end(); it++)
    {
        cout<<it->first<<"->"<<it->second<<endl;
    }
    
    return 0;


 }