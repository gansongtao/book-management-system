#include "BookList.cpp"
#include "ReaderList.cpp"
#include "Manager.cpp"
class ManagerList
{
    Manager *head = NULL;

public:
    ~ManagerList();
    Manager *find(Manager &a);
    Manager *strictFind(Manager &a);
    void load(Manager &a, BookList<int, class Base> &bookList, ReaderList &readerList);
    void add(Manager &a);
    void removal(string rev);
    void display();
};