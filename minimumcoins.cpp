class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int index = coins.size();
        vector<vector<int>> dp(index, vector<int>(amount + 1, 1e9));
        for(int k=0;k<=amount;k++) {
            if(k%coins[0]==0) dp[0][k] = k/coins[0];
        }
        for(int i=1;i<index;i++){
            for(int j=0;j<=amount;j++){
                int nonTake = dp[i-1][j];
        int take = INT_MAX;
        if(coins[i]<=j) take=1+dp[i][j-coins[i]];
        dp[i][j] = min(nonTake,take);
            }
        }
        int ans= dp[index-1][amount];
        if(ans>=1e9) return -1;
        return ans;
    }
};