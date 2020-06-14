// Lab_1_vector.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Vector.h"
Vector<float> vector(3, 4, 5, "First");
Vector<float> vector1(1, 2, 3, "Second");
Vector<float> result(0, 0, 0, "Result");
float res;
uint8_t input_key = '0';
bool truevalue;
using namespace std;
void print_menu(void)
{
    cout << "\n -----------------------------------------------\n";
    cout << "|0. Exit from Application                       |\n";
    cout << "|1. Write/edit vector.                          |\n";
    cout << "|2. Display vector.                             |\n";
    cout << "|3. X + Y.                                      |\n";
    cout << "|4. X - Y.                                      |\n";
    cout << "|5. Vector multiplication.                      |\n";
    cout << "|6. Scalar multiplication.                      |\n";
    cout << "|7. Multiplicate on num.                        |\n";
    cout << "|8. Module of vector.                           |\n";
    cout << " -----------------------------------------------\n";
}

int main()
{

    while (1)
    {
        if (input_key != '0')
        {
            cout << "Rebooting...\n";
        }
        else
        {
            cout << "Starting program!\n";
        }

        input_key = '0';
        res = 0;
        truevalue = true;

        while (truevalue)
        {

            do
            {
                print_menu();
                cin >> input_key;
                fflush(stdin);

                switch (input_key)
                {
                case '0':
                    break;

                case'1':
                    cout << "Choose number:" << endl;
                    cout << "1 -" << vector.getname() << endl;
                    cout << "2 -" << vector1.getname() << endl;
                    cin >> input_key;
                    if (input_key == '1')
                    {
                        cin >> vector;
                    }
                    else if (input_key == '2')
                    {
                        cin >> vector1;
                    }
                    else
                    {
                        cout << "Incorrect input!" << endl;
                        truevalue = false;
                    }
                    break;

                case '2':
                    cout << "Choose number:" << endl;
                    cout << "1 -" << vector.getname() << endl;
                    cout << "2 -" << vector1.getname() << endl;
                    cin >> input_key;
                    if (input_key == '1')
                    {
                        cout << vector;
                    }
                    else if (input_key == '2')
                    {
                        cout << vector1;
                    }
                    else
                    {
                        cout << "Incorrect input!" << endl;
                        truevalue = false;
                    }
                    break;

                case '3':
                    result = vector + vector1;
                    cout << result;
                    break;

                case '4':
                    cout << "Choose :" << endl;
                    cout << "1 :" << vector.getname() << "-" << vector1.getname() << endl;
                    cout << "2 :" << vector1.getname() << "-" << vector.getname() << endl;
                    cin >> input_key;
                    if (input_key == '1')
                    {
                        result = vector - vector1;
                        cout << result;
                    }
                    else if (input_key == '2')
                    {
                        result = vector1 - vector;
                        cout << result;
                    }
                    else
                    {
                        cout << "Incorrect input!" << endl;
                        truevalue = false;
                    }
                    break;
                   

                case '5':
                    res = vector * vector1;
                    cout << "Result:" << res << endl;
                    break;

                case '6':
                    result = vector ^ vector1;
                    cout << result;
                    break;

                case '7':
                    cout << "Choose number:" << endl;
                    cout << "1 :" << vector.getname() <<  endl;
                    cout << "2 :" << vector1.getname() << endl;
                    cin >> input_key;
                    cout << "Write num multiplicate on" << endl;
                    cin >> res;
                    if (input_key == '1')
                    {
                        vector.multnum(res);
                        cout << vector;
                    }
                    else if (input_key == '2')
                    {
                        vector1.multnum(res);
                        cout << vector;
                    }
                    else
                    {
                        cout << "Incorrect input!" << endl;
                        truevalue = false;
                    }
                    break;
                case '8':
                    cout << "Choose number:" << endl;
                    cout << "1 :" << vector.getname() << endl;
                    cout << "2 :" << vector1.getname() << endl;
                    cin >> input_key;
                    if (input_key == '1')
                    {
                        res = vector.getmodule();
                        cout << res;
                    }
                    else if (input_key == '2')
                    {
                        res = vector1.getmodule();
                        cout << res;
                    }
                    else
                    {
                        cout << "Incorrect input!" << endl;
                        truevalue = false;
                    }
                    break;

                default:
                    cout << "Input key is incorrect\n";
                    truevalue = false;
                    break;
                }
            } while (input_key != '0');
            cout << "Your sure want to exit?\n" << "Y - yes\n" << "N - no\n";
            cin >> input_key;
            if (input_key == 'Y')
            {
                cout << "GOOD BYE!\n";
                return 0;
            }
            else
            {
                truevalue = false;
            }
        }
    }
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
