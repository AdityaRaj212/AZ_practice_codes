
class Solution {
public:
    long long maximumTotalCost(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefixSum(n+1,0);

        for(int i=0;i<n;i++){
            if(i%2==0){
                prefixSum[i+1] = prefixSum[i] + nums[i];
            }else{
                prefixSum[i+1] = prefixSum[i] - nums[i];
            }
        }
        
        vector<long long> dp(n+1, LLONG_MIN);
        // dp[0] = nums[0];
        dp[0] = 0;

        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                
                long long cost = prefixSum[i] - prefixSum[j];
                dp[i] = max(dp[i],dp[j]+cost);
                
            }
            // dp[i] = max(dp[i], prefixSum[i + 1]);
        }

        long long maxCost = LLONG_MIN;
        for(int i=1;i<=n;i++){
            maxCost = max(maxCost, dp[i]);
        }
        
        return maxCost;
    }
};