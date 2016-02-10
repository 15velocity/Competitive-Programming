#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;

int dir[][2]={{0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,-1},{1,-1},{-1,1}};
char matrix[51][51];
int memo[51][51];

int longest(int r,int c)
{
	if(memo[r][c]!=-1)
		return memo[r][c];
	
	int x,y,m=1,i;
	for(i=0;i<8;i++)
	{
		x=dir[i][0];
		y=dir[i][1];
		if(matrix[r+x][c+y]==matrix[r][c]+1)
			m=max(longest(r+x,c+y)+1,m);
	}
	return memo[r][c]=m;
}

int main()
{
	int h,w,i,j,tc=1,res;
	cin>>h>>w;
	while(h!=0 || w!=0)
	{
		res=0;
		
		memset(memo,-1,sizeof(memo));
		memset(matrix,48,sizeof(matrix));
		
		for(i=0;i<h;i++)
			for(j=0;j<w;j++)
				cin>>matrix[i][j];
		
		for(i=0;i<h;i++)
		{
			for(j=0;j<w;j++)
			{
				if(matrix[i][j]=='A')
				{
					res= max(longest(i,j),res);
				}
			}
		}
				
		cout<<"Case "<<tc++<<": "<<res<<endl;
		cin>>h>>w;
	}
}
