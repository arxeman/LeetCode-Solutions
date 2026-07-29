class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int max1=INT_MIN,max2=INT_MIN,max3=INT_MIN;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int p1=nums[n-1]*nums[n-2]*nums[n-3];
        int p2=nums[0]*nums[1]*nums[n-1];
        return max(p1,p2);
    }
};