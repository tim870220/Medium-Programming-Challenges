#include <bits/stdc++.h>
using namespace std;

// string LRUCache(string strArr[], int n){
//     unordered_map<char, list<char>::iterator> m;
//     list<char> cache;

//     for (int i = 0; i < n; i++){
//         char c = strArr[i][0];
//         if (m.find(c) != m.end()){
//             cache.erase(m[c]);
//             m.erase(c);
//         }
//         cache.push_front(c);
//         m[c] = cache.begin();
//         if (cache.size() > 5){
//             m.erase(cache.back());
//             cache.pop_back();
//         }
//     }
//     stringstream ss;
//     // int i = 0;
//     // for(auto ii = cache.rbegin(); ii != cache.rend(); ii++) {
//     //     // cout << *ii << endl;
//     //     ss << *ii;
//     //     if (i != cache.size()-1)
//     //         ss << '-';
//     //     i++;
//     // }
//     // for(auto ii = cache.rbegin(); ii != cache.rend(); ii++) {
//     //     // cout << *ii << endl;
//     //     ss << *ii;
//     //     if (ii != --cache.rend())
//     //         ss << '-';
//     // }

//     list<char>::reverse_iterator it = cache.rbegin();
//     // auto it = cache.rbegin();
//     for (int i = 0; i < cache.size(); i++){
//         ss << *it;
//         advance(it, 1);
//         if (i != cache.size()-1)
//             ss << '-';
//     }

//     return ss.str();
// }

// string LRUCache(string strArr[], int n){
//     unordered_map<char, list<char>::iterator> m;
//     list<char> cache;

//     for (int i = 0; i < n; i++){
//         char c = strArr[i][0];
//         if (m.find(c) != m.end()){
//             cache.erase(m[c]);
//             m.erase(c);
//         }
//         cache.push_back(c);
//         m[c] = --cache.end();
//         if (cache.size() > 5){
//             m.erase(cache.front());
//             cache.pop_front();
//         }
//     }
//     stringstream ss;
//     list<char>::iterator it = cache.begin();
//     // auto it = cache.begin();
    
//     for (int i = 0; i < cache.size(); i++){
//         ss << *it;
//         advance(it, 1);
//         if (i != cache.size()-1)
//             ss << '-';
//     }

//     return ss.str();
// }
string LRUCache(string strArr[], int n){
    unordered_map<string, list<string>::iterator> m;
    list<string> cache;

    for (int i = 0; i < n; i++){
        string c = strArr[i];
        if (m.find(c) != m.end()){
            cache.erase(m[c]);
            m.erase(c);
        }
        cache.push_back(c);
        m[c] = --cache.end();
        if (cache.size() > 5){
            m.erase(cache.front());
            cache.pop_front();
        }
    }
    stringstream ss;
    // list<string>::iterator it = cache.begin();
    auto it = cache.begin();
    
    for (int i = 0; i < cache.size(); i++){
        ss << *it;
        advance(it, 1);
        if (i != cache.size()-1)
            ss << '-';
    }

    return ss.str();
}

int main()
{
    string A[] = {"A", "B", "C", "D", "A", "E", "D", "Z"};
    cout << LRUCache(A, sizeof(A) / sizeof(A[0])) << endl; // C-A-E-D-Z
    return 0;
}