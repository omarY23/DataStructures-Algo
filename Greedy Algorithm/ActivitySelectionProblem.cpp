/*---The Activity Selection Problem is an optimization problem which deals with the selection of non-conflicting
 activities that needs to be executed by a single person or machine in a given time frame.----*/

#include<bits/stdc++.h>
using namespace std;

int main(){

    int n; cin>>n;
    vector<vector<int>> v;


    for(int i = 0;i<n;i++){
    int start, end;
    cin>>start>>end;
    v.push_back({start, end});
    }

    //custom comparator
    sort (v.begin(),v.end(),[&] (vector<int> &a,vector<int> &b){
        return a[1] < b[1];
    });

    // as the activity whoch ends first will be definitely chosen
    int take = 1;
    int end = v[0][1];

    for(int i = 1;i<n;i++){
        if(v[i][0] >= end) {
        take++;
        end = v[i][1];
        }
    }
    cout<<take<<endl;
    
    
    return 0;
}