// id:373929389
// runtime:28 ms
// memory:19.5 MB
// title:向下的路径节点之和
// translatedTitle:向下的路径节点之和
// questionId:1000307
// time:2022-10-17 20:17:03

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
    using ll=long long;
    int ans=0;
    ll target;
    unordered_multiset<ll>st;
    void dfs(TreeNode*x,ll xs){
        ans+=st.count(xs-target);
        st.insert(xs);
        if(x->left)dfs(x->left,xs+x->left->val);
        if(x->right)dfs(x->right,xs+x->right->val);
        st.erase(st.find(xs));
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root)return 0;
        st.insert(0);
        target=targetSum;
        dfs(root,root->val);
        return ans;
    }
};