﻿/*********************************************************************************
 * Curso de Programación 1. Tema 11 (Registros)
 * Autores: Miguel Ángel Latre y Javier Martínez
 * Última revisión: 19 de noviembre de 2019
 * Resumen: Fichero de implementación «nif.cpp» del módulo «nif».
 * Codificación de caracteres original de este fichero: UTF-8 con BOM
\********************************************************************************/

#include <iostream>
#include <iomanip>
#include "nif.h"
using namespace std;

/*
 * Pre:  ---
 * Post: Ha devuelto la letra del número de identificación fiscal que corresponde
 *       a un número de documento nacional de identidad igual a «dni».
 */
char calcularLetra(const int dni) {
    const int NUM_LETRAS = 23;
    const char TABLA_NIF[NUM_LETRAS + 1] = "TRWAGMYFPDXBNJZSQVHLCKE";
    return TABLA_NIF[dni % NUM_LETRAS];
}

/*
 * Pre:  ---
 * Post: Ha devuelto «true» si y solo si «nifAValidar» define un NIF válido, es
 *       decir, su letra es la que le corresponde a su DNI.
 */
bool esValido(const Nif nifAValidar) {
    return calcularLetra(nifAValidar.dni) == nifAValidar.letra;
}


/*
 * Pre:  El valor del parámetro «nifAEscribir» representa un NIF válido.
 * Post: Ha escrito «nifAEscribir» en pantalla, con un formato como «01234567-L».
 *       También ha modificado el carácter de relleno que utiliza el manipulador
 *       «setw», estableciendo el espacio en blanco.
 */
void mostrar(const Nif nifAEscribir) {
    cout << setfill('0');
    cout << setw(8) << nifAEscribir.dni << "-" << nifAEscribir.letra;
    cout << setfill(' ');
}
