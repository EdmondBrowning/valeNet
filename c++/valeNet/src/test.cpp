//
// Created by edmond on 18-8-10.
//

#include <sys/socket.h>

#include <sys/ioctl.h>

#include <netinet/if_ether.h>

#include <net/if.h>

#include <linux/sockios.h>

#include <stdio.h>

#include <string.h>
#include <unistd.h>


int main1() {

    char* device= const_cast<char *>("enp6s0"); //eth0是网卡设备名
    unsigned char macaddr[ETH_ALEN]; //ETH_ALEN（6）是MAC地址长度
    struct ifreq req;
    int err,i;
    int s=socket(AF_INET,SOCK_DGRAM,0); //internet协议族的数据报类型套接口
    strcpy(req.ifr_name,device); //将设备名作为输入参数传入
    err=ioctl(s,SIOCGIFHWADDR,&req); //执行取MAC地址操作
    close(s);
    if(err != -1)
    {
        memcpy(macaddr,req.ifr_hwaddr.sa_data,ETH_ALEN); //取输出的MAC地址
        for(i=0;i<ETH_ALEN;i++)
            printf("%02x\n",macaddr[i]);
    } else{
        printf("error");
    }

}