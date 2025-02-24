#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 500005;
ll ask(ll x)
{
    cout << "query " << x << endl;
    cin >> x;
    return x;
}
ll ksm(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
        {
            res *= a;
        }
        a *= a;
        b >>= 1;
    }
    return res;
}
void slove()
{
    ll tag = ask(0);
    ll ans[100];
    ll n = 18;
    for (int i = 1; i <= n; i++)
    {
        ll l = 0, r = 9;
        while (l < r)
        {
            int mid = (l + r + 1) >> 1;
            if (ask(mid * ksm(10, i - 1)) == tag + mid)
            {
                l = mid;
            }
            else
            {
                r = mid - 1;
            }
        }
        ans[i] = 9 - l;
        // cout << "@#@#@#" << ans[i] << endl;
    }
    bool flag = 0;
    cout << "answer ";
    ll s = 0;
    for (int i = n; i >= 1; i--)
    {
        if (flag)
        {
            s = s * 10 + ans[i];
        }
        else
        {
            if (ans[i] == 0)
            {
                continue;
            }
            else
            {
                s = ans[i];
                flag = 1;
            }
        }
    }
    if (flag == 0)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << s << endl;
    }
}
int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    ll _ = 1;
    // cin>>_;
    while (_--)
    {
        slove();
    }
}