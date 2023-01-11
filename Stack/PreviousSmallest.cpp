#include <iostream>
#include <stack>
#include <vector>
using namespace std;


vector<int> prevSmaller(vector<int>& nums){
    stack<int> st;
    vector<int> ans;
    for(int i=0; i<nums.size();i++){

        while (!st.empty() && st.top()>= nums[i])
        {
            st.pop();
        }
        if(st.empty()){
            ans.push_back(-1);
        }
        else{
            ans.push_back(st.top());
        }
        st.push(nums[i]);      

    }
    return ans;
}

int main() {
    vector<int> nums =  {4, 10, 5, 18, 3, 12, 7};
    vector<int> ans = prevSmaller(nums);

    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
}