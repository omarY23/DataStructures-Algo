// Form a number from a subarray of a given length which is divisible by 3   ------------->

#include <bits/stdc++.h>
using namespace std;

void formNumberSubarray(vector <int> arr, int k){

int sum= 0;

pair<int, int> ans;
bool found =false;
    for(int i =0; i<k; i++){
        sum += arr[i];
    }

    if(sum%3==0){
    found =true;
    ans = make_pair(0, k-1);
    }

    for (int j = k; j < arr.size(); j++)
    {
        if(found)
        break;

        sum = sum + arr[j] - arr[j-k];
        if(sum%3 == 0){
            ans = make_pair(j- k+1, j);
            found = true;
        }

    }
        if(!found){
            cout<<"Cannot form a number from the given array"<<endl;
        }
        else{

            cout<<"Starting index"<<" "<<ans.first<<endl;
            cout<<"Ending index"<<" "<<ans.second<<endl;
                       
        }

}


int main(){

    vector<int> v ={1, 2, 6, 4};
    int k =3;

    formNumberSubarray(v, k);
    return 0;
}