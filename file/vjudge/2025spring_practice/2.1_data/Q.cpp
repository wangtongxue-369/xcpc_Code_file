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
ll _ = 1, n, m, ans = 0, w[MAXN], h[MAXN];
void solve()
{
	cin >> n;
	stack<ll> st;
	for (int i = 1; i <= n; i++)
	{
		cin >> w[i] >> h[i];
	}
	st.push(0);
	ll tmp = 0;
	h[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		if (h[st.top()] <= h[i])
		{
			st.push(i);
			continue;
		}
		else
		{
			while (st.size() && h[st.top()] > h[i])
			{
				tmp = h[st.top()];
				while (st.size() && h[st.top()] == tmp)
				{
					st.pop();
				}
				ans++;
			}
			st.push(i);
		}
	}
	while (st.size() && h[st.top()] > 0)
	{
		tmp = h[st.top()];
		while (st.size() && h[st.top()] == tmp)
		{
			st.pop();
		}
		ans++;
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
