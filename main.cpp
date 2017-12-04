/**
 * Cashion Penha
 * Lab 6
 * Decimal/ Binary Numbering Systems Conversion
 * 09/10/2017
 */

/**< preprocessor directives / header files*/
#include <iostream>
#include <cstdio>
#include <windows.h>
#include <math.h>

using namespace std;/** Includes commonly used tools, such as cout, cin, To prevent typing "std" */


/**< Binary to decimal function, separate function to convert from binary to decimal*/
int bin_2_dec(long long n)
{
    int decimal=0, i=0, remainder;
    while (n!=0)// looping until n is not equal to 0
    {
        remainder = n%10;
        n = n/10;
        decimal= decimal+remainder*pow(2,i);
        ++i;
    }
    return decimal; // returning the decimal value as result of the function
}

/**< Decimal to Binary function, separate function to convert from decimal to binary*/
int dec_2_bin(long long x)
{
    int re,binary=0,i=1;
    while (x!=0)
    {
      re=x%2;
      x=x/2;
      binary=binary+(re*i);
      i=i*10;
    }
    return binary;
}

/**< Separate function to display the menu when called in the main function*/
void menu(void)
{
	/**< clear screen - not good programming practice! - system specific */
	system("cls");

	/**< print menu */
	cout << "_______________________________________________" <<
            "\nDecimal / Binary Numbering Systems Conversion" <<
			"\n\nChoose from one of the following:" <<
			"\nb - Binary to decimal" <<
			"\nd - Decimal to binary"
			"\nq - quit" <<
			"\n_______________________________________________" <<endl;

	return;
}


/**< main function */
int main(void)
{
	/**< variable declarations */
	char input;

	/**< continue running program until q is pressed */
	do
	{
		/**< display menu and get user input */
		menu();
		fflush(stdin);
		cin >> input;
		fflush(stdin);

		/**< switch case statement to implement user's decision */
		switch (input)
		{
			/**< When b is entered by user, get values from user, and call the binary to decimal function */
			case 'b':   cout << "\nBinary to decimal conversion...\n" << endl;
                        long long n;
                        cout << "Enter a binary number: ";
                        cin >> n;
                        cout << n << " in binary = " << bin_2_dec(n) << " in decimal";
                        fflush(stdin);/**< Used to clear the buffer before displaying the menu again*/
						getchar();
						break;

			/**< When d is entered by user, get values from user, and call the decimal to binary */
			case 'd':   cout << "\nDecimal to binary conversion...\n" << endl;
                        long long x;
                        cout << "Enter a decimal number: ";
                        cin >> x;
                        cout << x << " in decimal = " << dec_2_bin(x) << " in binary";
                        fflush(stdin);
						getchar();
						break;

			/**< When q is entered by user, provide salutation and end the program*/
			case 'q':   cout << "\nThanks for using the program, Goodbye...\n" << endl;
                        cout << "Press any key to close window"<< endl;
                        fflush(stdin);
                        break;

            /**< When unknown value is entered by user, display the error and display menu again after a key is pressed */
			default:	cout << "\nInvalid input, try again...\n" << endl;
						/**< wait for key to be pressed */
						cout << "Press any key to continue..." << endl;
						fflush(stdin);
						getchar();
						break;
		}
	}
	while (input != 'q');/**< Keep looping until q is not entered by the user */

	return 0;
}
