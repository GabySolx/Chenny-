#include "pch.h"
#include <conio.h>
#include <time.h>
#include <iostream>

using namespace std;

void generatearray(int* myarray, short n)
{
    for (short i = 0; i < n; i++) 
    {
        myarray[i] = 1 + rand() % 30;
    }
}

void printarray(int* myarray, short n)
{
    for (short i = 0; i < n; i++)
    {
        cout << myarray[i] << "   ";
    }
    cout << endl;
}

void bubblesort(int*myarray, short n) 
{
    int aux;

    for (short i = 0; i < n - 1; i++)
    {
        for (short j = 0; j < n - 1 - i; j++)
        {
            if (myarray[j] > myarray[j + 1])
            {
                aux = myarray[j];
                myarray[j] = myarray[j + 1];
                myarray[j + 1] = aux;
            }
        }
    }
}

void repeat(int*myarray, short n)
{
    short counter = 0;
    int aux = myarray[0];
    for (short i = 0; i < n; i++)
    {
        for (short j = 0; j < n - 1; j++)
        {
            if (myarray[i] == myarray[j])
            {
                counter += 1;
                aux = myarray[i];
                myarray[i] = myarray[j];
                myarray[j] = aux;
            }
            else
            {
                counter = 1;
            }
            
        }
    }
    cout << "The number " << aux << " is repeated " << counter << " times" << endl;
}

void erase(int* myarray, short n)
{
    for (short i = 0; i < n; i++) 
    {
        for (short j = 0; j < n; j++) 
        {
            if (i != j)
            {
                if (myarray[i] == myarray[j])
                {
                    myarray[j] = NULL;
                }
            }
        }
    }
}

void menu()
{
    cout << "1. Print numbers" << endl;
    cout << "2. Execute bubble sort" << endl;
    cout << "3. Repeated numbers" << endl; 
    cout << "4. Delete repeated numbers" << endl;
    cout << "5. Exit" << endl;
}

int main()
{
    srand(time(NULL));
    short op; short n = 10;

    int* myarray = new int[n];

    generatearray(myarray, n);

    while (true)
    {
        menu();
        cout << "Enter the option: ", cin >> op;
        switch (op)
        {
        case 1:
            printarray(myarray, n); break;
        case 2: 
            bubblesort(myarray, n); break;
        case 3: 
            repeat(myarray, n); break;
        case 4: 
            erase(myarray, n); break;
        case 5:
            exit(0); break;
        }

        getch();
        system("cls");
    }

    getch();
    return 0;
}
