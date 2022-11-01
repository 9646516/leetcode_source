// id:374507839
// runtime:32 ms
// memory:15.9 MB
// title:Remove Duplicate Node LCCI
// translatedTitle:移除重复节点
// questionId:100163
// time:2022-10-19 15:36:03

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
    ListNode* removeDuplicateNodes(ListNode* head) {
        ListNode*root=new ListNode();
        root->next=head;
        auto prev=root;
        auto now=head;
        unordered_set<int>st;
        while(now){
            if(!st.count(now->val)){
                st.insert(now->val);
                prev=now;
                now=now->next;
            }else{
                prev->next=now->next;
                now=now->next;
            }
        }
        auto ret=root->next;
        delete root;
        return ret;
    }
};