/*
 * File:   vendedor.h
 * Author: AirZs
 *
 * Creado el 25 de septiembre de 2010, 10:42
 */

#ifndef VENDEDOR_H
#define	VENDEDOR_H

//Constantes
#define ORD_V_RUT = 1;
#define ORD_V_NOM = 2;
#define ORD_V_EDAD = 3;
#define ORD_V_CANTVENT = 4;


#include <string>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include "Libro.h"
#include "ListaEstatica.h"
#include "ListaEnlazada.h"
#include "Cliente.h"
#include "Venta.h"

class Venta;
class Cliente;

using namespace std;
#pragma GCC visibility push(default)

class Vendedor{
public:

    //Iniciadores y obligatorios
    Vendedor();
    Vendedor(int intRut);
    Vendedor(const Vendedor& orig);
    virtual ~Vendedor();
    bool operator<(Vendedor *otroVend);
    bool operator>(Vendedor *otroVend);
    bool operator==(Vendedor *otroVend);
    //////////////////////////////////

    //Setters
    void setNombre(string strNombre);
    void setEdad(int intEdad);
    void setDireccion(string strDireccion);
    int setEmail(string strEmail);
    void addTelefono(int telefonoAgregado);
    void addVenta(Venta *ventaAgregada);
    void setIdCont(int intId);
    //////////////////////////////////

    //Getters
    int getId();
    int getRut();
    string getResumen();
    string getNombre();
    int getEdad();
    string getDireccion();
    ListaEstatica<int> *getTelefonos();
    ListaEnlazada<Venta> *getVentas();
    ListaEnlazada<int> *getListIdVentas();
    int getIdCont();
    //////////////////////////////////

    //Otras Funciones
    Cliente *ingresaCliente();
    string verInfoCliente(Cliente *Cliente);
    Venta *verHistorialCliente(Cliente *cliente); 
    Cliente *editarCliente(Cliente *cliente);
    Libro *ingresaLibro(); 
    void realizarVenta();
    //////////////////////////////////

private:

    static int idCont;
    static int numOrder;    // Codigos: 1->Rut / 2->Nombre / 3-> Edad / 4-> Cantidad de Ventas
    int id;
    int rut;
    string nombre;
    int edad;
    string direccion;
    string email;
    ListaEstatica<int> *telefonos;
    ListaEnlazada<Venta> *ventas;
    ListaEnlazada<int> *listVentas;
    string pass;
};

#endif	/* VENDEDOR_H */
