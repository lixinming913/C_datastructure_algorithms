/*
 * 链表中环的入口结点
 */
 
 
#include<stdio.h>
#include<stdlib.h> 


typedef struct node {
    int           m_key;
    struct node  *pnext;
}node_t;


node_t *
create(int k)
{
    node_t *pnew = (node_t *)malloc(sizeof(node));
    
    pnew->mkey = k;
    pnew->pnext = NULL;

	return pnew;
}


void 
connect(node_t* pnode1, node_t* pnode2)
{
    if(pnode1 == NULL)
        return;
    
    pnode1->pnext = pnode2;
}


/*找到环中两指针相遇的节点*/
node_t * 
MeetingNode(node_t *pnode)
{
    if(pnode == NULL)
        return NULL;
        
    node_t *pSlow,*pFast;
	pSlow = pnode->pnext;
	if(pSlow == NULL)
		return NULL;

    pFast = pSlow->pnext;       
    while(pFast != NULL && pSlow != NULL) {
		if(pSlow == pFast)
			return pFast;

		pSlow = pSlow->pnext;

        pFast = pFast->pnext;
		if(pFast != NULL)
			pFast = pFast->pnext;       
    }
    
    return NULL;   
}


node_t *
EntryNode(node_t *root)
{
    node_t *meetnode = MeetingNode(root);
    if(meetnode == NULL)
        return NULL;
    
    int in_circle = 1;
    node_t *pnode1 = meetnode;
    while(pnode1->pnext != meetnode) {
        pnode1 = pnode1->pnext;
        ++in_circle; 
    }
    
    node_t *pnode2 = root;
    int i = 0;
    for(; i < in_circle; ++i)
        pnode2 = pnode2->pnext;
        
    pnode1 = root;
    while(pnode1 != pnode2) {
        pnode1 = pnode1->pnext;
        pnode2 = pnode2->pnext;
    }
    
    return pnode1;
}


void
test()
{
    node_t *pnode1 = create(1);
    node_t *pnode2 = create(2);
    node_t *pnode3 = create(3);
    node_t *pnode4 = create(4);
    node_t *pnode5 = create(5);
    node_t *pnode6 = create(6);   

    connect(pnode1, pnode2);
    connect(pnode2, pnode3);
    connect(pnode3, pnode4);
    connect(pnode4, pnode5);
    connect(pnode5, pnode6);
    connect(pnode6, pnode3);
    
    node_t *entrynode = EntryNode(pnode1);
    
    printf("%d\n", entrynode->mkey);
}

void
main()
{
    test();
}
