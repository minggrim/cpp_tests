// https://alrightchiu.github.io/SecondRound/comparison-sort-heap-sortdui-ji-pai-xu-fa.html#bh
// https://rust-algo.club/sorting/heapsort/

#include <iostream>
#include <vector>

namespace Malgo {
template<class T>
void LogContainer(T &container) {
    for (auto &e : container) {
        std::cout << e << " ";
    }
    std::cout << std::endl;
}

template<class T>
void ShiftDown(T &container, size_t start, size_t c_size, bool reversed) {

    if (reversed) {
        for (;;) {
            // no child
            if (start * 2 > c_size) break;

            // one left child
            if (start * 2 + 1 > c_size) {
                if (container[start * 2 - 1]  < container[start - 1]) {
                    std::swap(container[start * 2 - 1], container[start - 1]);
                }
                break;
            }

            size_t smaller = 0;
            if (container[start * 2 - 1] < container[start * 2]) {
                smaller = start * 2;
            }
            else {
                smaller = start * 2 + 1;
            }

            if (container[smaller - 1] < container[start - 1]) {
                std::swap(container[smaller - 1], container[start - 1]);
                start = smaller;
            }
            else {
                break;
            }
        }
    }
    else {
        for (;;) {
            // no child
            if (start * 2 > c_size) break;

            // one left child
            if (start * 2 + 1 > c_size) {
                if (container[start * 2 - 1]  > container[start - 1]) {
                    std::swap(container[start * 2 - 1], container[start - 1]);
                }
                break;
            }

            size_t bigger = 0;
            if (container[start * 2 - 1] > container[start * 2]) {
                bigger = start * 2;
            }
            else {
                bigger = start * 2 + 1;
            }

            if (container[bigger - 1] > container[start - 1]) {
                std::swap(container[bigger - 1], container[start - 1]);
                start = bigger;
            }
            else {
                break;
            }
        }
    }
}

template <class T>
void Heapify(T &container, bool reversed) {
    // start from size() / 2
    //            *
    //         *     * <------------------- start from size() / 2
    //       *   * *   * <------------------------no leaf
    for (size_t e = container.size() / 2 ; e >= 1; e--) {
        ShiftDown(container, e, container.size() - e + 1, reversed);
    }
}


template <class T>
void HeapSort(T &container, bool reversed = false) {
    Heapify(container, reversed);

    size_t c_size = container.size();
    while(c_size > 1) {

        // shift down
        ShiftDown(container, 1, c_size, reversed);

        // swap
        std::swap(container[0], container[c_size - 1]);

        // [0, ..., c_size - 2] [c_size - 1]
        c_size--;
    }
}
};


using namespace Malgo;

int main() {
    std::vector<int> a {3, 6, 1, 2, 4, 6, 7, 5};

    HeapSort(a);
    LogContainer(a);

    HeapSort(a, true);
    LogContainer(a);
}
