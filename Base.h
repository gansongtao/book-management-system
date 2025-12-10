#include <iostream>
using namespace std;
class Base
{
private:
    string bname, author, press;        // 书号 书名 作者 出版社
    int storenum, borrownum, canBorrow; // 藏书量 借出数 可借数量

public:
    Base(string bname1, string author1, string press1, int storenum1, int canBorrow1, int borrownum1);
    string gbname() const;
    string gauthor() const;
    string gpress() const;
    int gstorenum() const;
    int gcanBorrow() const;
    int gborrownum() const;
    void setInformationg();
    void storeBook();
    void returnBook();
    void borrowBook();
    void setAuthor(string str);
    void setPress(string str);
};