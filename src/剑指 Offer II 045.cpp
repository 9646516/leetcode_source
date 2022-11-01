// id:373921119
// runtime:12 ms
// memory:21.3 MB
// title:二叉树最底层最左边的值
// translatedTitle:二叉树最底层最左边的值
// questionId:1000298
// time:2022-10-17 19:57:45

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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*>q1,q2;
        int ret;
        q1.push(root);
        while(!q1.empty()){
            ret=q1.front()->val;
            while(!q1.empty()){
                auto now=q1.front();
                q1.pop();
                if(now->left)q2.push(now->left);
                if(now->right)q2.push(now->right);
            }
            swap(q1,q2);
        }
        return ret;
    }
};