#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
bool cmp(ll s1, ll s2)
{
    return s1 > s2;
}
bool cmp2(ll s1, ll s2)
{
    return llabs(s1) < llabs(s2);
}
void slove()
{
    ll k, n, m;
    cin >> k >> n >> m;
    vector<ll> az, af, bz, bf;
    ll suma = 0, sumb = 0;
    ll sumaz = 0, sumaf = 0, sumbz = 0, sumbf = 0;
    ll x;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        if (x == 0)
        {
            suma++;
        }
        else if (x > 0)
        {
            az.push_back(x);
            sumaz++;
        }
        else
        {
            sumaf++;
            af.push_back(x);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> x;
        if (x == 0)
        {
            sumb++;
        }
        else if (x > 0)
        {
            sumbz++;
            bz.push_back(x);
        }
        else
        {
            sumbf++;
            bf.push_back(x);
        }
    }

    sort(az.begin(), az.end(), cmp);
    sort(bz.begin(), bz.end(), cmp);
    ll p1 = 0, p2 = 0;
    vector<ll> ve;
    while (p1 < az.size() && p2 < bz.size())
    {
        ve.push_back(az[p1] * bz[p2]);
        p1++, p2++;
    }
    sort(af.begin(), af.end());
    sort(bf.begin(), bf.end());
    ll p3 = 0, p4 = 0;
    while (p3 < af.size() && p4 < bf.size())
    {
        ve.push_back(af[p3] * bf[p4]);
        p3++, p4++;
    }
    vector<ll> v1, v2;
    while (p1 < az.size())
    {
        v1.push_back(az[p1]);
        p1++;
    }
    while (p3 < af.size())
    {
        v1.push_back(af[p3]);
        p3++;
    }
    while (p2 < bz.size())
    {
        v2.push_back(bz[p2]);
        p2++;
    }
    while (p4 < bf.size())
    {
        v2.push_back(bf[p4]);
        p4++;
    }
    p1 = 0, p2 = 0;
    sort(v1.begin(), v1.end(), cmp2);
    sort(v2.begin(), v2.end(), cmp2);
    ll s1 = min((ll)v1.size(), sumb), s2 = min((ll)v2.size(), suma);
    while (s1)
    {
        ve.push_back(0);
        s1--;
    }
    while (s2)
    {
        ve.push_back(0);
        s2--;
    }
    ll res = max((k - (ll)ve.size()), 0ll);
    ll en = min(v1.size() - s1, v2.size() - s2);
    ll w = min(en, res);
    for (int i = 0; i < w; i++)
    {
        ve.push_back(v1[i] * v2[w - i - 1]);
    }
    if (k == 194034)
    {
        // cerr << suma << ' ' << sumaz << ' ' << sumaf << ' ' << sumb << ' ' << sumbz << ' ' << sumbf << '\n';
    }
    while (ve.size() < k)
    {
        ve.push_back(0);
    }
    ll ans = 0;
    sort(ve.begin(), ve.end(), cmp);
    for (int i = 0; i < k; i++)
    {
        ans += ve[i];
    }
    cout << ans << '\n';
    // for (auto it : ve)
    // {
    //     cout << it << ' ';
    // }
    // cout << '\n';
}
signed main()
{
    ll _ = 1;
    // cin>>_;
    while (_--)
    {
        slove();
    }
    return 0;
}

// 110  6
// 101  5
// 循环4次 再操作一次
// pop 1 goto 2 push 1

// 只push首位置
// 维护一个最后的位置
// 二分找第一个大于等于it的位置
//