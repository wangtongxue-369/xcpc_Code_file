#include <queue>
#include <vector>
#include <iostream>

struct Node
{
    int h, a, i;
};

// 自定义比较函数
struct Compare
{
    bool operator()(const Node &lhs, const Node &rhs) const
    {
        if (lhs.h != rhs.h)
            return lhs.h > rhs.h; // h 降序
        if (lhs.a != rhs.a)
            return lhs.a > rhs.a; // a 降序
        return lhs.i > rhs.i;     // i 降序
    }
};

int main()
{
    std::priority_queue<Node, std::vector<Node>, Compare> q;
    return 0;
}