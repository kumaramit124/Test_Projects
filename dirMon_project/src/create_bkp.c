#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define EVENT_SIZE (sizeof(struct inotify_event))
#define EVENT_BUF_LEN (1024 * (EVENT_SIZE + 16))

int directory_exists(const char *path) {
    struct stat dir_info;
    if (stat(path, &dir_info) != 0) {
        return 0; // Directory doesn't exist
    }
    return S_ISDIR(dir_info.st_mode);
}

int create_directory(const char *path) {
    if (mkdir(path, 0700) != 0) {
        perror("Failed to create directory");
        return 0;
    }
    printf("Directory created: %s\n", path);
    return 1;
}

void create_backup(const char *src_path, const char *dest_path) {
    char backup_filename[256];
    snprintf(backup_filename, sizeof(backup_filename), "%s/%s.bak", dest_path, strrchr(src_path, '/') + 1);

    FILE *src_file = fopen(src_path, "rb");
    if (src_file == NULL) {
        perror("Failed to open source file");
        exit(EXIT_FAILURE);
    }

    FILE *dest_file = fopen(backup_filename, "wb");
    if (dest_file == NULL) {
        perror("Failed to create backup file");
        fclose(src_file);
        exit(EXIT_FAILURE);
    }

    char buffer[1024];
    size_t read_bytes;

    while ((read_bytes = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
        fwrite(buffer, 1, read_bytes, dest_file);
    }

    fclose(src_file);
    fclose(dest_file);

    printf("Created backup: %s\n", backup_filename);
}

void delete_file(const char *filename) {
    if (remove(filename) != 0) {
        perror("Failed to delete file");
        exit(EXIT_FAILURE);
    }
    printf("Deleted file: %s\n", filename);
}
