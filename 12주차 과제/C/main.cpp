#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int dfs(TreeNode* node, int sum);

TreeNode* buildTree(const vector<int>& nodes) {
    if (nodes.empty() || nodes[0] == 0) return NULL;
    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);
    size_t i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* current = q.front();
        q.pop();
        if (i < nodes.size() && nodes[i] != 0) {
            current->left = new TreeNode(nodes[i]);
            q.push(current->left);
        }
        i++;
        if (i < nodes.size() && nodes[i] != 0) {
            current->right = new TreeNode(nodes[i]);
            q.push(current->right);
        }
        i++;
    }
    return root;
}

int pathSum(TreeNode* root, int sum) {
    if (!root) return 0;
    return dfs(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
}

int dfs(TreeNode* node, int sum) {
    if (!node) return 0;
    sum -= node->val;
    return (sum == 0 ? 1 : 0) + dfs(node->left, sum) + dfs(node->right, sum);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int W, M;
        cin >> W >> M;
        vector<int> nodes(M);
        for (int i = 0; i < M; ++i) {
            cin >> nodes[i];
        }
        TreeNode* root = buildTree(nodes);
        cout << pathSum(root, W) << endl;
    }
    return 0;
}
