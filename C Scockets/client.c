#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>


void *func();
void *func2();

int s;
int c;
char msg[256];
char msg_rec[256];
int n=0;

int main(int argc,char* argv[]){


    int port = atoi(argv[1]);

    struct sockaddr_in cli_adder;
        
    s = socket(AF_INET, SOCK_STREAM, 0);

    if (s<0)
        printf("Error socket\n");
    else
        printf("Socket connected\n");

    struct sockaddr_in serv_adder;
    int len = sizeof(serv_adder);
    serv_adder.sin_family = AF_INET;
    serv_adder.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_adder.sin_port = htons(port);

    c = connect(s, (struct sockaddr*)&serv_adder,len);

    if (c<0)
        printf("Error in connect\n");
    else
        printf("Connect successfull\n");


    pthread_t total[9];

    pthread_create(&total[0],NULL,func,NULL);
    pthread_create(&total[1],NULL,func2,NULL);
    pthread_join(total[1],NULL);
}

void *func(){
    while (1){
        fgets (msg, 100, stdin);
        n = write(s,msg,strlen(msg));
    }
    pthread_exit(0);
}
void *func2(){
    char bye[256]="exit";
    while (1){
        n = read(s, msg, 255);
        if(n<0)break;
        msg[n]='\0';
        printf("SERVER: %s",msg);
        if((strncmp(msg,bye,4)==0)&&(n==5)){    
            break;
        }
    }
    pthread_exit(0);
}
