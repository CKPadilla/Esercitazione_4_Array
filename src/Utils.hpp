#pragma once

#include <iostream>

using namespace std;

// ImportDatas legge gli input dal file data
// filePath: nome del file
// n: dimenzione di w ed r
// w: frazione di S
// r: rate
// S: somma iniziale
// return: true se successo, false se error
bool ImportDatas(const string& inputFilePath,   // reference al nome dell'input file in main
    unsigned int& n,   // reference a n in main
    double*& w,   // reference al puntatore w in main
    double*& r,   // refference al puntatore r in main
    unsigned int& S );   // reference a S in main


// ComputeTotVal fa la somma totale dopo i rate
// n: dimensione di w ed r
// w
// r
//S
// return: V = somma totale dopo i rate
double ComputeTotVal(const int& n,
    const int& S,
    const double* const& w,
    const double* const& r);


// ComputeTotRate: calcola il rate totale attraverso la formula
// V: somma totale dopo i rate
//S
// return: R = rate totale
double ComputeTotRate(const int& S,
    const double& V);

            

// Esporta un vettore in stringa
// n
// v: vettore
// return: string
string ArrayToString(const int& n,
    const double* const& v);


// ExportResult esporta tutto il risultato nel file
// outputFilePath: nome del file di output
// w
// r
// V
// R
// S
// return: risultato dell'export = true se successo, false se error                                
bool ExportResult(const string& outputFile,
    const int& n,
    const double* const& w,
    const double* const& r,
    const double& V,
    const double& R,
    const int& S);




