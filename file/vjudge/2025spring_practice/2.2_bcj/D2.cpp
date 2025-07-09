#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int mod = 1e9 + 3;
#define ll long long
#define PII pair<ll, ll>
int n, p[N], s[N * 3];
struct shu
{
    int x, y, e;
} zu[N];
bool cmp(shu x, shu y)
{
    return x.e > y.e;
}
int find(int x)
{
    if (x != p[x])
        p[x] = find(p[x]);
    return p[x];
}
void solve()
{
    cin >> n;
    int idx = -1;
    for (int i = 0; i < n; i++)
    {
        int x, y, e;
        cin >> zu[i].x >> zu[i].y >> zu[i].e;
        s[++idx] = zu[i].x, s[++idx] = zu[i].y;
    }
    sort(zu, zu + n, cmp);
    sort(s, s + idx);
    int len = unique(s, s + idx) - s;
    for (int i = 0; i < n; i++)
    {
        zu[i].x = lower_bound(s, s + len, zu[i].x) - s;
        zu[i].y = lower_bound(s, s + len, zu[i].y) - s;
    }
    for (int i = 0; i < len; i++)
        p[i] = i;
    for (int i = 0; i < n; i++)
    {
        if (zu[i].e == 1)
            p[find(zu[i].x)] = find(zu[i].y);
        else if (find(zu[i].x) == find(zu[i].y))
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}