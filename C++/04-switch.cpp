/*
===============================================================================
 04 - SWITCH STATEMENT
===============================================================================
 No input needed (we loop over sample values instead of reading one).

 Problem: Given a day number 1-7, print the day name.
          1 = Monday, 2 = Tuesday ... 7 = Sunday. Anything else -> error.

 When to use switch instead of if-else?
   - You compare ONE variable against many FIXED values (int / char / enum).
   - switch does NOT work with strings, doubles, or ranges like (x > 5).
===============================================================================
*/

#include <bits/stdc++.h>
using namespace std;

void printDay(int day)
{
    switch (day)               // the value being checked
    {
    case 1:                    // runs if day == 1
        cout << "Monday";
        break;                 // JUMP OUT of the switch. Without it, the next case runs too!
    case 2:
        cout << "Tuesday";
        break;
    case 3:
        cout << "Wednesday";
        break;
    case 4:
        cout << "Thursday";
        break;
    case 5:
        cout << "Friday";
        break;
    case 6:
        cout << "Saturday";
        break;
    case 7:
        cout << "Sunday";
        break;
    default:                   // runs when NO case matches (like the final else)
        cout << "Wrong day - check again";
    }
    cout << "\n";
}

// FALL-THROUGH: if you leave out break, execution "falls" into the next case.
// Sometimes this is used ON PURPOSE to group cases together.
void dayType(int day)
{
    switch (day)
    {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        cout << day << " -> Weekday\n";   // 1,2,3,4,5 all land here
        break;
    case 6:
    case 7:
        cout << day << " -> Weekend\n";
        break;
    default:
        cout << day << " -> Invalid\n";
    }
}

// switch on a char
void isVowel(char ch)
{
    switch (ch)
    {
    case 'a': case 'e': case 'i': case 'o': case 'u':
        cout << ch << " is a vowel\n";
        break;
    default:
        cout << ch << " is a consonant\n";
    }
}

int main()
{
    for (int day = 0; day <= 8; day++) {   // 0 and 8 show the default case
        cout << day << ": ";
        printDay(day);
    }

    dayType(3);
    dayType(7);
    dayType(9);

    isVowel('e');
    isVowel('k');

    // To read the day from input instead:
    //   int day; cin >> day; printDay(day);

    return 0;
}

/*
 EXPECTED OUTPUT:
 0: Wrong day - check again
 1: Monday
 2: Tuesday
 3: Wednesday
 4: Thursday
 5: Friday
 6: Saturday
 7: Sunday
 8: Wrong day - check again
 3 -> Weekday
 7 -> Weekend
 9 -> Invalid
 e is a vowel
 k is a consonant

 BUG THAT WAS IN THE OLD VERSION OF THIS FILE:
   `return 0;` was written INSIDE the default case, so main() had no
   return on the normal path. Always keep `return 0;` at the end of main,
   outside the switch.
*/
