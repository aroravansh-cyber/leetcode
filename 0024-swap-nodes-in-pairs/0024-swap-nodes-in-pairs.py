class Solution:
    def swapPairs(self, head):
        base = ListNode(0)
        base.next = head
        cur = base
        while cur.next and cur.next.next:
            p = cur.next
            q = p.next
            p.next = q.next
            q.next = p
            cur.next = q
            cur = p
        return base.next