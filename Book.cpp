#ifndef BOOK
#define BOOK
#include "Base.cpp"
template <typename T1, class T2>
class Book
{
public:
    string key;
    Base data;
    int ht;
    Book<T1, T2> *lchild, *rchild;
    Book(string k, Base d)
    {
        key = k;
        data = d;
        ht = 1;
        lchild = rchild = NULL;
    }
    Book(Base d)
    {
        key = "null";
        data = d;
        ht = 1;
        lchild = rchild = NULL;
    }
    Book()
    {
        key = "null";
        Base a;
        data = a;
        ht = 1;
        lchild = rchild = NULL;
    }
    string gbno() const
    {
        return key;
    }
    void setbno(string str)
    {
        key = str;
    }
    void bookDisplay()
    {
        cout << "Book Number:" << gbno() << endl;
        cout << "Book Name:" << data.gbname() << endl;
        cout << "Press:" << data.gpress() << endl;
        cout << "Store number:" << data.gstorenum() << endl;
        cout << "Can borrow:" << data.gcanBorrow() << endl;
    }
    bool operator==(const Book<T1, T2> &m)
    {
        return (key == m.key);
    }
};
#endif