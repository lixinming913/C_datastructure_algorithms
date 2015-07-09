/*
 *二叉搜索树与双向链表
 */
 

#include<stdio.h>
#include<stdlib.h>


struct 
BinaryTreeNode{
    int                         m_nValue;
    BinaryTreeNode*      m_pLeft;
    BinaryTreeNode*      m_pRight;
};


void 
ConvertNode(BinaryTreeNode* pNode, BinaryTreeNode** pLastNodeInList)
{
    if( pNode == NULL )
        return ;
        
    BinaryTreeNode* pCurrent = pNode;
    if (pCurrent->m_pLeft != NULL)
        ConvertNode( pCurrent->m_pLeft, pLastNodeInList );

    pCurrent->m_pLeft = *pLastNodeInList;
    if( *pLastNodeInList != NULL )
        (*pLastNodeInList)->m_pRight = pCurrent;

    *pLastNodeInList = pCurrent;
    if(pCurrent->m_pRight != NULL)
        ConvertNode( pCurrent->m_pRight, pLastNodeInList );
}


BinaryTreeNode*
Convert(BinaryTreeNode* pRootOfTree)
{
    /*pLastNodeList指向双向链表的尾结点*/
    
    BinaryTreeNode* pLastNodeList = NULL;                                   
    ConvertNode(pRootOfTree , &pLastNodeList);

    /*需要返回头结点*/
    
    BinaryTreeNode* pHeadOfList = pLastNodeList;
    while( pHeadOfList != NULL 
              && pHeadOfList->m_pLeft != NULL ) 
    {
        pHeadOfList = pHeadOfList->m_pLeft;
    }
    
    return pHeadOfList;
}


BinaryTreeNode*
Create(int data)
{
    BinaryTreeNode*  pNode = new BinaryTreeNode();

    pNode->m_nValue = data;
    pNode->m_pLeft = NULL;
    pNode->m_pRight = NULL;

    return pNode;
}


void 
ConnectNode(BinaryTreeNode* pRoot, BinaryTreeNode* pleft, BinaryTreeNode* pright)
{
    if(pRoot != NULL) {
        pRoot->m_pLeft = pleft;
        pRoot->m_pRight = pright;
    }

    return ;
}


void
print_normal(BinaryTreeNode* pRoot)
{
    if( pRoot == NULL)
        return;

    BinaryTreeNode* pNode = pRoot;
    while(pNode) {
        printf(" %d ",pNode->m_nValue);
        pNode = pNode->m_pRight;
    }
}


void 
print_reverse(BinaryTreeNode* pRoot)
{
    if(!pRoot)
        return ;
        
    BinaryTreeNode* pNode = pRoot;
    while( pNode->m_pRight ) {
        pNode = pNode->m_pRight;
    }
    
    while(pNode) {
        printf(" %d ", pNode->m_nValue);
        pNode = pNode->m_pLeft;
    }
}


void
test()
{
    BinaryTreeNode* pNode1 = Create(10);
    BinaryTreeNode* pNode2 = Create(6);
    BinaryTreeNode* pNode3 = Create(14);
    BinaryTreeNode* pNode4 = Create(4);
    BinaryTreeNode* pNode5 = Create(8);
    BinaryTreeNode* pNode6 = Create(12);
    BinaryTreeNode* pNode7 = Create(16);
    
    ConnectNode(pNode1, pNode2, pNode3);
    ConnectNode(pNode2, pNode4, pNode5);
    ConnectNode(pNode3, pNode6, pNode7);

    BinaryTreeNode* pHead = Convert( pNode1 );
    
    printf("二叉树转换成排序双向链表\n");
    
    printf("从左至右链表顺序：\n"); 
    print_normal(pHead);
    
    printf("\n从右至左链表顺序:\n");
    print_reverse(pHead);
}


void 
main()
{
    test();
}