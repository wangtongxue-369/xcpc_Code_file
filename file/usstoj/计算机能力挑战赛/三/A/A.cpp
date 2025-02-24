#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll mod = 1e9 + 7;
const ll N = 500005;
ll _ = 1, n, m, ans = 0, a[N], f[N];
void solve()
{
    cin >> n;
    char c;
    map<string, ll> ma;
    for (int i = 1; i <= n; i++)
    {
        string s;

        cin >> s;
        //  c = getchar();
        // cout << s << '\n';
        if (s == "add")
        {
            getline(cin, s);
            // cout << s << '\n';
            ma[s]++;
            // cout << ma[s] << '\n';
        }
        else
        {
            getline(cin, s);
            // cout << s << '\n';
            if (ma[s] >= 1)
            {
                cout << "yes" << '\n';
            }
            else
            {
                cout << "no" << '\n';
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
