/*
 * 给定一个二叉树和固定一个结点，如何找出中序遍历顺序的下一节点
 */
 
 
#include<stdio.h>
#include<stdlib.h>


struct BinaryTreeNode {
    int             m_key;
    BinaryTreeNode *pLeft;
    BinaryTreeNode *pRight;
    BinaryTreeNode *parent;
};


BinaryTreeNode *
create(int m)
{
    BinaryTreeNode *pnode = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    
    pnode->m_key = m;
    pnode->pLeft = NULL;
    pnode->pRight = NULL;
    pnode->parent = NULL;
    
    return pnode;
}


void
connect(BinaryTreeNode *Parent, BinaryTreeNode*Left, BinaryTreeNode*Right)
{
    if(Parent == NULL)
        return;
    
    Parent->pLeft = Left;
    Parent->pRight = Right;
    
    if(Left != NULL) 
        Left->parent = Parent;
        
    if(Right != NULL)
        Right->parent = Parent;
}


BinaryTreeNode *
GetNext(BinaryTreeNode *pnode)
{
    if(pnode == NULL)
        return NULL;
    
    BinaryTreeNode *pnext = NULL;
    /*如果有右子树*/
    if(pnode->pRight != NULL) {
        BinaryTreeNode *right = pnode->pRight;
        while(right->pLeft != NULL)
            right = right->pLeft;
            
        pnext = right;
    } 
    /*如果没有右子树*/
    else if(pnode->parent != NULL)
    {
        BinaryTreeNode *pCurrent = pnode;
        BinaryTreeNode *pParent = pnode->parent;
        while(pParent != NULL && pCurrent == pParent->pRight) {
            pCurrent = pParent;
            pParent = pParent->parent;          
        }
        
        pnext = pParent;
    }
    
    return pnext;
}


void 
test()
{
    BinaryTreeNode *pNode1 = create(1);
    BinaryTreeNode *pNode2 = create(2);
    BinaryTreeNode *pNode3 = create(3);
    BinaryTreeNode *pNode4 = create(4);
    BinaryTreeNode *pNode5 = create(5);
    BinaryTreeNode *pNode6 = create(6);
    BinaryTreeNode *pNode7 = create(7);
    
    connect(pNode1, pNode2, pNode3);
    connect(pNode2, pNode4, pNode5);
    connect(pNode3, pNode6, NULL);
    connect(pNode5, NULL, pNode7);
    
    BinaryTreeNode *GetNextNode = GetNext(pNode7);
    printf("%d next is %d\n", pNode7->m_key, GetNextNode->m_key);
}


void 
main()
{
    test();
}