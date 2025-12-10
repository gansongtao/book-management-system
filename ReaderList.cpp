#ifndef READERLIST
#define READERLIST
#include "ReaderList.h"
ReaderList::~ReaderList()
{
    for (Reader *r = head; r = head; delete r)
        head = head->next;
}
Reader *ReaderList::find(Reader &a) // 查找
{
    Reader *m = head;
    while (m)
    {
        if (m->no == a.no)
            return m;
        m = m->next;
    }
    return m;
}
Reader *ReaderList::strictFind(Reader &a)
{
    Reader *m = head;
    while (m)
    {
        if (*m == a)
        {
            a.no = m->no;
            return m;
        }
        m = m->next;
    }
    return m;
}
void ReaderList::write() // 写入文件
{
    ofstream out("reader1.txt");
    Reader *r = head;
    while (r)
    {
        out << r->no << ' ' << r->name << ' ' << r->getrrepass() << ' ' << r->albno[0] << ' ' << r->albno[1] << ' ' << r->albno[2] << ' ' << r->albno[3] << ' ' << r->albno[4] << ' ' << r->albno[5] << ' ' << r->albno[6] << ' ' << r->albno[7] << endl;
        r = r->next;
    }
    out.close();
    remove("reader.txt");
    rename("reader1.txt", "reader.txt");
}
void ReaderList::load(Reader &a, BookList<int, class Base> &bookList, ReaderList &readerList) // 登入
{
    if (strictFind(a))
    {
        Reader *z = find(a);
        cout << "Login success" << endl;
        int n = 0;
        char re;
        string note = "000";
        cout << "1. Display personal information" << endl;
        cout << "2. Lend book" << endl;
        cout << "3. Return book" << endl;
        cout << "Please choose (-1 for upper layer):" << endl;
        while (cin >> n)
        {
            system("cls");
            if (n == 1)
            {
                z->readerDisplay(bookList);
                cout << "Press any number to return..." << endl;
                cin >> re;
                system("cls");
            }
            else if (n == 2)
            {
                if (z->alreadyBorrowNum() == 8)
                    cout << "You cannot lend more than 8 books" << endl;
                else
                {
                    cout << "Please input book number to lend:";
                    cin >> note;
                    if (Book<int, class Base> *bz = bookList.allFind(note))
                    {
                        Base temp = bz->data;
                        if (temp.gcanBorrow() > 1)
                        {
                            z->setSingleAlbno(z->canalbnonum(), note);
                            temp.borrowBook();
                            cout << "Lending successful." << endl;
                        }
                        else
                            cout << "All copies of the book are lent." << endl;
                    }
                    else
                        cout << "Wrong number." << endl;
                }
                cout << "Press any number to return..." << endl;
                cin >> re;
                system("cls");
            }
            else if (n == 3)
            {
                cout << "Please input book number to return:";
                cin >> note;
                if (Book<int, class Base> *bz = bookList.allFind(note))
                {
                    if (z->alreadyBorrow(note))
                    {
                        Base temp = bz->data;
                        if (temp.gcanBorrow() < temp.gstorenum())
                        {
                            temp.returnBook();
                            z->returnReaderBook(note);
                            cout << "Return successful." << endl;
                        }
                        else
                            cout << "Wrong number." << endl;
                    }
                    else
                        cout << "You did not lend the book." << endl;
                }
                else
                    cout << "Wrong number." << endl;
                cout << "Press any number to return..." << endl;
                cin >> re;
                system("cls");
            }
            else if (n == -1)
                break;
            else
            {
                cout << "Input Error" << endl;
            }
            cout << "1. Display personal information" << endl;
            cout << "2. Lend book" << endl;
            cout << "3. Return book" << endl;
            cout << "Please choose (-1 for upper layer):" << endl;
        }
    }
    else
        cout << "Input Error" << endl;
}
void ReaderList::add(Reader &a) // 添加信息
{
    Reader *pn = new Reader(a);
    if (head)
        pn->next = head;
    else
        pn->next = NULL;
    head = pn;
}
void ReaderList::readerStringRemove(string str) // 移除
{
    Reader reader(str);
    if (Reader *rz = find(reader))
        rz->readerSetNull();
}
void ReaderList::display()
{
    Reader *pn = head;
    while (pn)
    {
        pn->display();
        pn = pn->next;
    }
}
void ReaderList::newAdd()
{
    string linNo, linName, linPass;
    cout << "Please input reader information" << endl;
    cout << "Account\tName\tPassword" << endl;
    cin >> linNo >> linName >> linPass;
    Reader linReader(linNo);
    if (find(linReader))
        cout << "Account registered." << endl;
    else
    {
        Reader linReader1(linNo, linName, linPass);
        add(linReader1);
        cout << "Registration successful." << endl;
    }
}
#endif