/***********************************
*J. Sakumoto
*Exceptions, Templates, and Standard Template Library (STL) Part A
*4/15/25
*V 1.0
************************************/

#include <iostream>
#include <stdexcept>

using namespace std;

class invalidCharacterException : public exception {
public:
    const char* what( ) const noexcept override {
        return "Invalid character: start must be a letter (A-Z or a-z).";
    }
};

class invalidRangeException : public exception {
public:
    const char* what( ) const noexcept override {
        return "Invalid range: resulting character is not a valid letter.";
    }
};

char character( char start , int offset ) {
    if ( !( ( start >= 'A' && start <= 'Z' ) || ( start >= 'a' && start <= 'z' ) ) ) {
        throw invalidCharacterException( );
    }

    char result = start + offset;

    if ( ( start >= 'A' && start <= 'Z' && ( result < 'A' || result > 'Z' ) ) ||
        ( start >= 'a' && start <= 'z' && ( result < 'a' || result > 'z' ) ) ) {
        throw invalidRangeException( );
    }

    return result;
}

int main( ) {
    char starts [ ] = { 'a', 'a', 'Z', '?', 'A' };
    int offsets [ ] = { 1, -1, -1, 5, 32 };

    for ( int i = 0; i < 5; ++i ) {
        try {
            char result = character( starts [ i ] , offsets [ i ] );
            cout << "character('" << starts [ i ] << "', " << offsets [ i ] << ") = '" << result << "'" << endl;
        }
        catch ( const invalidCharacterException& e ) {
            cout << "character('" << starts [ i ] << "', " << offsets [ i ] << ") threw invalidCharacterException: " << e.what( ) << endl;
        }
        catch ( const invalidRangeException& e ) {
            cout << "character('" << starts [ i ] << "', " << offsets [ i ] << ") threw invalidRangeException: " << e.what( ) << endl;
        }
    }

    return 0;
}
