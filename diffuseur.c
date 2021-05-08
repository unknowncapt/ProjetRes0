#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <limits.h>

#define MAXLINE 1024



int main(int argc, char **argv)
{
    int Mastersocket;
    int NEWsocket;
    char buffdiff[MAXLINE];
    struct sockaddr_in server, client;
    socklen_t taille;
    taille = sizeof(server);


    Mastersocket = socket(AF_INET, SOCK_DGRAM, 0);
   // bzero(buff, MAXLINE); //initialise à 0 buff

    if (Mastersocket == -1)
    {
        printf("erreur socket \n");
        exit(0);
    }
    printf("nice socket crée\n");

    memset(&server, 0, sizeof(server));
    memset(&client,0,sizeof(client));

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(1717);

    if (bind(Mastersocket, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        perror("ERROR de binding");
        exit(1);
    }
    printf("bind fait \n");

    printf("waitinguss...\n");

    char myIP[INET_ADDRSTRLEN];
    int myPORT= ntohs(server.sin_port);
    inet_ntop(AF_INET,&server,myIP,INET_ADDRSTRLEN);//convertie l'ip en string
    printf("ip server %s \n",myIP);
    printf("my port %d \n", myPORT);


      while (1){
           char diff[1024] = {"DIFF"};
            char monid[1024] = "test /0";
            char bufftest[MAXLINE];

          int num_message = 0;
         char  recvu = recvfrom(Mastersocket, (char *) buffdiff, MAXLINE, 0, (struct sockaddr *)&server, &taille);
         if (recvu != 0 ){

             char * ipconnected;
             char * portconnected;
             ipconnected = inet_ntoa(server.sin_addr);
             portconnected = ntohs(server.sin_port); 
             char messagerecv = recvu; // stock message recu

         }
         //l'objectif c'est [DIFF␣num-mess␣id␣message]
        printf("entrer votre message à diffuser \n");
        scanf("%s\n",buffdiff); //stock message du diffuseru dans buffdiff
        num_message ++;
        strcat(diff, num_message); //Diff + "" + num
        strcat(diff,monid);//Diff + "" + num + " "+ id
        bufftest == strcat(strcpy(bufftest,diff),buffdiff);//Diff + "" + num + " "+ id + " " +  message
        sendto(Mastersocket,buffdiff,strlen(buffdiff),0,(struct sockaddr *)&server, taille);
        printf("Message envoyé \n"); 

        


      }


}