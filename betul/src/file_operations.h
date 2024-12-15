#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H

void create_file(const char *filename);
void delete_file(const char *filename);
void copy_file(const char *source, const char *destination);
void move_file(const char *source, const char *destination);
void display_file(const char *filename);

#endif

