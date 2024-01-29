#include <iostream>
#include <string>

typedef struct Element* po;
struct Element {
    char Data;
    po Next;
};

po newNode(char data) {
    po node = new Element;
    node->Data = data;
    node->Next = nullptr;
    return node;
}

void printList() {

}

int main() {
    po top = nullptr;
    std::string name;// 
    std::getline(std::cin, name);

    for (int i = 0; i < name.length(); i++)
    {
        po node = newNode(name[i]);
        node->Next = top;
        top = node;
    }

    std::cout << std::endl;

    printList();

    return 0;
}