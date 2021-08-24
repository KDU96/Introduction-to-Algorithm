#include "TextJustification.hpp"

int main(){
    string input = "My name is Dong U Kim. I am twenty seven years old! Whear are you from? I am from Korea!";
    TextJustification   myString(input, 20);
    cout << myString << endl;
}