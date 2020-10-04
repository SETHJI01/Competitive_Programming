#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll p,q,r;
ll a,b,c;

const int maxN = 1e5;
ll arr[maxN];
ll arr1[maxN];

bool check1(ll N, ll M, ll n, ll m)
{
	if (N - n == M - m)
		return true;
	else if (N != 0 && M != 0 && n % N == 0 && m % M == 0 && n/N == m/M)
		return true;
	return false;
}

ll case2()
{
	if (check1(p,q,a,b) || check1(p,r,a,c) || check1(q,r, b,c))
		return 1;
	return 2;
}

ll case3()
{
	ll g,h;
	for (int i = 1; i < min(a,b); ++i)
	{
		if (i >= 1000)
			break;
		if (p % i == 0)
		{
			g = p;
			break;
		}
		else
			h = i;

	}
	if ((p - a == q - b) && (q - b == r - c))
		return 1;
	if (p != 0 && q != 0 && r != 0 && a%p == 0 && b%q == 0 && c%r == 0 && a/p == b/q && b/q == c/r)
		return 1;
	if (p != q && q != r && r != p && (a-b)%(p-q) == 0 && (b-c)%(q-r) == 0 && (a-c)%(p-r) == 0 && ((a-b)/(p-q) == (b-c)/(q-r)) && ((b-c)/(q-r) == (a-c)/(p-r)))
		return 2;
	if (check1(p,q,a,b) || check1(p,r,a,c) || check1(q,r, b,c))
		return 2;
	if (check1(q+a-p, r+a-p, b,c) || check1(p+c-r, q+c-r, a,b) || check1(p+b-q, r+b-q, a,c))
		return 2;
	if (check1(q, r, b-(a-p),c-(a-p)) || check1(p, q, a-(c-r),b-(c-r)) || check1(p, r, a-(b-q),c-(b-q)))
		return 2;
	if ((p != 0 && a%p == 0 && check1(q*(a/p),r*(a/p),b,c)) || (q != 0 && b%q == 0 && check1(p*(b/q),r*(b/q),a,c)) || (r != 0 && c%r == 0 && check1(p*(c/r),q*(c/r),a,b)))
		return 2;
	if (check1(q+a-p, r, b,c) || check1(p+c-r, q, a,b) || check1(p+b-q, r, a,c) || check1(q, r+a-p, b,c) || check1(p, q+c-r, a,b) || check1(p, r+b-q, a,c))
		return 2;
	if (check1(q, r, b-(a-p),c) || check1(p, q, a-(c-r),b) || check1(p, r, a-(b-q),c) || check1(q, r, b,c-(a-p)) || check1(p, q, a,b-(c-r)) || check1(p, r, a,c-(b-q)))
		return 2;
	if ((p != 0 && a%p == 0 && check1(q*(a/p),r,b,c)) || (q != 0 && b%q == 0 && check1(p*(b/q),r,a,c)) || (r != 0 && c%r == 0 && check1(p*(c/r),q,a,b)) || (p != 0 && a%p == 0 && check1(q,r*(a/p),b,c)) || (q != 0 && b%q == 0 && check1(p,r*(b/q),a,c)) || (r != 0 && c%r == 0 && check1(p,q*(c/r),a,b)))
		return 2;
	if (p != 0 && a%p == 0 && a != 0 && ((b%(a/p) == 0 && check1(q,r,b/(a/p),c)) || (c%(a/p) == 0 && check1(q,r,b,c/(a/p)))))
		return 2;
	if (q != 0 && b%q == 0 && b != 0 && ((a%(b/q) == 0 && check1(p,r,a/(b/q),c)) || (c%(b/q) == 0 && check1(p,r,a,c/(b/q)))))
		return 2;
	if (r != 0 && c%r == 0 && c != 0 && ((a%(c/r) == 0 && check1(p,q,a/(c/r),b)) || (b%(c/r) == 0 && check1(p,q,a,b/(c/r)))))
		return 2;
	return 3;
}



ll solve()
{
	cin >> p >> q >> r;
	cin >> a >> b >> c;
	std::vector<int> diff;
	if (p != a)
		diff.push_back(0);
	if (q != b)
		diff.push_back(1);
	if (r != c)
		diff.push_back(2);
	if (diff.size() == 0)
		return 0;
	if (diff.size() == 1)
		return 1;

	if (diff.size() == 2)
		return case2();
	return case3();
}

int main()
{

    ll tc;
    cin >> tc;
    for (ll i = 0;i < tc;i++)
    {
    	cout << solve() << "\n";
    }
    return 0;
}