// Minimize the maximum number of pages allocated to a student------------->

#include <bits/stdc++.h>
using namespace std;

int arraySum(int a[], int n)        //Function to find sum of all elements of an array
{
    int initial_sum = 0;
    return accumulate(a, a+n, initial_sum);
}

bool isFeasible(int a[], int n, int k, int mid)
{
    int sum = 0, students=1;

    for (int i = 0; i < n; i++)
    {
        if(sum + a[i] > mid){
            students++;
            sum = a[i];
        }
        else{
            sum += a[i];
        }
               
    }
    
    if(students<=k)
    return true;

    else
    return false;

}

int minimizeAllocationMaxPages(int arr[], int n, int k){

    
    int min = *min_element(arr, arr + n);
    int max = arraySum(arr, n);

    
    int res;
    while (min<=max )
    {
        int mid = (min + max)/2;

        if(isFeasible(arr, n , k, mid)){
            max = mid-1;
            res = mid;
        }

        else{
            min = mid + 1;
        }
    }
    return res;

}


int main(){

    int arr[] = {10, 20, 5, 15, 5};
    int n = 5;
    int k = 2;

    cout<<minimizeAllocationMaxPages(arr, n, k);
    return 0;
}