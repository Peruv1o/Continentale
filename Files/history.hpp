#ifndef HISTORY_HPP
#define HISTORY_HPP

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

inline void viewEU_History() 
{
    ifstream infile("Files/EUhistory.txt");
    if (!infile.is_open()) 
    {
        cout << "No history found!" << endl;
        return;
    }

    string line;
    cout << "\n--- History ---\n";
    while (getline(infile, line)) 
    {
        cout << line << endl;
    }
    infile.close();
    cout << "----------------\n";
}

inline void viewNA_History() 
{
    ifstream infile("Files/NAhistory.txt");
    if (!infile.is_open()) 
    {
        cout << "No history found!" << endl;
        return;
    }

    string line;
    cout << "\n--- North America History ---\n";
    while (getline(infile, line)) 
    {
        cout << line << endl;
    }
    infile.close();
    cout << "----------------\n";
}

inline void viewSA_History() 
{
    ifstream infile("Files/SAhistory.txt");
    if (!infile.is_open()) 
    {
        cout << "No history found!" << endl;
        return;
    }

    string line;
    cout << "\n--- South America History ---\n";
    while (getline(infile, line)) 
    {
        cout << line << endl;
    }
    infile.close();
    cout << "----------------\n";
}

inline void viewAF_History() 
{
    ifstream infile("Files/AFhistory.txt");
    if (!infile.is_open()) 
    {
        cout << "No history found!" << endl;
        return;
    }

    string line;
    cout << "\n--- Africa History ---\n";
    while (getline(infile, line)) 
    {
        cout << line << endl;
    }
    infile.close();
    cout << "----------------\n";
}

inline void viewAS_History() 
{
    ifstream infile("Files/AShistory.txt");
    if (!infile.is_open()) 
    {
        cout << "No history found!" << endl;
        return;
    }

    string line;
    cout << "\n--- Asia History ---\n";
    while (getline(infile, line)) 
    {
        cout << line << endl;
    }
    infile.close();
    cout << "----------------\n";
}

inline void viewOC_History() 
{
    ifstream infile("Files/OChistory.txt");
    if (!infile.is_open()) 
    {
        cout << "No history found!" << endl;
        return;
    }

    string line;
    cout << "\n--- Oceania History ---\n";
    while (getline(infile, line)) 
    {
        cout << line << endl;
    }
    infile.close();
    cout << "----------------\n";
}


#endif
