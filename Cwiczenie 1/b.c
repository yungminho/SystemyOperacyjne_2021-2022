#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){

    int UID = getuid();
    int GID = getgid();
    int PID = getpid();
    int PPID = getppid();
    int PGID = getpgid(PID);

    printf("Parent Process:  UID:   %d | GID:   %d | PID:   %d | PPID:  %d | PGID:  %d\n", UID, GID, PID, PPID, PGID);
        
    for(int i = 0; i < 4; i++){
        switch(fork()){
            case -1:
                perror("ERROR: fork error\n");
                exit(EXIT_FAILURE);
            case 0:
                /* Child Process */
                UID = getuid();
                GID = getgid();
                PID = getpid();
                PPID = getppid();
                PGID = getpgid(PID);

                printf("Child Process:  UID:   %d | GID:   %d | PID:   %d | PPID:  %d | PGID:  %d\n", UID, GID, PID, PPID, PGID);
                break;
            default:
                /* Parent Process */
                if(wait(NULL) == -1){
                    perror("ERROR: wait error\n");
                    exit(EXIT_FAILURE);
                }
                break;
        }
    }

    return 0;
}
