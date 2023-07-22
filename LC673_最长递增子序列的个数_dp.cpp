//2023.7.22 照抄题解

class Solution {
public:
    int findNumberOfLIS(vector<int> &nums) {
        int n = nums.size(), maxLen = 0, ans = 0;
        vector<int> dp(n), cnt(n);				//状态数组
        for (int i = 0; i < n; ++i) {
            dp[i] = 1;
            cnt[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    if (dp[j] + 1 > dp[i]) {	//从0到j最长子序列长度超出从0到i
                        dp[i] = dp[j] + 1;		//状态转移
                        cnt[i] = cnt[j]; 		//重置计数
                    } else if (dp[j] + 1 == dp[i]) {	//遇到相重序列
                        cnt[i] += cnt[j];		//计数增加
                    }
                }
            }
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                ans = cnt[i]; 					//重置计数
            } else if (dp[i] == maxLen) {
                ans += cnt[i];
            }
        }
        return ans;
    }
};
