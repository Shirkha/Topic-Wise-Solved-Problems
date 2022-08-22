Partition List

Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.



== => Create dummy pointer and seprate the two list then again join the two lists

ListNode* partition(ListNode* head, int x) {
	// ListNode* node1 = new ListNode();
	// ListNode* node2 = new ListNode();
	// ListNode *p1 = node1, *p2 = node2;

	//OR      ListNode---> Structure ListNode*---->pointer
	ListNode node1(0), node2(0);
	ListNode *p1 = &node1, *p2 = &node2;

	while (head) {
		if (head->val < x) {
			p1->next = head;
			p1 = p1->next;
		}
		else {
			p2->next = head;
			p2 = p2->next;
		}
		head = head->next;
	}
	p2->next = NULL;
	//p1->next = node2->next;
	// return node1->next;
	//OR
	p1->next = node2.next;
	return node1.next;
}