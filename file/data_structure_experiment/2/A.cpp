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
struct node
{
    ll data;
    struct node *next;
};
node *init()
{
    node *head = (node *)malloc(sizeof(node));
    if (head == NULL)
    {
        cout << "内存不足，分配失败" << endl;
        return NULL;
    }
    head->next = NULL;
    return head;
}
bool adddata(node *head, ll val)
{
    node *newnode = (node *)malloc(sizeof(node));
    if (newnode == NULL)
    {
        cout << "内存不足，分配失败" << endl;
        return 0;
    }
    node *p = head;
    while (!(p->next == NULL))
    {
        p = p->next;
    }
    newnode->data = val;
    newnode->next = NULL;
    p->next = newnode;
    return 1;
}
void printlist(node *head)
{
    cout << "链表输出：" << endl;
    node *p = head->next;
    while (!(p == NULL))
    {
        cout << p->data << ' ';
        p = p->next;
    }
    cout << "输出结束" << endl;
}
void sortlist(node *head)
{
    node *p = head->next;
    node *pr = head;
    node *p1 = head->next;
    while (!(p1->next == NULL))
    {
        p = p1;
        while (!(p->next == NULL))
        {
            if (p->data % 2 == 1 && p->next->data % 2 == 0)
            {
                swap(p->data, p->next->data);
            }
            p = p->next;
        }
        p1 = p1->next;
    }
}
void reverselist(node *head, ll left, ll right)
{
    node *pl, *pr;
    node *p = head;
    ll len = 0;
    while (p->next != NULL)
    {
        len++;
        p = p->next;
    }
    if (!((1 <= left && left <= len) && (1 <= right && right <= len)))
    {
        cout << "你输入的范围不合法" << endl;
        return;
    }
    ll s = 0;
    pl = head;
    while (s != left)
    {
        s++;
        pl = pl->next;
    }
    for (int i = 0; i < (right - left + 1) / 2; i++)
    {
        pr = head;
        s = 0;
        while (s != right - i)
        {
            s++;
            pr = pr->next;
        }
        swap(pl->data, pr->data);
        pl = pl->next;
    }
}
void solve()
{
    node *head = init();
    if (head == NULL)
    {
        return;
    }
    cout << "请输入数据" << endl;
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i += 2)
    {
        ll val;
        if (i == s.length() - 1)
            val = s[i] - '0';
        else
            val = (s[i] - '0') * 10 + s[i + 1] - '0';
        bool flag = adddata(head, val);
        if (!flag)
            return;
    }
    printlist(head);
    sortlist(head);
    printlist(head);
    cout << "请输入倒置的区间" << endl;
    ll l, r;
    cin >> l >> r;
    reverselist(head, l, r);
    printlist(head);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll _ = 1;
    // cin>>_;
    while (_--)
    {
        solve();
    }
    return 0;
}
