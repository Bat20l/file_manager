#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include "logger.h"

void list_directory(const char *path) {
    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("Unable to read directory");
        log_operation("List Directory", "Failed");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }
    closedir(dir);
    log_operation("List Directory", "Success");
}

void search_file(const char *directory, const char *filename) {
    DIR *dir = opendir(directory);
    if (dir == NULL) {
        perror("Unable to open directory");
        log_operation("Search File", "Failed");
        return;
    }

    struct dirent *entry;
    int found = 0;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, filename) == 0) {
            printf("File found: %s/%s\n", directory, filename);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("File not found in directory: %s\n", directory);
    }
    closedir(dir);
    log_operation("Search File", found ? "Success" : "Failed");
}

