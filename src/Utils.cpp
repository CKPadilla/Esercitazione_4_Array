#include "Utils.hpp"
#include "iostream"
#include "fstream"
#include "sstream"
#include "iomanip"

using namespace std;


/*
// Funzione : ImportDatas
// Inputs :
const string& inputFilePath : il percorso del file dei dati
unsigned int& n : numero di investimenti
double*& w : reference ad un puntatore di double : percentuali di investimento della somma iniziale
double*& r : reference ad un puntatore di double : percentuali di ritorno
unsigned int& S : somma iniziale investita
*/
bool ImportDatas(const string& inputFilePath,   
                   unsigned int& n,   
                   double*& w,  
                   double*& r,   
                   unsigned int& S )   
{
    // Apertura del file di input
    ifstream file;
    file.open(inputFilePath);

    if (file.fail())
    {
        cerr<< "ERRORE di apertura del file."<< endl;
        return false;   
    }

    /// LETTURA E MEMORIZZAZIONE DEI DATI

    // Somma iniziale S
    string line;
    string ignora;

    getline(file, line);   // leggo S;1000
    istringstream lineStream_S(line); 
    getline(lineStream_S, ignora, ';');   // Salvo in "ignora_S" la S del data che a me non interessa

    lineStream_S >> S;   // S = 1000
    

    // Numero di assets n
    getline(file, line);   // leggo n;8
    istringstream lineStream_n(line);  
    getline(lineStream_n, ignora, ';');   // ignoro 'n'

    lineStream_n >> n;
    

    // Ignoro la riga "w;r"
    getline(file, line);

    // Alloco nella memoria w e r, dato che ora ho la dimensione n
    w = new double[n];
    r = new double[n];

    unsigned int i = 0;   // per iterazione w,r
    while (getline(file, line))   //finchè c'è una riga da leggere
    {
        char separator;   
        istringstream lineStream_wr(line);   

        lineStream_wr >> w[i];
        lineStream_wr >> separator;   //ignoro il ';'
        lineStream_wr >> r[i];

        i++ ;  //iterazione w,r

    }

    file.close();   //fine file -> chiudo

    return true;
}

/************************************************/

/*
// Funzione : Calcola_valFinale
// Inputs : n,S,w,r come prima
// Outputs : v : valore finale dopo le rate
*/
double Calcola_valFinale(const int& n,
    const int& S,
    const double* const& w,
    const double* const& r)
{
double V = 0;
for (int i = 0; i < n; i++) {
    V += w[i] * S * (1 + r[i]);
    }

return V;
}

/************************************************/

/*
//Funzione: Calcola_rateTotale
// Inputs : S,V
// Outputs :  (V-S)/S : rendimento
*/
double Calcola_rateTotale(const int& S, const double& V) { return (V - S) / S;}

/************************************************/

/*
// Funzione : ArrayToString : trasforma un array in una stringa
// Inputs : n, v (in cui v sono w e r)
// Outputs : v sottofroma di stringa
*/
string ArrayToString(const int& n,
    const double* const& v)
{
string str;
ostringstream toString;
toString << "[ ";
for (int i = 0; i < n; i++)
toString<< v[i]<< " ";
toString << "]";

return toString.str();
}

/************************************************/

/*
// Funzione : ExportResult : esporta i risultati richiesti su un file
// Inputs : 
const string& outputFile : file di output su cui scrivere
dati n,w,r,V,R,S
// Output : dati scrittu sull'outputFile
*/
bool ExportResult(const string& outputFile,
    const int& n,
    const double* const& w,
    const double* const& r,
    const double& V,
    const double& R,
    const int& S)
{

// Apro file di scrittura
ofstream file;
file.open(outputFile);

if (file.fail())
{
cerr<< "ERRORE nell'apertura del file di output."<< endl;
return false;
}

file << setprecision(2);   

file << "S = "<< S << "; " << "" << noshowpoint << "n = " << n << endl;   // noshowpoint toglie lo zero decimale 

file << "w = [ ";
for (int i = 0; i < n; i++)
file << w[i] << " ";
file << " ]" << endl;

file << "r = [ ";
for (int i = 0; i < n; i++)
file << r[i]<< " ";
file << " ]" << endl;


file << "Rate of return of the portfolio: "<< fixed << setprecision(4) << R << endl;
file << fixed << setprecision(2) << "V: " << V << endl;


file.close();   // chiudo outputFile

return true;
}