/*
 * 判断二叉树是否对称
 */
 
 
#include<stdio.h>
#include<stdlib.h>


struct BinaryTreeNode {
    int             m_key;
    BinaryTreeNode *pLeft;
    BinaryTreeNode *pRight;
};


BinaryTreeNode *
create(int m)
{
    BinaryTreeNode *pnode = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    
    pnode->m_key = m;
    pnode->pLeft = NULL;
    pnode->pRight = NULL;
    
    return pnode;
}


void
connect(BinaryTreeNode *Parent, BinaryTreeNode*Left, BinaryTreeNode*Right)
{
    if(Parent == NULL)
        return;
    
    Parent->pLeft = Left;
    Parent->pRight = Right;
}


bool
IsSymmetrical(BinaryTreeNode *pHead1, BinaryTreeNode *pHead2)
{
    if(pHead1 == NULL && pHead2 == NULL)
        return true;
    
    if(pHead1 == NULL || pHead2 == NULL)
        return false;
    
    if(pHead1->m_key != pHead2->m_key)
        return false;
        
    return IsSymmetrical(pHead1->pLeft, pHead2->pRight) 
          && IsSymmetrical(pHead1->pRight, pHead2->pLeft);
}


bool 
IsSymmetrical(BinaryTreeNode *pHead)
{
    return IsSymmetrical(pHead, pHead);
}

void 
test()
{
    BinaryTreeNode *pNode1 = create(1);
    BinaryTreeNode *pNode2 = create(2);
    BinaryTreeNode *pNode3 = create(2);
    BinaryTreeNode *pNode4 = create(3);
    BinaryTreeNode *pNode5 = create(3);
    BinaryTreeNode *pNode6 = create(4);
    BinaryTreeNode *pNode7 = create(4);
    
    connect(pNode1, pNode2, pNode3);
    connect(pNode2, pNode4, pNode6);
    connect(pNode3, pNode7, pNode5);
    
    if(IsSymmetrical(pNode1))
        printf("二叉树对称\n");
    else
        printf("二叉树不对称\n");

}


void 
main()
{
    test();
}