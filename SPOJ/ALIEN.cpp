#include<iostream>
#include<stdio.h>

using namespace std;

long long st[1000001];

int main()
{
	long long csum,len,tc,ans,i,j,n,m;
	
	cin>>tc;
	while(tc--){
		
		scanf("%lld %lld",&n,&m);
		for(i=0;i<n;i++)
			
			scanf("%lld",&st[i]);
		
		ans=0,len=0;
		i=0;
		j=1;
		csum=st[0];
		while(i<n && j<n){
			
			while(1){
				if(csum+st[j] <= m && j<n){
					csum=csum+st[j];
					j++;
				}
				else{
					if(len <= j-i){
						if(j-i == len)
							ans=min(ans,csum);
						else	
							ans=csum;
						
						len=j-i;
					}
						
					
					break;
				}
			}
			csum-=st[i];
			i++;
		}
		printf("%lld %lld\n",ans,len);
	}
}
