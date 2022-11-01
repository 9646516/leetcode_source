// id:374511172
// runtime:8 ms
// memory:7.5 MB
// title:Delete Middle Node LCCI
// translatedTitle:删除中间节点
// questionId:100187
// time:2022-10-19 15:43:48

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
    void deleteNode(ListNode* node) {
        *node=*(node->next);
    }
};