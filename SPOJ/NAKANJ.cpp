#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
ii p1,p2;
int vis[8][8],dist[8][8];
int xt[] = {1,1,-1,-1,2,2,-2,-2};
int yt[] = {2,-2,2,-2,1,-1,1,-1};

int bfs(){
    queue<ii> q;
    int u,v,i,x,y;
    ii tmp;
    q.push(p1);
    vis[p1.first][p1.second] = 1;
    while(!q.empty()){
        tmp = q.front();
        q.pop();
        x = tmp.first;
        y = tmp.second;
        if(x==p2.first && y==p2.second)
            return dist[x][y];

        for(i=0;i<8;i++){
            u = x + xt[i];
            v = y + yt[i];
            if(u>=0 && v>=0 && u<8 && v<8 && !vis[u][v]){
                q.push(make_pair(u,v));
                vis[u][v] = 1;
                dist[u][v] = dist[x][y]+1;
            }
        }
    }
}

int main()
{
    int tc;
    string s1,s2;
    cin>>tc;
    while(tc--){
        cin>>s1>>s2;
        p1.second = s1[0] - 'a';
        p1.first = (7 - (s1[1] - '1'));
        p2.second = s2[0] - 'a';
        p2.first = (7 - (s2[1] - '1'));

        memset(dist,0,sizeof(dist));
        memset(vis,0,sizeof(vis));
        cout<<bfs()<<endl;
    }
}
