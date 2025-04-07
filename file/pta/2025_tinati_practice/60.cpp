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
struct Person
{
    int id;
    int income = 0;
    int count = 0;
};

bool cmp(const Person &a, const Person &b)
{
    if (a.income != b.income)
        return a.income > b.income;
    if (a.count != b.count)
        return a.count > b.count;
    return a.id < b.id;
}
void solve()
{
    int N;
    cin >> N;
    vector<Person> people(N + 1);
    for (int i = 1; i <= N; ++i)
    {
        people[i].id = i;
    }

    for (int i = 1; i <= N; ++i)
    {
        int K;
        cin >> K;
        for (int j = 0; j < K; ++j)
        {
            int N_j, P_j;
            cin >> N_j >> P_j;
            people[N_j].income += P_j;
            people[N_j].count++;
            people[i].income -= P_j;
        }
    }
    sort(people.begin() + 1, people.end(), cmp);
    for (int i = 1; i <= N; ++i)
    {
        printf("%d %.2f\n", people[i].id, people[i].income / 100.0);
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