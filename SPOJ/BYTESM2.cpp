#include<iostream>
#include<string.h>

using namespace std;

int h,w,dp[101][101],ft[101][101];

int main()
{
	int tc,i,j,ans;
	cin>>tc;
	while(tc--)
	{
		memset(dp,0,sizeof(dp));
		ans=0;
		cin>>h>>w;
		for(i=0;i<h;i++)
			for(j=0;j<w;j++)
				cin>>ft[i][j];
		
		for(i=0;i<h;i++)
			dp[i][0]=0;
		
		for(i=0;i<w;i++)
			dp[0][w]=0;
		
		for(i=1;i<=h;i++){
			for(j=1;j<=w;j++){
				dp[i][j]=ft[i-1][j-1]+max(dp[i-1][j-1],max(dp[i-1][j],dp[i-1][j+1]));
			}
		}
		
		for(i=1;i<=w;i++)
			ans=max(dp[h][i],ans);	
		
		cout<<ans<<endl;
	}
}
