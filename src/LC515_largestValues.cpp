/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        deque<TreeNode*>q;
        vector<int>ans;
        if (root == nullptr) return ans;
        q.push_back(root);
        while (!q.empty()){
            int sz = q.size();//当前层的循环次数
            int maxNum = INT_MIN;

            for (int i = 0; i < sz; i++){
                TreeNode *node = q.front();//每次node都要获取元素
                q.pop_front();//每便利一个元素就要出队
                if (node->left) q.push_back(node->left);
                if (node->right) q.push_back(node->right);
                maxNum = max(maxNum, node->val);
            }
            ans.push_back(maxNum);
        }
        return ans;
    }
};