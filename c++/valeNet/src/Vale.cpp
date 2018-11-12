//
// Created by edmond on 18-6-7.
//

#include <iostream>
#include <unistd.h>
#include "p2p/kad/VKad.h"
#include "p2p/kad/VSHA1.h"
#include <bitset>
#include "tools/Mac.h"

using namespace std;

int main(){
//    auto * vProcess = new MyProcess();
//    vProcess->start();
//    wily::VKad* vKad = wily::VKad::getInstance();
    wily::VSHA1 sha1;

    wily::VKad* vKad = wily::VKad::getInstance();

    auto * vNode = new wily::VNode("192.168.0.1",sha1.getSHA1(wily::Mac().get_mac()));
    vKad->addNode(vNode);

    auto* vResource = new wily::VResource();
    cout<<vKad->findNearLestNode(vResource)<<endl;
//
    cout<<(sha1.getSHA1(wily::Mac().get_mac()))<<endl;
}


