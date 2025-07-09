#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<array<i64, 3>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    if (k == 1)
    {
        cout << "-1";
        return;
    }
    sort(a.begin(), a.end());
    auto check = [&](i64 t) -> bool
    {
        vector<array<i64, 3>> b(n);
        for (int i = 0; i < n; i++)
        {
            b[i][0] = a[i][0] + a[i][1] * t;
            b[i][1] = i;
            b[i][2] = a[i][2];
        }
        sort(b.begin(), b.end());
        for (int i = 0; i < n - 1; i++)
        {
            if (b[i][0] == b[i + 1][0] && b[i][2] != b[i + 1][2])
            {
                return 1;
            }
            if (b[i][0] < b[i + 1][0] && a[b[i][1]][0] > a[b[i + 1][1]][0] && b[i][2] != b[i + 1][2])
            {
                return 1;
            }
        }
        return 0;
    };
    i64 l = -1, r = 1e18;
    while (l + 1 != r)
    {
        i64 mid = l + r >> 1;
        if (check(mid))
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    cout << l;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}