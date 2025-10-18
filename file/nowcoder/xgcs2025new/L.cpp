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
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
struct node
{
    int l, r;
    mutable ll val;
    node(int l_ = -1, int r_ = -1, ll val_ = 0)
    {
        l = l_, r = r_, val = val_;
    }
    bool operator<(const node &a) const
    {
        return l < a.l;
    }
};
typedef set<node>::iterator IT;
set<node> st;
IT split(int pos)
{
    IT it = st.lower_bound(node(pos));
    if (it != st.end() && it->l == pos)
        return it;
    --it;
    node tmp = *it;
    st.erase(it);
    st.insert(node(tmp.l, pos - 1, tmp.val));
    return st.insert(node(pos, tmp.r, tmp.val)).first;
}

void assign(int l, int r, ll val)
{
    IT itr = split(r + 1), itl = split(l);
    st.erase(itl, itr);
    st.insert(node(l, r, val));
}

void add(int l, int r, ll val)
{
    IT itr = split(r + 1), itl = split(l);
    for (IT it = itl; it != itr; ++it)
    {
        it->val += val;
    }
}

ll querySum(int l, int r)
{
    IT itr = split(r + 1), itl = split(l);
    ll res = 0;
    for (IT it = itl; it != itr; ++it)
    {
        res += (it->r - it->l + 1) * it->val;
    }
    return res;
}

ll queryKth(int l, int r, int k)
{
    vector<pair<ll, int>> vec(0);
    IT itr = split(r + 1), itl = split(l);
    for (IT it = itl; it != itr; ++it)
    {
        vec.push_back(make_pair(it->val, it->r - it->l + 1));
    }
    sort(vec.begin(), vec.end());
    for (vector<pair<ll, int>>::iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if ((k -= it->second) <= 0)
            return it->first;
    }
    return -1;
}
void solve()
{
    ll p;
    cin >> n >> p;
    ll op, l, r, v;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    while (p--)
    {
        cin >> op;
        if (op == 1)
        {
            cin >> l >> r >> v;
            for (int i = 1; i <= r - l + 1; i++)
            {
                a[i + l - 1] += i * v;
            }
        }
        else if (op == 2)
        {
            cin >> l >> r >> v;
            for (int i = 1; i <= r - l + 1; i++)
            {
                a[i + l - 1] = i * v;
            }
        }
        else
        {
            ans = 0;
            cin >> l >> r;
            for (int i = max(l, 2ll); i <= min(r, n - 1); i++)
            {
                if (a[i - 1] < a[i] && a[i] > a[i + 1])
                {
                    ans++;
                }
                if (a[i - 1] > a[i] && a[i] < a[i + 1])
                {
                    ans++;
                }
            }
            cout << ans << '\n';
        }
    }
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