#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
int main(void)
{
    char * filePath = "myfile.txt";
    /**
     * If the open function ends with success, returns the file descriptor otherwise -1.
    */
    if((open(filePath, O_RDONLY)) == -1)
    {
        /**
        *   If the file cannot be opened. The "open" function will pass error number to global "errno" variable.
        * For unix/linux system there isn't a standartization for system error number. So "switch case" statment 
        * with "errno" expression will not be portable. Because the exact same error number may refer 
        * different error expression for various unix/linux systems. Assume that Linux system A have "Access Denied"
        * error with error number "9" and other linux system B may have "Access Denied" error with error number "11".
        * Practically, Using the posix "strerror" function will return the error expression that is dedicated to error no.
        * In this situation using "strerror" is usefull.
        */
        fprintf(stderr,"open: %s\n", strerror(errno));
        /**
         * Terminate program with failure.
        */
        exit(EXIT_FAILURE);
    }
    printf("%s file opened.\n",filePath);
    return EXIT_SUCCESS;
}