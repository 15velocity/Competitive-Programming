#include<bits/stdc++.h>

using namespace std;

int n,m;
int vis[1001][1001];
char s[1001][1001];

void traverse(int r,int c){
    if(!vis[r][c]){
        vis[r][c]=1;
        if(s[r][c]=='N')
            traverse(r-1,c);

        else if(s[r][c]=='S')
            traverse(r+1,c);

        else if(s[r][c]=='E')
            traverse(r,c+1);

        else if(s[r][c]=='W')
            traverse(r,c-1);

        if(r+1<m && s[r+1][c] == 'N')
            traverse(r+1,c);
        if(r-1>=0 && s[r-1][c] == 'S')
            traverse(r-1,c);
        if(c+1<n && s[r][c+1] == 'W')
            traverse(r,c+1);
        if(c-1>=0 && s[r][c-1] == 'E')
            traverse(r,c-1);
    }
}

int main()
{
    int ans=0;
    cin>>m>>n;
    for(int i=0;i<m;i++)
        cin>>s[i];

    memset(vis,0,sizeof(vis));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(!vis[i][j]){
                ans++;
                traverse(i,j);
            }
        }
    }
    cout<<ans;
}
