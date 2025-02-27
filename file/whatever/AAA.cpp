cin >> n >> m;
ll x, y;
vector ve(n + 10, vector<ll>());
for (int i = 1; i <= m; i++)
{
    cin >> x >> y;
    x--;
    y--;
    if (x != y)
    {
        ve[x].push_back(y);
    }
}
for (auto it : ve)
{
    sort(it.begin(), it.end());
}
mint ans(1);
auto dfs = [&](this auto &&self, ll l, ll r) -> void
{
    if (l == r)
    {
        return;
    }
    ll p = l;
    ll cnt = 0;
    while (p < r)
    {
        while (!ve[p].empty() && ve[p].back() > r)
        {
            ve[p].pop_back();
        }
        if (ve[p].empty())
        {
            p++;
            cnt++;
        }
        else
        {
            ll to = ve[p].back();
            ve[p].pop_back();
            self(p, to);
            p = to;
        }
    }
    ans = ans * cat[cnt];
};
dfs(0, n - 1);
cout << ans.x << '\n';