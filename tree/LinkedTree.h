//
// Created by xiao on 2017/2/6.
//

#ifndef TREE_LINKEDTREE_H
#define TREE_LINKEDTREE_H

#include "Node.h"

/**
 * 链表实现二叉树
 */
class LinkedTree {
public:
    LinkedTree();
    ~LinkedTree();
    Node * searchNode(int nodeIndex);
    bool addNode(int nodeIndex,int direction,Node *pNode);
    bool deleteNode(int nodeIndex,Node *pNode);

    void preorderTraverse();//前序遍历
    void inorderTraverse();//中序遍历
    void postorderTraverse();//后序遍历

private:
    Node *m_pRoot;

};


#endif //TREE_LINKEDTREE_H
