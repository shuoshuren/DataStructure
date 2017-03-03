//
// Created by xiao on 2017/2/6.
//

#include "LinkedTree.h"

LinkedTree::LinkedTree(){
    m_pRoot = new Node();
}

LinkedTree::~LinkedTree(){
    deleteNode(0, nullptr);
}

Node * LinkedTree::searchNode(int nodeIndex){
    return m_pRoot->searchNode(nodeIndex);
}

/**
 *
 * @param nodeIndex
 * @param direction
 * @param pNode
 * @return
 */
bool LinkedTree::addNode(int nodeIndex,int direction,Node *pNode){
    Node *pSearchNode = searchNode(nodeIndex);
    if(pSearchNode == nullptr){
        return false;
    }

    Node *node = new Node();
    if(nullptr == node){
        return false;
    }
    node->index = pNode->index;
    node->data = pNode->data;
    node->pParent = pSearchNode;
    if(direction == 0){
        pSearchNode->pLChild = node;
    } else{
        pSearchNode->pRChild = node;
    }
    return true;

}

bool LinkedTree::deleteNode(int nodeIndex,Node *pNode){
    Node *temp = searchNode(nodeIndex);
    if(temp == nullptr){
        return false;
    }
    if(pNode != nullptr){
        pNode->data = temp->data;
        pNode->index = temp->index;
    }

    temp->deleteNode();
    return true;
}

/**
 * 前序遍历
 */
void LinkedTree::preorderTraverse(){
    m_pRoot->preorderTraverse();
}

/**
 * 中序遍历
 */
void LinkedTree::inorderTraverse(){
    m_pRoot->inorderTraverse();
}

/**
 * 后序遍历
 */
void LinkedTree::postorderTraverse(){
    m_pRoot->postorderTraverse();
}