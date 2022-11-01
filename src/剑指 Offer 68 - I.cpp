// id:373662900
// runtime:36 ms
// memory:22.8 MB
// title:二叉搜索树的最近公共祖先 LCOF
// translatedTitle:二叉搜索树的最近公共祖先
// questionId:100346
// time:2022-10-16 23:18:12

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
    void solve(TreeNode*x,int need,vector<TreeNode*> &v){
        v.push_back(x);
        if(x->val==need){
            return;
        }else if(x->val>need){
            solve(x->left,need,v);
        }else{
            solve(x->right,need,v);
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> v1,v2;
        solve(root,p->val,v1);
        solve(root,q->val,v2);
        sort(v2.begin(),v2.end());
        for(int i=v1.size()-1;i>=0;i--){
            if(binary_search(v2.begin(),v2.end(),v1[i])){
                return v1[i];
            }
        }
        return nullptr;
    }
};