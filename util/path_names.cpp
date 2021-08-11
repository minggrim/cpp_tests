#include <iostream>
#include <vector>
#define STOPAT_NON_CHAR(idx, path, c)           \
    while(idx < path.size()) {                  \
        if (path[idx] != c) break;              \
        idx++;                                  \
    }

static std::vector<std::string> path_names(const std::string & path) {
    std::vector<std::string> names;

    size_t head = 0;

    STOPAT_NON_CHAR(head, path, '/');

    // here, head points to non-'/' char
    size_t tail = head;
    while (head < path.size()) {
        tail++;
        
        if (tail >= path.size()) {
            // reach end
            names.push_back(path.substr(head, tail - head));
            head = tail;
        }
        else if (path[tail] == '/') {
            // find one
            names.push_back(path.substr(head, tail - head));
            head = tail;

            STOPAT_NON_CHAR(head, path, '/');
            tail = head;
        }
    }
    
    return names;
}


int main( int argc, const char **argv ) {
    if (argc < 2) {
        std::cout << "Give me a path" << std::endl;
        return -1;
    }

    auto x = path_names(argv[1]);

    std::cout << "Split:" << std::endl;
    for ( auto &p : x) {
        std::cout << p << std::endl;
    }

    return 0;
}
