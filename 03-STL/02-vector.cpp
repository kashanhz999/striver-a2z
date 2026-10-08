#include<bits/stdc++.h>
using namespace std;

// Chhota helper - poora vector ek line mein print kar deta hai
void print(vector<int> &v){
    for(auto x : v) cout << x << " ";
    cout << endl;
}

void explainVector(){

    // Vector = dynamic array. Normal array ka size fix hota hai,
    // vector ka size apne aap badh jaata hai jab naya element daalte hain.
    vector<int> v;

    // push_back -> last mein element daal deta hai
    v.push_back(1);         // {1}

    // emplace_back -> same kaam, but object seedha vector ke andar banata hai
    // isliye thoda fast hai (pair / class objects mein farak dikhta hai)
    v.emplace_back(2);      // {1, 2}
    print(v);               // 1 2


    // Vector of pairs - har element ek pair hai
    vector<pair<int,int>> vec;

    vec.push_back({1, 2});  // push_back mein {} braces dene padte hain
    vec.emplace_back(3, 4); // emplace_back mein braces nahi chahiye, khud pair bana leta hai
    cout << vec[0].first << " " << vec[0].second << endl;   // 1 2
    cout << vec[1].first << " " << vec[1].second << endl;   // 3 4


    // Declare karne ke aur tarike
    vector<int> v1(5);          // 5 elements, sab 0      -> {0,0,0,0,0}
    vector<int> v2(5, 100);     // 5 elements, sab 100    -> {100,100,100,100,100}
    vector<int> v3(v2);         // v2 ki copy
    print(v1);
    print(v2);
    print(v3);


    // Elements access karna (index 0 se start hota hai)
    vector<int> a = {10, 20, 30, 40, 50};
    cout << a[0] << endl;       // 10
    cout << a.at(1) << endl;    // 20 - galat index pe error deta hai, isliye safe hai
    cout << a.front() << endl;  // 10 - pehla element
    cout << a.back() << endl;   // 50 - aakhri element
    cout << a.size() << endl;   // 5  - kitne elements hain


    // Iterator - pointer jaisa samjho, * lagane se value milti hai
    // begin() -> pehle element ko point karta hai
    // end()   -> aakhri element ke BAAD wali jagah ko (last element pe nahi!)
    vector<int>::iterator it = a.begin();
    cout << *it << endl;        // 10
    it++;
    cout << *it << endl;        // 20


    // Loop chalane ke 3 tarike - teeno ka output same hai
    for(int i = 0; i < a.size(); i++) cout << a[i] << " ";
    cout << endl;

    for(auto it = a.begin(); it != a.end(); it++) cout << *it << " ";
    cout << endl;

    for(auto x : a) cout << x << " ";    // sabse easy - for-each loop
    cout << endl;


    // Delete karna
    a.pop_back();                       // last element hata diya -> {10,20,30,40}
    print(a);

    a.erase(a.begin() + 1);             // index 1 (20) hata diya -> {10,30,40}
    print(a);

    // Range erase: [start, end) -> start include, end exclude
    vector<int> b = {1, 2, 3, 4, 5};
    b.erase(b.begin() + 1, b.begin() + 3);   // index 1 aur 2 hate -> {1,4,5}
    print(b);


    // Insert karna (beech mein)
    vector<int> c = {100, 200};
    c.insert(c.begin(), 300);           // shuru mein 300      -> {300,100,200}
    c.insert(c.begin() + 1, 2, 10);     // index 1 pe do baar 10 -> {300,10,10,100,200}
    print(c);


    // Kuch aur kaam ke functions
    vector<int> x = {1, 2};
    vector<int> y = {3, 4};
    x.swap(y);                          // dono ki values aapas mein badal di
    print(x);                           // 3 4
    print(y);                           // 1 2

    x.clear();                          // poora vector khaali
    cout << x.empty() << endl;          // 1 (true) - kyunki ab khaali hai
}

int main(){
    explainVector();
    return 0;
}
