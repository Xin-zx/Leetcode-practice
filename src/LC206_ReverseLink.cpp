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
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = nullptr;
        ListNode *cur = head;
        while (cur != nullptr){
            ListNode *p = cur->next;//需要保存节点
            cur->next = pre;//此时cur与与原来的下一个节点已经断开；
            pre = cur;
            cur = p;
        }
        return pre;
    }
};