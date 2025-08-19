/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* head;
    struct ListNode* dummy;
    uint8_t increasing = 0;
    dummy = malloc(sizeof(struct ListNode));
    head = dummy;
    while (l1 != NULL || l2 != NULL) {
        dummy->val = 0;
        if (l1 != NULL) {
            dummy->val += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            dummy->val += l2->val;
            l2 = l2->next;
        }
        dummy->val += increasing;
        if (dummy->val >= 10) {
            dummy->val -= 10;
            increasing = 1;
        } else
            increasing = 0;
        dummy->val = (dummy->val) % 10;

        if (l1 != NULL || l2 != NULL) {
            dummy->next = malloc(sizeof(struct ListNode));
            dummy = dummy->next;
        } else if (increasing == 1) {
            dummy->next = malloc(sizeof(struct ListNode));
            dummy = dummy->next;
            dummy->val = 1;
        }
    }
    dummy->next = NULL;
    return head;
}
