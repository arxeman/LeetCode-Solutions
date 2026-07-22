class Solution {
private: 
    int solve(vector<int>& coins,int ind,int target,vector<vector<int>>& dp){
        if(target==0) return 0;
        if(ind==0){
            if(target%coins[ind]==0) return target/coins[ind];
            return 1e9;
        }
        if(dp[ind][target]!=-1) return dp[ind][target];
        int not_take=solve(coins,ind-1,target,dp);
        int take=1e9;
        if(target>=coins[ind]){
            take=1+solve(coins, ind, target-coins[ind],dp);
        }
        return dp[ind][target]=min(take,not_take);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,-1));
        int ans=solve(coins,n-1,amount,dp);
        if(ans>=1e9) return -1;
        return ans;
    }
};