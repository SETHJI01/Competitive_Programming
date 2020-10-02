#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    ll t,n,d;
    cin>>t;
    while(t--)
    {
        cin>>n>>d;
        ll c[n];
        for(int i=0;i<n;i++)
            cin>>c[i];
        sort(c,c+n);
        ll st =0 , ed = 1e10 , ians=0;
        while(st<=ed)
        {
            ll mid = (st+ed)/2, curr=c[0],poss=1;
            for(int i=1;i<n;i++)
            {
                ll nxt = curr + mid;
                if(nxt>=c[i] && nxt<=(c[i]+d))
                    curr=nxt;
                else if(nxt<c[i])
                    curr=c[i];
                else
                {
                    poss=0;
                    break;
                }
            }
            if(poss)
            {
                ians=mid;
                st=mid+1;
            }
            else
                ed=mid-1;
        }
        long double s = ians, e = ians+1.0,ans=ians;
        while(s<=e)
        {
            ll pos=1;
            long double mid = ((s+e))/(2.0) , curr=c[0];
            for(int i=1;i<n;i++)
            {
                long double nxt = curr+mid, lo=c[i], hi=c[i]+d;
                if(nxt<=hi && nxt>=lo)
                    curr = nxt;
                else if(nxt<c[i])
                    curr=c[i];
                else{
                    pos=0;
                    break;
                }
            }
            if(pos)
            {
                ans=mid;
                s = (mid+0.000000001);
            }
            else
                e = (mid-0.000000001);
        }
        cout<<fixed<<setprecision(10)<<ans<<endl;
    }
}
