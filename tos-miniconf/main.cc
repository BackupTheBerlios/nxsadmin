/* 
 * File:   termos-xconf.h
 * Author: Maxim Stjazhkin, maxim.stjazhkin@ukrpost.ua
 *
 * Created on 28 липня 2008, 16:13
 */

#include <iostream>
#include <fstream>

/*
 * 
 */
using namespace std;

int main(int argc, char** argv) {

    char ch;
    char str[256];

    ofstream fout("test.dat");
    if (!fout) {
        cout << "Cannot open file for output.\n";
        return 1;
    }

    fout << "This is a line of text.\n";
    fout << "This is another line of text.\n";
    fout << "This is the last line of text.\n";

    fout.close();
    if (!fout.good()) {
        cout << "An error occured when writing to the file.\n";
        return 1;
    }

    ifstream fin("test.dat", ios::in);
    if (!fin) {
        cout << "Cannot open file for input.\n";
        return 1;
    }

    cout << "Use get():\n";
    cout << "Here are the first three characters: ";
    for (int i = 0; i < 3; ++i) {
        fin.get(ch);
        cout << ch;
    }
    cout << endl;

    fin.get(str, 255);
    cout << "Here is the rest of the first line: ";
    cout << str << endl;
    fin.get(ch);

    cout << "\nNow use getline():\n";
    fin.getline(str, 255);
    cout << str << endl;
    fin.getline(str, 255);
    cout << str;
    
    fin.close();
    if (!fin.good()) {
        cout << "Error occured while reading or closing the file.\n";
        return 1;
    }

    return (EXIT_SUCCESS);
}

