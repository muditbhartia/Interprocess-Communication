#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>


void *func();
void *func2(void *args);
void *handle(void *args);

char msg[256];
int n=0;
int l=255;
char msg_send[255];
int s;
int sd2;
socklen_t clilen;
int a;

int main(int argc,char* argv[]){

    int port = atoi(argv[1]);

    s = socket(AF_INET, SOCK_STREAM, 0);
    if (s>0)
        printf("Socket created successfully %d\n",s);
    else
        printf("Unable to create Socket");

    struct sockaddr_in servaddr, cli_adder;
    servaddr.sin_family=AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(port);
    
    sd2=bind(s ,(struct sockaddr*) &servaddr, sizeof(servaddr));
    if (sd2<0)
        printf("Cant Bind\n");
    else
        printf("Binded %d\n",sd2);

    listen(s,5);
	char ip[30];
    clilen = sizeof(cli_adder);
    while((a = accept(s, (struct sockaddr*) &cli_adder, &clilen))>0)
    {
    	strcpy(ip,inet_ntoa(cli_adder.sin_addr));
    	printf("IP address is: %s\n", ip);
    	printf("port is: %d\n", (int)ntohs(cli_adder.sin_port));
    	pthread_t conn[9];
    	pthread_create(&conn[0],NULL,handle,(void *)ip);
    }
    if (a<0)
   		printf("Cant accept\n");
   	else
   		printf("accepted\n");
   
}
void *handle(void *args)
{
	pthread_t total[9];
    pthread_create(&total[0],NULL,func,NULL);
    pthread_create(&total[1],NULL,func2,(void *)args);
    pthread_join(total[1],NULL);
    pthread_exit(0);
   
}
void *func()
{	
	while (1){
        fgets (msg, 100, stdin); 		       
        n = write(a,msg,strlen(msg));
    }
    pthread_exit(0);
}
void *func2(void *args)
{
	char initm[30];
	strcpy(initm,"CLIENT ");
	char *ip = (char *) args;
	strcat(initm,ip); 
    char bye[10]="exit";
    while (1){
        n = read(a, msg, l);
        if(n<0)
        break;
        msg[n]='\0';
        printf("%s : %s",initm,msg);
        if((strncmp(msg,bye,4)==0)&&(n==5)){    
            break;
        }
    }
    pthread_exit(0);
}
