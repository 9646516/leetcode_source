// id:373921957
// runtime:0 ms
// memory:11.9 MB
// title:二叉树的右侧视图
// translatedTitle:二叉树的右侧视图
// questionId:1000299
// time:2022-10-17 19:59:37

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
    vector<int> rightSideView(TreeNode* root) {
        if(!root)return {};
        queue<TreeNode*>q1,q2;
        vector<int>ret;
        q1.push(root);
        while(!q1.empty()){
            int last;
            while(!q1.empty()){
                auto now=q1.front();
                q1.pop();
                if(q1.empty())last=now->val;
                if(now->left)q2.push(now->left);
                if(now->right)q2.push(now->right);
            }
            swap(q1,q2);
            ret.push_back(last);
        }
        return ret;
    }

};