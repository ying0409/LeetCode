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
    ListNode* recursive(ListNode* head, ListNode* pre, int count) {
        if(count < 0) return pre;
        ListNode* last = recursive(head->next, head, count-1);
        head->next = pre;
        return last;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(right-left <= 0) return head;
        ListNode* empty = new ListNode;
        empty->next = head;
        ListNode* start = empty;
        ListNode* pre = empty;
        for(int i=0; i<left; ++i) {
            start = start->next;
            if(i != left-1) pre = pre->next;
        }
        ListNode* ori = empty;
        for(int i=0; i<right+1; ++i) {
            ori = ori->next;
        }
        ListNode* last = recursive(start, pre, right-left);
        pre->next = last;
        start->next = ori;
        return empty->next;
    }
};