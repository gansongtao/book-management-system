#include "Reader.cpp"
class ReaderList
{
    Reader *head = NULL;

public:
    ~ReaderList();
    Reader *find(Reader &a);
    Reader *strictFind(Reader &a);
    void write();
    void load(Reader &a, BookList<int, class Base> &bookList, ReaderList &readerList);
    void add(Reader &a);
    void readerStringRemove(string str);
    void display();
    void newAdd();
};