// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include <iostream>

using namespace std;

int main(int argc, const char* argv[])
{
    cout << "Hello World!" << endl;

    if (argc != argc) {
        return 1;
    }

    return 0;
}
