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

void push(po& top, char data) {
    po node = newNode(data);
    node->Next = top;
    top = node;
    std::cout << data << " pushed in the stack\n";
}

char pop(po& top) {
    po temp = top;
    top = top->Next;
    char popped = temp->Data;
    delete temp;
    return popped;
}

char peek(po top) {
    return top->Data;
}

int main() {
    po top = nullptr;
    std::string name;
    std::getline(std::cin, name);
    
    for (int i = 0; i < name.length(); i++)
    {
        push(top, name[i]);
    }

    std::cout << std::endl;

    for (int i = 0; i < name.length(); i++)
    {
        std::cout << pop(top) << " is popped out of the stack\n";
    }

    return 0;
}