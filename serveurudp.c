#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <limits.h>
#define _GNU_SOURCE

#define PORT 1717
#define MAXLINE 1024
#define INT_MAX 999

//#define RAND_MAX 30

//count nb_message 
int countid(int valeur){
    while (valeur >= 0){
        if(valeur == INT_MAX){
        printf("NOMBRE MAX DE MESSAGE \n");
        //valeur = 0;
        }
    valeur++;
    }
    return 0;
}

void *memmem(const void *haystack, size_t hlen, const void *needle, size_t nlen)
{
    int needle_first;
    const void *p = haystack;
    size_t plen = hlen;

    if (!nlen)
        return NULL;

    needle_first = *(unsigned char *)needle;

    while (plen >= nlen && (p = memchr(p, needle_first, plen - nlen + 1)))
    {
        if (!memcmp(p, needle, nlen))
            return (void *)p;

        p++;
        plen = hlen - (p - haystack);
    }

    return NULL;
}

int findPattern (const char *buffer, size_t bufSize, const char *pattern)
{
    int i,j;
    int patternLen;


    patternLen = strlen (pattern);

    for (i=0; i<bufSize-patternLen; ++i)
    {
        for (j=0; j<patternLen; ++j)
        {
            if (buffer[i+j] != pattern[j])
            {
                break;
            }
        }
        if (j == patternLen)
        {
            return i;
        }
    }
    return -1;
}



int main(int argc, char **argv)
{
    int Mastersocket;
    int NEWsocket;
    char buff[MAXLINE];
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
    //int len, reception;

    
    //permet de récup ip port adresse  A STOCKER DANS UN BUFFER DÉDIER
    getpeername(Mastersocket , (struct sockaddr*)&server , (socklen_t*)&taille);  
                    printf("Server info , ip %s , port %d \n" , 
                          inet_ntoa(server.sin_addr) , ntohs(server.sin_port)); 




     //on fait des test
        char diff[1024] = {"DIFF"};
        char monid[1024] = "test /0";
        char bufftest[MAXLINE];
        char * messagetest = "blalalalal";
        int num_message = 0;
        num_message = countid(num_message);

        bufftest == strcat(strcpy(bufftest,diff),messagetest);
        printf("test %s \n",bufftest);
        //strcpy(bufftest," ");
        //strcat(bufftest,monid);
        //strcat(bufftest,diff);

        char *hello = "Hello";
        char  recvu = recvfrom(Mastersocket, (char *) buff, MAXLINE, 0, (struct sockaddr *)&server, &taille);
        buff[recvu] = '\0';
        printf(" message Client : %s\n", buff);
        sendto(Mastersocket, hello, strlen(hello), 0, (struct sockaddr *)&server, taille);
        printf("message envoyé\n");

        //récupere le info du dernier client connecter au socket
         getpeername(Mastersocket , (struct sockaddr*)&server , (socklen_t*)&taille);  
                    printf("CLient information , ip %s , port %d \n" , 
                          inet_ntoa(server.sin_addr) , ntohs(server.sin_port)); 
    while (1){

       /* int valread;
        valread = read(Mastersocket,buff,1024);
        if (valread = read(Mastersocket,buff,1024) != 0)
        {
            printf("test %s",valread);
        } */

       //envoimessage TOUT MIS EN COMMENTAIRE POUR L'INSTANT DE MEME POUR LA BOUCLE WHILE DANS CLIENTUDP
        char envoibis[1024];
        printf("entrer votre message \n");
        scanf("%s\n",buff);
        sendto(Mastersocket,envoibis,strlen(envoibis),0,(struct sockaddr *)&server, taille);
        printf("Message envoyé \n");

    //aucun retour :/
     if(findPattern(buff,MAXLINE,"STOP")){
        printf("test réussi");
    }

        char* resultat =  strstr(buff,"STOP");
        if( resultat == NULL) {
            printf("oups");
            }else{
            printf("nice");
            }

        //TEST pour stocker adresse et port dans un chaine
        //char stuff[MAXLINE];
        //char *chaine = "tess";
        //chaine[0] = "ntohs(server.sin_port)";
        //stuff[0] = '\0';
        //strcat( strcat (strcpy(stuff,inet_ntoa(server.sin_addr))," "),chaine);
        //strcat(stuff, chaine);
       // printf(" truc %s",stuff);




       



    }
    //close(Mastersocket);
    return 0;
}

