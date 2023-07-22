// 2023.7.22 思路来源题解

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if( n==0 )
            return 0;
        vector<int> dp(n,0);
        int temp = 0;
        for( int i=0 ; i<n ; i++ ){
            dp[i] = 1;
            temp = 0;
            for( int j=0 ; j<i ; j++ ){
                if( nums[j]<nums[i]&&temp<dp[j] )
                    temp = dp[j];
            }
            dp[i] += temp;
        }
        int ret = 0;
        for( int i=0 ; i<n ; i++ )
            if( dp[i]>ret )
                ret = dp[i];
        return ret;
    }
};

// 注：本题与最长数对链不同，最长数对链可排序，是因为最长数对链的顺序可调，而“子序列”
// 的定义决定了改=该顺序不可调
