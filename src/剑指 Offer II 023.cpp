// id:373848109
// runtime:40 ms
// memory:14.2 MB
// title:两个链表的第一个重合节点
// translatedTitle:两个链表的第一个重合节点
// questionId:1000259
// time:2022-10-17 16:16:56

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto A=headA,B=headB;
        while(A!=B){
            A=A?A->next:headB;
            B=B?B->next:headA;
        }
        return A;
    }
};