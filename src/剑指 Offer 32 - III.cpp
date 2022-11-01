// id:373302535
// runtime:4 ms
// memory:12.1 MB
// title:从上到下打印二叉树 III LCOF
// translatedTitle:从上到下打印二叉树 III
// questionId:100314
// time:2022-10-15 21:03:51

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
        for(int i=1;i<ret.size();i+=2){
            reverse(ret[i].begin(),ret[i].end());
        }
        return ret;
    }
};