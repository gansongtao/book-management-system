#ifndef MANAGER
#define MANAGER
#include "Manager.h"
Manager::Manager(string no = "null", string name = "null", string p = "123456") : People(name, no), pass(p) {}
string Manager::getmpass() // 获得修改后的密码
{
    return pass;
}
string Manager::mpeople(string a) // 改名字
{
    return name = a;
}
void Manager::display()
{
    cout << "Name:" << name << "\tAccount:" << no << endl;
}
Manager Manager::setManager(string account, string password)
{
    string num = "null";
    Manager a(num, account, password);
    return a;
}
void Manager::gname() // 修改名字
{
    string na;
    cout << "Please set name:" << endl;
    cin >> na;
    mpeople(na);
}
void Manager::gpass() // 修改密码
{
    string p;
    cout << "Please set password:" << endl;
    cin >> p;
    pass = p;
}
void Manager::managerDisplay() // 显示个人信息
{
    cout << "Account:" << no << "\tName:" << name << "\tPassword:" << pass << endl;
}
bool Manager::operator==(const Manager &m)
{
    return (pass == m.pass && name == m.name);
}
#endif