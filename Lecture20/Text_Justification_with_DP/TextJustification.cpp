#include "TextJustification.hpp"

TextJustification::TextJustification(const string& input, const int& pw)
:inputText(input), outputText(input), pageWidth(pw), start(0)
{}

int TextJustification::badNess(const int& index, const int& end){
    if(outputText.at(index+1) != ' ')
        return numeric_limits<int>::max();
    else if(outputText.at(index+1) == ' ')
        return (pageWidth - (index-start) + 1) * (pageWidth - (index-start) +1);
    else
        return  -1;
}
void TextJustification::OneLineJustification(){
    int table[pageWidth];
    for(int i=start; i<start + pageWidth; i++)
        table[i-start]    =   badNess(i, pageWidth);

    int least = 0;
    for(int i=0; i<pageWidth; i++){
        if(table[least] > table[i])     least   =   i;
    }
    least += start;
    outputText.at(least+1) =   '\n';
    start   =   least+2;
}

void TextJustification::CompletleyJustification(){
    while(inputText.length() - start > pageWidth)
        OneLineJustification();
    
}
ostream& operator<<(ostream& out, TextJustification& in){
    in.CompletleyJustification();
    out << in.outputText;
    return out;
}
