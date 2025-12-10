#include "ManagerList.cpp"
int main()
{
    std::ios::sync_with_stdio(false);
    Reader reader2, reader3;
    Manager manager2, manager3;
    string a, b, c, d, ds, es, fs, gs, hs, is, js, ks, account, password;
    int e, f, g, i1 = 0;
    char re = 0;
    ifstream inbook("book.txt", ios::in);
    BookList<int, Base> blist;
    ReaderList rlist;
    ManagerList mlist;
    while (inbook >> a >> b >> c >> d >> e >> f >> g)
    {
        Base temp(b, c, d, e, f, g);
        Book<int, Base> rea(a, temp);
        blist.add(rea);
    }
    inbook.close();
    ifstream inreader("reader.txt", ios::in);
    while (inreader >> a >> b >> c >> ds >> es >> fs >> gs >> hs >> is >> js >> ks)
    {
        Reader reader1(a, b, c);
        reader1.setalbno(ds, es, fs, gs, hs, is, js, ks);
        rlist.add(reader1);
    }
    inreader.close();
    ifstream inmanager("manager.txt", ios::in);
    while (inmanager >> a >> b >> c)
    {
        Manager manager1(a, b, c);
        mlist.add(manager1);
    }
    inmanager.close();
    cout << "Welcome to Book<T1, class Base> Management System" << endl;
    cout << "1.Search for book" << endl;
    cout << "2.Reader login" << endl;
    cout << "3.Manager login" << endl;
    cout << "------------------------------------------------------\n";
    cout << "Please choose (1/2/3, -1 for exit):";
    while (cin >> i1)
    {
        system("cls");
        switch (i1)
        {
        case 1:
            cout << "----------------------------------\n";
            blist.find();
            cout << "Press any number to return..." << endl;
            cin >> re;
            break;
        case 2:
            cout << "----------------------------------" << endl;
            cout << "Account ";
            cin >> account;
            cout << "Password ";
            cin >> password;
            reader3 = reader2.setReader(account, password);
            rlist.load(reader3, blist, rlist);
            system("cls");
            break;
        case 3:
            cout << "----------------------------------" << endl;
            cout << "Account ";
            cin >> account;
            cout << "Password ";
            cin >> password;
            manager3 = manager2.setManager(account, password);
            mlist.load(manager3, blist, rlist);
            system("cls");
            break;
        case -1:
            blist.write();
            rlist.write();
            cout << "Thanks for using." << endl;
            break;
        default:
            cout << "Input Error" << endl;
            break;
        }
        if (i1 == -1)
            return 0;
        cout << "Welcome to Book<T1, class Base> Management System" << endl;
        cout << "1.Search for book" << endl;
        cout << "2.Reader login" << endl;
        cout << "3.Manager login" << endl;
        cout << "------------------------------------------------------\n";
        cout << "Please choose (1/2/3, -1 for exit):";
    }
    return 0;
}