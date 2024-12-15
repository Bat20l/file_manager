#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "logger.h"

void create_file(const char *filename) {
    int fd = creat(filename, S_IRUSR | S_IWUSR);
    if (fd < 0) {
        perror("Error creating file");
        log_operation("Create File", "Failed");
    } else {
        printf("File created: %s\n", filename);
        close(fd);
        log_operation("Create File", "Success");
    }
}

void delete_file(const char *filename) {
    if (unlink(filename) < 0) {
        perror("Error deleting file");
        log_operation("Delete File", "Failed");
    } else {
        printf("File deleted: %s\n", filename);
        log_operation("Delete File", "Success");
    }
}

void copy_file(const char *source, const char *destination) {
    FILE *src = fopen(source, "r");
    FILE *dest = fopen(destination, "w");
    if (src == NULL || dest == NULL) {
        perror("Error copying file");
        log_operation("Copy File", "Failed");
        return;
    }

    char buffer[1024];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, bytes, dest);
    }

    fclose(src);
    fclose(dest);
    printf("File copied from %s to %s\n", source, destination);
    log_operation("Copy File", "Success");
}

void move_file(const char *source, const char *destination) {
    if (rename(source, destination) < 0) {
        perror("Error moving file");
        log_operation("Move File", "Failed");
    } else {
        printf("File moved from %s to %s\n", source, destination);
        log_operation("Move File", "Success");
    }
}

void display_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        log_operation("Display File", "Failed");
        return;
    }

    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    fclose(file);
    printf("\n");
    log_operation("Display File", "Success");
}

