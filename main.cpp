#include <iostream>
#include <string>
#include <cstdlib>

#include "Files/continents.hpp"
#include "Files/countries.hpp"
#include "Files/history.hpp"


#include "Files/Europa.hpp"
#include "Files/NorthAmerica.hpp"
#include "Files/SouthAmerica.hpp"
#include "Files/Africa.hpp"
#include "Files/Asia.hpp"
#include "Files/Oceania.hpp"


using namespace std;

void continentSelector();
void mainMenu();
void historyChooser();


int main()
{
    mainMenu();
}

void mainMenu()
{
    system("cls");
    cout << ".-----------------------------------------------------------." << endl;
    cout << "|                 Welcome to 'Continentale'                 |" << endl;
    cout << ".-----------------------------------------------------------." << endl << endl << endl;

    cout << ".-----------------------------------------------------------." << endl;
    cout << "|                   [1]   Play Game                         |" << endl;
    cout << ".-----------------------------------------------------------." << endl;

    cout << ".-----------------------------------------------------------." << endl;
    cout << "|                   [2]  View History                       |" << endl;
    cout << ".-----------------------------------------------------------." << endl;

    cout << ".-----------------------------------------------------------." << endl;
    cout << "|                   [3]   Exit Game                         |" << endl;
    cout << ".-----------------------------------------------------------." << endl << endl;

    cout << "Enter Option: ";

    int choice;
    cin >> choice;
    switch(choice)
    {
        case 1: continentSelector(); break;
        case 2: historyChooser(); break; // implement this
        case 3: exit(0);
        default: cout << "Invalid option. Try again."; mainMenu(); break;
    }
}

void continentSelector()
{
    system("cls");

    cout << ".-----------------------------------------------------------." << endl;
    cout << "|                   Choose the continent                    |" << endl;
    cout << ".-----------------------------------------------------------." << endl << endl << endl;


    for(int i = 1; i <= continents.size(); i++)
    {
        cout << i << ": " << continents[i-1] << endl;
        cout << "---------------------------------------------------------" << endl << endl;
    }

        cout << "0: Back to Main Menu" << endl;
        cout << "---------------------------------------------------------" << endl << endl;
    cout << '\n';
    cout << "Enter Option: ";

    int choice;
    cin >> choice;
    switch(choice)
    {
        case 0: mainMenu();
        case 1: Europe();
                system("pause");
                mainMenu();
                break;
        case 2: NorthAmericaChallenge();
                system("pause");
                mainMenu();
                break;
        case 3: SouthAmericaChallenge();
                system("pause");
                mainMenu();
                break;
        case 4: AfricaChallenge();
                system("pause");
                mainMenu();
                break;
        case 5: AsiaChallenge();
                system("pause");
                mainMenu();
                break;
        case 6: OceaniaChallenge();
                system("pause");
                mainMenu();
                break;
        default : mainMenu(); break;
    }
}

void historyChooser()
{
    system("cls");

    cout << ".-----------------------------------------------------------." << endl;
    cout << "|              Choose the continent's history               |" << endl;
    cout << ".-----------------------------------------------------------." << endl << endl << endl;


    for(int i = 1; i <= continents.size(); i++)
    {
        cout << i << ": " << continents[i-1] << endl;
        cout << "---------------------------------------------------------" << endl << endl;
    }
        cout << "0: Back to Main Menu" << endl;
        cout << "---------------------------------------------------------" << endl << endl;
    

    cout << "Enter Option: ";

    int choice;
    cin >> choice;
    switch(choice)
    {
        case 0: mainMenu();

        case 1: system("cls");
                viewEU_History();
                system("pause");
                mainMenu();
                break;
        case 2: system("cls");
                viewNA_History();
                system("pause");
                mainMenu();
                break;
        case 3: system("cls");
                viewSA_History();
                system("pause");
                mainMenu();
                break;
        case 4: system("cls");
                viewAF_History();
                system("pause");
                mainMenu();
                break;
        case 5: system("cls");
                viewAS_History();
                system("pause");
                mainMenu();
                break;
        case 6: system("cls");
                viewOC_History();
                system("pause");
                mainMenu();
                break;
        default : mainMenu(); break;
        
    }
}
