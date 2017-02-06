#include<bits/stdc++.h>
#define FOR(i,a,b) for(i=a;i<b;i++)
#define SI(n) scanf("%d",&n)
#define PB push_back
using namespace std;

priority_queue<int,vector<int>, greater<int> > prq;
vector<int> adj[101],topsort;

int N,M,vis[101],ind[101];

void visit(){
    int u;
    while(!prq.empty()){
        u=prq.top();
        prq.pop();
        topsort.PB(u);
        for(vector<int> ::iterator it=adj[u].begin();it!=adj[u].end();it++){
            ind[(*it)]--;
            if(!ind[(*it)])
                 prq.push(*it);
        }
    }
}

int main(){
    int i,j,k,x,y;
    SI(N);
    SI(M);
    memset(vis,0,sizeof(vis));
    memset(ind,0,sizeof(ind));
    topsort.clear();
    FOR(j,0,M){
        SI(x); SI(k);
        FOR(i,0,k){
            SI(y);
            adj[y].PB(x);
        }
        ind[x]+=k;
    }

    FOR(i,1,N+1)
        if(!ind[i])
            prq.push(i);

    visit();

    FOR(i,0,topsort.size())
        cout<<topsort[i]<<" ";
}
