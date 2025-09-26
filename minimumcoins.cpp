class Solution {
public:
    int compute(int index,int target,vector<int>&arr,vector<vector<int>>&dp){

        if(index==0){
            if(target%arr[index]==0) return target/arr[index];
            else return 1e9;
        }
        if(dp[index][target]!=-1) return dp[index][target];
        int nonTake = compute(index-1,target,arr,dp);
        int take = INT_MAX;
        if(arr[index]<=target) take=1+compute(index,target-arr[index],arr,dp);
        dp[index][target] = min(nonTake,take);
        return dp[index][target];

    }
    int coinChange(vector<int>& coins, int amount) {
        int index = coins.size();
        vector<vector<int>> dp(index, vector<int>(amount + 1, -1));
        int ans= compute(index-1,amount,coins,dp);
        if(ans>=1e9) return -1;
        return ans;
    }
};