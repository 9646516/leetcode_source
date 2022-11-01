// id:373947595
// runtime:40 ms
// memory:33.1 MB
// title:所有大于等于节点的值之和
// translatedTitle:所有大于等于节点的值之和
// questionId:1000315
// time:2022-10-17 20:58:51

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
    vector<int>V;
    vector<int>P;
    void dfs(TreeNode*x){
        V.push_back(x->val);
        if(x->left)dfs(x->left);
        if(x->right)dfs(x->right);
    }
    void dfs2(TreeNode*x){
        int idx=lower_bound(V.begin(),V.end(),x->val)-V.begin();
        x->val=P.back();
        if(idx)x->val-=P[idx-1];
        if(x->left)dfs2(x->left);
        if(x->right)dfs2(x->right);
    }
    TreeNode* convertBST(TreeNode* root) {
        if(!root)return root;
        dfs(root);
        sort(V.begin(),V.end());
        P=V;
        for(int i=1;i<(int)V.size();i++){
            P[i]+=P[i-1];
        }
        dfs2(root);
        return root;
    }
};