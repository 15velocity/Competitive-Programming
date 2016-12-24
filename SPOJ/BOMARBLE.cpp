#include<iostream>

using namespace std;

int main()
{
	int n,i,k,dp[1001];
	
	dp[1]=5;
	for(i=0,k=2;k<1001;k++,i++)
	{
		dp[k]= dp[k-1]+7+3*i;
	}
	
	while(1)
	{
		cin>>n;
		if(n==0)
			break;
			
		cout<<dp[n]<<endl;
	}
}
