#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> e[200005];
int a[200005] = {0};
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> ans(n + 3, 0), a(n + 3, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        int ma = 1;
        if (a[i] >= 7)
        {
            ma = a[i] / 4;
        }
        for (auto j : e[a[i]])
        {
            if (j > ma)
            {
                ans[j] += 1;
                ans[j + 1] -= 1;
                // cout << ans[j] << " " << ans[j-1] << endl;
            }
        }
        ans[ma + 1] -= 1;
        ans[0] += 1;
    }
    int pos = 1;
    for (int i = 1; i <= n; i++)
    {
        ans[i] += ans[i - 1];
        // cout << ans[i] << endl;
        if (ans[i] + k >= n)
        {
            pos = i;
        }
    }
    cout << pos << '\n';
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    a[1] = 1;
    for (int i = 2; i <= 200000; i++)
    {
        for (int j = 1; j <= sqrt(i); j++)
        {
            if (i % j == 0)
            {
                e[i].push_back(j);
                if (j * j != i)
                    e[i].push_back(i / j);
            }
        }
    }
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}