// id:373302257
// runtime:0 ms
// memory:12.1 MB
// title:从上到下打印二叉树 II LCOF
// translatedTitle:从上到下打印二叉树 II
// questionId:100312
// time:2022-10-15 21:02:51

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)return {};
        queue<pair<int,TreeNode*>>q;
        q.push({0,root});
        vector<vector<int>>ret;
        while(!q.empty()){
            auto [dep,now]=q.front();q.pop();
            ret.resize(dep+1);
            ret[dep].push_back(now->val);
            if(now->left){
                q.push({dep+1,now->left});
            }
            if(now->right){
                q.push({dep+1,now->right});
            }
        }
        return ret;
    }
};