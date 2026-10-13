/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
      vector<vector<int>>Ans;
        if (root == nullptr) return Ans;
        deque<Node*> q;
        q.push_back(root);
        while (!q.empty()){
            int sz = q.size();
            vector<int>levelAns;
            for (int i = 0; i < sz; i++){
            Node *node = q.front();
            q.pop_front();//child是一个数组
            for (auto c : node->children)
            {
                if (c) q.push_back(c);
            }
            levelAns.push_back(node->val);
            }
            Ans.push_back(levelAns);
        }
        return Ans;
    }
};