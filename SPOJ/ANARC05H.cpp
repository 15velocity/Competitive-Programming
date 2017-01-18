#include<iostream>
#include<string>
#include<cstring>

using namespace std;

int dp[100][256];
int len, cs;
string s;
//char s[32];

int solve(int pos, int rsum)
{
	if(pos==0)
		return 1;		
	
	if(dp[pos][rsum] != -1)			
		return dp[pos][rsum];
	
	int i,sum=0,c=0;
	
	for(i=pos-1;i>=0;i--)
	{
		sum+=(s[i]-'0');
		if(sum<=rsum)
			c+=solve(i,sum);
		
	}
	
	return dp[pos][rsum]=c;
}

int main()
{
	int k=1;
	while(1)
	{
		memset(dp,-1,sizeof(dp));
		cin>>s;
		
		if(s=="bye")
			break;
			
		cout<<k<<". "<<solve(s.size(),1000)<<endl;
		k++;
	}
}
