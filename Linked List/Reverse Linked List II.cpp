Reverse Linked List II

Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list


        == > See DSA notes


ListNode * reverseBetween(ListNode* head, int left, int right) {
	ListNode* dummy = new ListNode(0);
	dummy->next = head;
	ListNode* pre = dummy;

	for (int i = 0; i < left - 1; i++)
		pre = pre->next;
	ListNode* start = pre->next;
	ListNode* trail = start->next;

	for (int i = 0; i < right - left; i++) {
		start->next = trail->next;
		trail->next = pre->next;
		pre->next = trail;
		trail = start->next;
	}
	return dummy->next;
}