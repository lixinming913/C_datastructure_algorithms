/*
 *  Intersection of Two Linked Lists 
 *  Write a program to find the node at which the intersection of two singly linked lists begins.
 */


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 typedef struct ListNode ListNode;
 
 int length(ListNode *head) {
        if(head == NULL)
            return 0;
        
        int cnt = 0;
        ListNode *pnode = head;
        
        while(pnode != NULL) {
            ++cnt;
            pnode = pnode->next;
        }
        
        return cnt;
    }


struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {

        if(!headA && !headB)
            return NULL;
        if(!headA || !headB)
            return NULL;
            
        int lengthA = length(headA);
        int lengthB = length(headB);
        int diff = lengthA - lengthB;
        
        ListNode *pnode1 = headA;
        ListNode *pnode2 = headB;
 
        
        if(diff > 0) {
            int n = diff;
            while(n && pnode1) {
                pnode1 = pnode1->next;
                --n;
            }
            
            while(pnode1 && pnode2 && pnode1->val != pnode2->val) {
                pnode1 = pnode1->next;
                pnode2 = pnode2->next;
            }
            if(!pnode1 && !pnode2)
                return NULL;
            if(pnode1->val == pnode2->val)
                return pnode1;
        } else {
            int n = -diff;
            while(n && pnode2) {
                pnode2 = pnode2->next;
                --n;
            }
            
            while(pnode1 && pnode2 && pnode1->val != pnode2->val) {
                pnode1 = pnode1->next;
                pnode2 = pnode2->next;
            }
            if(!pnode1 && !pnode2)
                return NULL;
            if(pnode1->val == pnode2->val)
                return pnode1;
           
        }
}