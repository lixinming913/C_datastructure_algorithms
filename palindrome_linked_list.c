/*
 *  Palindrome Linked List 
 *  Given a singly linked list, determine if it is a palindrome. do it in O(n) time and O(1) space
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    if(head == NULL || head->next == NULL)
        return true;    
    
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    
    while(fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next;
        fast = fast->next;
    }
    
    struct ListNode* mid = slow->next;
    
    struct ListNode* pre = NULL;
    struct ListNode* node = mid;
    while(node) {
        struct ListNode *next = node->next;
        node->next = pre;
        pre = node;
        node = next;
    }
    
    struct ListNode *head2 = pre;
    while(head2 != NULL && head != NULL) {
        if(head->val != head2->val)
            return false;
        head2 = head2->next;
        head = head->next;
    }
    
    return true;    
}