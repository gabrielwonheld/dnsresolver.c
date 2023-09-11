// fazendo um DNS resolver, como o proprio nome diz

#include <stdio.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>


int main(int argc, char *argv[]){

//              printf("             Nixcoder \n");

        if(argc <= 1){

                printf("Exemplo de uso -> ./dnsresolver www.exemple.com \n");
        }else{

                struct hostent *alvo = gethostbyname(argv[1]);


                if (alvo == NULL){

                        printf("Ocorreu um erro...\n");

                }else{
                        int i = 0;

                        while(alvo -> h_addr_list[i]!=NULL){

                                struct in_addr *address = (struct in_addr *)alvo->h_addr_list[i];
                                printf("%s ==> IP: %s\n",argv[1], inet_ntoa(*address));
                                i++;

                        }
                }
        }
return 0;
}
