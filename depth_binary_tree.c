/*
 * 二叉树的深度问题
 */
 
 
 #include<stdio.h>
 #include<stdlib.h>
 
 
 struct 
 BinaryTreeNode
 {
    int				    m_nValue;
    BinaryTreeNode	*m_pLeft;
    BinaryTreeNode	*m_pRight;
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

 
 int 
 GetBinaryTreeDepth(BinaryTreeNode* root)
 {
    if(root == NULL)
        return 0;
    
    int left_depth;
    int right_depth;
    
    left_depth = GetBinaryTreeDepth(root->m_pLeft);
    right_depth = GetBinaryTreeDepth(root->m_pRight);
    
    return (left_depth > right_depth) ? (left_depth + 1) : (right_depth + 1);        
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
    
    int depth = GetBinaryTreeDepth(head);
    
    printf("BinaryTree depth is %d\n", depth);
    
    return 0;
    
 }