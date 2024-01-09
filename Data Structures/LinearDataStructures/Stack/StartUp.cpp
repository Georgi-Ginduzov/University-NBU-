#include <iostream>
#include <string>

typedef struct Element* po;
struct Element {
    char Data;
    po Next;
};

po newNode(int data) {
    po node = new Element;
    node->Data = data;
    node->Next = nullptr;
    return node;
}

bool isEmpty(po top) {
    return top == nullptr;
}

void push(po& top, char data) {
    po node = newNode(data);
    node->Next = top;
    top = node;
    std::cout << data << " pushed in the stack\n";
}

char pop(po& top) {
    if (isEmpty(top)) {
        std::cout << "Stack is empty\n";
        return -1;
    }
    po temp = top;
    top = top->Next;
    char popped = temp->Data;
    std::cout << temp->Data << " is popped out\n";
    delete temp;
    return popped;
}

char peek(po top) {
    if (isEmpty(top)) {
        std::cout << "Stack is empty\n";
        return -1;
    }
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
        pop(top);
    }

    return 0;
}