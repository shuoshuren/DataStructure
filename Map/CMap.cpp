//
// Created by xiao on 2017/2/7.
//

#include <iostream>
#include <cstring>
#include "CMap.h"
using namespace std;

CMap::CMap(int capacity) {
    m_iCapacity = capacity;
    m_iNodeCount = 0;
    m_pNodeArray = new Node[m_iCapacity];
    m_pMatrix = new int[m_iCapacity*m_iCapacity];
    memset(m_pMatrix,0,m_iCapacity*m_iCapacity* sizeof(int));
    m_pEdge = new Edge[m_iCapacity-1];
}

CMap::~CMap() {
    delete [] m_pMatrix;
    delete [] m_pNodeArray;
    delete [] m_pEdge;
}

/**
 * 向图中加入顶点（节点）
 * @param pNode
 * @return
 */
bool CMap::addNode(Node *pNode) {
    m_pNodeArray[m_iNodeCount].m_cData = pNode->m_cData;
    m_iNodeCount++;
    return true;
}

/**
 * 重置顶点
 * @return
 */
bool CMap::resetNode() {
    for (int i=0;i<m_iNodeCount;i++){
        m_pNodeArray[i].m_bIsVisited = false;
    }
}

/**
 * 为有向图设置邻接矩阵
 * @param row
 * @param col
 * @param val
 * @return
 */
bool CMap::setValueToMatrixForDirectedGraph(int row, int col, int val) {
    if(row<0||row>=m_iCapacity){
        return false;
    }
    if(col<0||row>=m_iCapacity){
        return false;
    }
    m_pMatrix[m_iCapacity*row+col] = val;
    return true;

}

/**
 * 为无向图设置邻接矩阵
 * @param row
 * @param col
 * @param val
 * @return
 */
bool CMap::setValueToMatrixForUndirectedGraph(int row, int col, int val) {
    if(row<0||row>=m_iCapacity){
        return false;
    }
    if(col<0||row>=m_iCapacity){
        return false;
    }
    m_pMatrix[m_iCapacity*row+col] = val;
    m_pMatrix[m_iCapacity*col+row] = val;
    return true;
}

/**
 * 从矩阵中获取权值
 * @param row
 * @param col
 * @param val
 * @return
 */
bool CMap::getValueFromMatrix(int row, int col, int &val) {
    if(row<0||row>=m_iCapacity){
        return false;
    }
    if(col<0||row>=m_iCapacity){
        return false;
    }
    val = m_pMatrix[row*m_iCapacity+col];
    return true;
}

/**
 * 打印邻接矩阵
 */
void CMap::printMatrix() {
    for (int i = 0; i < m_iCapacity; ++i) {
        for (int j = 0; j < m_iCapacity; ++j) {
            cout<<m_pMatrix[i*m_iCapacity+j]<<" ";
        }
        cout<<endl;
    }
}

/**
 * 深度优先遍历
 * @param nodeIndex
 */
void CMap::depthFirstTraverse(int nodeIndex) {
    int value = 0;
    cout<<m_pNodeArray[nodeIndex].m_cData<<" ";
    m_pNodeArray[nodeIndex].m_bIsVisited = true;

    //通过邻接矩阵判断是否与其他的顶点有连接
    for(int i=0;i<m_iCapacity;i++){
        getValueFromMatrix(nodeIndex,i,value);

        if(value!=0){//判断有弧连接其他点

            if(m_pNodeArray[i].m_bIsVisited){//判断改点是否已经访问过
                continue;
            }else{
                depthFirstTraverse(i);
            }
        }else{//如果没有去向索引为i的顶点的弧，则继续
            continue;
        }

    }

}

/**
 * 广度优先遍历
 * @param nodeIndex
 */
void CMap::breadthFirstTraverse(int nodeIndex) {

    cout<<m_pNodeArray[nodeIndex].m_cData<<" ";
    m_pNodeArray[nodeIndex].m_bIsVisited = true;
    vector<int> curVec;
    curVec.push_back(nodeIndex);
    breadthFirstTraverseImpl(curVec);

}

void CMap::breadthFirstTraverseImpl(vector<int> preVec) {
    int value = 0;
    vector<int> curVec;
    for (int i = 0; i < preVec.size(); ++i) {
        for(int j=0;j<m_iCapacity;j++){
            getValueFromMatrix(preVec[i],j,value);
            if(value!=0){//判断有弧连接其他点
                if(m_pNodeArray[j].m_bIsVisited){//判断改点是否已经访问过
                    continue;
                }else{
                    cout<<m_pNodeArray[j].m_cData<<" ";
                    m_pNodeArray[j].m_bIsVisited = true;
                    curVec.push_back(j);
                }
            }else{
                continue;
            }
        }
        
    }

    if(curVec.size() == 0){
        return;
    }else{
        breadthFirstTraverseImpl(curVec);
    }

}

/**
 * 普利姆算法
 * @param nodeIndex
 */
void CMap::primTree(int nodeIndex) {
    int weightValue = 0;
    int edgeCount = 0;
    vector<int> nodeVec;
    vector<Edge> edgeVec;

    cout<<m_pNodeArray[nodeIndex].m_cData<<endl;

    nodeVec.push_back(nodeIndex);
    m_pNodeArray[nodeIndex].m_bIsVisited = true;

    while(edgeCount<m_iCapacity-1){
        int temp = nodeVec.back();
        for (int i = 0; i < m_iCapacity; ++i) {
            getValueFromMatrix(temp,i,weightValue);
            if(weightValue != 0){
                if(m_pNodeArray[i].m_bIsVisited){
                    continue;
                }else{
                    Edge edge(temp,i,weightValue);
                    edgeVec.push_back(edge);
                }
            }
        }

        //从可选边集合中找出最小边
        int edgeIndex = getMinEdge(edgeVec);
        edgeVec[edgeIndex].m_bSelected = true;

        cout<<edgeVec[edgeIndex].m_iNodeIndexA<<"----"<<edgeVec[edgeIndex].m_iNodeIndexB<<" ";
        cout<<edgeVec[edgeIndex].m_iWeightValue<<endl;

        m_pEdge[edgeCount] = edgeVec[edgeIndex];
        edgeCount++;

        int nextNodeIndex = edgeVec[edgeIndex].m_iNodeIndexB;
        nodeVec.push_back(nextNodeIndex);
        m_pNodeArray[nextNodeIndex].m_bIsVisited = true;

        cout<<m_pNodeArray[nextNodeIndex].m_cData<<endl;
    }

}

/**
 * 获取最小边
 * @param edgeVec
 * @return
 */
int CMap::getMinEdge(vector<Edge> edgeVec) {
    int minWeight = 0;
    int edgeIndex = 0;
    int i = 0;
    for (i = 0; i < edgeVec.size(); ++i) {
        if(!edgeVec[i].m_bSelected){
            minWeight = edgeVec[i].m_iWeightValue;
            edgeIndex = i;
            break;
        }
    }

    if(minWeight == 0){
        return -1;
    }

    for (; i < edgeVec.size(); ++i) {
        if(edgeVec[i].m_bSelected){
            continue;
        }else{
            if(minWeight>edgeVec[i].m_iWeightValue){
                minWeight = edgeVec[i].m_iWeightValue;
                edgeIndex = i;
            }
        }
    }

    return edgeIndex;
}

/**
 * 克鲁斯卡尔生成树
 * @param nodeIndex
 */
void CMap::kruskalTree() {
    int weightValue = 0;
    int edgeCount  = 0;

    //定义存放节点集合的数组
    vector< vector<int> > nodeSets;

    //第一步.取出所有的边
    vector<Edge> edgeVec;
    for (int i = 0; i < m_iCapacity; ++i) {
        for (int j = i+1; j < m_iCapacity; ++j) {
            getValueFromMatrix(i,j,weightValue);
            if(weightValue!=0){
                Edge edge(i,j,weightValue);
                edgeVec.push_back(edge);
            }
        }
    }

    //第二步.从所有边中取出组成最小生成树的边
    //1.找出算法结束条件
    while(edgeCount<m_iCapacity-1){

        //2.从边集合中找到最小边
        int minEdgeIndex = getMinEdge(edgeVec);
        edgeVec[minEdgeIndex].m_bSelected = true;

        //3.找出最小边连接的点
        int nodeAIndex = edgeVec[minEdgeIndex].m_iNodeIndexA;
        int nodeBIndex = edgeVec[minEdgeIndex].m_iNodeIndexB;

        bool nodeAIsInSet = false;
        bool nodeBIsInSet = false;

        int nodeAInSetLabel = -1;
        int nodeBInSetLabel = -1;

        //4.找出点所在的点集合
        for (int i = 0; i < nodeSets.size(); ++i) {
           nodeAIsInSet =  isInSet(nodeSets[i],nodeAIndex);
            if(nodeAIsInSet){
                nodeAInSetLabel = i;
            }
        }

        for (int i = 0; i < nodeSets.size(); ++i) {
            nodeBIsInSet =  isInSet(nodeSets[i],nodeBIndex);
            if(nodeBIsInSet){
                nodeBInSetLabel = i;
            }
        }

        //5.根据点所在集合的不同做出不同的处理
        if(nodeAInSetLabel == -1 && nodeBInSetLabel == -1){
            vector<int> vec;
            vec.push_back(nodeAIndex);
            vec.push_back(nodeBIndex);
            nodeSets.push_back(vec);
        }else if(nodeAInSetLabel == -1 && nodeBInSetLabel !=-1){

            nodeSets[nodeBInSetLabel].push_back(nodeAIndex);

        }else if(nodeAInSetLabel != -1 && nodeBInSetLabel == -1){

            nodeSets[nodeAInSetLabel].push_back(nodeBIndex);

        }else if(nodeAInSetLabel != -1 && nodeBInSetLabel != -1 && nodeAInSetLabel != nodeBInSetLabel){
            //合并两个vector
            mergeNodeSet(nodeSets[nodeAInSetLabel],nodeSets[nodeBInSetLabel]);
            for (int k = nodeBInSetLabel; k < nodeSets.size()-1; ++k) {
                nodeSets[k] = nodeSets[k+1];
            }
        }else if(nodeAInSetLabel != -1 && nodeBInSetLabel != -1 && nodeAInSetLabel == nodeBInSetLabel){
            continue;
        }

        m_pEdge[edgeCount] = edgeVec[minEdgeIndex];
        edgeCount++;

        cout<<edgeVec[minEdgeIndex].m_iNodeIndexA<<"---"<<edgeVec[minEdgeIndex].m_iNodeIndexB<<" ";
        cout<<edgeVec[minEdgeIndex].m_iWeightValue<<endl;

    }



}

/**
 * 判断点是否在集合中
 * @param nodeSet
 * @param target
 * @return
 */
bool CMap::isInSet(vector<int> nodeSet,int target){
    for (int i = 0; i < nodeSet.size(); ++i) {
        if(nodeSet[i] == target){
            return true;
        }
    }
    return false;
}

/**
 * 合并两个集合
 * @param nodeSetA
 * @param nodeSetB
 */
void CMap::mergeNodeSet(vector<int> &nodeSetA,vector<int> nodeSetB){
    for (int i = 0; i < nodeSetB.size(); ++i) {
        nodeSetA.push_back(nodeSetB[i]);
    }
}
