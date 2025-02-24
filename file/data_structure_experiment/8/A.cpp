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

void heapchange(int i)
{
    int smallest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && a[left] < a[smallest])
    {
        smallest = left;
    }

    if (right <= n && a[right] < a[smallest])
    {
        smallest = right;
    }

    if (smallest != i)
    {
        swap(a[i], a[smallest]);
        heapchange(smallest);
    }
}

void heapSort()
{
    for (int i = n / 2; i >= 1; i--)
    {
        heapchange(i);
    }
    for (int i = n; i >= 2; i--)
    {
        swap(a[1], a[i]);
        heapchange(1);
    }
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        a[i] = rand() % 101;
    }
    // 插入排序
    for (int i = 2; i <= n; i++)
    {
        int key = a[i];
        int j = i - 1;
        while (j >= 1 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
    for (int i = 1; i <= n; i++)
    {
        a[i] = rand() % 101;
    }
    // 简单选择排序
    for (int i = 1; i < n; i++)
    {
        int key = i;
        for (int j = i + 1; j <= n; j++)
        {
            if (a[j] < a[key])
            {
                key = j;
            }
        }
        swap(a[i], a[key]);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    // 堆排序
    for (int i = 1; i <= n; i++)
    {
        a[i] = rand() % 101;
    }
    heapSort();
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cin>>_;
    srand(time(0));
    while (_--)
    {
        solve();
    }
    return 0;
}
