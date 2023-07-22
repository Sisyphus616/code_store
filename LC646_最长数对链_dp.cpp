//2023.7.22 照抄题解

int findLongestChain(vector<vector<int>>& pairs) {
    int n = pairs.size(), maxlen = 0, ans = 0;
    vector<int> dp(n,1);
    sort(pairs.begin(),pairs.end());			//先对数对进行排序
    for( int i=0 ;i<n ; i++ ){
        for( int j=0 ; j<i ; j++ ){
            if( pairs[i][0]>pairs[j][1] )		//数对i前数大于数对j后数
                dp[i] = max(dp[i],dp[j]+1);		//状态转移
        }
    }
    return dp[n-1];
}
