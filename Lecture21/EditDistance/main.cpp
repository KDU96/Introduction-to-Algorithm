#include "editdistance.hpp"

int main(){
    StringEditDistance myClass("MIS", "SID");
    StringEditDistance yourClass("HIEROGLYPHOLOGY", "MICHAELANGELO");

    cout << "print my class : " << endl;
    myClass.printDistanceTable();
    cout << "cost : " << myClass.getCost() << endl;

    cout << "print your class : " << endl;
    yourClass.printDistanceTable();
    cout << "cost : " << yourClass.getCost() << endl;
}