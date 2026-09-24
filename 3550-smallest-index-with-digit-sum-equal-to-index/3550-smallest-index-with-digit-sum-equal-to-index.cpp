class Solution {
public:
    int digitSum(int x){
        int ans=0;
        while(x!=0){
            ans+=x%10;
            x/=10;
        }
        return ans;
    }
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int x=nums[i];
            if(digitSum(x)==i){
                return i;
            }
        }
        return -1;
    }
};