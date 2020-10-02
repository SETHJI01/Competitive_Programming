#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fin for(int i=0;i<n;i++)
#define ff first
#define ss second
#define vi vector<ll>
#define vc vector<char>
#define vii vector<ll,ll>
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	/*#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif*/
	ll T;
	cin>>T;
	ll n,x,temp;
	vector<ll> a;
	set<ll> s;
	while(T--){
	cin>>n>>x;
	ll day;
	for(ll i=0;i<n;i++){
		ll val;
		cin>>val;
		a.push_back(val);
		s.insert(val);
	}

	{
		sort(a.begin(),a.end());
		ll day =0;
		ll pos =0;
		int p=0;
		while(p<n && (x)>a[p])
		{
			pos++;
			p++;
		}
		while(pos>0 && (a[pos-1]*2)>=a[pos])
			pos--;
        while(pos>0 && (a[pos-1]*2)>x)
            pos--;
		for(ll i= pos;i<n;i++){
			while(x<a[i]){
				day++;
				x*=2;
			}
			x=a[i];
			x*=2;
			day++;
		}
		cout<<day+pos<<endl;
	}
	a.clear();
	s.clear();
}
	return 0;
}