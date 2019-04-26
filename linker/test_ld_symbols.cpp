#include <iostream>
#include <unistd.h>

extern char __executable_start[];
extern char etext[], _etext[], __etext[];
extern char edata[], _edata[];
extern char end[], _end[];

int main() {
    std::cout << " __executable_start :" << (void*)__executable_start << std::endl;
    std::cout << " etext :" << (void*) etext << std::endl;
    std::cout << " _etext :" << (void*) _etext << std::endl;
    std::cout << " __etext :" << (void*) __etext << std::endl;
    std::cout << " edata :" << (void*) edata << std::endl;
    std::cout << " _edata :" << (void*) _edata << std::endl;
    std::cout << " end :" << (void*) end << std::endl;
    std::cout << " _end :" << (void*) _end << std::endl;
    sleep(10000);
}
/*
 __executable_start :0x55c781527000
 etext :0x55c781527c0d
 _etext :0x55c781527c0d
 __etext :0x55c781527c0d
 edata :0x55c781729010
 _edata :0x55c781729010
 end :0x55c781729138
 _end :0x55c781729138


55c781527000-55c781528000 r-xp 00000000 00:2f 1204029                    /.../test_ld_symbols
55c781728000-55c781729000 r--p 00001000 00:2f 1204029                    /.../test_ld_symbols
55c781729000-55c78172a000 rw-p 00002000 00:2f 1204029                    /.../test_ld_symbols

*/
