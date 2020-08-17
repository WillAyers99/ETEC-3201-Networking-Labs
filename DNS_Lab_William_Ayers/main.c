//William Ayers
#include<stdio.h>
#include<stdlib.h>
#include <winsock2.h>
#include <ws2tcpip.h>

#ifndef NI_MAXHOST
#define NI_MAXHOST 1025
#endif

int main(void)
{
    WSADATA wsa;
    //Initialize Winsock.
    printf("\nInitialising Winsock...");
    if (WSAStartup(MAKEWORD(2,2),&wsa) != 0)
    {
        printf("Failed. Error Code : %d",WSAGetLastError());
        return 1;
    }
    printf("Initialised.\n");
    struct hostent * h_ent;
    unsigned int i;

    printf("Enter a domain name: ");
    char* domain;
    gets(domain);
    h_ent = gethostbyname(domain);
    printf("Official name: %s\n", h_ent->h_name);
    i=0;
    while(h_ent->h_aliases[i]!=NULL)
    {
        printf("alisa[%d]: %s\n",i,h_ent->h_aliases[i]);
        i++;
    }
    i=0;
    while(h_ent->h_addr_list[i]!=NULL)
    {
        printf("h_addr_list[%d]: %s\n",i,inet_ntoa(*(struct in_addr*)h_ent->h_addr_list[i]));
        i++;
    }
    WSACleanup();
    return 0;
}
