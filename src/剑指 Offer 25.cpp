// id:373293507
// runtime:16 ms
// memory:18.8 MB
// title:合并两个排序的链表  LCOF
// translatedTitle:合并两个排序的链表
// questionId:100286
// time:2022-10-15 20:31:59

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1&&!l2)return nullptr;
        if(!l1)return l2;
        if(!l2)return l1;
        ListNode*now;
        if(l1->val<l2->val){
            now=l1;
            l1=l1->next;
        }else{
            now=l2;
            l2=l2->next;
        }
        now->next=mergeTwoLists(l1,l2);
        return now;
    }
};