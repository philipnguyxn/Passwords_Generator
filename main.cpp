#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>

using namespace std;

string Generator( string* alphabets_numbers, int upperLimit ){
    string passwords;
    srand(time(0));

    for ( int i = 0 ; i < upperLimit; i++ )
    {
        passwords += alphabets_numbers[ (rand() % upperLimit) - 1 ];
    }
    return passwords;
}

int main() {
    int upperLimit;
    cout << "Enter the upper limit you want: ";
    cin >> upperLimit;

    bool upper_lower_required;
    cout << "Do your password need to be in uppercase: ";
    cin >> upper_lower_required;

    string special_characters;
    cout << "Enter what special characters you  want: ";
    cin >> special_characters;

    vector <string> alphabets_numbers = {
        "0123456789",
        "abcdefghijklmnopqrstuvwxyz",
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    };

    if ( upper_lower_required == true &&  special_characters == " " )
    {
        alphabets_numbers.push_back( "`~!@#$%^&*/-" );
    }
    else if ( upper_lower_required == true &&  special_characters != " " )
    {
        for ( int i = 0; i < special_characters.length(); i++)
        {
            alphabets_numbers.push_back( special_characters );
        }
    }
    else if ( upper_lower_required != true &&  special_characters == " " )
    {
        alphabets_numbers.push_back( "`~!@#$%^&*/-" );
        alphabets_numbers.pob_back( "ABCDEFGHIJKLMNOPQRSTUVWXYZ" );
    }
    else
    {
        alphabets_numbers.pob_back( "ABCDEFGHIJKLMNOPQRSTUVWXYZ" );
        for ( int i = 0; i < special_characters.length() ; i++)
        {
            alphabets_numbers.push_back( special_characters );
        }
    }
    string* p_alphabet_numbers = &alphabets_numbers[0];

    string passwords = Generator( p_alphabet_numbers, upperLimit );
    cout << "Here's your passwords: " << passwords << endl;

    return 0;
}