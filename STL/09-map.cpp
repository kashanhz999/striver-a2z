/*
===============================================================================
 STL 09 - MAP, MULTIMAP, UNORDERED_MAP
===============================================================================
 No input needed.

 A map stores KEY -> VALUE pairs. Keys are unique; you look up a value by its key.
 Like a dictionary: word (key) -> meaning (value).

     map<string, int> age;
     age["Ali"] = 25;          "Ali"  -> 25
     age["Sara"] = 22;         "Sara" -> 22

 | container              | key order | duplicate keys | insert/find/erase     | internals      |
 |------------------------|-----------|----------------|-----------------------|----------------|
 | map<K, V>              | SORTED    | no             | O(log n)              | red-black tree |
 | multimap<K, V>         | SORTED    | YES            | O(log n)              | red-black tree |
 | unordered_map<K, V>    | no order  | no             | O(1) avg, O(n) worst  | hash table     |

 Each element is a pair<const K, V>:  it->first = key, it->second = value.

 #1 use in DSA: FREQUENCY COUNTING (hashing). Also: two-sum, grouping, caching.
===============================================================================
*/

#include <bits/stdc++.h>
using namespace std;

void explainMap()
{
    cout << "--- map ---\n";
    map<string, int> marks;

    // Insert / update
    marks["Kashan"] = 95;               // insert
    marks["Ali"] = 80;
    marks.insert({"Sara", 88});         // insert with a pair
    marks.emplace("Zain", 70);
    marks["Ali"] = 85;                  // key exists -> UPDATE the value

    // Iterating - keys come out SORTED
    for (auto &p : marks) cout << p.first << " -> " << p.second << "\n";

    // C++17 structured bindings (cleaner)
    for (auto &[name, m] : marks) cout << name << ":" << m << " ";
    cout << "\n";

    // Lookup
    cout << "Sara = " << marks["Sara"] << "\n";

    // DANGER: operator[] on a MISSING key INSERTS it with a default value (0)
    cout << "size before = " << marks.size();
    int x = marks["Nobody"];            // creates "Nobody" -> 0 !
    cout << ", marks[\"Nobody\"] = " << x << ", size after = " << marks.size() << "\n";

    // Safe ways to check if a key exists (don't insert):
    if (marks.find("Ali") != marks.end()) cout << "Ali exists\n";
    if (marks.count("Bob") == 0) cout << "Bob doesn't exist\n";

    // Erase by key
    marks.erase("Nobody");
    cout << "size after erase = " << marks.size() << "\n";

    // first / last key, lower_bound works on KEYS
    cout << "first key = " << marks.begin()->first << ", last key = " << marks.rbegin()->first << "\n";
    cout << "lower_bound(\"L\") = " << marks.lower_bound("L")->first << "\n";   // first key >= "L"
}

void explainFrequency()
{
    cout << "--- frequency counting ---\n";
    vector<int> a = {3, 1, 3, 2, 1, 3};
    map<int, int> freq;
    for (int v : a) freq[v]++;          // missing key starts at 0 -> perfect for counting
    for (auto &[val, cnt] : freq) cout << val << " appears " << cnt << " times\n";

    // Most frequent element
    int best = -1, bestCnt = 0;
    for (auto &[val, cnt] : freq)
        if (cnt > bestCnt) { best = val; bestCnt = cnt; }
    cout << "most frequent = " << best << "\n";

    // Character frequency with unordered_map
    string s = "mississippi";
    unordered_map<char, int> cf;
    for (char c : s) cf[c]++;
    cout << "in mississippi: s=" << cf['s'] << " i=" << cf['i'] << " p=" << cf['p'] << " m=" << cf['m'] << "\n";
}

void explainTwoSum()
{
    cout << "--- two sum (unordered_map) ---\n";
    // Find indices of two numbers that add up to target. O(n) average.
    vector<int> nums = {2, 7, 11, 15};
    int target = 18;
    unordered_map<int, int> seenAt;     // value -> index
    for (int i = 0; i < (int)nums.size(); i++) {
        int need = target - nums[i];
        if (seenAt.count(need)) {
            cout << "indices " << seenAt[need] << " and " << i << " (" << need << " + " << nums[i] << ")\n";
            break;
        }
        seenAt[nums[i]] = i;
    }
}

void explainMultimap()
{
    cout << "--- multimap ---\n";
    multimap<string, int> mm;
    mm.insert({"math", 90});
    mm.insert({"math", 75});            // same key allowed
    mm.insert({"art", 60});
    for (auto &[k, v] : mm) cout << k << " " << v << "\n";
    // No operator[] on multimap (which value would it return?)
    cout << "count(math) = " << mm.count("math") << "\n";
}

void explainMapWithPairKey()
{
    cout << "--- map with pair key ---\n";
    // Keys can be any comparable type, e.g. grid cells (row, col)
    map<pair<int, int>, string> grid;
    grid[{0, 0}] = "start";
    grid[{2, 3}] = "goal";
    cout << "(2,3) = " << grid[{2, 3}] << "\n";
    // NOTE: unordered_map<pair<int,int>, ...> does NOT compile without a custom hash.
}

int main()
{
    explainMap();
    explainFrequency();
    explainTwoSum();
    explainMultimap();
    explainMapWithPairKey();
    return 0;
}

/*
 EXPECTED OUTPUT:
 --- map ---
 Ali -> 85
 Kashan -> 95
 Sara -> 88
 Zain -> 70
 Ali:85 Kashan:95 Sara:88 Zain:70
 Sara = 88
 size before = 4, marks["Nobody"] = 0, size after = 5
 Ali exists
 Bob doesn't exist
 size after erase = 4
 first key = Ali, last key = Zain
 lower_bound("L") = Sara
 --- frequency counting ---
 1 appears 2 times
 2 appears 1 times
 3 appears 3 times
 most frequent = 3
 in mississippi: s=4 i=4 p=2 m=1
 --- two sum (unordered_map) ---
 indices 1 and 2 (7 + 11)
 --- multimap ---
 art 60
 math 90
 math 75
 count(math) = 2
 --- map with pair key ---
 (2,3) = goal
*/
