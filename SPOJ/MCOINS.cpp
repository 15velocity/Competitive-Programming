#include<iostream>
#include<string.h>
#define MAX 1000000

using namespace std;

int dp[MAX+1];

int main()
{
	int i,m,n,k,l;
	cin>>k>>l>>m;	
	
	if(l<k)
		swap(k,l);
	
	memset(dp,-1,sizeof(dp));
	
	dp[0]=0;
	dp[1]=1;
	dp[k]=1;
	dp[l]=1;
	
	for(i=2;i<MAX+1;i++){
		
		if(dp[i]!=-1)
			continue;
		
		if(i<k){
			if(dp[i-1]==1)
				dp[i]=0;
			else
				dp[i]=1;
		}
		
		else if(i<l){
			if(dp[i-1]==1 && dp[i-k]==1)
				dp[i]=0;
			else
				dp[i]=1;
		}
			
		else if(dp[i-1]==1 && dp[i-k]==1 && dp[i-l]==1)
			dp[i]=0;
		
		else
			dp[i]=1;
	}
	
	while(m--)
	{
		cin>>n;
		if(dp[n])
			cout<<"A";
		else
			cout<<"B";		
	}
}
