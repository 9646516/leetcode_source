// id:373955369
// runtime:48 ms
// memory:35.8 MB
// title:二叉搜索树迭代器
// translatedTitle:二叉搜索树迭代器
// questionId:1000316
// time:2022-10-17 21:17:54

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
class BSTIterator {
public:
    pair<TreeNode*,TreeNode*>flatten(TreeNode*x){
        auto head=new TreeNode();
        auto tail=head;
        if(x->left){
            auto [h,t]=flatten(x->left);
            tail->right=h;
            tail=t;
        }
        tail->right=x;
        x->left=nullptr;
        tail=tail->right;
        if(x->right){
            auto [h,t]=flatten(x->right);
            tail->right=h;
            tail=t;
        }
        auto h=head->right;
        delete head;
        return {h,tail};
    }
    TreeNode*head;
    BSTIterator(TreeNode* root) {
        auto [h,t]=flatten(root);
        t->right=nullptr;
        head=h;
    }
    
    int next() {
        int ret=head->val;
        head=head->right;
        return ret;
    }
    
    bool hasNext() {
        return head!=nullptr;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */