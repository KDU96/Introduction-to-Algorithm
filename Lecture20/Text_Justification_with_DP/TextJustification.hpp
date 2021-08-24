#ifndef     _TEXT_JUSTIFICATION_HPP_
#define     _TEXT_JUSTIFICATION_HPP_

#include    <string>
#include    <limits>
#include    <cmath>
#include    <iostream>
using namespace std;

class TextJustification{
    private :
        string  inputText;
        string  outputText;
        int     pageWidth;
        int     badNess(const int& index, const int& end);
        int     start;
        void    OneLineJustification();
        void    CompletleyJustification();
    public :
        TextJustification(const string& input, const int& pageWidth);
        ~TextJustification(){}
        friend ostream& operator<<(ostream& out, TextJustification& in);


};
#endif