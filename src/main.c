#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {


    if (argc != 2) {
        printf("please enter exactly one command, in quotes if necessary\n");
        return -1;
    }
    // when run with an effective ID of 0, this will set ALL the uids (real, effective etc)
    // for the process to 0. without this, real uid remain non-zero and filesystem checks
    // will fail for us
    if (setuid(0)!=0) {
        printf("unable to become root, is %s owned by root and the SUID bit set?\n", argv[0]);
        printf("sudo chown root:root %s\n", argv[0]);
        printf("sudo chmod +s %s\n", argv[0]);
        return -1;
    }
    system(argv[1]);
}
