#include<bits/stdc++.h>

using namespace std;

char s[183][183];
int ans[183][183];
int vis[183][183],m,n;
int xt[]={0,0,1,-1};
int yt[]={1,-1,0,0};
typedef pair<int,int > ii;

void bfs(){
    int i,j,u,v;
    queue<ii> q;

    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            if(s[i][j]=='1'){
                q.push(make_pair(i,j));
                vis[i][j]=1;
                ans[i][j]=0;
            }
            else
                ans[i][j]=1<<30;


    while(!q.empty()){
        ii tmp = q.front();
        q.pop();

        for(i=0;i<4;i++){
            u = tmp.first + xt[i];
            v = tmp.second + yt[i];

            if(u>=0 && u<m && v>=0 && v<n && !vis[u][v] && (ans[u][v]>ans[tmp.first][tmp.second]+1)){
                ans[u][v]=ans[tmp.first][tmp.second] + 1;
                q.push(make_pair(u,v));
                vis[u][v] = 1;
            }
        }
    }
}

int main()
{
    int tc,i,j;
    cin>>tc;
    while(tc--){
        cin>>m>>n;
        for(i=0;i<m;i++)
            cin>>s[i];

        memset(vis,0,sizeof(vis));
        bfs();

        for(i=0;i<m;i++){
            for(j=0;j<n;j++)
                cout<<ans[i][j]<<" ";
            cout<<endl;
        }
    }
}
