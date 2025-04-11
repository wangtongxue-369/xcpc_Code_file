#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define InF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, f[MAXN];

void solve()
{
    int n, k, m;
    cin >> n >> k >> m;
    vector<double> a;

    for (int i = 0; i < n; ++i)
    {
        vector<int> ve(k);
        for (int j = 0; j < k; ++j)
        {
            cin >> ve[j];
        }
        sort(ve.begin(), ve.end());
        double sum = 0;
        for (int j = 1; j < k - 1; ++j)
        {
            sum += ve[j];
        }
        double avg = sum / (k - 2);
        a.push_back(avg);
    }

    sort(a.begin(), a.end());
    for (int i = a.size() - m; i < a.size(); ++i)
    {
        if (i != a.size() - m)
            cout << " ";
        cout << fixed << setprecision(3) << a[i];
    }
    cout << endl;
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