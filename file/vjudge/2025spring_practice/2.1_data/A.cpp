#include <iostream>
using namespace std;

const int N = 100010;
const int M = 1000001;

int e[N], ne[N];
int pos[M];
int idx = 2;
int head = 1;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    e[1] = 1;
    ne[1] = 0;
    pos[1] = 1;

    while (q--)
    {
        int op, x, y;
        cin >> op;
        if (op == 1)
        {
            cin >> x >> y;
            int pos_x = pos[x];
            e[idx] = y;
            ne[idx] = ne[pos_x];
            ne[pos_x] = idx;
            pos[y] = idx;
            idx++;
        }
        else if (op == 2)
        {

            cin >> x;
            int pos_x = pos[x];
            int nxt = ne[pos_x];
            if (nxt == 0)
                cout << 0 << "\n";
            else
                cout << e[nxt] << "\n";
        }
        else if (op == 3)
        {

            cin >> x;
            int pos_x = pos[x];
            int nxt = ne[pos_x];
            if (nxt != 0)
            {
                ne[pos_x] = ne[nxt];
                pos[e[nxt]] = 0;
            }
        }
    }

    return 0;
}
