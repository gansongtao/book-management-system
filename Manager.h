#include "People.cpp"
class Manager : public People
{
private:
    string pass;

public:
    Manager *next;
    Manager(string no, string name, string p);
    string getmpass();
    string mpeople(string a);
    void display();
    Manager setManager(string account, string password);
    void gname();
    void gpass();
    void managerDisplay();
    bool operator==(const Manager &m);
};