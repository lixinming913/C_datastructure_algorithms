/*
 * 二叉树的深度问题
 */
 
 
 #include<stdio.h>
 #include<stdlib.h>
 
 
 struct 
 BinaryTreeNode
 {
    int              m_nValue;
    BinaryTreeNode  *m_pLeft;
    BinaryTreeNode  *m_pRight;
 };
 
 
 BinaryTreeNode*
 createBinaryTreeNode(int value)
 {
    BinaryTreeNode* pNode = new BinaryTreeNode();
    
    pNode->m_nValue = value;
    pNode->m_pLeft = NULL;
    pNode->m_pRight = NULL;
    
    return pNode;
 }


 void 
 connectBinaryTreeNode(BinaryTreeNode* pParent, BinaryTreeNode* pLeftChild,
                                  BinaryTreeNode* pRightChild)
 {
    if(!pParent)
        return;

    pParent->m_pLeft = pLeftChild;
    pParent->m_pRight = pRightChild;
}
 
 
 bool
 IsBalance(BinaryTreeNode* root, int *depth)
 {
    if(root == NULL) {
        *depth = 0;
        return true;
    }
    
    int left, right;
    if(IsBalance(root->m_pLeft, &left) 
       && IsBalance(root->m_pRight, &right)
    {
        int diff = left - right;
        if(diff <= 1 && diff >= -1) {
            *depth = 1 + (left > right ? left : right);
            return true;
        }
    }
    
    return false;
 }
 
 
  bool
  IsBalance(BinaryTreeNode* root)
  {
    int depth = 0;
    
    return IsBalance(root, &depth);
  }
 
 
 BinaryTreeNode*
 creat_binary_tree( )
 {
    BinaryTreeNode* pNode1 = createBinaryTreeNode(1);
    BinaryTreeNode* pNode2 = createBinaryTreeNode(2);
    BinaryTreeNode* pNode3 = createBinaryTreeNode(3);
    BinaryTreeNode* pNode4 = createBinaryTreeNode(4);
    BinaryTreeNode* pNode5 = createBinaryTreeNode(5);
    BinaryTreeNode* pNode6 = createBinaryTreeNode(6);
    BinaryTreeNode* pNode7 = createBinaryTreeNode(7);
    
    connectBinaryTreeNode(pNode1, pNode2, pNode3);
    connectBinaryTreeNode(pNode2, pNode4, pNode5);
    connectBinaryTreeNode(pNode5, pNode7, NULL);
    connectBinaryTreeNode(pNode3, NULL, pNode6);
    
    return pNode1;
 }
 
 int 
 main( )
 {
    BinaryTreeNode* head = (BinaryTreeNode*)malloc( sizeof(BinaryTreeNode) );;
    
    head = creat_binary_tree( );    
    
    if( IsBalance(head) )
        printf("BinaryTree is AVL tree\n");
    
    return 0;
    
 }
