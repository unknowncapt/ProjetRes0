#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 1717
#define MAXLINE 1024

int main(int argc, char **argv)
{
    int socketsama;
    char buff[MAXLINE];
    struct sockaddr_in server;

    socketsama = socket(AF_INET, SOCK_DGRAM, 0);
   // bzero(buff, MAXLINE); //initialise à 0 buff

    if (socketsama == -1)
    {
        printf("erreur socket");
        exit(0);
    }
    else
    {
        printf("nice socket crée\n");
    }

    memset(&server, 0, sizeof(server));
    //memset(&client, 0, sizeof(client));

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(1717);


    printf("waiting...\n");
    int len, reception, testreceiv;

    len = sizeof(server);
   

        char *hello = "STOP";
        
        //int sendu = sendto(socketsama, hello, strlen(hello), 0, (struct sockaddr *)&server, len);
        //int recvu = recvfrom(socketsama, buff, sizeof(buff), 0, (struct sockaddr *)&server, &len);
        //printf("message envoyé");

    
 
        sendto(socketsama, hello, strlen(hello), 0, (struct sockaddr *)&server, len);
        printf("message envoyé \n");
        reception = recvfrom(socketsama, buff, sizeof(buff), 0, (struct sockaddr *)&server, &len);
        buff[reception] = '\0';
        printf("réponse du Server : %s\n", buff);

//test pour recevoir en continue un message envoyé par le serveur
//         while (1){
//        testreceiv = recvfrom(socketsama, buff, sizeof(buff), 0, (struct sockaddr *)&server, &len);
//        buff[testreceiv] = '\0';
//        printf("réponse du Server : %s\n", buff);
//       }


    close(socketsama);
    return 0;
}