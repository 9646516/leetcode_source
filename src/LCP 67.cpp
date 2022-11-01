// id:370591676
// runtime:712 ms
// memory:161.7 MB
// title:装饰树
// translatedTitle:装饰树
// questionId:1000482
// time:2022-10-07 15:06:00

class Solution {
  public:
    TreeNode *expandBinaryTree(TreeNode *root) {
        if (!root)
            return nullptr;
        if (root->left) {
            auto jb = new TreeNode();
            jb->val = -1;
            jb->left = expandBinaryTree(root->left);
            jb->right = nullptr;
            root->left = jb;
        }
        if (root->right) {
            auto jb = new TreeNode();
            jb->val = -1;
            jb->left = nullptr;
            jb->right = expandBinaryTree(root->right);
            root->right = jb;
        }
        return root;
    }
};