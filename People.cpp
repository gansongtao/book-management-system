#ifndef PEOPLE
#define PEOPLE
#include "People.h"
People::People(string na = "null", string n = "null") : name(na), no(n) {}
string People::mpeople(string a) // 改名字
{
    return name = a;
}
void People::display()
{
    cout << "Name:" << name << "\tAccount:" << no << endl;
}
#endif