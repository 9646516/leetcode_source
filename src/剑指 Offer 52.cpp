// id:373630221
// runtime:44 ms
// memory:14.4 MB
// title:两个链表的第一个公共节点  LCOF
// translatedTitle:两个链表的第一个公共节点
// questionId:100326
// time:2022-10-16 21:30:34

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
    ListNode *getIntersectionNode(ListNode *A, ListNode *B) {
        if(!A&&!B)return nullptr;
        else{
            auto pA=A,pB=B;
            while(pA!=pB){
                pA=pA?pA->next:B;
                pB=pB?pB->next:A;
            }
            return pA;
        }
    }
};