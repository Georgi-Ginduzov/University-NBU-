#include <iostream>

struct Element {
    char Data;
    Element* Next;
};

typedef Element* po;

int main() {
    po na = NULL, p, placeFinder;
    char x;

    std::cin >> x;

    while (x != '0')
    {
        p = new Element;
        p->Data = x;
        p->Next = NULL;

        if (na == NULL || na->Data >= p->Data) {
            p->Next = na;
            na = p;
        }
        else {
            placeFinder = na;
            while (placeFinder->Next != NULL && placeFinder->Next->Data < p->Data) {
                placeFinder = placeFinder->Next;
            }
            p->Next = placeFinder->Next;
            placeFinder->Next = p;
        }
        std::cin >> x;
    }

    po temp = na;
    while (temp != NULL) {
        std::cout << temp->Data;
        temp = temp->Next;
    }

    return 0;
}
