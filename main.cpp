#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main(){
    const double h = 6.626e-34;
    const double m = 9.11e-31;

    double L;
    int n;

    cout << "box length(m): " ;
    cin >> L;

    cout << "Quantum Number: ";
    cin >> n;

    double E = (n * n * h * h) / (8 * m * L * L);

    cout << "\n Energ Level E_" << n << " = " << E << " Joules\n";

    //File output
    ofstream file("output.csv");
    file << "x , psi, probabilty\n";

    int N = 200;
    double dx = L / N;

    for(int i = 0; i <= N; i++){
        double x = i * dx;

        double psi = sin(n * M_PI * x / L);
        

        double prob = psi * psi;

        file << x << "," << psi << "," << prob << "\n";

    }

    file.close();

    cout << "\n Data saved to output.csv" << endl;

    return 0;
}
