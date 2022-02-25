#include <cstdlib>
#include <cstring>
#include <iostream>

class MyString {
public:
    MyString (size_t str_size) : size(str_size + 1) {
        c_ptr = (char *) malloc(size);
        if (!c_ptr) throw std::bad_alloc();
        memset(c_ptr, 0, size);
    };

    MyString (const char * cstr) {
        size = strlen(cstr) + 1;
        c_ptr = (char *) malloc(size);
        if (!c_ptr) throw std::bad_alloc();
        strcpy(c_ptr, cstr);
    }

    ~MyString() {
        if (c_ptr) free(c_ptr);
    }

    // IOP : */!=/++
    struct MyIter {
        char * p;
        char & operator*() {return *p;}
        bool operator != (const MyIter &rhs) { return p != rhs.p; }
        void operator ++() {++p;}
    };

    // *----------------o
    // ^                ^
    // begin()          end()

    // IOP : return iterable object begin()
    MyIter begin() const { return MyIter {c_ptr}; }

    // IOP : return iterable object end()
    MyIter end() const { return MyIter {c_ptr + size - 1}; }
private:
    char * c_ptr;
    size_t size;
};

int main() {
    MyString a {"hihi"};
    for (auto & c : a) {
        std::cout << c << std::endl;
    }
    return 0;
}
