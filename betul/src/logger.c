#include <stdio.h>
#include <time.h>

void log_operation(const char *operation, const char *result) {
    FILE *logfile = fopen("logs/operations.log", "a");
    if (logfile == NULL) {
        perror("Error opening log file");
        return;
    }

    time_t now = time(NULL);
    fprintf(logfile, "%s: %s - %s\n", ctime(&now), operation, result);
    fclose(logfile);
}


