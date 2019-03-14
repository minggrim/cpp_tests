#include <iostream>

void eliminate_tail(std::string &str, char e) {
    if (str.empty())
        return;

    // at least one character.

    size_t t_ptr = str.length() - 1;

    // move ptr if '/' up to first charactor
    // exit condition : (reach first) or (cur non '/')
    while (t_ptr > 0 && str[t_ptr] == e) {
        t_ptr --;
    }

    // t_ptr != str.length() - 1  :  ptr not moved.
    if (t_ptr != str.length() - 1 && str[t_ptr + 1] == e) {
        str.erase(t_ptr + 1);
    }

	if (str.length() == 1 && str[0] == e) {
		str.erase(0);
	}
}

int main() {
	std::string x = "//a///////////////";
	eliminate_tail(x, '/');
	std::cout << x << std::endl;
}
