#include<iostream>
#include<math.h>

using namespace std;

int main()
{
	long long tc,n,cnt;
	cin>>tc;
	while(tc--)
	{
		cin>>n;
		if(n<=2){
			cout<<1<<endl;
			continue;
		}
		printf("%lld\n",((long long)(floor(( log(2*M_PI*n)/2 + n*(log(n)-1) )/log(10)) + 1)));
	}	
}
