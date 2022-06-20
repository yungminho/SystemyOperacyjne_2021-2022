#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    int PID = getpid();
    int PPID = getppid();
    int PGID = getpgid(PID);

    printf("Parent Process:\nPID:   %d\nPPID:  %d\nPGID:  %d\n", PID, PPID, PGID);
    
    for(int i = 0; i < 3; i++){
        switch(fork()){
            case -1:
                perror("ERROR: fork error\n");
                exit(EXIT_FAILURE);
            case 0:
                /* Child Process */

                PID = getpid();
                PPID = getppid();
                PGID = getpgid(PID);

                printf("Child Process:\nPID:   %d\nPPID:  %d\nPGID:  %d\n", PID, PPID, PGID);



                break;
            default:
                /* Parent Process */
                sleep(5 - i);
                break;
        }
    }

    return 0;
}
