#include<bits/stdc++.h>
using namespace std;
 
vector<int> g[100001];
int in[100001], low[100001], vis[100001];
int timer;
bool hasbridge;
vector<pair<int,int>> egdeList;
 
void dfs(int node,int parent)
{
    vis[node]=1;
    in[node] =timer;
    low[node]=timer;
    timer++;
 
    for(auto it:g[node])
    {
        if(it==parent)
        {
            continue;
        }
        else if(vis[it]==1)
        {
            //egde node - child is a back egde
            low[node]= min(low[node], in[it]);
            if(in[node]>in[it])
            egdeList.push_back({node,it});
        }
        else
        {
            //egde node - child is forward egde
            dfs(it,node);
 
            if(low[it]> in[node])
            {
                hasbridge=true;
                return;
            }
            egdeList.push_back({node,it});
            low[node]=min(low[node],low[it]);
        }
    }
}
int main()
{
    int n,e,v,u;
    cin>>n>>e;
    while(e--)
    {
        cin>>v>>u;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    memset(vis,0,sizeof(vis));
    dfs(1,-1);
    if(hasbridge)
        cout<<0<<endl;
    else{
        for(auto p:egdeList)
        {
            cout<<p.first<<" "<<p.second<<endl;
        }
    }
}