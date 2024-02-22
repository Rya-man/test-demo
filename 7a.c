#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <time.h>
#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    struct dirent *dir;
    struct stat ms;
    DIR *dp;

    dp = opendir(".");
    if (dp) {
        while ((dir = readdir(dp)) != NULL) {
            stat(dir->d_name, &ms);
            printf("%ld  %d  %d  %ld  %lu  %s  %s \n", ms.st_ino, ms.st_uid, ms.st_gid, (long)ms.st_size, (unsigned long)ms.st_nlink, ctime(&ms.st_atime), dir->d_name);
            printf("\nfile permissions user\t");
            printf((ms.st_mode & S_IRUSR) ? "R" : "-");
            printf((ms.st_mode & S_IWUSR) ? "W" : "-");
            printf((ms.st_mode & S_IXUSR) ? "X" : "-");
            printf("\n");
            printf("\nfile permissions group\t");
            printf((ms.st_mode & S_IRGRP) ? "R" : "-");
            printf((ms.st_mode & S_IWGRP) ? "W" : "-");
            printf((ms.st_mode & S_IXGRP) ? "X" : "-");
            printf("\n");
            printf("\nfile permissions other\t");
            printf((ms.st_mode & S_IROTH) ? "R" : "-");
            printf((ms.st_mode & S_IWOTH) ? "W" : "-");
            printf((ms.st_mode & S_IXOTH) ? "X" : "-");
            printf("\n");
        }
        closedir(dp);
    }
    return 0;
}
