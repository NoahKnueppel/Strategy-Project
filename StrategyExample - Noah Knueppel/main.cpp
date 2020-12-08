#include <iostream>
using namespace std;
 
class SandwichPB
{
    public:
        virtual void sort() const = 0;
};
 
class Crunchy: public SandwichPB 
{
    public:
        virtual void sort() const {
            cout << "Crunchy Peanut Butter\n";
        }
};
 
class Creamy: public SandwichPB {
    public:
        virtual void sort() const {
            cout << "Creamy Peanut Butter\n";
        }
};
 
class LowFat: public SandwichPB
{
    public:
        virtual void sort() const {
            cout << "Low Fat Peanut Butter\n";
        }
};
 
class SandwichJelly 
{
    public:
        virtual void search() const = 0;
};
 
class Grape: public SandwichJelly 
{
    public:
        virtual void search() const {
            cout << "Grape Jelly\n";
        }
};

class Strawberry: public SandwichJelly 
{
    public:
        virtual void search() const {
            cout << "Strawberry Jelly\n";
        }
};

class Raspberry: public SandwichJelly 
{
    public:
        virtual void search() const {
            cout << "Raspberry Jelly\n";
        }
};

// Context
class Collection 
{
    private:
        SandwichPB* m_sort;
        SandwichJelly* m_search;
    public:
        Collection(){}
        void set_sort(SandwichPB* s){
            m_sort = s;
        }
        void set_search(SandwichJelly* s){
            m_search = s;
        }
        void sort() const {
            m_sort->sort();
        }
        void search() const {
            m_search->search();
        }
};
 
 
int main(int argc, char *argv[])
{
    Crunchy crunchy;
    Creamy creamy;
    LowFat lowfat;

    Grape grape;
    Strawberry strawberry;
    Raspberry raspberry;
 
    Collection colA;
    colA.set_sort(&crunchy);
    colA.sort();

    Collection colB;
    colB.set_search(&strawberry);
    colB.search();

    return 0;
}