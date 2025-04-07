#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ull unsigned long long
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> x(n);
    vector<int> y(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }
    int sum = 0;
    auto cross = [&](int a, int b) -> int
    {
        return x[a] * y[b] - x[b] * y[a];
    };
    for (int i = 1; i <= k; i++)
    {
        sum += cross(i - 1, i);
    }
    int ans = 0;
    for (int a = k + 1, b = 0; b < n; b++)
    {
        int c = (b + k) % n;
        while (cross(c, a) + cross(a, b) < cross(c, (a + 1) % n) + cross((a + 1) % n, b))
        {
            a = (a + 1) % n;
        }
        ans = max(ans, sum + cross(c, a) + cross(a, b));
        sum += cross(b + 1, b) + cross(c, (c + 1) % n);
    }
    cout << fixed << setprecision(11) << ans / 2.0 << "\n";
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _;
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
