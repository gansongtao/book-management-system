#ifndef BASE
#define BASE
#include "Base.h"
Base::Base(string bname1 = "null", string author1 = "null", string press1 = "null", int storenum1 = 0, int canBorrow1 = 0, int borrownum1 = 0) : bname(bname1), author(author1), press(press1), storenum(storenum1), canBorrow(canBorrow1), borrownum(borrownum1) {}
string Base::gbname() const // 获得书名
{
    return bname;
}
string Base::gauthor() const // 获得作者
{
    return author;
}
string Base::gpress() const // 获得出版社
{
    return press;
}
int Base::gstorenum() const // 获得藏书量
{
    return storenum;
}
int Base::gcanBorrow() const // 获得可借数量
{
    return canBorrow;
}
int Base::gborrownum() const // 获得借出数量
{
    return borrownum;
}
void Base::setInformationg()
{
    cout << "Please input book information" << endl;
    cout << "Book Number\tAuthor\tPress\tStore Number\tCan Borrow" << endl;
    cin >> bname >> author >> press >> storenum >> canBorrow;
    borrownum = storenum - canBorrow;
    cout << "Set successful." << endl;
}
void Base::storeBook() // 存入该书
{
    storenum++;
    canBorrow--;
}
void Base::returnBook() // 还书
{
    canBorrow++;
    borrownum--;
}
void Base::borrowBook() // 借书
{
    canBorrow--;
    borrownum++;
}
void Base::setAuthor(string str)
{
    author = str;
}
void Base::setPress(string str)
{
    press = str;
}
#endif