#ifndef READER
#define READER
#include "Reader.h"
Reader::Reader(string no = "null", string name = "null", string p = "123456") : People(name, no)
{
    pass = p;
    int i;
    for (i = 0; i < 8; i++)
        albno[i] = "null";
}
string Reader::getrname() // 获得名字
{
    return name;
}
string Reader::getrrepass() // 获得密码
{
    string repass = pass;
    return repass;
}
bool Reader::operator==(Reader &m)
{
    return (pass == m.pass && name == m.name);
}
void Reader::readerSetNull()
{
    no = "null";
}
Reader Reader::setReader(string account, string password)
{
    return Reader("null", account, password);
}
void Reader::gname() // 修改名字
{
    string na;
    cout << "Please set name:" << endl;
    cin >> na;
    mpeople(na);
}
void Reader::gpass() // 修改密码
{
    string p;
    cout << "Please set password:" << endl;
    cin >> p;
    pass = p;
}
void Reader::setalbno(string s1, string s2, string s3, string s4, string s5, string s6, string s7, string s8) // 设置已借的书的书号
{
    albno[0] = s1;
    albno[1] = s2;
    albno[2] = s3;
    albno[3] = s4;
    albno[4] = s5;
    albno[5] = s6;
    albno[6] = s7;
    albno[7] = s8;
}
void Reader::readerDisplay(BookList<int, class Base> &reBookList) // 显示读者信息
{
    cout << "Account:" << no << endl;
    cout << "Name:" << name << endl;
    cout << "Books Lent:" << endl;
    for (int i = 0; i < 8; i++)
        if (albno[i] != "null")
            reBookList.readerBookFind(albno[i]);
}
int Reader::alreadyBorrowNum() // 获得已借书的数量
{
    int n = 0;
    for (int i = 0; i < 8; i++)
        if (albno[i] != "null")
            n++;
    return n;
}
int Reader::canalbnonum() // 获得可借书的数组的序号
{
    int n = 0;
    for (int i = 0; i < 8; i++)
        if (albno[i] == "null")
        {
            n = i;
            break;
        }
    return n;
}
void Reader::setSingleAlbno(int i, string str)
{
    albno[i] = str;
}
void Reader::returnReaderBook(string str) // 还书时清除账户关于该书的记录
{
    for (int i = 0; i < 8; i++)
        if (albno[i] == str)
        {
            albno[i] = "null";
            break;
        }
}
bool Reader::alreadyBorrow(string str) // 是否借过该书
{
    int n = 0;
    for (int i = 0; i < 8; i++)
        if (albno[i] == str)
        {
            n = 1;
            break;
        }
    return n;
}
void Reader::setReaderInformation()
{
    cout << "Please input information" << endl;
    cout << "Name\tPassword" << endl;
    cin >> name >> pass;
    cout << "Set successful." << endl;
}
#endif