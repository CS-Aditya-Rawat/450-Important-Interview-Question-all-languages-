def removeDuplicates(head):
    #code here
    cur = head.next
    pre = head
    temp = head.next
    while cur:
        if cur.data == pre.data:
            temp = cur.next
            pre.next = cur.next
            cur = temp
        else:
            pre = cur
            cur = cur.next
