class Solution {
public:
    int compute(int index,int target,vector<int>&arr){

        if(index==0){
            if(target%arr[index]==0) return target/arr[index];
            else return 1e9;
        }
        int nonTake = compute(index-1,target,arr);
        int take = INT_MAX;
        if(arr[index]<=target) take=1+compute(index,target-arr[index],arr);
        return min(nonTake,take);

    }
    int coinChange(vector<int>& coins, int amount) {
        int ans= compute(coins.size()-1,amount,coins);
        if(ans>=1e9) return -1;
        return ans;
    }
};