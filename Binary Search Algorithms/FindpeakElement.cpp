/* Find the peak element in an array using binary search algorithm. peak element means values at
   left and right indices must be smaller ------------->
*/

//wrong soln

#include <bits/stdc++.h>
using namespace std;

bool isPeakElement(int arr[], int mid, int n){
    
    if((arr[mid] > arr[ mid-1] && arr[mid] > arr[mid+1]) || (arr[mid] > arr[mid+1] && mid-1 <0) || (arr[mid] > arr[mid-1] && mid+1 > n-1))
        return true;
    
    return false;
}

int findPeakElement(int arr[], int n){

    int low = 0; int high = n-1;

    while (low <= high)
    {
        int mid = (low + high)/2;

        if(isPeakElement(arr, mid, n)){
            return mid;
        }

        else if(arr[mid-1] > arr[mid]){                 // then we search peak in left half
            high = mid-1;
        }

        else{
            low = mid + 1;
        }

    }
    return -1;

}

int main(){

    int arr[] = {20, 10, 15, 13, 30, 5 , 23};

    int index = findPeakElement(arr, 4);
    cout<<index<<endl;
    cout<<arr[index];
    return 0;
}
