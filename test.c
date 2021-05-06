#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <limits.h>

#define PORT 1717
#define MAXLINE 1024
#define INT_MAX 999


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


int main(){
        char diff[1024] = {"DIFF"};
        char monid[1024] = "test";
        char bufftest[1024] = " ";
        char * messagetest = "blalalalal";
        int num_message = 0;
        char buff[MAXLINE];
        //char Message = [diff,monid];
        //num_message = countid(num_message);

        //bufftest == strcat(strcpy(bufftest,diff),messagetest);

        strcat(bufftest,monid);
        strcat(bufftest,messagetest ); //ajouter espace et faire des test pour voir si element et dans message
        strcat(bufftest,diff);
        
        //memcpy(bufftest,monid,1024);

        if(memmem(buff,MAXLINE,"STOP",5)){
        printf("test réussi");
    }
        
        
        printf(" %s",bufftest);

        char* resultat =  strstr(buff,"STOP");
        if( resultat == NULL) {
            printf("oups");
            }else{
            printf("nice");
            }


}
