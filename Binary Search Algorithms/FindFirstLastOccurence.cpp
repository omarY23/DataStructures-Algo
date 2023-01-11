/* Given an array of integers nums sorted in non-decreasing order, find the starting
 and ending position of a given target value.*/

 class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low =0;
        int high = nums.size() - 1;
        vector<int> ans(2);

        int flag1 = 0;
        //finding first occurence
        while(low<=high){
            int mid = (low + high)/2;

            if(nums[mid] == target){
                ans[0] = mid;
                high = mid-1;
                flag1 =1;
            }
            else if(target < nums[mid]){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
            
        }
        if(flag1 == 0){
            ans[0] = -1;
        }

        int flag2=0;
        low =0;
        high = nums.size() - 1;
        //finding last occurence
        while(low<=high){
            int mid = (low + high)/2;

            if(nums[mid] == target){
                ans[1] = mid;
                low = mid+1;
                flag2 =1;
            }
            else if(target < nums[mid]){
                high = mid-1;
            }
            else{
                low = mid+1;
            }

        }
        if(flag2 ==0){
            ans[1] =-1;
        }
        return ans;
    }
};