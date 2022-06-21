#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]){

    if(argc != 2){
        perror("ERROR: Wrong number of arguments\n");
        exit(EXIT_FAILURE);
    }

    char dir[strlen(argv[1]) + 2];
    strcpy(dir, "./");
    strcat(dir, argv[1]);

    for(int i = 0; i < 3; i++){
        switch(fork()){
            case -1:
                perror("ERROR: fork error\n");
                exit(EXIT_FAILURE);
            case 0:
                /* Child Process */
                execlp(dir, argv[1], NULL);
                perror("ERROR: execlp error\n");
                _exit(EXIT_FAILURE);
            default:
                /* Parent Process */
                if(wait(NULL) == -1){
                    perror("ERROR: wait error\n");
                    exit(EXIT_FAILURE);
                }
                break;
        }
    }
    execlp(dir, argv[1], NULL);
    return 0;
}
