/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* reverseListIteratively(ListNode* head) {
	// initialization
    ListNode* prevNode = NULL;
    ListNode* nextNode = NULL;
    while (head != NULL) {
        nextNode = head -> next;
        head -> next = prevNode;
        prevNode = head;
        head = nextNode;
    }
    return prevNode; // head
}

ListNode* findMiddle(ListNode* head) {
    ListNode* middleNode, *endNode;
	// set bth to head for the start
    middleNode = head;
    endNode = head;
    while (endNode != NULL) {
        if (endNode -> next == NULL) // list has one element
            return middleNode; // so head is also a middle
        endNode = endNode -> next -> next;
        if (endNode == NULL) // if there are even elements in the list
            return middleNode; // return one before the actual middle
        middleNode = middleNode -> next;
    }
    return middleNode; // return middle if odd elements are in the list
}

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head -> next == NULL) // check for zero- and one-element lists -- consider them always a palindrome
            return true;
        ListNode* middleNode = findMiddle(head);
        middleNode -> next = reverseListIteratively(middleNode -> next); // reverse the last half of the list.
        while (middleNode -> next != NULL) {
			// now check element's values head by head :)
            if (head -> val != middleNode -> next -> val) {
            	return false;
            } else {
				// and move heads
                head = head -> next;
                middleNode -> next = middleNode -> next -> next;    
            }
        }
        return true;
    }
};