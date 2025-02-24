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
ll mo[110] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool check(ll i)
{
	if (i % 400 == 0 || (i % 4 == 0 && i % 100 != 0))
		return 1;
	else
		return 0;
}
void solve()
{
	ans = 0;
	cin >> n;
	ll day = 2;
	for (int i = 1998; i < n; i++)
	{
		if (check(i))
			day += 366;
		else
			day += 365;
	}
	for (int i = 1; i <= 12; i++)
	{
		if ((day + 13) % 7 == 4)
		{
			ans++;
		}
		if (i == 2 && check(n))
		{
			day += 29;
		}
		else
		{
			day += mo[i];
		}
	}
	cout << ans << '\n';
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	// cin>>_;
	while (_--)
	{
		solve();
	}
	return 0;
}
