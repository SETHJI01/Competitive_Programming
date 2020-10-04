#include<bits/stdc++.h>
using namespace std;
 
int col[10000]={0};
void DFS ( vector<int> dfs[],int a,int arr[],int height)
{
    arr[a]=1;
    for(auto it:dfs[a])
    {
        if(arr[it] == -1)
            DFS(dfs, it, arr,height+1);
    }
    return;
}
bool DFS_bipartite(vector<int> dfs[],int a,int arr[],int c)
{
    arr[a]=1;
    col[a]=c;
    for(auto it:dfs[a])
    {
        if(arr[it] == -1)
        {
            if(DFS_bipartite(dfs,it,arr,(c+1)%2)==false)
                return false;
        }
        if(col[a]==col[it])
            return false;
    }
    return true;
}
int main()
{
    int T;
    cin>>T;
    for(int t=1;t<=T;t++)
    {
        memset(col,0,sizeof(col));
 
    int n,e;
    cin>>n>>e;
    vector<int> dfs[n+1];
    int v1,v2;
    for(int i=0;i<e;i++)
    {
 
        cin>>v1>>v2;
        dfs[v1].push_back(v2);
        dfs[v2].push_back(v1);
    }
    int a[n+1];
    for(int i=0;i<=n;i++)
        a[i]=-1;
    int c=0;
    bool status;
    status=DFS_bipartite(dfs,1,a,c);
    for(int i=1;i<=n;i++)
    {
        if(a[i]==-1)
            status=DFS_bipartite(dfs,i,a,c);
        if(status ==false)
            break;
    }
    cout<<"Scenario #"<<t<<":"<<endl;
    status?cout<<"No suspicious bugs found!":cout<<"Suspicious bugs found!";
    cout<<endl;
    }
 
}
 