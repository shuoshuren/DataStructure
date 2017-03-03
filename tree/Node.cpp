//
// Created by xiao on 2017/2/6.
//
#include <iostream>
#include "Node.h"
using namespace std;

Node::Node() {
    index = 0;
    data = 0;
    pLChild = nullptr;
    pRChild = nullptr;
    pParent = nullptr;
}

Node * Node::searchNode(int nodeIndex){
    if(this->index == nodeIndex){
        return this;
    }
    Node *temp = nullptr;
    if(this->pLChild != nullptr){
        if(this->pLChild->index == nodeIndex){
            return this->pLChild;
        }else{
            temp = this->pLChild->searchNode(nodeIndex);
            if(temp != nullptr){
                return temp;
            }
        }
    }

    if(this->pRChild != nullptr){
        if(this->pRChild->index == nodeIndex){
            return this->pRChild;
        }else{
            temp = this->pRChild->searchNode(nodeIndex);
            return temp;

        }
    }

    return nullptr;

}

void Node::deleteNode() {
    if(this->pLChild != nullptr){
        this->pLChild->deleteNode();

    }

    if(this->pRChild != nullptr){
        this->pRChild->deleteNode();

    }

    if(this->pParent != nullptr){
        if(this->pParent->pLChild == this){
            this->pParent->pLChild = nullptr;
        }
        if(this->pParent->pRChild == this){
            this->pParent->pRChild = nullptr;
        }
    }
    delete this;

}

/**
 * 前序遍历
 */
void Node::preorderTraverse(){
    cout<<this->index<<"   "<<this->data<<endl;

    if(this->pLChild != nullptr){
        this->pLChild->preorderTraverse();
    }

    if(this->pLChild != nullptr){
        this->pLChild->preorderTraverse();
    }
}

/**
 * 中序遍历
 */
void Node::inorderTraverse(){


    if(this->pLChild != nullptr){
        this->pLChild->inorderTraverse();
    }

    cout<<this->index<<"   "<<this->data<<endl;

    if(this->pLChild != nullptr){
        this->pLChild->inorderTraverse();
    }
}

/**
 * 后序遍历
 */
void Node::postorderTraverse(){


    if(this->pLChild != nullptr){
        this->pLChild->postorderTraverse();
    }

    if(this->pLChild != nullptr){
        this->pLChild->postorderTraverse();
    }

    cout<<this->index<<"   "<<this->data<<endl;
}
