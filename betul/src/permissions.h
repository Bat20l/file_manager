#ifndef PERMISSIONS_H
#define PERMISSIONS_H

#include <sys/stat.h>

void change_permissions(const char *filename, mode_t mode);

#endif

