#include "class.h"

int main() {
    particella a(1,1.6E-19);
    elettrone *e=new elettrone();

    cout << "particella " << a.getmassa() << ", " << a.getcarica() << endl;
    a.print(); 
    cout << "elettrone " << e->getmassa() << ", " << e->getcarica() << endl;
    e->print();

    particella b(a);
    particella d(*e);
    elettrone  f(d);

    return 0;
}
