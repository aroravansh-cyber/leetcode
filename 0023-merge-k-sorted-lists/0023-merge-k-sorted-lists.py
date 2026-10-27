class Solution:
    def mergeKLists(self, lists: list[ListNode | None]) -> ListNode | None:
        heap = []

        # Push the head of each non-empty list.
        # The index i breaks ties so ListNode objects are never compared.
        for i, node in enumerate(lists):
            if node:
                heapq.heappush(heap, (node.val, i, node))

        dummy = ListNode()
        tail = dummy

        while heap:
            _, i, node = heapq.heappop(heap)
            tail.next = node
            tail = node
            if node.next:
                heapq.heappush(heap, (node.next.val, i, node.next))

        return dummy.next