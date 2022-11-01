// id:374538293
// runtime:24 ms
// memory:23.7 MB
// title:Minimum Height Tree LCCI
// translatedTitle:最小高度树
// questionId:100174
// time:2022-10-19 16:48:18

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
    TreeNode* dfs(const int *src,int len){
        if(len<=0)return nullptr;
        if(len==1){
            TreeNode*ret=new TreeNode(*src);
            return ret;
        }
        int mid=(len+1)/2;
        TreeNode*ret=new TreeNode(*(src+mid-1));
        //1..mid-1
        ret->left=dfs(src,mid-1-1+1);
        //mid+1..len
        ret->right=dfs(src+mid,len-mid-1+1);
        return ret;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(nums.data(),nums.size());
    }
};