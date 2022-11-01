// id:374180391
// runtime:1888 ms
// memory:78.5 MB
// title:链表排序
// translatedTitle:链表排序
// questionId:1000341
// time:2022-10-18 15:47:25

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
    pair<ListNode*,ListNode*> solve(ListNode*F){
        if(!F->next)return {F,F};
        int cnt=0;
        ListNode*swp;
        for(ListNode*i=F;i!=nullptr;i=i->next){
            cnt++;
            if(rand()%cnt==0){
                swp=i;
            }
        }
        swap(F->val,swp->val);
        auto cmp=F;
        F=F->next;
        auto head1=new ListNode();
        auto tail1=head1;
        auto head2=new ListNode();
        auto tail2=head2;
        for(ListNode*i=F;i!=nullptr;i=i->next){
            if(i->val<cmp->val){
                tail1->next=i;
                tail1=i;
            }else{
                tail2->next=i;
                tail2=i;
            }
        }
        auto root1=head1->next;
        delete head1;

        auto root2=head2->next;
        delete head2;
        if(root1&&root2){
            tail1->next=nullptr;
            tail2->next=nullptr;
            auto [h1,t1]=solve(root1);
            auto [h2,t2]=solve(root2);
            t1->next=cmp;
            cmp->next=h2;
            t2->next=nullptr;
            return {h1,t2};
        }else if(root1){
            auto [h1,t1]=solve(root1);
            t1->next=cmp;
            cmp->next=nullptr;
            return {h1,cmp};
        }else{
            auto [h2,t2]=solve(root2);
            cmp->next=h2;
            t2->next=nullptr;
            return {cmp,t2};
        }
       
    }
    ListNode* sortList(ListNode* head) {
        if(!head)return nullptr;
        return solve(head).first;
    }
};