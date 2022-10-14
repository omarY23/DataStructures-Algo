/* For a given array and an integer K, check if any subarray of size K exists in the array such that
   concatenation of elements form a palindrome.------------------->  
*/

#include<bits/stdc++.h>
using namespace std;

bool isPallindrome(int n) {
int temp = n, number = 0;
while(temp > 0) {
number = number*10 + temp%10;
temp = temp/10;
}
if(number == n) {
return true;
}
return false;
}
 

int subArrayPallindrome(vector<int> arr, int k){
    int num=0;


    for (int i = 0; i < k; i++)
    {
        num = num*10 + arr[i];
    }

    if(isPallindrome(num)){                      // we return 0 means from index 0 itself, k elements are forming a pallindrome no.
        return 0;
    }

    for (int j = k; j < arr.size(); j++)
    {
        num = (num % (int)pow(10, k-1))*10;
        num = num + arr[j];

         if(isPallindrome(num)){
            return j-k+1; 
            
        }
    }
    
    return -1;   
    
}

int main()
{
    vector<int> arr = {2, 3, 5, 1, 1, 5};
int k = 4;
int ans = subArrayPallindrome(arr, k);

if(ans == -1) {
cout << "palindromic subarray doesn't exist" << endl;
}

else{
for(int i=ans; i<ans+k; i++) {
cout << arr[i] << " ";
}
cout << endl;
}

return 0;
}