/*
===============================================================================
 08 - STRINGS
===============================================================================
 No input needed.

 A string is a sequence of characters. In C++ you have two kinds:
   1. C-style char array:  char name[] = "abc";   -> stored as 'a' 'b' 'c' '\0'
      ('\0' = null character, marks the end). Old style, avoid in DSA.
   2. std::string:         string name = "abc";   -> USE THIS. Grows automatically,
      has many built-in functions, can be compared with ==, joined with +.

 A string behaves like an array of chars: s[0] is the first character.
===============================================================================
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    // ---------------------------------------------------------------
    // 1. Create, length, access
    // ---------------------------------------------------------------
    string s = "hello";
    cout << "s = " << s << ", length = " << s.length() << " (same as s.size())\n";
    cout << "first = " << s[0] << ", last = " << s[s.size() - 1] << " (or s.back())\n";

    s[0] = 'H';                       // strings are MUTABLE in C++
    cout << "after s[0]='H': " << s << "\n";

    // ---------------------------------------------------------------
    // 2. Traversal
    // ---------------------------------------------------------------
    cout << "chars: ";
    for (int i = 0; i < (int)s.size(); i++) cout << s[i] << "-";
    cout << "\n";

    cout << "for-each: ";
    for (char ch : s) cout << ch << " ";
    cout << "\n";

    // ---------------------------------------------------------------
    // 3. Concatenation & append
    // ---------------------------------------------------------------
    string first = "Kashan", last = "Haider";
    string full = first + " " + last;
    cout << "full = " << full << "\n";
    full += "!";                      // append
    full.push_back('!');              // append one char
    cout << "after appends = " << full << "\n";
    full.pop_back();                  // remove last char
    cout << "after pop_back = " << full << "\n";

    // ---------------------------------------------------------------
    // 4. Comparison - lexicographic (dictionary order, by ASCII)
    // ---------------------------------------------------------------
    cout << boolalpha;                // print bools as true/false instead of 1/0
    cout << "\"apple\" < \"banana\" : " << (string("apple") < "banana") << "\n"; // true
    cout << "\"abc\" == \"abc\"    : " << (string("abc") == "abc") << "\n";      // true
    cout << "\"Zebra\" < \"apple\" : " << (string("Zebra") < "apple") << "\n";   // true ('Z'=90 < 'a'=97)
    cout << noboolalpha;

    // ---------------------------------------------------------------
    // 5. Useful functions
    // ---------------------------------------------------------------
    string t = "data structures";

    // substr(start, length)
    cout << "substr(0, 4) = " << t.substr(0, 4) << "\n";     // data
    cout << "substr(5)    = " << t.substr(5) << "\n";        // structures (till end)

    // find - returns index of first match, or string::npos if not found
    cout << "find(\"struct\") = " << t.find("struct") << "\n"; // 5
    if (t.find("xyz") == string::npos) cout << "\"xyz\" not found\n";

    // insert / erase / replace
    string u = "abcdef";
    u.insert(3, "XY");               // abcXYdef
    cout << "insert: " << u << "\n";
    u.erase(3, 2);                   // remove 2 chars from index 3 -> abcdef
    cout << "erase:  " << u << "\n";
    u.replace(0, 3, "123");          // replace 3 chars from 0 -> 123def
    cout << "replace:" << u << "\n";

    // reverse & sort (from <algorithm>)
    string r = "racecar", w = "dcba";
    string rev = r;
    reverse(rev.begin(), rev.end());
    cout << r << (rev == r ? " is" : " is NOT") << " a palindrome\n";
    sort(w.begin(), w.end());
    cout << "sorted dcba = " << w << "\n";

    // ---------------------------------------------------------------
    // 6. Character functions (from <cctype>)
    // ---------------------------------------------------------------
    string mixed = "Hello World 123";
    int upper = 0, lower = 0, digit = 0, space = 0;
    for (char ch : mixed) {
        if (isupper(ch)) upper++;
        else if (islower(ch)) lower++;
        else if (isdigit(ch)) digit++;
        else if (ch == ' ') space++;
    }
    cout << "upper=" << upper << " lower=" << lower << " digit=" << digit << " space=" << space << "\n";

    string up = mixed;
    for (char &ch : up) ch = toupper(ch);  // & so we modify the real char
    cout << "toupper: " << up << "\n";

    // Frequency of each letter using an array of 26 (VERY common trick)
    string word = "banana";
    int freq[26] = {0};
    for (char ch : word) freq[ch - 'a']++;   // 'a'->0, 'b'->1 ...
    cout << "freq in banana: ";
    for (int i = 0; i < 26; i++)
        if (freq[i] > 0) cout << char('a' + i) << "=" << freq[i] << " ";
    cout << "\n";

    // ---------------------------------------------------------------
    // 7. Conversions
    // ---------------------------------------------------------------
    int num = stoi("456");               // string -> int (stoll for long long)
    string numStr = to_string(789);      // int -> string
    cout << "stoi(\"456\") + 1 = " << num + 1 << ", to_string(789) + \"!\" = " << numStr + "!" << "\n";

    // ---------------------------------------------------------------
    // 8. Reading strings
    // ---------------------------------------------------------------
    //   string word; cin >> word;      -> reads ONE word (stops at space)
    //   string line; getline(cin, line); -> reads the full line
    //   (remember cin.ignore() between them - see 01-basics-io.cpp)

    return 0;
}

/*
 EXPECTED OUTPUT:
 s = hello, length = 5 (same as s.size())
 first = h, last = o (or s.back())
 after s[0]='H': Hello
 chars: H-e-l-l-o-
 for-each: H e l l o
 full = Kashan Haider
 after appends = Kashan Haider!!
 after pop_back = Kashan Haider!
 "apple" < "banana" : true
 "abc" == "abc"    : true
 "Zebra" < "apple" : true
 substr(0, 4) = data
 substr(5)    = structures
 find("struct") = 5
 "xyz" not found
 insert: abcXYdef
 erase:  abcdef
 replace:123def
 racecar is a palindrome
 sorted dcba = abcd
 upper=2 lower=8 digit=3 space=2
 toupper: HELLO WORLD 123
 freq in banana: a=3 b=1 n=2
 stoi("456") + 1 = 457, to_string(789) + "!" = 789!
*/
