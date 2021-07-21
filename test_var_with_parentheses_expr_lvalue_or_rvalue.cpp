
int dummy_return() {
    int d = 100;
    return d;
}

int main() {
    int x = 100;
    int *y = &(x);               // lvalue
//  y = &(x + 1);                // rvalue, error: lvalue required as unary ‘&’ operand
//  y = &100;                    // rvalue, error: lvalue required as unary ‘&’ operand
//  y = &(100);                  // rvalue, error: lvalue required as unary ‘&’ operand
//  y = &dummy_return();         // rvalue, error: lvalue required as unary ‘&’ operand
//  y = &(dummy_return());       // rvalue, error: lvalue required as unary ‘&’ operand
}
