//
// Created by xiao on 2017/2/6.
//

#ifndef TREE_TREE_H
#define TREE_TREE_H

/**
 * 数组实现二叉树
 */
class Tree {
public:
    Tree(int size,int *pRoot);
    ~Tree();
    int * searchNode(int nodeIndex);
    bool addNode(int nodeIndex,int direction,int *pNode);
    bool deleteNode(int nodeIndex,int *pNode);
    void treeTraverse();
private:
    int *m_pTree;
    int m_iSize;

};


#endif //TREE_TREE_H
