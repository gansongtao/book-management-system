#ifndef MANAGERLIST
#define MANAGERLIST
#include "ManagerList.h"
ManagerList::~ManagerList()
{
    for (Manager *r = head; r = head; delete r)
        head = head->next;
}
Manager *ManagerList::find(Manager &a) // 查找
{
    Manager *m = head;
    while (m)
    {
        if (m->no == a.no)
            return m;
        m = m->next;
    }
    return m;
}
Manager *ManagerList::strictFind(Manager &a)
{
    Manager *m = head;
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
void ManagerList::load(Manager &a, BookList<int, class Base> &bookList, ReaderList &readerList) // 登入
{
    string readern = "NULL", note = "000";
    char re = 0;
    if (strictFind(a))
    {
        Manager *z = find(a);
        Book<int, class Base> linBook;
        Reader linReader;
        cout << "Login successful." << endl;
        int n = 0, n4 = 0;
        z->display();
        cout << "1. Display personal information" << endl;
        cout << "2. Book<T1, class Base> information maintenance" << endl;
        cout << "3. Reader information maintenance" << endl;
        cout << "Please choose (-1 for upper layer):" << endl;
        while (cin >> n)
        {
            system("cls");
            if (n == 1)
            {
                z->managerDisplay();
                cout << "Press any number to return..." << endl;
                cin >> re;
                system("cls");
                cout << "1. Display personal information" << endl;
                cout << "2. Book<T1, class Base> information maintenance" << endl;
                cout << "3. Reader information maintenance" << endl;
                cout << "Please choose (-1 for upper layer):" << endl;
            }
            if (n == 2)
            {
                cout << "1. Add book" << endl;
                cout << "2. Delete book" << endl;
                cout << "3. Set book information" << endl;
                cout << "Please choose (-1 for upper layer):" << endl;
                while (cin >> n4)
                {
                    system("cls");
                    if (n4 == 1)
                    {
                        cout << "Please input book number to add:";
                        cin >> note;
                        linBook.setbno(note);
                        if (Book<int, class Base> *bz = bookList.allFind(note))
                        {
                            Base temp = bz->data;
                            temp.storeBook();
                            cout << "Saved" << endl;
                        }
                        else
                        {
                            string linName, linAuthor, linPress;
                            int linNum;
                            cout << "Please input book information:" << endl;
                            cout << "Book number\tAuthor\tPress\tBooks added" << endl;
                            cin >> linName >> linAuthor >> linPress >> linNum;
                            Base temp(linName, linAuthor, linPress, linNum, linNum, 0);
                            Book<int, class Base> saveBook(note, temp);
                            bookList.add(saveBook);
                            cout << "Saved" << endl;
                        }
                        cout << "Press any number to return..." << endl;
                        cin >> re;
                    }
                    if (n4 == 2)
                    {
                        cout << "Please input book number to delete:";
                        cin >> note;
                        if (Book<int, class Base> *bz = bookList.allFind(note))
                        {
                            bookList.stringRemove(note);
                            cout << "Delete successful" << endl;
                        }
                        cout << "Press any number to return..." << endl;
                        cin >> re;
                    }
                    if (n4 == 3)
                    {
                        cout << "Please input book number to set:";
                        cin >> note;
                        if (Book<int, class Base> *bz = bookList.allFind(note))
                        {
                            Base temp = bz->data;
                            temp.setInformationg();
                        }
                        else
                            cout << "Book does not exist." << endl;
                        cout << "Press any number to return..." << endl;
                        cin >> re;
                    }
                    system("cls");
                    cout << "1. Display personal information" << endl;
                    cout << "2. Book<T1, class Base> information maintenance" << endl;
                    cout << "3. Reader information maintenance" << endl;
                    cout << "Please choose (-1 for upper layer):" << endl;
                    break;
                }
            }
            if (n == 3)
            {
                cout << "1. Add reader" << endl;
                cout << "2. Delete reader" << endl;
                cout << "3. Set reader information" << endl;
                cout << "Choose 1/2/3 (-1 for upper layer):" << endl;
                cin >> n4;
                system("cls");
                if (n4 == 1)
                {
                    readerList.newAdd();
                    cout << "Press any number to return..." << endl;
                    cin >> re;
                }
                if (n4 == 2)
                {
                    cout << "Please input reader account to delete";
                    cin >> note;
                    linReader.no = note;
                    if (Reader *ez = readerList.find(linReader))
                    {
                        readerList.readerStringRemove(note);
                        cout << "Delete successful." << endl;
                    }
                    cout << "Press any number to return..." << endl;
                    cin >> re;
                }
                if (n4 == 3)
                {
                    cout << "Please input reader account to set:";
                    cin >> note;
                    linReader.no = note;
                    if (Reader *rz = readerList.find(linReader))
                    {
                        rz->setReaderInformation();
                        cout << "Set successful." << endl;
                    }
                    else
                        cout << "Account does not exist." << endl;
                    cout << "Press any number to return..." << endl;
                    cin >> re;
                }
                system("cls");
                cout << "1. Display personal information" << endl;
                cout << "2. Book<T1, class Base> information maintenance" << endl;
                cout << "3. Reader information maintenance" << endl;
                cout << "Please choose (-1 for upper layer):" << endl;
            }
            if (n == -1)
                break;
        }
    }
    else
        cout << "Input Error" << endl;
}
void ManagerList::add(Manager &a) // 添加信息
{
    Manager *pn = new Manager(a), *q = head;
    if (!head)
    {
        head = pn;
        pn->next = NULL;
    }
    q = head;
    while (q->next)
        q = q->next;
    q->next = pn;
    pn->next = NULL;
}
void ManagerList::removal(string rev) // 移除
{
    Manager rea(rev), *r = head;
    while (r)
    {
        if (*r == Manager(rea))
        {
            r = r->next;
            delete r;
            break;
        }
        r = r->next;
    }
}
void ManagerList::display()
{
    Manager *pn = head;
    while (pn)
    {
        pn->display();
        pn = pn->next;
    }
}
#endif