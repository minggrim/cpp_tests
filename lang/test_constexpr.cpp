#include <iostream>
constexpr int get_mul(int a, int b) {
    return a * b;
}

int main() {
    constexpr int x = get_mul(3, 5); 



    int y = get_mul(1,5);



    int z = get_mul(x , y);
    return 0;
}

/*
000000000000073a <main>:
 73a:	55                   	push   %rbp
 73b:	48 89 e5             	mov    %rsp,%rbp
 73e:	48 83 ec 10          	sub    $0x10,%rsp
 742:	c7 45 f4 0f 00 00 00 	movl   $0xf,-0xc(%rbp)      // because 3, 5 are constexpr, x is compile time calculated. x is a constexpr
 749:	c7 45 f8 05 00 00 00 	movl   $0x5,-0x8(%rbp)      // becuase 1, 5 are constexpr, y is compile time calculated, but y is not a constexpr.
 750:	8b 45 f8             	mov    -0x8(%rbp),%eax
 753:	89 c6                	mov    %eax,%esi
 755:	bf 0f 00 00 00       	mov    $0xf,%edi
 75a:	e8 68 00 00 00       	callq  7c7 <_Z7get_mulii>   // because y is not a constexpr, so get_mul called. if we do not have this line, compiler even won't generate get_mul function code.
 75f:	89 45 fc             	mov    %eax,-0x4(%rbp)
 762:	b8 00 00 00 00       	mov    $0x0,%eax
 767:	c9                   	leaveq 
 768:	c3                   	retq   
*/
