#include<bits/stdc++.h>

using namespace std;

long long f,s,g,up,d,vis[1000001],dis[1000001];

long long bfs(){
    queue<int> q;
    q.push(s);
    vis[s]=1;
    int u,v;
    while(!q.empty()){
        u=q.front();
        q.pop();
        if(u+up==g || u-d==g)
            return dis[u]+1;

        if(u+up<=f && !vis[u+up]){
            q.push(u+up);
            vis[u+up]=1;
            dis[u+up]=dis[u]+1;
        }
        if(u-d>0 && !vis[u-d]){
            q.push(u-d);
            vis[u-d]=1;
            dis[u-d]=dis[u]+1;
        }
    }
    return 0;
}

int main()
{
    cin>>f>>s>>g>>up>>d;
    memset(vis,0,sizeof(vis));
    memset(dis,0,sizeof(dis));
    if(s==g)
        cout<<0;
    else{
        long long ans = bfs();
        if(ans==0)
            cout<<"use the stairs";
        else
            cout<<ans;
    }
}
