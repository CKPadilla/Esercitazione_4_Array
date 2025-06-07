#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "src/Utils.hpp"

using namespace std;

int main()
{
    string inputFileName = "data.txt";
    unsigned int n = 0;
    unsigned int S = 0;
    double* w = nullptr;
    double* r = nullptr;

    if (!ImportDatas(inputFileName, n, w, r, S))
    {
        cerr<< "Importazione non riuscita!"<< endl;
        return -1;
    }
    else {
        cout << fixed << setprecision(2) << "S: " << S << endl;
        cout << "n = "<< n << endl;
        cout << "w = " << ArrayToString(n , w) << endl;
        cout << "r = " << ArrayToString(n , r) << endl;
    }

    double V = Calcola_valFinale(n, S, w, r);
    double R = Calcola_rateTotale(S, V);

    cout << "Rate of return of the portfolio: " << fixed << setprecision(4) << R << endl;
    cout << fixed << setprecision(2) << "V: " << V << endl;
    

    string outputFileName = "result.txt";
    if (!ExportResult(outputFileName, n, w, r, V,R,S))
    {
        cerr<< "Problemi nell'esportazione!"<< endl;
        return -1;
    }
    else
        cout<< "Esportazione terminata con successo."<< endl;

    delete[] w;   //libera la memoria non necessaria
    delete[] r;

    return 0;
}

