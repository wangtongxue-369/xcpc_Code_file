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
ll _ = 1, n, m, ans = 0, f[MAXN];
struct node
{
    int id;
    int sr = 0;
    int count = 0;
};

bool cmp(const node &a, const node &b)
{
    if (a.sr != b.sr)
        return a.sr > b.sr;
    if (a.count != b.count)
        return a.count > b.count;
    return a.id < b.id;
}
void solve()
{
    int N;
    cin >> N;
    vector<node> a(N + 1);
    for (int i = 1; i <= N; ++i)
    {
        a[i].id = i;
    }

    for (int i = 1; i <= N; ++i)
    {
        int K;
        cin >> K;
        for (int j = 0; j < K; ++j)
        {
            int nj, pj;
            cin >> nj >> pj;
            a[nj].sr += pj;
            a[nj].count++;
            a[i].sr -= pj;
        }
    }
    sort(a.begin() + 1, a.end(), cmp);
    for (int i = 1; i <= N; ++i)
    {
        printf("%d %.2f\n", a[i].id, a[i].sr / 100.0);
    }
}

int main()
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