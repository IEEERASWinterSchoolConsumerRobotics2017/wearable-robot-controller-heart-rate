#include "view.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <wearable-robot-controller-heart-rate.h>


void *user_data = NULL;

/* UDP */
int udp_sockfd;
int udp_serverlen;
struct sockaddr_in udp_serveraddr;
struct hostent *udp_server;
//char *udp_the_ip = "104.131.47.73";
char *udp_the_ip = "10.18.81.7";
int udp_portno = 2362;

#define SRV_IP "999.999.999.999"

#define BUFSIZE 1024



void print_debug(int x, int y)
{
	/* debug location */
	char debug_buff[256];
	snprintf(debug_buff, 256, "x = %d  y = %d", x, y);


	dlog_print(DLOG_ERROR, LOG_TAG, "*******dan test %d", 42);
	dlog_print(DLOG_ERROR, LOG_TAG, "************************************************");
	dlog_print(DLOG_ERROR, LOG_TAG, "************************************************");
	dlog_print(DLOG_ERROR, LOG_TAG, "************************************************");
	dlog_print(DLOG_ERROR, LOG_TAG, debug_buff);
	dlog_print(DLOG_ERROR, LOG_TAG, "************************************************");
	dlog_print(DLOG_ERROR, LOG_TAG, "************************************************");
	dlog_print(DLOG_ERROR, LOG_TAG, "************************************************");
}

void print_debugf(float x)
{
	/* debug location */
	char debug_buff[256];
	snprintf(debug_buff, 256, "%f", x);


	dlog_print(DLOG_ERROR, LOG_TAG, "*******dan test %d", 42);
	dlog_print(DLOG_ERROR, LOG_TAG, "************************************************");
	dlog_print(DLOG_ERROR, LOG_TAG, "************************************************");
	dlog_print(DLOG_ERROR, LOG_TAG, "************************************************");
	dlog_print(DLOG_ERROR, LOG_TAG, debug_buff);
	dlog_print(DLOG_ERROR, LOG_TAG, "************************************************");
	dlog_print(DLOG_ERROR, LOG_TAG, "************************************************");
	dlog_print(DLOG_ERROR, LOG_TAG, "************************************************");
}

void error(char *msg) {

	dlog_print(DLOG_ERROR, LOG_TAG, "************************************************");
	dlog_print(DLOG_ERROR, LOG_TAG, "************************************************");
	dlog_print(DLOG_ERROR, LOG_TAG, "************************************************");
	dlog_print(DLOG_ERROR, LOG_TAG, msg);
	dlog_print(DLOG_ERROR, LOG_TAG, "************************************************");
	dlog_print(DLOG_ERROR, LOG_TAG, "************************************************");
	dlog_print(DLOG_ERROR, LOG_TAG, "************************************************");
    //exit(0);
}

void eprint(char *msg) {

	dlog_print(DLOG_ERROR, LOG_TAG, "************************************************");
	dlog_print(DLOG_ERROR, LOG_TAG, "************************************************");
	dlog_print(DLOG_ERROR, LOG_TAG, "************************************************");
	dlog_print(DLOG_ERROR, LOG_TAG, msg);
	dlog_print(DLOG_ERROR, LOG_TAG, "************************************************");
	dlog_print(DLOG_ERROR, LOG_TAG, "************************************************");
	dlog_print(DLOG_ERROR, LOG_TAG, "************************************************");
    //exit(0);
}




int send_udp_one(void)
{

    int sockfd, n;
    int serverlen;
    struct sockaddr_in serveraddr;
    struct hostent *server;
    char *the_ip = "104.131.47.73";
    int portno = 2362;
    //CURL *curl;
    //CURLcode res;
    //curl_socket_t sockfd;
//    char buf[BUFSIZE];


    /* socket: create the socket */
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    /* build the server's Internet address */
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = inet_addr(the_ip);
    serveraddr.sin_port = htons(portno);

    /* get a message from the user */
    char *buf = "hello robot\n\r";

    /* send the message to the server */
    serverlen = sizeof(serveraddr);
    n = sendto(sockfd, buf, strlen(buf), 0, &serveraddr, serverlen);
    //n = sendto(sockfd, buf, strlen(buf), MSG_DONTWAIT, &serveraddr, serverlen);

    if (n < 0)
      error("ERROR in sendto");


    /* print the server's reply */
/*
    n = recvfrom(sockfd, buf, strlen(buf), 0, &serveraddr, &serverlen);
    if (n < 0)
      error("ERROR in recvfrom");
    printf("Echo from server: %s", buf);
 */
    return 0;


}




int init_udp(void)
{
    /* socket: create the socket */
    udp_sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (udp_sockfd < 0)
    {
        error("ERROR opening socket");
        return -1;
    }

    /* build the server's Internet address */
    udp_serveraddr.sin_family = AF_INET;
    udp_serveraddr.sin_addr.s_addr = inet_addr(udp_the_ip);
    udp_serveraddr.sin_port = htons(udp_portno);

    udp_serverlen = sizeof(udp_serveraddr);

    return 0;

}

int send_udp(float x)
{
    /* get a message from the user */
    char buf[256];

	char *s1 = "heart rate";

	snprintf(buf, 256, "%s %.3f", s1, x);


    /* send the message to the server */
    int n = sendto(udp_sockfd, buf, strlen(buf), 0, &udp_serveraddr, udp_serverlen);
//    n = sendto(sockfd, buf, strlen(buf), MSG_DONTWAIT, &serveraddr, serverlen);

    if (n < 0)
      error("ERROR in sendto");

    return 0;


}
