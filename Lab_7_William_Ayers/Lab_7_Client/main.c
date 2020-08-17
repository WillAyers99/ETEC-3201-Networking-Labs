#include <stdio.h>
#include <winsock2.h>
#define msg_len 5000
int main()
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

    int mySocket=0;
    struct sockaddr_in server;

    //create a socket
    if((mySocket = socket(AF_INET, SOCK_STREAM, 0 )) == -1)
    {
        printf("Error: could not create socket.\n");
    }
    printf("Socket Created.\n");

    //fill in address structure.
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(0x1234);

    //connect to server
    if (connect(mySocket, (struct sockaddr*)&server, sizeof(server)) < 0)
    {
        printf("Error: couldn't connect.\n");
        return -1;
    }
    printf("Connected!\n");
    //do something with the connected socket here
    char * message = "Watson can you hear me?";
    if (send(mySocket, message, strlen(message), 0) < 0)
    {
        printf("Send failed. Code=%d\n", WSAGetLastError());
        return -1;
    }
    printf("Data Sent\n");

    closesocket(mySocket);

    WSACleanup();

    return 0;
}
