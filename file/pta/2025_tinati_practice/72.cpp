#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> VI;
typedef vector<vector<int>> VII;
const ll mod{998244353}, inf{0x3f3f3f3f3f3f3f3f};

void solve()
{
    int n;
    cin >> n;
    vector<pair<pair<int, double>, string>> zan(n);
    for (int i = 0; i < n; ++i)
    {
        string name;
        int cnt;
        cin >> name >> cnt;
        set<int> s;
        for (int j = 0; j < cnt; ++j)
        {
            int x;
            cin >> x;
            s.insert(x);
        }
        zan[i] = {{s.size(), 1.0 * s.size() / cnt}, name};
    }
    sort(zan.begin(), zan.end(), greater<>());
    for (int i = 0; i < 3; ++i)
    {
        if (i)
            cout << ' ';
        if (i < zan.size())
        {
            cout << zan[i].second;
        }
        else
        {
            cout << "-";
        }
    }
    cout << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t{1};
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}