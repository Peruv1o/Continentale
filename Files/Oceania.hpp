#ifndef OCEANIA_HPP
#define OCEANIA_HPP

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

inline stack<string> OceaniaCountriesInput;
inline atomic<int> secondsOC(60);
inline atomic<bool> timeUpOC(false);

inline void timerOC() 
{
    while (secondsOC > 0) 
    {
        this_thread::sleep_for(chrono::seconds(1));
        secondsOC--;
    }
    timeUpOC = true;
}

inline void OceaniaChallenge() 
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard leftover newline
    system("cls");
    cout << ".-----------------------------------------------------------." << endl;
    cout << "|                      Oceania Challenge                   |" << endl;
    cout << ".-----------------------------------------------------------." << endl;
    thread t(timerOC);

    string input;
    int correct = 0;
    const int maxim = oceania.size();

    while (!timeUpOC) 
    {
        cout << "\nTime remaining: " << secondsOC << " seconds" << endl;
        cout << "Enter country " << correct << "/" << maxim << ": ";
        if (!getline(cin, input)) break;

        if (timeUpOC) break;

        if (find(oceania.begin(), oceania.end(), input) != oceania.end()) 
        {
            bool alreadyEntered = false;
            stack<string> temp = OceaniaCountriesInput;
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
                OceaniaCountriesInput.push(input);
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
            cout << "Country not found in Oceania!" << endl;
        }
    }

    t.join();

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

    vector<string> enteredCountries;
    stack<string> tempStack = OceaniaCountriesInput;
    while (!tempStack.empty()) 
    {
        enteredCountries.push_back(tempStack.top());
        tempStack.pop();
    }

    cout << "\nCountries you entered (top -> bottom):" << endl;
    printCountries5PerRow(enteredCountries);

    vector<string> missedCountries;
    for (const auto& country : oceania) 
    {
        bool entered = false;
        tempStack = OceaniaCountriesInput;
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

    // Save history
    ofstream outfile("OChistory.txt", ios::app);
    outfile << "Game session:\n";
    for (const auto& c : enteredCountries) 
    {
        outfile << c << endl;
    }
    outfile << "Total countries entered: " << correct << endl;
    outfile << "---------------------\n";
    outfile.close();
}

#endif
