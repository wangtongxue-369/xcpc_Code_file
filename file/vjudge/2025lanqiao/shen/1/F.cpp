#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define inf 0x3f3f3f3f
const ll mod = 1e9 + 7;
ll _ = 1, n, m, ans = 0, f[20][20][20][20], a[20][20];
void slove()
{
    cin >> n;
    ll s1, s2, s3;
    while (cin >> s1 >> s2 >> s3 && s1 != 0)
    {
        a[s1][s2] = s3;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int w = 1; w <= n; w++)
            {
                for (int q = 1; q <= n; q++)
                {
                    f[i][j][w][q] = max(max(f[i - 1][j][w - 1][q], f[i - 1][j][w][q - 1]), max(f[i][j - 1][w][q - 1], f[i][j - 1][w - 1][q])) + a[i][j];
                    if (i != w && j != q)
                    {
                        f[i][j][w][q] += a[w][q];
                    }
                }
            }
        }
    }
    cout << f[n][n][n][n] << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cin>>_;
    while (_--)
    {
        slove();
    }
    return 0;
}