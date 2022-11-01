// id:373273647
// runtime:16 ms
// memory:24.5 MB
// title:重建二叉树 LCOF
// translatedTitle:重建二叉树
// questionId:100283
// time:2022-10-15 19:13:50

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
    vector<int>a,b;
    TreeNode*solve(int l1,int r1,int l2,int r2){
        if(l1>r1)return nullptr;
        int root=a[l1];
        int split=-1;
        for(int i=l2;i<=r2;i++){
            if(b[i]==root){
                split=i;break;
            }
        }
        int len1=split-1-l2+1;
        TreeNode*ret=new TreeNode();
        ret->val=root;
        ret->left=solve(l1+1,l1+1+len1-1,l2,split-1);
        ret->right=solve(l1+1+len1-1+1,r1,split+1,r2);
        return ret;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        a=preorder;
        b=inorder;
        return solve(0,(int)a.size()-1,0,(int)b.size()-1);
    }
};