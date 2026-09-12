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
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode(-1, head);
        ListNode *p = dummy;
        while (p->next != nullptr && p->next->next != nullptr){
            ListNode *tmp1 = p->next;//存上已断开的节点
            ListNode *tmp2 = p->next->next->next;//存已断开的节点
            p->next = p->next->next;
            p->next->next = tmp1;
            tmp1->next = tmp2;
            p = p->next->next;
        }
        return dummy->next;
    }
};