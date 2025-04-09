#include <iostream>
#include <Eigen/Eigen>
#include <iomanip>

using namespace std;
using namespace Eigen;

double soluzioneconPALU(const Matrix2d& A, const Vector2d& b) {
    Vector2d x = A.partialPivLu().solve(b);
    Vector2d x_nota(2);
    x_nota <<-1.0e+0,-1.0e+00;
    double errore = ((x-x_nota).norm())/(x_nota).norm();
    return errore;
}

double soluzioneconQR(const Matrix2d& A, const Vector2d& b) {
    Vector2d x = A.householderQr().solve(b);
    Vector2d x_nota(2);
    x_nota <<-1.0e+0,-1.0e+00;
    double errore = ((x-x_nota).norm())/(x_nota).norm();
    return errore;
}

void print(const Matrix2d& A, Vector2d& b, const string& matrice){
    cout << "l'errore di approssimazione usando la fattorizzazione PALU per " << matrice <<" è:"<< setprecision(30) << scientific << soluzioneconPALU(A,b)<<endl;
    cout << "l'errore di approssimazione usando la fattorizzazione QR per " << matrice <<" è:"<< setprecision(30) << scientific << soluzioneconQR(A,b)<<endl;
}

int main()
{
    Matrix2d A; A <<5.547001962252291e-01,-3.770900990025203e-02, 8.320502943378437e-01,-9.992887623566787e-01;
    Matrix2d B; B <<5.547001962252291e-01,-5.540607316466765e-01, 8.320502943378437e-01,-8.324762492991313e-01;
    Matrix2d C; C <<5.547001962252291e-01,-5.547001955851905e-01, 8.320502943378437e-01,-8.320502947645361e-01;

    Vector2d a; a <<-5.169911863249772e-01, 1.672384680188350e-01;
    Vector2d b; b <<-6.394645785530173e-04, 4.259549612877223e-04;
    Vector2d c; c <<-6.400391328043042e-10, 4.266924591433963e-10;

    print(A,a,"A");
    print(B,b,"B"); 
    print(C,c,"C");

    return 0;
}

