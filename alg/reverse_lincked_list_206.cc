/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* reverseListIteratively(ListNode* head) {
    ListNode* prevNode = NULL;
        ListNode* nextNode = NULL;
        while (head != NULL) {
			// keep next node since the pointer to it will be trashed
            nextNode = head -> next;
			// switch the next pointer to point backwards
            head -> next = prevNode;
			// move couple of pointers forward
            prevNode = head;
            head = nextNode;
        }
    return prevNode; // head
}

ListNode* reverseListRec(ListNode* head) {
	// base exit from recursion
    if (head == NULL || head -> next == NULL)
        return head;
	// tip: think backwards
    ListNode* res = reverseListRec(head -> next);
    head -> next -> next = head;
    head -> next = NULL;
    return res;
}


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        return reverseListRec(head);
    }
};