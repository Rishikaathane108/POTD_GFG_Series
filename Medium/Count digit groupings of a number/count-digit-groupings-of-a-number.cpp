//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int dp[101][902];
    
    int recur(int ind, int sum, string& str){
        if(ind>=str.size())return 1;
        if(dp[ind][sum]!=-1)return dp[ind][sum];
        int ans=0;
        int sum1=0;
        for(int i=ind;i<str.size();i++){
            sum1+=str[i]-'0';
            if(sum1>=sum)ans+=recur(i+1,sum1,str);
        }
        return dp[ind][sum]=ans;
    }
	int TotalCount(string str){
	    // Code here
	    memset(dp, -1, sizeof(dp));
	    return recur(0,0,str);
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution ob;
		int ans = ob.TotalCount(str);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends