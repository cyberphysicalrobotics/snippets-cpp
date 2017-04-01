//
// Created by Taehyung Kim on 3/31/17.
// http://www.drdobbs.com/windows/user-defined-hash-functions-for-unordere/231600210?pgno=1
// Method one: User-defined hash function using a simple function with function class.

#include <iostream>
#include <unordered_map>
#include <string>
#include <functional>

using namespace std;

typedef pair<string,string> Name;

size_t name_hash( const Name& name )
{
    return hash<string>()(name.first) ^ hash<string>()(name.second);
}

int main(int argc, char* argv[])
{
    unordered_map<Name, int, function<decltype(name_hash) >> ids(100, name_hash);
    ids[Name("Mark", "Nelson")] = 40561;
    ids[Name("Andrew","Binstock")] = 40562;
    for ( auto ii = ids.begin() ; ii != ids.end() ; ii++ )
        cout << ii->first.first
             << " "
             << ii->first.second
             << " : "
             << ii->second
             << endl;
    return 0;
}