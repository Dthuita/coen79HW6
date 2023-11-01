
#include <iostream>
#include <iomanip> //needed for setw()
#include <vector>
#include "scuclass.h"

using namespace coen79_hw6;
using namespace std;

int printItem(const int idx, Student *d, void *p)
{
    cout << setw(2) << idx << ": " << *d << endl;
    *((int *)p) = idx; // for personal use to combine counter and printnode function

    return 0;
}

int main()
{

    ///////////////DEBUGGING line by line code///////////////

    SCUClass coen79;

    coen79.insert(1234, "Dav");
    coen79.insert(2344, "Poll");
    coen79.insert(6969, "Cool");

    int n = 0;
    coen79.traverse(printItem, (void *)&n);
    cout << "total students is: " << n + 1 << endl;

    coen79.remove(2344);

    int x = 0;
    coen79.traverse(printItem, (void *)&x);
    cout << "total students is: " << x + 1 << endl;
}