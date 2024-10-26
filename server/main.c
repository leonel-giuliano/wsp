#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>
#include <string.h>

#include "server.h"
#include "key.h"
#include "errnum.h"


int main(void) {
    int                 e = 0;
    int                 servfd;
    volatile char       ch_exit = '\0';
    struct sockaddr_in  servaddr;
    pthread_t           th_key;


    if((servfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
        return errnum(ERR_NEW_SCK);

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SERV_PORT);

    if(bind(servfd, (struct sockaddr *)&servaddr, sizeof(servaddr))) {
        e = errnum(ERR_BIND);
        goto close_servfd;
    }

    if(listen(servfd, SERV_BACKLOG)) {
        e = errnum(ERR_LISTEN);
        goto close_servfd;
    }


    e = pthread_create(&th_key, NULL, th_key_handler, (void *)&ch_exit);
    if(e) {
        errnum(ERR_NEW_TH);
        goto close_servfd;
    }


    close_servfd:
        if(close(servfd)) e = errnum(ERR_CLOSE_SCK);

        return e;
}
