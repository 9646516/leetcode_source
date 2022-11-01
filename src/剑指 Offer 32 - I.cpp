// id:373301661
// runtime:4 ms
// memory:11.6 MB
// title:从上到下打印二叉树 LCOF
// translatedTitle:从上到下打印二叉树
// questionId:100311
// time:2022-10-15 21:00:54

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        if(!root)return {};
        queue<TreeNode*>q;
        q.push(root);
        vector<int>ret;
        while(!q.empty()){
            auto now=q.front();q.pop();
            ret.push_back(now->val);
            if(now->left){
                q.push(now->left);
            }
            if(now->right){
                q.push(now->right);
            }
        }
        return ret;
    }
};