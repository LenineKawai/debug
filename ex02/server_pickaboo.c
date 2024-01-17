#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


// THIS PROGRAM SHOULD MAKE AN INFITE LOOP

int main(int ac, char **av)
{
    int serverFd;
    struct sockaddr_in serverAddr;

    if (ac != 2)
    {
        printf("gimme a port above 1000 plz\n");
    }

    serverFd = socket(AF_INET, SOCK_STREAM, -1);
    if (serverFd < 0)
        exit (1);

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    serverAddr.sin_port = htons(atoi(av[1]));

    if (bind(serverFd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == 0) 
        exit (2);
    
    if (listen(serverFd, 4096) < 0)
        exit (3);
    
    while (1)
    {
        ;
    }
}