#include "People.cpp"
#include "BookList.cpp"
class Reader : public People
{
    string pass;

public:
    string albno[8];
    Reader *next;
    Reader(string no, string name, string p);
    string getrname();
    string getrrepass();
    bool operator==(Reader &m);
    void readerSetNull();
    Reader setReader(string account, string password);
    void gname();
    void gpass();
    void setalbno(string s1, string s2, string s3, string s4, string s5, string s6, string s7, string s8);
    void readerDisplay(BookList<int, class Base> &reBookList);
    int alreadyBorrowNum();
    int canalbnonum();
    void setSingleAlbno(int i, string str);
    void returnReaderBook(string str);
    bool alreadyBorrow(string str);
    void setReaderInformation();
};