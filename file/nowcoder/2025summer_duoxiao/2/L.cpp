#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int inv2 = (mod + 1) / 2;           // 2的逆元
const int inv4 = 1ll * inv2 * inv2 % mod; // 4的逆元

ll ksm(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
        {
            res = res * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
int main()
{
    int _ = 1;
    cin >> _;
    while (_--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            a[i]--;
        }
        vector<ll> b;
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                int cnt = 0;
                int nxt = i;
                while (!vis[nxt])
                {
                    vis[nxt] = 1;
                    cnt++;
                    nxt = a[nxt];
                }
                b.push_back(cnt);
            }
        }
        ll ans = 1;
        vector<ll> c;
        for (auto it : b)
        {
            if (it % 2 == 0)
            {
                ans = (ans * (it * it / 4) % mod) % mod;
            }
            else
            {
                c.push_back(it);
            }
        }
        for (auto it : c)
        {
            ans = (ans * ksm(it, c.size() - 1)) % mod;
        }
        cout << ans % mod << '\n';
    }
    return 0;
}