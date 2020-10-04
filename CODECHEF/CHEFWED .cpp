#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void insert(ll mat[1001][1001], ll a[1001], ll I,ll J,ll k)
{
    ll cnt[101]={0};
    ll count = k;
    for(ll i=I;i<=J;i++)
    {
        cnt[a[i]]++;
        if(cnt[a[i]]>1)
        {
            if(cnt[a[i]]==2)
                count+=2;
            else
                count++;
        }
        mat[I][i]=count;
    }
}
ll calc(ll mat[1001][1001],ll n)
{
    ll cnt=0;
    ll i=0,j=0,x;
    vector<ll> vec,vecb;
    vecb.push_back(0);
    while(i<n && j<n)
    {
        x=0;
        
        while( j<n-1 &&mat[i][j] == mat[i][j+1])
            j++;
        cnt+=mat[i][j];
        auto itr=vecb.begin();
        for(auto it:vec)
        {
            x+=(*itr);
            itr++;
           
            if(cnt> x+ mat[it][j])
            {
                cnt= x+ mat[it][j];
                break;
            }
        }
        vec.push_back(i);
        vecb.push_back(mat[i][j]);
        i=j+1;
        j++;
        
    }
    return cnt;
}
ll calc2(ll mat[1001][1001],ll n)
{
    ll cnt=0;
    ll i=0,j=0,x=mat[0][n-1];
    while(i<n-1 )
    {
        cnt = mat[0][i] + mat[i+1][n-1];
        x=min(x,cnt);
        i++;
    }
    return x;
}
int main() {
    ll t,k,n;
    cin>>t;
    
   
    while(t--)
    {
        ll mat[1001][1001];
         ll a[1001];
        cin>>n>>k;
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n;i++)
            insert(mat,a,i,n-1,k);
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<n;j++)
        //     {
        //         cout<<mat[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        ll ans1 = calc(mat,n);
        ll ans2= calc2(mat,n);
        cout<<min(ans1,ans2)<<endl;

    }
}
