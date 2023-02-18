/*Chef has a permutation P of length 2⋅N. He can perform the following operation on P:
Select an index i (1 \le i \lt 2 \cdot N)(1≤i<2⋅N) and swap Pi and Pi+1 

Chef would call the permutation P good, if the maximum element of the first half of P is less than the minimum element of the second half of P.

Find the minimum number of operations Chef needs to apply to make P good.
3 2 1 4
Output - 2
6 5 4 3 2 1
Output - 9
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int 

int main() {
    int t;
    cin>>t;
    
    while(t--){
        
        int n;
        cin>>n;
        int size=2*n;
        int a[size];
        
        for(int i=0; i<size ; i++)
        cin >> a[i];
        
        
        vector<ll> difference1;
        vector<ll> difference2;
        
        for(int i = 0; i < size; i++){
        //checking whether value lies in first window but actually
        //belongs to second window
        if(a[i]> size/2 && i < size/2 )
        difference1.push_back(i+1);
        //checking whether value lies in second window but actually
        //belongs to first window
        if(a[i]<= size/2 && i >= size/2)
        difference2.push_back(i+1);
        }
        ll op=0;
        for(int i=0; i<difference1.size(); i++)
        op+= abs(difference1[i] - difference2[i]);
        
        cout<<op<<endl;
    }
    
	return 0;
}

