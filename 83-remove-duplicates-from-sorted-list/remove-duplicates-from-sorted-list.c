struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode *c = head, *h = head;
    for (; h ; h->val != c->val && (c->next = h, c = h), h = h->next);
    return c && (c->next = NULL), head;
}