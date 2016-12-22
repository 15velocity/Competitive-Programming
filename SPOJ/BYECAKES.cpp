#include<iostream>

using namespace std;

int main()
{
	int e,f,s,m,ed,fd,sd,md,nc;
	while(1)
	{
		cin>>e>>f>>s>>m>>ed>>fd>>sd>>md;
		if(e==-1)
			break;
			
		nc= e%ed == 0 ? e/ed : e/ed+1 ;
		nc = max(nc , (f%fd == 0 ? f/fd : f/fd+1));
		nc = max(nc , (s%sd == 0 ? s/sd : s/sd+1));
		nc = max(nc , (m%md == 0 ? m/md : m/md+1));
		
		e = nc*ed - e;
		f = nc*fd - f;
		s = nc*sd - s;
		m = nc*md - m;
		
		cout<<e<<" "<<f<<" "<<s<<" "<<m<<endl;
	}
}
