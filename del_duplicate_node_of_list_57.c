/*
 * 删除链表中重复的结点1->2->2->3->3->4变成1->4
 */
 
 
#include<stdio.h>
#include<stdlib.h>


struct ListNode {
    int         m_key;
    ListNode   *pnext;    
};

ListNode *
create(int m)
{
    ListNode *pNode = (ListNode *)malloc(sizeof(ListNode));
  
    pNode->m_key = m;
    pNode->pnext = NULL;
        
    return pNode;
}


void 
connect(ListNode *pNode1, ListNode *pNode2)
{
    if(!pNode1)
        return;
    
    pNode1->pnext = pNode2;
}


void deleteDuplication(ListNode **head)
{
    if(head == NULL || *head == NULL)
        return;
        
    ListNode *PreNode = NULL;
    ListNode *pNode = *head;
    
    while(pNode != NULL) {
        bool Duplication = false;
        ListNode *pNext = pNode->pnext;
        
        if(pNext != NULL && pNext->m_key == pNode->m_key)
            Duplication = true;
        
        if(!Duplication) {
            PreNode = pNode;
            pNode = pNode->pnext;
        } else {
            ListNode *DelToNode = pNode;
            int delkey = pNode->m_key;
            while(DelToNode != NULL && DelToNode->m_key == delkey) {
                pNext = DelToNode->pnext;
                free(DelToNode);
                DelToNode = NULL;
                
                DelToNode = pNext;
            }
            
            if(PreNode == NULL)
                *head = pNext;
            else
                PreNode->pnext = pNext;
            pNode = pNext;
        }        
    }
}


void 
print(ListNode **head)
{
    if(*head == NULL)
        return;
        
    ListNode *pNode = *head;
    while(pNode != NULL) {
        printf("%d ", pNode->m_key);
		pNode = pNode->pnext;
    }
}


void
test()
{
    ListNode *pNode1 = create(1);
    ListNode *pNode2 = create(2);
    ListNode *pNode3 = create(2);    
    ListNode *pNode4 = create(3);   
    ListNode *pNode5 = create(3);    
    ListNode *pNode6 = create(4);
    
    connect(pNode1, pNode2);
    connect(pNode2, pNode3);
    connect(pNode3, pNode4);
    connect(pNode4, pNode5);
    connect(pNode5, pNode6);
    
    print(&pNode1);
    printf("\n");
    
    deleteDuplication(&pNode1);
    
    print(&pNode1);
    printf("\n");
}


int
main()
{
    test();
    
    return 0;
}