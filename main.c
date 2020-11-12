#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>

/**
 * @brief The Developer should handle every function return value(Ofcourse there are some exceptions).
 * So to decrease line count exit_sys wrapper function can be used. 
 * 
 * @param msg The message will be written output stream with dedicated error expression.
 * 
*/
void exit_sys(const char * msg);

int main(void)
{
    char * filePath = "myfile.txt";
    /**
     * If the open function ends with success, returns the file descriptor otherwise -1.
    */
    if((open(filePath, O_RDONLY)) == -1)
        exit_sys("open");
    
    printf("%s file opened.\n",filePath);
    return EXIT_SUCCESS;
}

void exit_sys(const char * msg)
{
    perror(msg);
    exit(EXIT_FAILURE);
}
