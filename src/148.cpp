// id:326013920
// runtime:1808 ms
// memory:153.7 MB
// title:Sort List
// translatedTitle:排序链表
// questionId:148
// time:2022-06-16 20:41:27

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
    pair<ListNode*,ListNode*>gao(ListNode*src){
        if(!src){
            return {nullptr,nullptr};
        }else if(!src->next){
            return {src,src};
        }else{
            ListNode*rhs=src;
            {
                int len=0;
                auto now=src;
                while(now){
                    len++;
                    now=now->next;
                }
                int rnk=rand()%len;
                now=src;
                for(int i=1;i<rnk;i++){
                    now=now->next;
                }
                rhs=now;
            }
            swap(src->val,rhs->val);

            ListNode*head1=new ListNode();
            ListNode*tail1=head1;
            ListNode*head2=new ListNode();
            ListNode*tail2=head2;
            auto cmp=src;
            src=src->next;
            for(auto i=src;i;i=i->next){
                if(i->val<cmp->val){
                    tail1->next=i;
                    tail1=tail1->next;
                }else{
                    tail2->next=i;
                    tail2=tail2->next;
                }
            }
            tail1->next=nullptr;
            tail2->next=nullptr;
            if(head1->next&&head2->next){
                auto [f1,s1]=gao(head1->next);
                auto [f2,s2]=gao(head2->next);
                s1->next=cmp;
                cmp->next=f2;
                delete head1;
                delete head2;
                return {f1,s2};
            }else if(head2->next){
                auto [f2,s2]=gao(head2->next);
                cmp->next=f2;
                delete head1;
                delete head2;
                return {cmp,s2};
            }else{
                auto [f1,s1]=gao(head1->next);
                s1->next=cmp;
                cmp->next=nullptr;
                delete head1;
                delete head2;
                return {f1,cmp};
            }
        }

    }
    ListNode* sortList(ListNode* head) {
        return gao(head).first;
    }
};