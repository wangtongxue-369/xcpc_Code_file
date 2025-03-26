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
ll _ = 1, n, ans = 0, a[MAXN], f[MAXN];
bool cmp(PII s1, PII s2)
{
    return s1.second > s2.second;
}
void solve()
{

    string s;
    cin >> s;
    map<ll, ll> ma;
    set<ll> se;
    ll p = 0;
    vector<PII> ve;
    for (auto it : s)
    {
        se.insert(it - '0');
    }
    for (auto it : se)
    {
        ve.push_back({se.size() - p - 1, it});
        ma[it] = se.size() - p - 1;
        p++;
    }
    // if (ma.contains(it - '0') == 0)
    // {
    //     ma[it - '0'] = p;
    //     ve.push_back({p, it - '0'});
    //     p++;
    // }
    cout << "int[] arr = new int[]{";
    sort(ve.begin(), ve.end(), cmp);
    for (int i = 0; i < ve.size(); i++)
    {
        cout << ve[i].second << ",}"[i == ve.size() - 1];
    }
    cout << ";\n";
    cout << "int[] index = new int[]{";
    for (int i = 0; i < s.length(); i++)
    {
        cout << ma[s[i] - '0'] << ",}"[i == s.length() - 1];
    }
    cout << ";";
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
