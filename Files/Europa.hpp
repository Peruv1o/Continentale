#ifndef EUROPA_HPP
#define EUROPA_HPP

#include <iostream>
#include <cstdlib>
#include <string>

#include <vector>
#include <stack>
#include <thread>
#include <chrono>
#include <atomic>
#include <algorithm>

#include <fstream>
#include "countries.hpp"

using namespace std;

inline stack<string> countriesInput;
inline atomic<int> seconds(60);
inline atomic<bool> timeUp(false);

inline void timer() 
{
    while (seconds > 0) 
    {
        this_thread::sleep_for(chrono::seconds(1));
        seconds--;
    }
    timeUp = true;
}

inline void Europe() 
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard leftover newline
    system("cls");
    cout << ".-----------------------------------------------------------." << endl;
    cout << "|                    Europe Challenge                       |" << endl;
    cout << ".-----------------------------------------------------------." << endl;
    thread t(timer); // start timer thread

    string input;
    int correct = 0;
    const int maxim = europe.size();

    while (!timeUp) 
    {
        cout << "\nTime remaining: " << seconds << " seconds" << endl;
        cout << "Enter country " << correct << "/" << maxim << ": ";
        if (!getline(cin, input)) break;

        if (timeUp) break;

        // Check if input is a valid European country
        if (find(europe.begin(), europe.end(), input) != europe.end()) 
        {
            // Check if already entered
            bool alreadyEntered = false;
            stack<string> temp = countriesInput;
            while (!temp.empty()) {
                if (temp.top() == input) 
                {
                    alreadyEntered = true;
                    break;
                }
                temp.pop();
            }

            if (!alreadyEntered) 
            {
                countriesInput.push(input);
                correct++;
                cout << "Correct!" << endl;
            } 
            else 
            {
                cout << "You already entered this country!" << endl;
            }
        } 
        else 
        {
            cout << "Country not found in Europe!" << endl;
        }
    }

    t.join();

    // Helper lambda to print countries 5 per row
    auto printCountries5PerRow = [](const vector<string>& countries) 
    {
        int index = 1;
        for (size_t i = 0; i < countries.size(); i++) 
        {
            cout << index << ": " << countries[i] << "\t";
            if (index % 5 == 0) cout << endl;
            index++;
        }
        if (countries.size() % 5 != 0) cout << endl;
    };

    // Convert stack to vector to preserve LIFO order
    vector<string> enteredCountries;
    stack<string> tempStack = countriesInput;
    while (!tempStack.empty()) 
    {
        enteredCountries.push_back(tempStack.top());
        tempStack.pop();
    }

    cout << "\nCountries you entered (top -> bottom):" << endl;
    printCountries5PerRow(enteredCountries);

    // Prepare missed countries
    vector<string> missedCountries;
    for (const auto& country : europe) 
    {
        bool entered = false;
        tempStack = countriesInput;
        while (!tempStack.empty()) 
        {
            if (tempStack.top() == country)
             {
                entered = true;
                break;
            }
            tempStack.pop();
        }
        if (!entered) 
            missedCountries.push_back(country);
    }

    cout << "\nCountries you missed:" << endl;
    printCountries5PerRow(missedCountries);

    cout << "\nYou entered " << correct << " out of " << maxim << " possible countries!" << endl;

    // Save entered countries and count to history.txt
    ofstream outfile("EUhistory.txt", ios::app); // append mode
    outfile << "Game session:\n";

    // Save entered countries
    for (const auto& c : enteredCountries) 
    {
        outfile << c << endl;
    }

    // Save total count
    outfile << "Total countries entered: " << correct << endl;

    // Separate games with a line
    outfile << "---------------------\n";

    outfile.close();
}

#endif
