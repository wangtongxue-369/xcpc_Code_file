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
ll _ = 1, n, ans = 0, rts[MAXN], rmj[MAXN], vis[MAXN];
struct People
{
    int no;
    int dad;
    int mom;
    int kidnum;
    int housenum;
    double housearea;
    int kids[5];
};
People people[10000];
struct Family
{
    int peoplenum = 0;
    double avgnum = 0;
    double avgarea = 0;
    set<int> peoples;
    int minno;
};
Family family[10000];
int visit1[10000];
void init()
{
    for (int i = 0; i < 10000; i++)
        visit1[i] = i;
}
int find(int x)
{
    if (visit1[x] != x)
        visit1[x] = find(visit1[x]);
    return visit1[x];
}
void Union(int a, int b)
{
    int a1 = find(a);
    int b1 = find(b);
    if (a1 != b1)
        visit1[a1] = b1;
}
bool company(Family x1, Family x2)
{
    if (x1.avgarea == x2.avgarea)
    {
        return x1.minno < x2.minno;
    }
    else
        return x1.avgarea > x2.avgarea;
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
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
