#include "Box.h"
#include <iostream>
using namespace std;
Box::Box()
{
    cout << "Box Constuctor" << endl;
    x = 1;
    y = 2;
}

Box::Box(const Box &b)
{
    cout << "Box Constuctor" << endl;
}

void Box::getSize()
{
    cout << "Box Size"
         << "x:" << x << "y:" << y << endl;
    return;
}
