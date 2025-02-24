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
    ll k;
    cin >> n >> k;
    string s;
    cin >> s;
    ll i0 = 0, i1 = 0;
    for (int i = 0; i < n;)
    {
        string s1;
        if (s[i] == '0')
        {
            i0++;
            while (s[i] == '0' && i < n)
            {
                cout << s[i];
                i++;
            }
        }
        else
        {
            i1++;
            if (i1 == k - 1)
            {
                string s1, s2, s3;
                while (s[i] == '1' && i < n)
                {
                    s1 += s[i];
                    i++;
                }
                while (s[i] == '0' && i < n)
                {
                    s2 += s[i];
                    i++;
                }
                while (s[i] == '1' && i < n)
                {
                    s3 += s[i];
                    i++;
                }
                cout << s1 << s3 << s2;
                i0++;
                i1 = k;
            }
            else
            {
                while (s[i] == '1' && i < n)
                {
                    cout << s[i];
                    i++;
                }
                continue;
            }
        }
    }
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
