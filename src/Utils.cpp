#include "Utils.hpp"

#include "iostream"
#include "fstream"
#include "sstream"
#include "iomanip"

using namespace std;


/*IMPORT 
DATAS*/
bool ImportDatas(const string& inputFilePath,   // reference al nome dell'input file in main
                   unsigned int& n,   // reference a n in main
                   double*& w,   // reference al puntatore w in main
                   double*& r,   // refference al puntatore r in main
                   unsigned int& S )   // reference a S in main
{
    // Open File

    ifstream file;
    file.open(inputFilePath);

    if (file.fail())
    {
        cerr<< "file open failed"<< endl;
        return false;   // false, così nel main diventa true ed entra nel ciclo if
    }


    // Prendo il valore iniziale della somma S

    string line;
    string ignora_S;

    getline(file, line);   // leggo S;1000
    istringstream lineStream_S(line);   // Trasformo line in uno stream per scomporlo in pezzi
    getline(lineStream_S, ignora_S, ';');   // Salvo in "ignora" la S del data che a me non interessa

    lineStream_S >> S;   // converto 1000 in int (automatico per l'overload di >>) e lo salvo in S
    

    // Prendo il valore della dimensione n
    string ignora_n;
    getline(file, line);   // leggo n;8
    istringstream lineStream_n(line);   // Trasformo line in uno stream per scomporlo in pezzi
    getline(lineStream_n, ignora_n, ';');   // Salvo in "ignora" la n del data

    lineStream_n >> n;
    

    // Leggo e ignoro la riga "w;r"
    getline(file, line);

    // Alloco nella memoria gli array di dimensione n

    w = new double[n];
    r = new double[n];
    unsigned int i = 0;

    while (getline(file, line))   // fin tanto che non è la fine del file, eseguo il ciclo while
    {
        char separator;   // per ignorare il punto e virgola
        istringstream lineStream_wr(line);   // Stream per scomporre i pezzi

        lineStream_wr >> w[i];
        lineStream_wr >> separator;
        lineStream_wr >> r[i];

        i++ ;  //incremento per l'iterazione

    }

    // Close File
    file.close();

    return true;   // True, così nel main non entrare nella sezione di errorImportDatas
}



/*COMPUTE
TOTAL VALUE*/
double ComputeTotVal(const int& n,
    const int& S,
    const double* const& w,
    const double* const& r)
{
double V = 0;
for (unsigned int i = 0; i < n; i++)
V += w[i] * S * (1 + r[i]);

return V;
}



/*COMPUTE 
TOTAL RATE*/
double ComputeTotRate(const int& S,
    const double& V)
{
double R = (V - S) / S;

return R;
}




/*ARRAY 
TO STRING*/
string ArrayToString(const int& n,
    const double* const& v)
{
string str;
ostringstream toString;
toString << "[ ";
for (unsigned int i = 0; i < n; i++)
toString<< v[i]<< " ";
toString << "]";

return toString.str();
}


/*EXPORT
RESULTS ON FILE*/
bool ExportResult(const string& outputFile,
    const int& n,
    const double* const& w,
    const double* const& r,
    const double& V,
    const double& R,
    const int& S)
{

// Open File
ofstream file;
file.open(outputFile);

if (file.fail())
{
cerr<< "L'apertura del outputFile non è andata a buon fine!"<< endl;
return false;
}

file << fixed << setprecision(2);   // doppia precisione per S

file << "S = "<< S << "; " << "" << noshowpoint << "n = " << n << endl;   // noshowpoint fa sì che sono S abbia i numeri decimali ed n no

file << "w = [ ";
for (unsigned int i = 0; i < n; i++)
file << w[i] << " ";
file << " ]" << endl;

file << "r = [ ";
for (unsigned int i = 0; i < n; i++)
file << r[i]<< " ";
file << " ]" << endl;


file << "Rate of return of the portfolio: "<< R << endl;
file << fixed << setprecision(2) << "V: " << V << endl;

// Close File
file.close();

return true;
}