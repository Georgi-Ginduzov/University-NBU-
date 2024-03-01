#include <iostream>

// this progect's purpose is to show how to add/remove and overload elements/operators in a template

template <typename T, int N> 
class Set {
private:
    T elements[N];
    int currentNumberOfElements;

public:
    Set() {
        this->currentNumberOfElements = 0; 
    }

    void addElement(const T& element, int index) {
        if (index < 0 || index > currentNumberOfElements) {
            std::cout << "Index out of range\n";
            return;
        }
        if (currentNumberOfElements == N) {
            std::cout << "Table is full.\n";
            return;
        }

        // search whether element is in the set
        int i = 0;
        T last = elements[N - 1];
        if (last == element)
        {
            std::cout << "This number cannot be inserted because it is already in the set.\n";
        }
        else
        {
            elements[N - 1] = element;
            while (elements[i] != element)
            {
                i++;
            }
            elements[N - 1] = last;
            if (i < currentNumberOfElements + 1)
            {
                std::cout << "This number " << element << " cannot be inserted because it is already in the set.\n";
            }
            else
            {   
                for (int i = currentNumberOfElements; i > index; i--) {
                    elements[i] = elements[i - 1];
                }
                elements[index] = element;
                currentNumberOfElements++;
                std::cout << "Element " << element << " added to the set\n";
            }
        }
        
    }

    void remove(T element) {
        int i = 0;
        T last = elements[N - 1];
        if (last == element)
        {
            currentNumberOfElements--;
        }
        else
        {
            elements[N - 1] = element;
            while (elements[i] != element)
            {
                i++;
            }
            elements[N - 1] = last;
            if (i < currentNumberOfElements + 1)
            {
                //delete
                for (i; i < currentNumberOfElements - 1; i++)
                {
                    elements[i] = elements[i + 1];
                }currentNumberOfElements--;
            }
            else
            {
                std::cout << "Element not found\n";
            }
        }
        
    }

    void print() {
        for (int i = 0; i < currentNumberOfElements; i++) {
            std::cout << elements[i] << " ";
        }
        std::cout << "\n";
    }

    T& operator[](int index) {
        if (index < 0 || index >= currentNumberOfElements) {
            throw std::out_of_range("Index out of range");
        }
        return elements[index];
    }
};

int main() {

	Set<int, 10> set;
    set.addElement(10, 0);
    set.addElement(20, 1);
    set.addElement(30, 2);
    set.addElement(40, 3);
    set.print();

    set.remove(40);
    set.print();

    set.addElement(30, 2);
    set.print();

	return 0;
}