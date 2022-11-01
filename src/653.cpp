// id:373956794
// runtime:44 ms
// memory:38.6 MB
// title:Two Sum IV - Input is a BST
// translatedTitle:两数之和 IV - 输入二叉搜索树
// questionId:653
// time:2022-10-17 21:21:18

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
    unordered_map<int,int>mp;
    void dfs(TreeNode*x){
        mp[x->val]++;
        if(x->left)dfs(x->left);
        if(x->right)dfs(x->right);
    }
    bool findTarget(TreeNode* root, int k) {
        dfs(root);
        for(auto [a,b]:mp){
            if(a+a==k){
                if(b>1)return 1;
            }else{
                if(mp.count(k-a)){
                    return 1;
                }
            }
        }
        return 0;
    }
};