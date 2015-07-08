/*
 * 两个链表的第一个公共结点
 */
 
 #include<stdio.h>
 #include<stdlib.h>
 
 struct 
 ListNode{
	int    		m_nKey;
	ListNode*	m_pNext;	
 };
 
 typedef struct ListNode node_t;
 
 
 node_t* 
 create_node(int e)
 {
	node_t *pnode = ( node_t* )malloc( sizeof( node_t ) );
	
	pnode->m_nKey = e;
	pnode->m_pNext = NULL;
	
	return pnode;
 }
 
 
 void
 connect(node_t* pnode1, node_t* pnode2)
 {
	if( pnode1 == NULL )
		return ;
	
	pnode1->m_pNext = pnode2;
 }
 
 
 int 
 GetListLength( node_t* head )
 {
	unsigned int length = 0;
	
	node_t* node = head;
	while(node != NULL){
		++length;
		node = node->m_pNext;
	}
	
	return length;	
 }
 
 node_t*
 FindFirstCommonNode(node_t* pHead1, node_t* pHead2)
 {
	/*得到两个链表的长度*/
	
	unsigned int length1 = GetListLength( pHead1 );
	unsigned int length2 = GetListLength( pHead2 );
	int lenght_diff = length1 - length2;
	
	node_t* pListHeadLong = pHead1;
	node_t* pListHeadShort = pHead2;
	if( length1 < length2){
		pListHeadLong = pHead2;
		pListHeadShort = pHead1;
		lenght_diff = length2 - length1;
	}
	
	/*先在长的链表上走几步，在同时在两个表上遍历查询*/
	
	for(int i = 0; i < lenght_diff; i++){
		pListHeadLong = pListHeadLong->m_pNext;
	}
	
	while( pListHeadLong != NULL 
	          && pListHeadShort != NULL 
			  && pListHeadLong != pListHeadShort )
	{
			pListHeadLong = pListHeadLong->m_pNext;
			pListHeadShort =pListHeadShort->m_pNext;
	}
	
	node_t* firstcommonnode = pListHeadLong;
	
	return firstcommonnode;
 }
 
 
 void
 main()
 {
	node_t* pnode1 = create_node(1);
	node_t* pnode2 = create_node(2);
	node_t* pnode3 = create_node(3);
	node_t* pnode4 = create_node(4);
	node_t* pnode5 = create_node(5);
	node_t* pnode6 = create_node(6);
	node_t* pnode7 = create_node(7);
	
	/*List1*/
	
	connect(pnode1, pnode2);
	connect(pnode2, pnode3);
	connect(pnode3, pnode6);
	connect(pnode6, pnode7);
	
	/*List2*/
	
	connect(pnode4, pnode5);
	connect(pnode5, pnode6);
	
	node_t* pHead1 = pnode1;
	node_t* pHead2 = pnode4;
	
	node_t* common_node = FindFirstCommonNode(pHead1, pHead2);
	
	printf("The first common node is %d\n", common_node->m_nKey);					
 }