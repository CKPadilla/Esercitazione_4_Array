#pragma once

#include <iostream>

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
                   unsigned int& S );

/************************************************/

/*
// Funzione : Calcola_valFinale
// Inputs : n,S,w,r come prima
// Outputs : v : valore finale dopo le rate
*/
double Calcola_valFinale(const int& n,
    const int& S,
    const double* const& w,
    const double* const& r);

/************************************************/

/*
//Funzione: Calcola_rateTotale
// Inputs : S,V
// Outputs :  (V-S)/S : rendimento
*/
double Calcola_rateTotale(const int& S, const double& V);

/************************************************/

string ArrayToString(const int& n,
    const double* const& v);

/************************************************/

bool ExportResult(const string& outputFile,
    const int& n,
    const double* const& w,
    const double* const& r,
    const double& V,
    const double& R,
    const int& S);





