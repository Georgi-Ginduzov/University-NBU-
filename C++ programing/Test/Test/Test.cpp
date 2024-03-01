#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

class Int {
public:
    Int(int i = 0) : mi(i) {}

    bool operator<(const Int& a) const {
        return this->mi < a.mi;
    }

    Int& operator=(const Int& a) {
        this->mi = a.mi;
        ++m_assignments;
        return *this;
    }

    static int getAssignments() {
        return m_assignments;
    }

private:
    int mi;
    static int m_assignments;
};

int Int::m_assignments = 0;

int main() {
    std::list<Int> l = { Int(3), Int(1) };
    l.sort();
    std::cout << (Int::getAssignments() > 0 ? 1 : 0);

    std::vector<Int> v = { Int(2), Int() };
    std::sort(v.begin(), v.end());
    std::cout << (Int::getAssignments() > 0 ? 2 : 0) << std::endl;

    return 0;
}
