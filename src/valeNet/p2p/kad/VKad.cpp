//
// Created by edmond on 18-8-6.
//

#include "VKad.h"
#include "VSHA1.h"

namespace wily {

    VKad::VKad() {
        this->bucketList = new std::array<VKBucket* ,160>();
        this->vResourceTable = new VResourceTable();
        this->selfNode = new VNode();
    }

    void* VKad::findNearLestNode(VResource* vResource) {
        return findNearLestNode(vResource->getRid());
    }


    /**
     * 选取若干个距离资源节点最近的节点发送查询请求
     * @param rid
     * @return
     */
    void* VKad::findNearLestNode(std::bitset<160> rid) {
        VKBucket* vkBucket = (*this->bucketList)[0];
        return vkBucket->findVNode(rid);
    }

    /***
     * 1、选择对应的K桶
     * 2、判断K桶是否已满
     *      1、如果K桶未满，直接加新节点加入到K桶的末尾
     *      2、如果K桶已满，判断头部节点是否有响应，
     *          1、如果存在响应，丢弃当前节点信息，并且将头部节点移至K桶末尾
     *          2、头部节点不存在响应，移除头部节点，将当前节点加入至K桶末尾
     * @param vNode
     */
    void VKad::addNode(VNode* vNode) {
        (*this->bucketList)[0]->addVNode(vNode);
    }

    VKad::~VKad(){
        delete(this->bucketList);
        delete(this->vResourceTable);
    }

    VKad* VKad::getInstance() {
        static VKad instance;
        return &instance;
    }

    VResource* VKad::findResource(std::bitset<160> rid) {
        return this->vResourceTable->findResource(rid);
    }

    VResource* VKad::findResource(VResource *vResource) {
        return this->findResource(vResource->getRid());
    }
}