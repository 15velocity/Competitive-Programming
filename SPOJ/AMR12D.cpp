#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int tc;
	string s,t;
	cin>>tc;
	while(tc--){
		cin>>s;
		t=s;
		reverse(s.begin(),s.end());
		if(s == t)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}
