#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <iostream>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>

#define PER_PR 4096

void usage(const char * programe_name) {
    std::cout << programe_name << " <path> " << std::endl;
}

int main(int argc, const char ** argv) {
    if (argc != 2) {
        usage(argv[0]);
	return -1;
    }

    int fd = open(argv[1], O_RDWR, 0);

    if (fd == -1) {
	std::cout << "open \"" << argv[1] << "\" failed :" << strerror(errno) << std::endl;
	return -1;
    }

    struct stat file_stat;

    if (::fstat(fd, &file_stat) == -1) {
	std::cout << "fstat \"" << argv[1] << "\" failed " << strerror(errno) << std::endl;
	return -1;
    }

    const char *ptr = (const char *) mmap(NULL, file_stat.st_size, PROT_READ|PROT_WRITE, MAP_SHARED , fd , 0);

    if (ptr == nullptr) {
	std::cout << "mmap \"" << argv[1] << "\" failed " << std::endl;
	return -1;
    }

    std::cout << "===== Dump file by mmap start =====" << std::endl;
    for (const char *z = ptr; z < ptr + file_stat.st_size; z += PER_PR) {
        std::cout << std::string(z, (ptr + file_stat.st_size > z + PER_PR ? PER_PR : ptr + file_stat.st_size - z));
    }
    std::cout << "===== Dump file by mmap end =====" << std::endl;

    return 0;
}
