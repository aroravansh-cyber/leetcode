class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* temp = head;
        while (temp) {
            len++;
            temp = temp->next;
        }
        if (n == len) return head->next;
        temp = head;
        for (int i = 0; i < len - n - 1; i++) {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return head;
    }
};