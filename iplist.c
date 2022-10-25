//Listing network adapters on Linux and macOS
//copyright(c)2022 vishal ahirwar. all rights reserved.
#include<sys/socket.h>
#include<netdb.h>
#include<ifaddrs.h>
#include<stdio.h>
#include<stdlib.h>

#define SUCCESS 0
#define FAILED -1

void ListAddresses(struct ifaddrs*);
struct ifaddrs* Getifaddrs_ptr();
void print();

int main(void)
{
    print();
    struct ifaddrs*addresses=Getifaddrs_ptr();
    ListAddresses(addresses);
    freeifaddrs(addresses);
    return SUCCESS;
};

void print()
{
    system("clear");
    printf("\n[utility created by vishal ahirwar]\n");
};

struct ifaddrs* Getifaddrs_ptr()
{
    struct ifaddrs*addresses=NULL;
    if(getifaddrs(&addresses)==-1)
    {
        printf("getifaddrs() call failed!\n");
        exit(EXIT_FAILURE);
    };
    return addresses;
}
void ListAddresses(struct ifaddrs*addresses)
{
       //going through the addresses linked list
    struct ifaddrs*address=addresses;
    while(address)
    {
        int family=address->ifa_addr->sa_family;
        if(family==AF_INET || family==AF_INET6)
        {
            printf("[name] : \t\t%s\n",address->ifa_name);
            printf("[family] : \t\t%s\n",family==AF_INET?"IPv4":"IPv6");
            const int family_size=family==AF_INET?sizeof(struct sockaddr_in):sizeof(struct sockaddr_in6);
            char nameinfo[100];
            getnameinfo(address->ifa_addr,family_size,nameinfo,sizeof(nameinfo),0,0,NI_NUMERICHOST);
            printf("[IP] : \t\t%s\n",nameinfo);
            printf("\n--------------------------------------------\n");
        };
        address=address->ifa_next;
    };
};
