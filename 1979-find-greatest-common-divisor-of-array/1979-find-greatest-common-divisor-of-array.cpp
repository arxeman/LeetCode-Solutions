class Solution {
public:
    int findGCD(vector<int>& nums) {
        int minimum=INT_MAX, maximum=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<minimum)
                minimum=nums[i];
            if(nums[i]>maximum)
                maximum=nums[i];
        }
        return __gcd(minimum,maximum);
    }
};