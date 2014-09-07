/**************************************
 *  
 *  Project 1
 *      by Will Nasby & Iosif Vilcea
 *
 **************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){

    // PROMPT
    //  -uses unistd.h library.
    //  -gets HostName, LoginName and absolute path of Working Directory.

    char hostName[30];
    gethostname(hostName, 30);

    char *loginName = getlogin();

    char workingDir[255];
    getcwd(workingDir, 255);

    // FORMAT:
    //  <username>@<hostname>:<working.directory> $
    printf("<%s>@<%s>:<%s> $ " , loginName , hostName , workingDir);

    //
    // TODO: Everything.
    //

	return EXIT_SUCCESS;
}
