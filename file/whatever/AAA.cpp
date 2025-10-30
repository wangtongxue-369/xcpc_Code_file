/*
 /$$      /$$ /$$$$$$$$ /$$   /$$        /$$$$$$   /$$$$$$   /$$$$$$
| $$  /$ | $$|__  $__/| $$  / $$       /$__  $$ /$__  $$ /$__  $$
| $$ /$$$| $$   | $$   |  $$/ $$/      |__/  \ $$| $$  \__/| $$  \ $$
| $$/$$ $$ $$   | $$    \  $$$$/          /$$$$$/| $$$$$$$ |  $$$$$$$
| $$$_  $$$$    | $$     >$$  $$         |___  $$| $__  $$ \____  $$
| $$$/ \  $$$   | $$    /$$/\  $$       /$$  \ $$| $$  \ $$ /$$  \ $$
| $$/   \  $$   | $$   | $$  \ $$      |  $$$$$$/|  $$$$$$/|  $$$$$$/
|__/     \__/   |__/   |__/  |__//$$$$$$\______/  \______/  \______/
                                |______/
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 2000005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
void solve()
{
    cin >> n;
    string s;
    cin >> s;
    s = '1' + s + '1';
    ll st = n, tr = 1;
    vector<array<ll, 3>> ve(n + 10, {0, 0, 0});
    // CWP
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == 'C')
            ve[i][0]++;
        else if (s[i] == 'W')
            ve[i][1]++;
        else if (s[i] == 'P')
            ve[i][2]++;
        ve[i][0] += ve[i - 1][0], ve[i][1] += ve[i - 1][1], ve[i][2] += ve[i - 1][2];
    }
    for (ll i = 1; i < n; i++)
    {
        if (s[i] == s[i + 1])
        {
            st = min(st, i);
        }
        if (s[i] == s[i + 1])
        {
            tr = max(tr, i + 1);
        }
    }
    if (st == n && tr == 1)
    {
        cout << "Beautiful\n";
        return;
    }
    PII ans = {1, n};
    function<bool(ll l, ll r)> check = [&](ll l, ll r)
    {
        ll sc = ve[r][0] - ve[l - 1][0], sw = ve[r][1] - ve[l - 1][1], sp = ve[r][2] - ve[l - 1][2];
        ll maxc = max({sc, sw, sp});
        ll len = r - l + 1;
        bool flag = 0;
        if (len % 2 == 0)
        {
            char tmp = s[l];
            if ('C' != s[l - 1] && sc)
            {
                s[l] = 'C';
                sc--, len--, l++;
                maxc = max({sc, sw, sp});
                if (maxc == (len + 1) / 2)
                {
                    if (sc == maxc && (s[l - 1] != 'C' && s[r + 1] != 'C'))
                    {
                        flag = 1;
                    }
                    else if (sw == maxc && s[l - 1] != 'W' && s[r + 1] != 'W')
                    {
                        flag = 1;
                    }
                    else if (sp == maxc && s[l - 1] != 'P' && s[r + 1] != 'P')
                    {
                        flag = 1;
                    }
                }
                else if (maxc < (len + 1) / 2)
                {
                    flag = 1;
                }
                sc++, len++, l--;
            }
            if ('W' != s[l - 1] && sw)
            {
                s[l] = 'W';
                sw--, len--, l++;
                maxc = max({sc, sw, sp});
                if (maxc == (len + 1) / 2)
                {
                    if (sc == maxc && (s[l - 1] != 'C' && s[r + 1] != 'C'))
                    {
                        flag = 1;
                    }
                    else if (sw == maxc && s[l - 1] != 'W' && s[r + 1] != 'W')
                    {
                        flag = 1;
                    }
                    else if (sp == maxc && s[l - 1] != 'P' && s[r + 1] != 'P')
                    {
                        flag = 1;
                    }
                }
                else if (maxc < (len + 1) / 2)
                {
                    flag = 1;
                }
                sw++, len++, l--;
            }
            if ('P' != s[l - 1] && sp)
            {
                s[l] = 'P';
                sp--, len--, l++;
                maxc = max({sc, sw, sp});
                if (maxc == (len + 1) / 2)
                {
                    if (sc == maxc && (s[l - 1] != 'C' && s[r + 1] != 'C'))
                    {
                        flag = 1;
                    }
                    else if (sw == maxc && s[l - 1] != 'W' && s[r + 1] != 'W')
                    {
                        flag = 1;
                    }
                    else if (sp == maxc && s[l - 1] != 'P' && s[r + 1] != 'P')
                    {
                        flag = 1;
                    }
                }
                else if (maxc < (len + 1) / 2)
                {
                    flag = 1;
                }
                sp++, len++, l--;
            }
            s[l] = tmp;
        }
        if (len % 2 == 1)
        {
            if (maxc == (len + 1) / 2)
            {
                if (sc == maxc && (s[l - 1] != 'C' && s[r + 1] != 'C'))
                {
                    flag = 1;
                }
                else if (sw == maxc && s[l - 1] != 'W' && s[r + 1] != 'W')
                {
                    flag = 1;
                }
                else if (sp == maxc && s[l - 1] != 'P' && s[r + 1] != 'P')
                {
                    flag = 1;
                }
            }
            else if (maxc < (len + 1) / 2)
            {

                flag = 1;
            }
        }
        return flag;
    };
    if (check(1, n) == 0)
    {
        cout << "Impossible\n";
        return;
    }
    for (int i = 1; i <= st + 1; i++)
    {
        ll l = max((ll)i, tr - 1), r = n;
        while (l < r)
        {
            ll mid = (l + r) >> 1;
            // cerr << i << ' ' << mid << '\n';
            if (check(i, mid))
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        if (check(i, l) == 0)
        {
            continue;
        }
        // cout << i << ' ' << l << '\n';
        if (ans.second - ans.first + 1 > l - i + 1)
        {
            ans = {i, l};
        }
    }
    if (!check(ans.first, ans.second))
    {
        cout << "Impossible\n";
        return;
    }
    cout << "Possible\n";

    cout << ans.first << ' ' << ans.second << '\n';

    ll l = ans.first, r = ans.second;
    ll len = r - l + 1;
    ll sc = ve[r][0] - ve[l - 1][0], sw = ve[r][1] - ve[l - 1][1], sp = ve[r][2] - ve[l - 1][2];
    for (int i = l; i <= r; i++)
    {
        vector<pair<ll, char>> c;
        c.push_back({sc, 'C'});
        c.push_back({sw, 'W'});
        c.push_back({sp, 'P'});
        sort(c.begin(), c.end(), greater<PII>());
        for (auto [cnt, ch] : c)
        {
            if (cnt == 0)
            {
                continue;
            }
            if (s[i - 1] == ch)
            {
                continue;
            }
            s[i] = ch;
            if (ch == 'C')
            {
                sc--;
            }
            else if (ch == 'W')
            {
                sw--;
            }
            else
            {
                sp--;
            }
            break;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << s[i];
    }
    cout << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}