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
struct Book
{
    char key = 'N';
    int hh = 0;
    int mm = 0;
} book[1005];
int calculate(int h1, int m1, int h2, int m2)
{
    return h2 * 60 + m2 - h1 * 60 - m1;
}
void solve()
{

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        int count = 0;

        while (true)
        {
            int id;
            char key, punctuation;
            int h, m;
            cin >> id >> key >> h >> punctuation >> m;
            if (id == 0)
                break;

            if (key == 'E')
            {
                if (book[id].key == 'E' || book[id].key == 'N')
                    continue;
            }

            if (key == 'E' && book[id].key == 'S')
            {

                count++;
                int time = calculate(book[id].hh, book[id].mm, h, m);
                sum += time;
            }

            book[id].key = key;
            book[id].hh = h;
            book[id].mm = m;
        }

        if (count)
        {

            cout << count << " " << (int)(1.0 * sum / count + 0.5) << endl;
        }
        else
        {
            cout << "0 0\n";
        }
    }

    return;
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
