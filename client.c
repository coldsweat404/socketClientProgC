#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

#define port 8084

int main(int argc, char *argv[])
{
	int descripteur;
	socklen_t taille;
	struct sockaddr_in host;

	//Creation de la socket, si cela echoue, quitter le programme

	descripteur = socket(PF_INET, SOCK_STREAM, 0);
	if(descripteur == -1)
	{
		perror("Creation de la socket impossible");
		exit(EXIT_FAILURE);
	}

	//Creation du contexte d'adressage

	host.sin_family = PF_INET;
	host.sin_port = htons(port);
	host.sin_addr.s_addr = inet_addr("127.0.0.1"); //Adress LocalHost

	return EXIT_SUCCESS;
}
