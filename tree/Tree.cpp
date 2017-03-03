//
// Created by xiao on 2017/2/6.
//

#include "Tree.h"
#include <iostream>
using namespace std;

Tree::Tree(int size,int *pRoot){
    m_iSize = size;
    m_pTree = new int[m_iSize];
    for (int i=0;i<m_iSize;i++){
        m_pTree[i] = 0;
    }
    m_pTree[0] = *pRoot;
}

Tree::~Tree(){
    delete[] m_pTree;
    m_pTree = nullptr;
}

int * Tree::searchNode(int nodeIndex){
    if(nodeIndex<0 ||nodeIndex >= m_iSize){
        return NULL;
    }
    if(m_pTree[nodeIndex] == 0){
        return NULL;
    }
    return &m_pTree[nodeIndex];

}

/**
 * 插入节点
 * @param nodeIndex 父节点的索引
 * @param direction 插入节点的方向，0是左节点，1是右节点
 * @param pNode 插入节点的值
 * @return
 */
bool Tree::addNode(int nodeIndex,int direction,int *pNode){
    if(nodeIndex<0 ||nodeIndex >= m_iSize){
        return false;
    }
    if(m_pTree[nodeIndex] == 0){
        return false;
    }

    int addNodeIndex = 0;
    if(direction == 0){
        addNodeIndex = nodeIndex*2+1;
    }else{
        addNodeIndex = nodeIndex *2+2;
    }

    if(addNodeIndex >= m_iSize){
        return false;
    }
    if(m_pTree[addNodeIndex] != 0){
        return false;
    }
    m_pTree[addNodeIndex] = *pNode;


}

/**
 * 删除节点
 * TODO 删除其所有子节点以及后续子节点
 * @param nodeIndex
 * @param pNode
 * @return
 */
bool Tree::deleteNode(int nodeIndex,int *pNode){
    if(nodeIndex<0 ||nodeIndex >= m_iSize){
        return false;
    }
    if(m_pTree[nodeIndex] == 0){
        return false;
    }
    *pNode = m_pTree[nodeIndex];
    m_pTree[nodeIndex] = 0;
    int leftIndex = nodeIndex*2+1;
    int rightIndex = nodeIndex*2+2;
    int deleteNode = 0;
    if(leftIndex <=m_iSize){
        delete(leftIndex,&deleteNode);
    }
    if(rightIndex<=m_iSize){
        delete(rightIndex,&deleteNode);
    }

    return true;
}

void Tree::treeTraverse(){
    for (int i = 0; i < m_iSize; ++i) {
        cout<<m_pTree[i]<<" ";
    }
}
