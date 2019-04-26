#include <assert.h>
#include <deque>
#include <iostream>

struct DummyItem {
    DummyItem() : dummy_value(nullptr) {}

    DummyItem(const int &v) : dummy_value(new int(v)){}

    //
    DummyItem(const DummyItem &rhs) {
        std::cout << "copy ctor" << std::endl;
        copy_construct(rhs);
    }

    DummyItem & operator=(const DummyItem &rhs) {
        if (this == &rhs) return *this;
        std::cout << "copy =" << std::endl;
        copy_construct(rhs);
        return *this;
    }

    //
    DummyItem(DummyItem &&rhs) {
        std::cout << "mv ctor" << std::endl;
        move_construct(rhs);
    }

    DummyItem & operator=(DummyItem &&rhs) {
        if (this == &rhs) return *this;
        std::cout << "mv =" << std::endl;
        move_construct(rhs);
        return *this;
    }

    ~DummyItem() {
        if (dummy_value) {
            delete dummy_value;
            dummy_value = nullptr;
        }
    }

    bool is_resolved() {
        return (dummy_value != nullptr);
    }

    // Need to make sure not resolved first
    void mark_resolved(const int & i) {
        assert(dummy_value == nullptr);
        dummy_value = new int(i);
        msg = std::to_string(i) + " is resolved ";
    }
    friend std::ostream & operator << (std::ostream &os, const DummyItem &d);
private:
    void copy_construct(const DummyItem &rhs) {
        msg = rhs.msg;
        // copy and copy for exception safe
        const int *copy = nullptr, *release = nullptr;
        // copy points to rhs.dummy_value
        if (rhs.dummy_value) {                                                                                                                                                                                     
            copy = new int(*rhs.dummy_value);
        }                                                                                                                                                                                                      

        // release points to old dummy_value                                                                                                                                                                       
        if (dummy_value) {
            release = dummy_value;
        }
        // inode points to copy
        dummy_value = copy;
        if (release) {
            delete release;
            release = nullptr;
        }
    }

    void move_construct(DummyItem &rhs) {
        msg = std::move(rhs.msg);
        const int *release = dummy_value;
        dummy_value = rhs.dummy_value;
        rhs.dummy_value = nullptr;
        if (release) {
            delete release;
            release = nullptr;
        }
    }
public:
    const int *dummy_value {nullptr};
    std::string msg;
};

std::ostream & operator << (std::ostream &os, const DummyItem &d) {
    os << *d.dummy_value << ":" << &d << ":" << d.msg;
    return os;
}


int main() {
	std::deque<DummyItem> q;

    int num = 0;
    std::cout << "Test Move Start" << std::endl;
	for (int i = 0; i < 10; i++) {
		q.push_back(DummyItem());
	}
    while(q.size() > 0) {
        auto x = std::move(q.front());
        q.pop_front();
        if (x.is_resolved()) {
            std::cout << x << std::endl;
            continue;
        }

        x.mark_resolved(++num);
        q.push_back(std::move(x));
    }
    std::cout << "=====Test Move End=====" << std::endl;

    num = 0;
    std::cout << "Test Copy Ctor Start" << std::endl;
    for (int i = 0; i < 10; i++) {
        auto x = DummyItem();
        q.push_back(x);
    }

    while(q.size() > 0) {
        auto x = q.front();
        q.pop_front();
        if (x.is_resolved()) {
            std::cout << x << std::endl;
            continue;
        }

        x.mark_resolved(++num);
        q.push_back(x);
    }
    std::cout << "=====Test Copy Ctor End=====" << std::endl;

    DummyItem di;
    num = 0;
    std::cout << "Test Copy Assign Start" << std::endl;
    for (int i = 0; i < 10; i++) {
        di = DummyItem();
        q.push_back(di);
    }

    while(q.size() > 0) {
        di = q.front();
        q.pop_front();
        if (di.is_resolved()) {
            std::cout << di << std::endl;
            continue;
        }

        di.mark_resolved(++num);
        q.push_back(di);
    }
    std::cout << "=====Test Copy Assign End=====" << std::endl;

    num = 0;
    std::cout << "Test Move Assign Start" << std::endl;
    for (int i = 0; i < 10; i++) {
        di = DummyItem();
        q.push_back(di);
    }

    while(q.size() > 0) {
        di = q.front();
        q.pop_front();
        if (di.is_resolved()) {
            std::cout << di << std::endl;
            continue;
        }

        di.mark_resolved(++num);
        q.push_back(di);
    }
    std::cout << "=====Test Move Assign End=====" << std::endl;

    std::cout << "=====Test Self Copy Assign=====" << std::endl;
    di = di;
    std::cout << "=====Test Self Copy Assign End=====" << std::endl;

    std::cout << "=====Test Self Move Assign=====" << std::endl;
    di = std::move(di);
    std::cout << "=====Test Self Move Assign End=====" << std::endl;
}
