#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <cstring>
#include <new>
#include "scuclass.h"

// add ons to remove white space
#include <algorithm>
#include <cctype>

using namespace std;
using namespace coen79_hw6;

int printItem(const int idx, Student *d, void *p)
{
    cout << setw(2) << idx << ": " << *d << endl;

    return 0;
}

int counter(const int idx, Student *d, void *vp)
{
    int *ip = (int *)vp;
    ++*ip;
    return 0;
}
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cerr << "Usage: " << argv[0] << " <input_file>" << endl;
        return 1;
    }

    SCUClass coen79;

    ifstream inputFile(argv[1], ios::in);

    if (inputFile.is_open())
    {
        string line;
        while (getline(inputFile, line)) // read txt file line by line
        {
            // reset reading variables
            string CMD, name;
            int id;

            // seperation variables
            int count = 0;
            string word = "";

            // seperate data into diff variables
            for (int i = 0; i <= line.length(); i++)
            {
                if (line[i] == ' ' || line[i] == '\0')
                {
                    count++;
                    if (count == 1)
                    {
                        CMD = word;
                    }
                    else if (count == 2)
                    {
                        id = stoi(word);
                    }
                    else if (count == 3)
                    {
                        // removes white space
                        word.erase(std::remove_if(word.begin(), word.end(), ::isspace), word.end());
                        name = word;
                    }
                    word = "";
                }
                else
                {
                    word += line[i];
                }
            }

            // debug statement to get the command copied from txt file
            //  cout << CMD << " : " << studentID << " : " << firstName << endl << endl;

            if (CMD.compare("Student") == 0) // skip first line of txt file
                continue;

            if (CMD == "A" || CMD == "X")
            {
                if (CMD == "A")
                {
                    cout << "inserting ==> " << id << " : " << name << endl;
                    coen79.insert(id, name);
                }
                else
                {
                    coen79.remove(id);
                }
            }
            else if (CMD == "L")
            {
                int n = 0;
                coen79.traverse(counter, (void *)&n);
                cout << "all input: " << n << endl;
                coen79.traverse(printItem, NULL);
            }
        }

        inputFile.close(); // close the file
    }
    else
    {
        cerr << "Error opening input file: " << argv[1] << endl;
        return 1;
    }
    return 1;
}
