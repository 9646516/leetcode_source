// id:373956112
// runtime:48 ms
// memory:38.4 MB
// title:二叉搜索树中两个节点之和
// translatedTitle:二叉搜索树中两个节点之和
// questionId:1000319
// time:2022-10-17 21:19:47

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