#include <bits/stdc++.h>
namespace Fread
{
    const int SIZE = (1 << 18);
    char buf[SIZE], *p1 = buf, *p2 = buf;
    inline char getchar() { return (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, SIZE, stdin), p1 == p2) ? EOF : *p1++); }
}
namespace Fwrite
{
    const int SIZE = (1 << 18);
    char buf[SIZE], *S = buf, *T = buf + SIZE;
    inline void flush() { fwrite(buf, 1, S - buf, stdout), S = buf; }
    struct NTR
    {
        ~NTR() { flush(); }
    } ztr;
    inline void putchar(char c)
    {
        *S++ = c;
        if (S == T)
            flush();
    }
}
namespace Fastio
{
    struct Reader
    {
        template <typename T>
        Reader &operator>>(T &x)
        {
            char c = Fread::getchar();
            bool f = false;
            while (c < '0' or c > '9')
            {
                if (c == '-')
                    f = true;
                c = Fread::getchar();
            }
            x = 0;
            while (c >= '0' and c <= '9')
            {
                x = (x << 1) + (x << 3) + (c ^ 48);
                c = Fread::getchar();
            }
            if (f)
                x = -x;
            return *this;
        }
        Reader &operator>>(char &c)
        {
            c = Fread::getchar();
            while (c == '\n' || c == ' ' || c == '\r')
                c = Fread::getchar();
            return *this;
        }
        Reader &operator>>(char *str)
        {
            int len = 0;
            char c = Fread::getchar();
            while (c == '\n' || c == ' ' || c == '\r')
                c = Fread::getchar();
            while (c != '\n' && c != ' ' && c != '\r')
                str[len++] = c, c = Fread::getchar();
            str[len] = '\0';
            return *this;
        }
        Reader() {}
    } cin;
    struct Writer
    {
        template <typename T>
        Writer &operator<<(T x)
        {
            if (x == 0)
                return Fwrite::putchar('0'), *this;
            if (x < 0)
                Fwrite::putchar('-'), x = -x;
            static int sta[45], top = 0;
            while (x)
                sta[++top] = x % 10, x /= 10;
            while (top)
                Fwrite::putchar(sta[top] + '0'), --top;
            return *this;
        }
        Writer &operator<<(char c)
        {
            Fwrite::putchar(c);
            return *this;
        }
        Writer &operator<<(const char *str)
        {
            int cur = 0;
            while (str[cur])
                Fwrite::putchar(str[cur++]);
            return *this;
        }
        Writer() {}
    } cout;
}
#define cin Fastio ::cin
#define cout Fastio ::cout
using namespace std;
const int maxn = 1e6 + 10;
typedef pair<int, int> pii;
bool vis[maxn];
vector<pii> v;
int n, w, h;
inline int cal(int x, int y)
{
    if (x == 0)
        return y;
    if (y == h)
        return h + x;
    if (x == w)
        return 2 * h + w - y;
    return 2 * (h + w) - x;
}

inline void get(double t, double &x, double &y)
{
    if (t <= h)
        x = 0, y = t;
    else if (t <= h + w)
        x = t - h, y = h;
    else if (t <= 2 * h + w)
        x = w, y = 2 * h + w - t;
    else
        x = 2 * (h + w) - t, y = 0;
}

int main()
{
    cin >> n >> w >> h;
    for (int i = 0; i < n; ++i)
    {
        int X1, Y1, X2, Y2;
        cin >> X1 >> Y1 >> X2 >> Y2;
        v.push_back(pii(cal(X1, Y1), i));
        v.push_back(pii(cal(X2, Y2), i));
    }
    sort(v.begin(), v.end());
    int sz = int(v.size()), p = 0, cnt = 0, one = 0;
    for (int i = 0; i < sz; ++i)
    {
        if (p == i)
            vis[v[i].second] = true, ++p, ++cnt;
        while (!vis[v[p].second])
            vis[v[p].second] = true, p = (p + 1) % sz, ++cnt;
        if (cnt == n)
        {
            double ax1, ay1, ax2, ay2;
            get(v[i].first - 0.5, ax1, ay1);
            get(v[p].first - 0.5, ax2, ay2);
            printf("1\n%.8f %.8f %.8f %.8f\n", ax1, ay1, ax2, ay2);
            one = 1;
            break;
        }
        vis[v[i].second] = false, --cnt;
    }
    if (!one)
        printf("2\n0.5 0 %.8f %.8f\n0 %.8f %.8f %.8f\n", w - 0.5, 1.0 * h, h - 0.5, 1.0 * w, 0.5);
    return 0;
}