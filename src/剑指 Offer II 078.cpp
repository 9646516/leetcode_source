// id:374183826
// runtime:24 ms
// memory:13.1 MB
// title:合并排序链表
// translatedTitle:合并排序链表
// questionId:1000342
// time:2022-10-18 15:55:48

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto head=new ListNode();
        auto tail=head;
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>q;
        for(auto i:lists)if(i)q.push({i->val,i});
        while(!q.empty()){
            auto [_,now]=q.top();
            q.pop();
            tail->next=now;
            tail=now;
            if(now->next){
                q.push({now->next->val,now->next});
            }
        }
        auto ret=head->next;
        delete head;
        return ret;
    }
};