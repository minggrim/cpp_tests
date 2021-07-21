#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <iostream>

int main(int argc, const char **argv) {
    const char *dirname = "0123456789";
    int fd = open("./", O_RDONLY);

    if (fd == -1) {
        std::cout << "Open root dir failed" << std::endl;
        return -1;
    }

    for (int i = 0; i < 1000; i++) {
        int err = mkdirat(fd, dirname, 777);
        if (err == -1) {
            std::cout << "mkdirat failed at loop " << i << " errno " << errno << std::endl;
            return -1;
        }

	int new_fd = openat(fd, dirname, O_RDONLY);
        if (fd == -1) {
            std::cout << "opendirat failed at loop " << i << " errno " << errno << std::endl;
            return -1;
        }

        close(fd);
        fd = new_fd;
    }
}
