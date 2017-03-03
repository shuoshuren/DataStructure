//
// Created by xiao on 2017/2/6.
//

#ifndef TREE_NODE_H
#define TREE_NODE_H


class Node {
public:
    Node();
    Node * searchNode(int nodeIndex);
    void deleteNode();
    void preorderTraverse();//前序遍历
    void inorderTraverse();//中序遍历
    void postorderTraverse();//后序遍历
    int index;
    int data;
    Node *pLChild;
    Node *pRChild;
    Node *pParent;


};


#endif //TREE_NODE_H
