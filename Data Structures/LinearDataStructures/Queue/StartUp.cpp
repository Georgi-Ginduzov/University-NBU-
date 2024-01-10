#include <iostream>
#include <string>

typedef struct Element* po;
struct Element {
    char Data;
    po Next;
};

bool isEmpty(po beggy) {
    return beggy == nullptr;
}

po newNode(char data){
    po node = new Element;
    node->Data = data;
    node->Next = nullptr;

    return node;
}

void enqueue(po& beggy, po& endy, char data) {
    po node = newNode(data);
    if (isEmpty(beggy))
    {
        beggy = node;
        endy = node;
        std::cout << data << " is enqueued to the queue\n";
    }
    else
    {
        endy->Next = node;
        endy = node;
        std::cout << data << " is enqueued to the queue\n";
    }
}

char dequeue(po& beggy) {
    po temp = beggy;
    char dequeued = temp->Data;
    beggy = beggy->Next;
    delete temp;
    return dequeued;
}

int main() {
    po beggy = nullptr, endy= nullptr;

    std::string adress; // kaizer zemel 12, Sofia
    std::getline(std::cin, adress);

    for (int i = 0; i < adress.length(); i++)
    {
        enqueue(beggy, endy, adress[i]);
    }

    std::cout << std::endl;

    for (int i = 0; i < adress.length(); i++)
    {
        std::cout << dequeue(beggy) << " is dequeued from the queue\n";
    }

	return 0;
}