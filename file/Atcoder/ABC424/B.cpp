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
ll _ = 1, n, m, ans = 0; // a[MAXN], f[MAXN];
struct node
{
	set<ll> se;
	ll t = 1e18;
	ll i;
};
bool cmp(node s1, node s2)
{
	return s1.t < s2.t;
}
void solve()
{
	ll k;
	cin >> n >> m >> k;
	vector<node> a(n);
	ll s1, s2;
	for (ll i = 1; i <= k; i++)
	{
		cin >> s1 >> s2;
		s1--;
		a[s1].se.insert(s2);
		if (a[s1].se.size() == m)
		{
			a[s1].i = s1;
			a[s1].t = min(a[s1].t, i);
		}
	}
	sort(a.begin(), a.end(), cmp);
	for (int i = 0; i < n; i++)
	{
		if (a[i].se.size() == m)
		{
			cout << a[i].i + 1 << ' ';
		}
	}
	cout << '\n';
}
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