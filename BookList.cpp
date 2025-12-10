#ifndef BOOKLIST
#define BOOKLIST
#include <fstream>
#include "Book.cpp"
template <typename T1, class T2>
class BookList
{
    int size;
    Book<T1, T2> *r = NULL, *f = NULL;

public:
    ~BookList<T1, T2>()
    {
        DestroyBTree(r);
        r = NULL;
    }
    void DestroyBTree(Book<T1, T2> *b)
    {
        if (b)
        {
            DestroyBTree(b->lchild);
            DestroyBTree(b->rchild);
            delete b;
        }
    }
    int getht(Book<T1, T2> *p)
    {
        if (p == NULL)
            return 0;
        return p->ht;
    }
    Book<T1, T2> *right_rotate(Book<T1, T2> *a)
    {
        Book<T1, T2> *b = a->lchild;
        a->lchild = b->rchild;
        b->rchild = a;
        a->ht = max(getht(a->rchild), getht(a->lchild)) + 1;
        b->ht = max(getht(b->rchild), getht(b->lchild)) + 1;
        return b;
    }
    Book<T1, T2> *LL(Book<T1, T2> *a)
    {
        return right_rotate(a);
    }
    Book<T1, T2> *left_rotate(Book<T1, T2> *a)
    {
        Book<T1, T2> *b = a->rchild;
        a->rchild = b->lchild;
        b->lchild = a;
        a->ht = max(getht(a->rchild), getht(a->lchild)) + 1;
        b->ht = max(getht(b->rchild), getht(b->lchild)) + 1;
        return b;
    }
    Book<T1, T2> *RR(Book<T1, T2> *a)
    {
        return left_rotate(a);
    }
    Book<T1, T2> *LR(Book<T1, T2> *a)
    {
        Book<T1, T2> *b = a->lchild;
        a->lchild = left_rotate(b);
        return right_rotate(a);
    }
    Book<T1, T2> *RL(Book<T1, T2> *a)
    {
        Book<T1, T2> *b = a->rchild;
        a->rchild = right_rotate(b);
        return left_rotate(a);
    }
    Book<T1, T2> *SearchAVL(string k)
    {
        return _SearchAVL(r, k);
    }
    Book<T1, T2> *_SearchAVL(Book<T1, T2> *p, string k)
    {
        if (p == NULL)
            return NULL;
        if (p->key == k)
            return p;
        if (k < p->key)
            return _SearchAVL(p->lchild, k);
        else
            return _SearchAVL(p->rchild, k);
    }
    Book<T1, T2> *balance(Book<T1, T2> *t)
    {
        if (t == NULL)
            return t;
        if (getht(t->lchild) - getht(t->rchild) > 1)
        {
            if (getht(t->lchild->lchild) >= getht(t->lchild->rchild))
                t = RR(t);
            else
                t = RL(t);
        }
        else if (getht(t->rchild) - getht(t->lchild) > 1)
        {
            if (getht(t->rchild->rchild) >= getht(t->rchild->lchild))
                t = LL(t);
            else
                t = LR(t);
        }
        t->ht = max(getht(t->lchild), getht(t->rchild)) + 1;
        return t;
    }
    void InsertAVL(string k, Base d)
    {
        r = _InsertAVL(r, k, d);
    }
    Book<T1, T2> *_InsertAVL(Book<T1, T2> *p, string k, Base d)
    {
        if (p == NULL)
            return new Book<T1, T2>(k, d);
        else if (k.compare(p->key) < 0)
            p->lchild = _InsertAVL(p->lchild, k, d);
        else if (k.compare(p->key) > 0)
            p->rchild = _InsertAVL(p->rchild, k, d);
        else
            p->data = d;
        if (p->lchild && p->rchild)
            return balance(p);
        else
            return p;
    }
    Book<T1, T2> *findMin(Book<T1, T2> *t)
    {
        if (t == NULL)
            return t;
        if (t->lchild)
            return findMin(t->lchild);
        return t;
    }
    Book<T1, T2> *DeleteAVL(string element)
    {
        return _DeleteAVL(element, r);
    }
    Book<T1, T2> *_DeleteAVL(string element, Book<T1, T2> *t)
    {
        if (t == NULL)
            return t;
        if (element.compare(t->key) > 0)
            t->rchild = _DeleteAVL(element, t->rchild);
        else if (element.compare(t->key) < 0)
            t->lchild = _DeleteAVL(element, t->lchild);
        else if (t->lchild && t->rchild)
        {
            t->key = findMin(t->rchild)->key;
            t->rchild = _DeleteAVL(t->key, t->rchild);
        }
        else
            t = t->lchild == NULL ? t->rchild : t->lchild;
        if (t->lchild && t->rchild)
            return balance(t);
        return t;
    }
    Book<T1, T2> *allFind(string k)
    {
        return SearchAVL(k);
    }
    void find() // 查找
    {
        int n = 0;
        string nu = "null", nam = "null";
        Book<T1, T2> *linBook, *r;
        cout << "Please input book number:";
        cin >> nu;
        if (linBook = allFind(nu))
            linBook->bookDisplay();
        else
            cout << "Not Found" << endl;
    }
    void add(Book<T1, T2> &a) // 添加信息
    {
        InsertAVL(a.key, a.data);
    }
    void writing(Book<T1, T2> *head, ofstream &out) // 写入文件
    {
        if (head)
        {
            writing(head->lchild, out);
            Base temp = head->data;
            out << head->gbno() << ' ' << temp.gbname() << ' ' << temp.gauthor() << ' ' << temp.gpress() << ' ' << temp.gborrownum() << ' ' << temp.gstorenum() << ' ' << temp.gcanBorrow() << endl;
            writing(head->rchild, out);
        }
    }
    void write()
    {
        ofstream out("book1.txt");
        writing(r, out);
        out.close();
        remove("book.txt");
        rename("book1.txt", "book.txt");
    }
    void readerBookFind(string are) // 读者信息中图书查找
    {
        Book<T1, T2> *b = SearchAVL(are);
        Base temp = b->data;
        cout << "Book number:" << b->gbno() << "\tBook name:" << temp.gbname() << "\tAuthor:" << temp.gauthor() << "\tPress:" << temp.gpress() << endl;
    }
    void stringRemove(string str) // 依靠字符来移除信息
    {
        if (Book<T1, T2> *bz = allFind(str))
            DeleteAVL(bz->key);
    }
};
#endif