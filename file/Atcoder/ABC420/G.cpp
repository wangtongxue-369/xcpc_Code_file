/*
 /$$      /$$ /$$$$$$$$ /$$   /$$        /$$$$$$   /$$$$$$   /$$$$$$
| $$  /$ | $$|__  $__/| $$  / $$       /$__  $$ /$__  $$ /$__  $$
| $$ /$$$| $$   | $$   |  $$/ $$/      |__/  \ $$| $$  \__/| $$  \ $$
| $$/$$ $$ $$   | $$    \  $$$$/          /$$$$$/| $$$$$$$ |  $$$$$$$
| $$$_  $$$$    | $$     >$$  $$         |___  $$| $__  $$ \____  $$
| $$$/ \  $$$   | $$    /$$/\  $$       /$$  \ $$| $$  \ $$ /$$  \ $$
| $$/   \  $$   | $$   | $$  \ $$      |  $$$$$$/|  $$$$$$/|  $$$$$$/
|__/     \__/   |__/   |__/  |__//$$$$$$\______/  \______/  \______/
								|______/
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
void solve()
{
	ll x;
	function<ll(ll d)> get = [&](ll d)
	{
		return (d - (4 * x - 1) / d - 2) / 4;
	};
	cin >> x;
	set<ll> se;
	for (ll i = 1; i * i <= abs((4 * x - 1)); i++)
	{
		if ((4 * x - 1) % i == 0)
		{
			se.insert(get(i));
			se.insert(get(-i));
			se.insert(get((4 * x - 1) / i));
			se.insert(get(-(4 * x - 1) / i));
		}
	}
	cout << se.size() << '\n';
	for (auto it : se)
	{
		cout << it << " ";
	}
}
// (a+b)(a-b)
// aa-bb
// aa+2ab+bb
// m*m=n*n+n+x;
// m*m-n*n-n=x;
// m*m-n*(n+1)=x;
// 4mm-4n(n+1)=4x
// 4mm-4nn-4n-1=4x-1;
// 4mm-(4nn+4n+1)=4x-1;
// 4mm-((2n+1)(2n+1))=4x-1;
// (2m-(2n+1))(2m+(2n+1))=4x-1;
//
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	// cin >> _;
	while (_--)
	{
		solve();
	}
	return 0;
}