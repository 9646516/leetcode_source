// id:373287037
// runtime:12 ms
// memory:9 MB
// title:删除链表的节点 LCOF
// translatedTitle:删除链表的节点
// questionId:100299
// time:2022-10-15 20:09:05

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
    ListNode* deleteNode(ListNode* head, int val) {
        auto H=new ListNode();
        H->next=head;
        auto prev=H,now=head;
        while(now){
            if(now->val==val){
                prev->next=now->next;
                break;
            }
            prev=now;
            now=now->next;
        }
        auto ret=H->next;
        delete H;
        return ret;
    }
};