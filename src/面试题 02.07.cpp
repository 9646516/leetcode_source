// id:374516351
// runtime:44 ms
// memory:14.2 MB
// title:Intersection of Two Linked Lists LCCI
// translatedTitle:链表相交
// questionId:100167
// time:2022-10-19 15:56:15

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
        ListNode*pa=headA,*pb=headB;
        while(pa!=pb){
            pa=pa?pa->next:headB;
            pb=pb?pb->next:headA;
        }
        return pa;
    }
};