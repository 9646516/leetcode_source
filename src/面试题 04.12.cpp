// id:374562676
// runtime:12 ms
// memory:21.7 MB
// title:Paths with Sum LCCI
// translatedTitle:求和路径
// questionId:1000009
// time:2022-10-19 17:53:35

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
    int ans,target;
    unordered_multiset<int>st;
    void dfs(TreeNode*x,int xs){
        ans+=st.count(xs-target);
        st.insert(xs);
        if(x->left)dfs(x->left,xs+x->left->val);
        if(x->right)dfs(x->right,xs+x->right->val);
        st.erase(st.find(xs));
    }
    int pathSum(TreeNode* root, int sum) {
        if(!root){
            return 0;
        }
        ans=0;target=sum;
        st.insert(0);
        dfs(root,root->val);
        return ans;
    }
};