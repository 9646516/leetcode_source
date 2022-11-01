// id:373920082
// runtime:12 ms
// memory:21.7 MB
// title:二叉树每层的最大值
// translatedTitle:二叉树每层的最大值
// questionId:1000297
// time:2022-10-17 19:55:11

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
        if(!root)return {};
        queue<TreeNode*>q1,q2;
        vector<int>ret;
        q1.push(root);
        while(!q1.empty()){
            int mx=-2147483648;
            while(!q1.empty()){
                auto now=q1.front();
                mx=max(mx,now->val);
                q1.pop();
                if(now->left)q2.push(now->left);
                if(now->right)q2.push(now->right);
            }
            swap(q1,q2);
            ret.push_back(mx);
        }
        return ret;
    }
};