#include<iostream>
#include<string>
#include<string.h>

using namespace std;

string s;
int memo[5001];

bool check(char a, char b){
	if(((a-'0')*10 + (b-'0')) <=26)
		return true;
	return false;
}

int ways(int n,int p){
	if(p==n)
		return 0;
	else if(p==n-1)
		return 1;
	else if(p==n-2){
		if((s[p]!='0' && s[p+1]!='0') && check(s[p],s[p+1]))
			return 2;
		else if(!check(s[p],s[p+1]) || s[p]=='0')
			return 0;
		else
			return 1;	
	}
		
	
	if(memo[p]!=-1)
		return memo[p];
	
	int l,r;
	
	if(s[p]!='0' && s[p+1]!='0')
		l=ways(n,p+1);
	else
		l=0;	
	
	if(check(s[p],s[p+1]))
		r=ways(n,p+2);
	else
		r=0;
		
	return memo[p]=l+r;
}

int main()
{
	
	while(1){
		cin>>s;
		if(s[0]=='0')
			break;
		memset(memo,-1,sizeof(memo));
		cout<<ways(s.size(),0)<<endl;
		/*
		for(int i=0;i<s.size();i++){
			cout<<memo[i]<<" ";
		}
		cout<<endl;
		*/
	}
}
