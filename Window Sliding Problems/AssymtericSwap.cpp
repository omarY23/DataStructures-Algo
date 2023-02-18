/*Chef has two arrays A and B of the same size N.
In one operation, Chef can:
Choose two integers i and j and swap the elements A[i] and B[j]

Chef came up with a task to find the minimum possible value of (A_{max} - A_{min})
after performing the swap operation any (possibly zero) number of times.

denote the maximum and minimum elements of the array A respectively.

2 8 4 9 7
7 3 6 8 4
Output - 2
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--){
	    int n;
	    cin>>n;
	    
	    int A[n], B[n], C[2*n];
	    
	    for(int i=0; i<n; i++){
	        cin>>A[i];
	        C[i] = A[i];
	    }
	    
	    for(int i=0; i<n; i++){
	        cin>>B[i];
	        C[i+n] = B[i];
	    }
	    
	    
	    sort(C, C + 2*n);
	    
	    int diff = INT_MAX;
        // now sliding window approach. we find a window of n in which max -min is minimum
        for(int i =0; i<=n; i++){
            int mini = C[i];        //for any particular window as array is sorted
            int maxi = C[i+n-1];

            diff = min(diff, maxi-mini);
        }
	    cout<<diff<<endl;
	}
	return 0;
}
