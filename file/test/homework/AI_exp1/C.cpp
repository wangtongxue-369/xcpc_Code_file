#include <bits/stdc++.h>
#define ll long long

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

// 打印
void print_state(const std::array<int, 9> &a)
{
    for (int i = 0; i < 9; i++)
    {
        if (i % 3 == 0)
            std::cout << "\n";
        std::cout << a[i] << ' ';
    }
    std::cout << "\n";
}

// 曼哈顿 估价函数 h
int mhd(const std::array<int, 9> &a, const std::array<int, 9> &goal)
{
    int h = 0;
    for (int i = 0; i < 9; i++)
    {
        if (a[i] == 0)
            continue;
        for (int j = 0; j < 9; j++)
        {
            if (goal[j] == a[i])
            {
                h += abs(i / 3 - j / 3) + abs(i % 3 - j % 3);
                break;
            }
        }
    }
    return h;
}

struct Node
{
    std::array<int, 9> state;
    int g, h; // g是实际代价, h是估价
    bool operator<(Node const &other) const
    {
        return g + h > other.g + other.h; // 小根堆
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::array<int, 9> start, goal;

    std::cout << "输入初始状态(9个数字, 0表示空格):\n";
    for (int i = 0; i < 9; i++)
        std::cin >> start[i];

    std::cout << "输入目标状态:\n";
    for (int i = 0; i < 9; i++)
        std::cin >> goal[i];

    // A* priority queue
    std::priority_queue<Node> pq;

    // visited[state] = pa_state
    std::map<std::array<int, 9>, std::array<int, 9>> pa;
    pa[start] = start;

    pq.push({start, 0, mhd(start, goal)});

    bool solved = false;

    while (!pq.empty())
    {
        Node cur = pq.top();
        pq.pop();

        if (cur.state == goal)
        {
            solved = true;
            break;
        }

        int z = -1;
        for (int i = 0; i < 9; i++)
            if (cur.state[i] == 0)
                z = i;

        int x = z / 3, y = z % 3;

        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx < 0 || nx >= 3 || ny < 0 || ny >= 3)
                continue;

            int nz = nx * 3 + ny;
            std::array<int, 9> nxt = cur.state;
            std::swap(nxt[z], nxt[nz]);

            if (!pa.count(nxt))
            {
                pa[nxt] = cur.state;
                int g = cur.g + 1;
                int h = mhd(nxt, goal);
                pq.push({nxt, g, h});
            }
        }
    }

    if (!solved)
    {
        std::cout << "无解！\n";
        return 0;
    }

    std::vector<std::array<int, 9>> path;
    std::array<int, 9> cur = goal;

    while (true)
    {
        path.push_back(cur);
        if (cur == pa[cur])
            break;
        cur = pa[cur];
    }

    std::reverse(path.begin(), path.end());

    std::cout << "\n找到解，步数 = " << path.size() - 1 << "\n";
    std::cout << "移动过程如下：\n";

    for (int i = 0; i < path.size(); i++)
    {
        std::cout << "Step " << i << " :";
        print_state(path[i]);
        std::cout << "--------------\n";
    }

    return 0;
}
