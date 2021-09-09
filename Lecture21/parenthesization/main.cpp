#include "Matrix.hpp"

int main(){
    srand(time(0));
    Matrix A(3, 3);
    Matrix B(3, 3);

    Matrix P(2, 2);
    Matrix Q(2, 1);

    cout << P << endl;
    cout << Q << endl;

    Matrix C   =   A * B;
    Matrix R   =   P * Q;

    cout << R << endl;
    cout << C << endl;

    Matrix S(1, 1);
    S   =   C;
    cout << S << endl;

}
