#include "keyboard.h"
#include <iostream>

	using namespace std;

    keyboard::keyboard()
    {

    }

    keyboard::keyboard(char* linkQR, string content)
    {
        textQR = new char[strlen(linkQR) + 1];
        strcpy_s(textQR, strlen(linkQR) + 1, linkQR);

    }
