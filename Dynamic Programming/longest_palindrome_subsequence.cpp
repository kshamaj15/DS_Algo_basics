// https://practice.geeksforgeeks.org/problems/longest-palindromic-subsequence/0
// dynamic programming
// gfg
// medium


#include <bits/stdc++.h>
using namespace std;

int main() {
	    string s;
        cout<<"Please Enter the string"<<endl;
	    cin>>s;
	    int n = s.size();
	    string rs = s;
	    reverse(rs.begin(), rs.end()); 
	    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
	    
	    for(int i=0; i<=n; i++) {
	        dp[0][i] = 0;
	        dp[i][0] = 0;
	    }
	    
	    
	    for(int i=1; i<=n; i++) {
	        for(int j=1; j<=n; j++) {
	            if(s[i-1] == rs[j-1]) {
	                dp[i][j] = 1 + dp[i-1][j-1];
	            } else {
	                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
	            }
	        }
	    }
        cout<<endl;
	    cout<<dp[n][n]<<endl;
}