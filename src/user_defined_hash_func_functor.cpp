//
// Created by Taehyung Kim on 3/31/17.
// Method three: User-defined hash function using a functor.
// http://www.drdobbs.com/windows/user-defined-hash-functions-for-unordere/231600210?pgno=1

#include <iostream>
#include <unordered_map>
#include <string>
#include <functional>

using namespace std;

typedef pair<string,string> Name;

struct hash_name {
    size_t operator()(const Name &name) const {
        return hash<string>()(name.first) ^ hash<string>()(name.second);
    }
};

int main(int argc, char *argv[]) {
    unordered_map<Name, int, hash_name> ids;
    ids[Name("Mark", "Nelson")] = 40561;
    ids[Name("Andrew", "Binstock")] = 40562;

    for (auto ii = ids.begin(); ii != ids.end(); ii++)
        cout << ii->first.first
             << " "
             << ii->first.second
             << " : "
             << ii->second
             << endl;

    return 0;

}