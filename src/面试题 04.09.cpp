// id:374557000
// runtime:24 ms
// memory:19.5 MB
// title:BST Sequences LCCI
// translatedTitle:二叉搜索树序列
// questionId:1000010
// time:2022-10-19 17:35:06

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
    vector<vector<int>>V;
    vector<int>now;
    unordered_set<TreeNode*>q;
    void dfs(){
        if(q.empty()){
            V.push_back(now);
        }else{
            auto q2=q;
            for(auto i:q2){
                q.erase(i);
                now.push_back(i->val);
                if(i->left)q.insert(i->left);
                if(i->right)q.insert(i->right);
                dfs();
                now.pop_back();
                if(i->left)q.erase(i->left);
                if(i->right)q.erase(i->right);
                q.insert(i);
            }
        }
    }
    vector<vector<int>> BSTSequences(TreeNode* root) {
        if(!root)return {{}};
        q.insert(root);
        dfs();
        return V;
    }
};