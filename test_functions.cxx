/*
 * Name: David Thuita
 *
 * Assignment: Homework 6 ==> modified linkedlistTest.cxx from linkedlist.tar
 */

#include <iomanip>
#include <iostream>
#include <cstring>
#include <new>
#include "scuclass.h"

using namespace std;

namespace coen79_hw6
{
    /*
     * Sample testing code
     * First two trivial functions for traversal.
     * Then testing other stuff.
     */
    int printItem(const int idx, Student *d, void *p)
    {
        cout << setw(2) << idx << ": " << *d << endl;
        *((int *)p) = idx;

        return 0;
    }

    int counter(const int idx, Student *d, void *vp)
    {
        int *ip = (int *)vp;
        ++*ip;
        return 0;
    }

    int testSCUClass()
    {
        SCUClass coen79;

        const char *placeholder = "Student   ";
        string cmd;
        while (cin >> cmd)
        {
            if (cmd == "A" || cmd == "X")
            {
                int id;
                string name;
                cin >> id >> name;
                if (cmd == "A")
                    coen79.insert(id, name);
                else
                    coen79.remove(id);
            }
            else if (cmd == "L")
            {
                int n = 0;
                coen79.traverse(counter, (void *)&n);
                cout << "all input: " << n << endl;
                coen79.traverse(printItem, NULL);
            }
        }
        return EXIT_SUCCESS;
    }
}
