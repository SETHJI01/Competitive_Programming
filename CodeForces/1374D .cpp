#include<bits/stdc++.h>
#define ll long long int
using namespace std;
//code force round 653 div 3
//D
int main()
{
    ll t,n,k,a[200000],ans,cnt;
    ll mx,mxi;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        mx=0;mxi=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            a[i] = k - (a[i]%k);
        }
        sort(a,a+n);
        for(int i=0;i<n;i++)
        {
            if(a[i]!=k){
            cnt=1;
            while(a[i+1]==a[i] && i<n-1)
            {
                cnt++;
                i++;
            }
            if(mx<=cnt)
            {
                mx=cnt;
            }
            if(mx==cnt)
            {
                mxi=a[i];
            }
            }
 
        }
        if(mx==0)
        {
            cout<<0<<endl;continue;
        }
       
        ans = (mx-1)*k;
        ans+= mxi+1;
        cout<<ans<<endl;
    }
}