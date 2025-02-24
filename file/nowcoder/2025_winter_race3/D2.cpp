#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

// 计算一个单词的最少按键数
int getMinKeyPresses(const string &word, const string &prevWord)
{
    int commonPrefixLength = 0;
    while (commonPrefixLength < word.size() && commonPrefixLength < prevWord.size() && word[commonPrefixLength] == prevWord[commonPrefixLength])
    {
        commonPrefixLength++;
    }
    return word.size() - commonPrefixLength; // 输入当前单词需要按键数
}

// 线段树实现
class SegmentTree
{
public:
    vector<int> tree;
    int n;

    SegmentTree(int size)
    {
        n = size;
        tree.resize(4 * size, INT_MAX);
    }

    // 更新操作
    void update(int idx, int value, int l = 0, int r = -1, int pos = 1)
    {
        if (r == -1)
            r = n - 1; // 初始化时，r 是整个数组的范围

        if (l == r)
        {
            tree[pos] = value;
            return;
        }

        int mid = (l + r) / 2;
        if (idx <= mid)
        {
            update(idx, value, l, mid, 2 * pos);
        }
        else
        {
            update(idx, value, mid + 1, r, 2 * pos + 1);
        }

        // 更新当前节点
        tree[pos] = min(tree[2 * pos], tree[2 * pos + 1]);
    }

    // 区间查询
    int query(int L, int R, int l = 0, int r = -1, int pos = 1)
    {
        if (r == -1)
            r = n - 1;

        if (R < l || r < L)
            return INT_MAX; // 不在区间内

        if (L <= l && r <= R)
            return tree[pos]; // 完全在区间内

        int mid = (l + r) / 2;
        int leftQuery = query(L, R, l, mid, 2 * pos);
        int rightQuery = query(L, R, mid + 1, r, 2 * pos + 1);

        return min(leftQuery, rightQuery);
    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    vector<string> words(n);
    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
    }

    // 计算每个单词的最少按键数，并保存
    vector<int> minKeyPresses(n);
    minKeyPresses[0] = words[0].size(); // 第一个单词直接按下它的所有字符

    for (int i = 1; i < n; i++)
    {
        minKeyPresses[i] = getMinKeyPresses(words[i], words[i - 1]);
    }

    // 初始化线段树
    SegmentTree segTree(n);

    // 将所有单词的按键数插入线段树
    for (int i = 0; i < n; i++)
    {
        segTree.update(i, minKeyPresses[i]);
    }

    // 处理查询
    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--; // 转为 0-based 索引
        cout << segTree.query(l, r) << endl;
    }

    return 0;
}
