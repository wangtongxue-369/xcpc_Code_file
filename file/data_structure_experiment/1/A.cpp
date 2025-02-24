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
ll _ = 1; // n, m, ans = 0, a[MAXN], f[MAXN];
typedef int Elemtype;
int SIZE = 20;
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void merge(int a[], int &sizea, int b[], int &sizeb)
{
    for (int i = 0; i < sizeb; i++)
    {
        bool flag = 0;
        for (int j = 0; j < sizea; j++)
        {
            if (b[i] == a[j])
            {
                flag = 1;
                break;
            }
        }
        if (!flag)
        {
            sizea;
            a[sizea] = b[i];
            sizea++;
        }
    }
    for (int i = 0; i < sizea; i++)
    {
        for (int j = i + 1; j < sizea; j++)
        {
            if (a[i] == a[j])
            {
                swap(a[j], a[sizea - 1]);
                sizea--;
            }
        }
    }
    quickSort(a, 0, sizea - 1);
}
void solve()
{
    int a[SIZE], b[SIZE];
    int sizea, sizeb;
    printf("请输入顺序表A大小\n");
    scanf("%d", &sizea);
    printf("请输入顺序表A\n");
    for (int i = 0; i < sizea; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("请输入顺序表B大小\n");
    scanf("%d", &sizeb);
    printf("请输入顺序表B\n");
    for (int i = 0; i < sizeb; i++)
    {
        scanf("%d", &b[i]);
    }
    merge(a, sizea, b, sizeb);
    printf("合并后的顺序表A为:\n");
    for (int i = 0; i < sizea; i++)
    {
        printf("%d ", a[i]);
    }
}
signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    //  cin>>_;
    while (_--)
    {
        solve();
    }
    return 0;
}
