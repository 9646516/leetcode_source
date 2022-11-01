// id:374539869
// runtime:0 ms
// memory:7.9 MB
// title:List of Depth LCCI
// translatedTitle:特定深度节点链表
// questionId:100175
// time:2022-10-19 16:51:50

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> listOfDepth(TreeNode* tree) {
        queue<TreeNode*>q1,q2;
        vector<ListNode*>ret;
        auto head=new ListNode();
        q1.push(tree);
        while(!q1.empty()){
            auto tail=head;
            while(!q1.empty()){
                auto now=q1.front();
                q1.pop();
                tail->next=new ListNode(now->val);
                tail=tail->next;
                if(now->left)q2.push(now->left);
                if(now->right)q2.push(now->right);
            }
            tail->next=nullptr;
            ret.push_back(head->next);
            swap(q1,q2);
        }
        delete head;
        return ret;
    }
};