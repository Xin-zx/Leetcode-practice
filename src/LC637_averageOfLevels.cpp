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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>levelAns;
        if (root == nullptr) return levelAns;
        deque<TreeNode*> q;
        q.push_back(root);
        while (!q.empty()){
            int sz = q.size();
            double sum = 0;
            double avg = 0;

            for (int i = 0; i < sz; i++){
            TreeNode *node = q.front();
            q.pop_front();
            sum += node->val;
            if (node->left) q.push_back(node->left);
            if (node->right) q.push_back(node->right);
            }
            avg = sum / sz;
            levelAns.push_back(avg);
        }
        return levelAns;
    }
};