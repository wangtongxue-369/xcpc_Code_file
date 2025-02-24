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
typedef struct TreeNode
{
    char data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode *cnode(char data)
{
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void dfs(TreeNode *root, char *result, int *index)
{
    if (root == NULL)
    {
        return;
    }

    result[(*index)++] = root->data;
    dfs(root->left, result, index);
    dfs(root->right, result, index);
}

void solve()
{
    TreeNode *root = cnode('A');
    root->left = cnode('B');
    root->right = cnode('C');
    root->left->left = cnode('D');
    root->left->right = cnode('E');
    root->right->left = cnode('F');
    root->right->right = cnode('G');

    char result[MAXN];
    int index = 0;
    dfs(root, result, &index);
    for (int i = index - 1; i >= 0; i--)
    {
        printf("%c", result[i]);
    }
    printf("\n");
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    // cin>>_;
    while (_--)
    {
        solve();
    }
    return 0;
}
