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
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef char StackData;
typedef struct
{
    StackData *base;
    StackData *top;
    int stacksize;
} SeqStack;
bool StackEmpty(SeqStack *S)
{
    if (S->top == S->base)
        return 1;
    else
        return 0;
}
bool StackFull(SeqStack *S)
{
    if (S->top - S->base >= S->stacksize)
        return 1;
    else
        return 0;
}
bool InitStack(SeqStack *S)
{
    S->base = (StackData *)malloc(STACK_INIT_SIZE * sizeof(StackData));
    if (!S->base)
        return 0;
    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE;
    return 1;
}
bool Push(SeqStack *S, StackData x)
{
    if (StackFull(S))
    {
        S->base = (StackData *)realloc(S->base, (S->stacksize + STACKINCREMENT) * sizeof(StackData));
        if (!S->base)
            return 0;
        S->top = S->base + S->stacksize;
        S->stacksize += STACKINCREMENT;
    }
    *(S->top) = x;
    (S->top)++;
    return 1;
}
char Gettop(SeqStack *S)
{
    if (StackEmpty(S))
        return 0;
    char x;
    return x = *(S->top - 1);
}
char pop(SeqStack *S)
{
    if (StackEmpty(S))
        return 0;
    --(S->top);
    char x;
    return x = x = *(S->top);
}
bool isletter(char c)
{
    return (c >= 'A' && c <= 'Z');
}
bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}
ll precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}
void solve()
{
    cout << "请输入中缀表达式" << endl;
    string s, ans;
    cin >> s;
    SeqStack *st;
    InitStack(st);
    // if (!InitStack(st))
    // {
    //     cout << "创建失败" << endl;
    //     return;
    // }
    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        if (isletter(c))
        {
            ans += c;
        }
        else if (c == '(')
        {
            Push(st, c);
        }
        else if (c == ')')
        {
            while (!StackEmpty(st) && Gettop(st) != '(')
            {
                ans += pop(st);
            }
            pop(st);
        }
        else if (isOperator(c))
        {
            while (!StackEmpty(st) && precedence(Gettop(st)) >= precedence(c))
            {
                ans += pop(st);
            }
            Push(st, c);
        }
        else if (c == '#')
        {
            break;
        }
    }
    cout << "后缀表达式为" << endl;
    while (!StackEmpty(st))
    {
        ans += pop(st);
    }
    cout << ans << endl;
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