#include <stdio.h>
#include <winsock2.h>
#define msg_len 5000
int main(int argc , char *argv[])
{
    WSADATA wsa;
    int recv_size;
    //Initialize Winsock.
    printf("\nInitialising Winsock...");
    if (WSAStartup(MAKEWORD(2,2),&wsa) != 0)
    {
        printf("Failed. Error Code : %d",WSAGetLastError());
        return 1;
    }
    printf("Initialised.\n");

    //Create a socket
    int mySocket=0, newSocket;
    struct sockaddr_in my_addr;
    struct sockaddr_in their_addr;
    int their_addr_size;

    if((mySocket = socket(AF_INET, SOCK_STREAM, 0))==-1)
    {
        printf("Error: could not create socket.\n");
        return -1;
    }
    printf("Socket Created.\n");
    //fill in address structure
    my_addr.sin_addr.s_addr = 0;    //use default local address
    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(0x1234);
    //bind to address
    if(bind(mySocket,(struct sockaddr *)&my_addr,sizeof(struct sockaddr))==-1)
    {
        printf("Error: could not bind.\n");
        return -1;
    }
    printf("Socket Bound.\n");

    //listen with a back-log of 10 pending connections.
    if(listen(mySocket,10)==-1)
    {
        printf("Error: Could not listen.\n");
        return -1;
    }
    printf("Socket listening.\n");

    //accept connections
    their_addr_size=sizeof(their_addr);
    newSocket=accept(mySocket,(struct sockaddr*)&their_addr,&their_addr_size);
    printf("Connection accepted.\n");

    //do something with the connected socket here.

    char *message[msg_len];
    if((recv_size = recv(newSocket, message, msg_len, 0))==SOCKET_ERROR)
    {
        printf("Error: recv failed. Code=%d\n", recv_size);
        return -1;
    }
    printf("Message received. Bytes received = %d\n",WSAGetLastError());
    printf("%s\n",message);

    closesocket(mySocket);
    WSACleanup();

    return 0;
}

