/*
 * File:   Cliente.h
 * Author: Mateo
 *
 * Created on 23 de septiembre de 2010, 9:51
 */

#ifndef CLIENTE_H
#define	CLIENTE_H

#include <string>
#include "Venta.h"
#include "ListaEnlazada.h"
#include "ListaEstatica.h"


#define ORD_CLIENT_RUT 2
#define ORD_CLIENT_NOMBRE 3
#define ORD_CLIENT_CANTCOMPRAS 4

class Venta;

using namespace std;
//#pragma GCC visibility push(default)

class Cliente {
public:
    // CONSTRUCTORES, COPIAS, DESTRUCTORES
    Cliente(int rut, string nombre, int edad, string direccion, ListaEstatica<int> *telefonos);
    Cliente(int rut, string nombre, int edad, string direccion, ListaEstatica<int> *telefonos, string email);
    Cliente(int id, int rut, string nombre, int edad, string direccion, ListaEstatica<int> *telefonos, string email, ListaEnlazada<int> *idsComprasHechas);
    Cliente(const Cliente& orig);
    virtual ~Cliente();

    // SETTERS
    static void setNumOrder(int numOrder);
    static void setIdCont(int idCont);
    void setId(int id);
    void setRut(int rut);
    void setNombre(string nombre);
    void setEdad(int edad);
    void setDireccion(string direccion);
    int setEmail(string email);
    void setListaTelefonos(ListaEstatica<int> *listaTelefonos);
    void addIdCompra(int idCompra);

    // GETTERS
    int getId();
    static int getIdCont();
    int getRut();
    string getResumen();
    string getNombre();
    int getEdad();
    string getDireccion();
    ListaEstatica<int> *getTelefonos();
    ListaEnlazada<int> *getListIdCompras();
    string getEmail();
    ListaEnlazada<Venta> *getComprasHechas();

    // OPERADORES
    bool operator <(const Cliente& otroCliente) const;
    bool operator >(const Cliente& otroCliente) const;
    bool operator ==(const Cliente& otroCliente) const;

    // OTROS METODOS
    void addCompra(Venta *compra);

private:
    static int idCont;
    static int numOrder;
    int id;
    int rut;
    string nombre;
    int edad;
    string direccion;
    ListaEstatica<int> *telefonos;
    string email;
    ListaEnlazada<Venta> *comprasHechas;
    ListaEnlazada<int> *idComprasHechas;

};

#endif	/* CLIENTE_H */
