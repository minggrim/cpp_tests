#include <sys/prctl.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <chrono>
#include <thread>

using std::cout;
using std::cerr;
using std::endl;

static void wd() {
    while (true) {
        pid_t pid = fork();

        if (pid < 0) {
            cerr << "Fork error" << endl;
            exit(EXIT_FAILURE);
        }
        else if (pid == 0) {
            prctl(PR_SET_PDEATHSIG, SIGHUP);
            return;
        }
        else {
            // i am parent as watch dog.
            int status;
            ::waitpid(pid, &status, 0);
            cerr << pid << " child status changed " << status << endl;
            
            if (WIFEXITED(status) && (WEXITSTATUS(status) == EXIT_SUCCESS)) {
                cout << "child exit successfully, parent exit" << endl;
                exit(EXIT_SUCCESS);
            }
            ::usleep(500000);
        }
    }
}

void usage(const std::string & pname) {
    cout << pname << " <total mem size in KB> <per allocate in KB gt 0>" << endl;
}

int main(int argc, char**argv) {
    if (argc != 3) {
        usage(argv[0]);
        exit(1);
    }

    size_t msize = 0, per_size = 0;
    std::istringstream msizess {argv[1]};
    std::istringstream perss {argv[2]};

    msizess >> msize;
    perss >> per_size;

    if (per_size == 0) {
        cerr << " per allocate size should not be zero " << endl;
        exit(1);
    }

    wd();

    cout << "[" << getpid() << "] start to consume "
        << msize << "KB, allocate " << per_size << "KB every time" << endl;


    const size_t per_allocate = per_size * 1024;

    size_t total = msize * 1024;

    while (total) {
        char *p = nullptr;
        size_t allocated = per_allocate;

        if (total >= per_allocate) {
            p = (char *) malloc(per_allocate);
            total -= per_allocate;
        }
        else {
            p = (char *) malloc(total);
            allocated = total;
            total = 0;
        }
 
        if (p == nullptr) {
            total += allocated;
            cerr << "Failed to alloc " << (allocated / 1024) << "KB remain " << (total / 1024) << " not allocate " << endl;
            ::usleep(500000);
            continue;
        }
        else {
            cout << "[" << getpid() << "] alloc " << (allocated / 1024) << "KB successfully "
                << " remain " << (total / 1024) << "KB" << endl;
        }

        memset(p, 0, allocated);
    }

    std::this_thread::sleep_until(std::chrono::time_point<std::chrono::system_clock>::max());

    return 0;
}
