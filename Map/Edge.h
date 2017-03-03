//
// Created by xiao on 2017/2/7.
//

#ifndef MAP_EDGE_H
#define MAP_EDGE_H

/**
 * 边
 */
class Edge {
public:

    Edge(int nodeIndexA=0,int nodeIndexB=0,int weightValue=0);


    int m_iNodeIndexA;
    int m_iNodeIndexB;
    int m_iWeightValue;
    bool m_bSelected;

};


#endif //MAP_EDGE_H
