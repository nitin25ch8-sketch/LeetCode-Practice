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
    ListNode* rotateRight(ListNode* head, int k) {
        // 1. Handle edge cases (empty list, single node, or k = 0)
        if (!head || !head->next || k == 0) {
            return head;
        }

        // 2. Find the length of the list and the original tail node
        int len = 1;
        ListNode* tail = head;
        while (tail->next) {
            len++;
            tail = tail->next;
        }

        // 3. Calculate effective rotations (avoid unnecessary loops)
        k = k % len;
        if (k == 0) {
            return head; 
        }

        // 4. Find the new tail (len - k - 1 steps from the head)
        ListNode* new_tail = head;
        for (int i = 0; i < len - k - 1; i++) {
            new_tail = new_tail->next;
        }

        // 5. Break the list and reconnect
        ListNode* new_head = new_tail->next;
        new_tail->next = nullptr; // Break the circle
        tail->next = head;        // Connect old tail to old head

        return new_head;
    }
};