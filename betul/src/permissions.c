#include <stdio.h>
#include <sys/stat.h>
#include "logger.h"

void change_permissions(const char *filename, mode_t mode) {
    if (chmod(filename, mode) < 0) {
        perror("Error changing permissions");
        log_operation("Change Permissions", "Failed");
    } else {
        printf("Permissions changed for: %s\n", filename);
        log_operation("Change Permissions", "Success");
    }
}

