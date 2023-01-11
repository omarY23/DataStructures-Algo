//Given an integer array nums, find the subarray which has the largest sum and return its sum.

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int i = 0;
        int sum = 0;
        int maxi = INT_MIN;
        while(i<nums.size()){
            sum += nums[i];
            maxi = max(maxi, sum);
            
            if(sum<0)
            sum = 0;
        i++;
        }
        return maxi;
    }
};