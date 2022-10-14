// Search an element in a sorted and rotated array---------------->

#include <bits/stdc++.h>
using namespace std;

int searchRotatedArray(int arr[], int n, int key){

    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high)/2;

        if(arr[mid] == key){
            return mid;
        }

        else if(arr[low]< arr[mid]){                 // means left half is sorted
            if(key >= arr[low] && key < arr[mid]){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }

        }

        else{                                        // means right half is sorted
            if(key > arr[mid] && key<= arr[high]){
                low = mid + 1;
            }        
            else{
                high = mid - 1;
            }
        }

    }
    return -1;
}

int main(){

    int arr[] = {20, 30, 40, 50, 60, 5, 10};
    
    cout<<searchRotatedArray(arr,7, 5);

    return 0;
    
}