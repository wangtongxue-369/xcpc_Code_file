#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll mod = 1e9 + 7;
const ll N = 500005;
ll _ = 1, n, m, ans = 0; // a[N], f[N];
void solve()
{
	ll s, t, w;
	cin >> s >> t >> w;
	char a[N];
	cin >> a;
	for (int i = 1; i <= 5; i++)
	{
		for (int j = w - 1; j >= 0; j--)
		{
			if (a[j] + 1 <= 'a' + (t - (w - j)))
			{
				a[j]++;
				for (int k = j + 1; k < w; k++)
				{
					a[k] = a[j] + k - j;
				}
				cout << a << '\n';
				break;
			}
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	// cin>>_;
	while (_--)
	{
		solve();
	}
	return 0;
}
