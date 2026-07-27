class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        if(n==2){
            return ((nums[0]-1)*(nums[1]-1));
        }
        int maxx=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
               maxx=max(maxx,((nums[i]-1)*(nums[j]-1)));
            }
        }
        return maxx;
    }
};