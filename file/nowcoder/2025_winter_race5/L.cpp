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
	cin >> n;
	if (n <= 3)
	{
		cout << 0 << '\n';
		// cout << 0 << '\n';
		return;
	}
	if (n == 4 || n == 5)
	{
		cout << 1 << '\n';
		cout << 1 << ' ' << 2 << ' ' << 4 << '\n';
		return;
	}
	if (n % 6 <= 2)
	{
		cout << (n - (n % 6)) / 3 << '\n';
		for (int i = 1; i + 6 - 1 <= n; i += 6)
		{
			cout << i << ' ' << i + 1 << ' ' << i + 3 << '\n';
			cout << i + 2 << ' ' << i + 4 << ' ' << i + 5 << '\n';
		}
		return;
	}
	else
	{
		if (n % 6 == 4)
		{
			n--;
		}
		if (n % 6 == 5)
		{
			n -= 2;
		}
		cout << n / 3 << '\n';
		cout << "1 2 4" << '\n';
		cout << "3 5 9" << '\n';
		cout << "6 7 8" << '\n';
		ll p = ((n / 3) - 3) / 2;
		for (int i = 10, j = 1; j <= p; i += 6, j++)
		{
			cout << i << ' ' << i + 1 << ' ' << i + 4 << '\n';
			cout << i + 2 << ' ' << i + 3 << ' ' << i + 5 << '\n';
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> _;
	while (_--)
	{
		solve();
	}
	return 0;
}
