#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

static const char alphabets_numbers [] = {"0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ`~!@#$%^&*/-"} ;
int length = sizeof(alphabets_numbers) - 1;

string Generator( int size ){
    string passwords;

    for ( int i = 0 ; i < size; i++ )
    {
        int index = rand() % length;
        passwords += alphabets_numbers[index];
    }
    return passwords;
}

int main() {
    srand(time(0));

    int size;
    cout << "Enter the password size you want: ";
    cin >> size;

    string passwords = Generator(size);
    cout << "Here's your passwords: " << passwords << endl;

    return 0;
}

// g++ -std=c++17 main.cpp
// ./a.out