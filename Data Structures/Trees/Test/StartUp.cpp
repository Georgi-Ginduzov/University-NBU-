#include <iostream>



Element* ibd(int n) {
    int d = 0;
    if (n > 0)
    {
        Element* p;
        p = new Element;
        p->left = ibd(n / 2);
        cout << "enter value";
        cin >> d;
        p->data = d;
        p->right = ibd(n - n / 2 - 1);
        return p;
    }
    else
    {
        return NULL;
    }
}


int main() {

}