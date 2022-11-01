// id:373853223
// runtime:24 ms
// memory:70.5 MB
// title:链表中的两数相加
// translatedTitle:链表中的两数相加
// questionId:1000261
// time:2022-10-17 16:28:14

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void f(ListNode*x,vector<int>&v){
        while(x){
            v.push_back(x->val);
            x=x->next;
        }
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int>v1,v2,v3;
        f(l1,v1);
        f(l2,v2);
        int lbit=0;
        auto head=new ListNode();
        auto now=head;
        while(!v1.empty()||!v2.empty()){
            int xs=0;
            if(!v1.empty()){
                xs+=v1.back();
                v1.pop_back();
            }
            if(!v2.empty()){
                xs+=v2.back();
                v2.pop_back();
            }
            xs+=lbit;
            if(xs>=10){
                xs-=10;
                lbit=1;
            }else{
                lbit=0;
            }
            v3.push_back(xs);
        }
        if(lbit){
            v3.push_back(1);
        }
        while(!v3.empty()){
            now->next=new ListNode();
            now=now->next;
            now->val=v3.back();
            v3.pop_back();
        }
        now->next=nullptr;
        auto ret=head->next;
        delete head;
        return ret;
    }
};