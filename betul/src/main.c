#include <stdio.h>
#include "directory_ops.h"
#include "file_operations.h"
#include "permissions.h"
#include "logger.h"

int main() {
    int choice;
    char path1[256], path2[256];

    while (1) {
        printf("\n=== Terminal File Manager ===\n");
        printf("1. List Directory\n");
        printf("2. Create File\n");
        printf("3. Delete File\n");
        printf("4. Change File Permissions\n");
        printf("5. Copy File\n");
        printf("6. Move File\n");
        printf("7. Display File Content\n");
        printf("8. Search for File\n");
        printf("9. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter directory path: ");
                scanf("%s", path1);
                list_directory(path1);
                break;
            case 2:
                printf("Enter file name to create: ");
                scanf("%s", path1);
                create_file(path1);
                break;
            case 3:
                printf("Enter file name to delete: ");
                scanf("%s", path1);
                delete_file(path1);
                break;
            case 4:
                printf("Enter file name: ");
                scanf("%s", path1);
                printf("Enter new permissions (in octal): ");
                int permissions;
                scanf("%o", &permissions);
                change_permissions(path1, permissions);
                break;
            case 5:
                printf("Enter source file path: ");
                scanf("%s", path1);
                printf("Enter destination file path: ");
                scanf("%s", path2);
                copy_file(path1, path2);
                break;
            case 6:
                printf("Enter source file path: ");
                scanf("%s", path1);
                printf("Enter destination file path: ");
                scanf("%s", path2);
                move_file(path1, path2);
                break;
            case 7:
                printf("Enter file path to display content: ");
                scanf("%s", path1);
                display_file(path1);
                break;
            case 8:
                printf("Enter directory path to search in: ");
                scanf("%s", path1);
                printf("Enter file name to search for: ");
                scanf("%s", path2);
                search_file(path1, path2);
                break;
            case 9:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}

