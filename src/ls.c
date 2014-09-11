#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc, char* argv[])
{
    DIR *dir;
    struct dirent *file;
    struct stat lstat;
    if(argc < 2) {
    dir = opendir(".");
    }
    else {
    dir = opendir(argv[1]);
    }
    while((file = readdir(dir)) != NULL)
    {
        stat(file->d_name, &lstat);
        printf("%s\n", file->d_name);
    }
    closedir(dir);
}
