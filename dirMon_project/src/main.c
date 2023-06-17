#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/inotify.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "backup_utils.h"

#define EVENT_SIZE (sizeof(struct inotify_event))
#define EVENT_BUF_LEN (1024 * (EVENT_SIZE + 16))

void monitor_directory(const char *monitor_dir, const char *backup_dir) {
    int length, i = 0, wd;
    int fd;
    char buffer[EVENT_BUF_LEN];

    fd = inotify_init();

    if (fd < 0) {
        perror("inotify_init");
        exit(EXIT_FAILURE);
    }

    wd = inotify_add_watch(fd, monitor_dir, IN_MODIFY);

    while (1) {
        length = read(fd, buffer, EVENT_BUF_LEN);

        if (length < 0) {
            perror("read");
            exit(EXIT_FAILURE);
        }

        while (i < length) {
            struct inotify_event *event = (struct inotify_event *)&buffer[i];
            if (event->len) {
                if (event->mask & IN_MODIFY) {
                    char *filename = event->name;
                    char src_filepath[256];
                    char dest_directory[256];
                    snprintf(src_filepath, sizeof(src_filepath), "%s/%s", monitor_dir, filename);
                    snprintf(dest_directory, sizeof(dest_directory), "%s", backup_dir);

                    create_backup(src_filepath, dest_directory);
                    delete_file(src_filepath);
                }
            }
            i += EVENT_SIZE + event->len;
        }
        i = 0;
    }

    inotify_rm_watch(fd, wd);
    close(fd);
}

int main() {

    const char *directories[] = {
	    "/tmp/mon",
	    "/tmp/mon_backup"
    }

    const int num_dir = sizeof(directories) / sizeof(directories[0]);

    for (int i = 0; i < num_directories; i++) {
        const char *directory_path = directories[i];

        if (!directory_exists(directory_path)) {
            if (!create_directory(directory_path)) {
                exit(EXIT_FAILURE);
            }
        }
    }

    // Directory already exists or was created successfully
    printf("Directory exists: %s\n", directory_path);



    monitor_directory(monitor_dir, backup_dir);

    return 0;
}

