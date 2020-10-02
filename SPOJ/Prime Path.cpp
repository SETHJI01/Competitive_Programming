#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
#define ll long long int
vector<int> g[100001];
int col[10001]={0};
int a[100001]={0};
int dist[100001]={0};
int cnt;
vector<int> primes;
 
bool isprime(int n)
{
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}
bool iscnt(int a,int b)
{
    int cnt=0;
    while(a>0&&b>0)
    {
        if(a%10 != b%10)
            cnt++;
        a=a/10;b=b/10;
    }
    if(cnt==1)
        return true;
    return false;
}
void buig_graph()
{
    for(int i=1000;i<10000;i++)
    {
        if(isprime(i))
            primes.push_back(i);
    }
 
    for(int i=0;i<primes.size();i++)
    {
 
        for(int j=i+1;j<primes.size();j++)
        {
            int a=primes[i];
            int b=primes[j];
            if(iscnt(a,b))
            {
                g[a].push_back(b);
                g[b].push_back(a);
            }
        }
    }
}
void bfs(int node)
{
    a[node]=1;
    queue<int> q;
    q.push(node);
    //int level=0;
    dist[node]=0;
    while(q.size()!=0)
    {
        node = q.front();
        q.pop();
 
        for(auto it:g[node])
        {
            if(a[it]==0)
            {
                a[it]=1;
                dist[it]= dist[node]+1;
                q.push(it);
            }
        }
 
    }
}
int main()
{
    int t;
    int n,e;
    buig_graph();
    cin>>t;
    while(t--)
    {cin>>n>>e;
     
    memset(dist,-1,sizeof(dist));
    memset(a,0,sizeof(a));
    bfs(n);
    if(dist[e]==-1)
        cout<<"Impossible"<<endl;
    else
        cout<<dist[e]<<endl;
 
    }
}
 