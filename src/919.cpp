// id:373922717
// runtime:20 ms
// memory:21.6 MB
// title:Complete Binary Tree Inserter
// translatedTitle:完全二叉树插入器
// questionId:955
// time:2022-10-17 20:01:22

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
class CBTInserter {
public:
    TreeNode*root;
    int sz;
    void dfs(TreeNode*x){
        sz++;
        if(x->left)dfs(x->left);
        if(x->right)dfs(x->right);
    }
    CBTInserter(TreeNode* root) {
        this->root=root;
        sz=0;
        dfs(root);
    }
    
    int insert(int v) {
        sz++;
        int ffs;
        for(int i=31;i>=0;i--){
            if((sz>>i)&1){
                ffs=i;break;
            }
        }
        TreeNode*now=root;
        for(int i=ffs-1;i>=1;i--){
            if((sz>>i)&1){
                now=now->right;
            }else{
                now=now->left;
            }
        }
        if(sz&1){
            now->right=new TreeNode(v);
        }else{
            now->left=new TreeNode(v);
        }
        return now->val;
    }
    
    TreeNode* get_root() {
        return root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */