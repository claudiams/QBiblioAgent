/* 
 * File:   Venta.cpp
 * Author: Mateo
 * 
 * Created on 24 de septiembre de 2010, 11:33 PM
 */

#include "Venta.h"


/* Hacer:
 * Constructor copia
 * Destructor
 */

/****************************************
 VARIABLES ESTATICAS
 ****************************************/

int Venta::idCont = 1;
int Venta::numOrder = 1;

/****************************************
 CONSTRUCTORES, COPIAS, DESTRUCTORES
 ****************************************/

Venta::Venta() {
    this->id = Venta::idCont++;
    this->correlativo = false;
    this->idLibro = 0;
    this->libro = NULL;
    this->idCliente = 0;
    this->cliente = NULL;
    this->cantidadLibros = 0;
    this->montoTotal = 0;
    this->vendedor = NULL;
    this->fecha = NULL;
    this->idVendedor = 0;
}

Venta::Venta(int id, bool correlativo, int idLibro, int idCliente, int idVendedor, int cantidadLibros, int montoTotal, Fecha *fecha) {
    this->correlativo = correlativo;
    this->id = id;
    this->idLibro = idLibro;
    this->libro = NULL;
    this->idCliente = idCliente;
    this->cliente = NULL;
    this->cantidadLibros = cantidadLibros;
    this->montoTotal = montoTotal;
    this->vendedor = NULL;
    this->fecha = fecha;
    this->idVendedor = idVendedor;
}

Venta::Venta(bool correlativo, int idLibro, Libro *libro, int idCliente, Cliente *cliente, int idVendedor, Vendedor *vendedor, int cantidadLibros, int montoTotal, Fecha *fecha) {
    this->correlativo = correlativo;
    this->id = Venta::idCont++;
    this->idLibro = idLibro;
    this->libro = libro;
    this->idCliente = idCliente;
    this->cliente = cliente;
    this->cantidadLibros = cantidadLibros;
    this->montoTotal = montoTotal;
    this->vendedor = vendedor;
    this->fecha = fecha;
    this->idVendedor = idVendedor;
}

Venta::~Venta() {
}

/****************************************
 SETTERS
 ****************************************/

void Venta::setNumOrder(int numOrder) {
    Venta::numOrder = numOrder;
}

void Venta::setIdCont(int idCont) {
    Venta::idCont = idCont;
}

void Venta::setId(int id) {
    this->id = id;
}

void Venta::setCorrelativo(bool correlativo) {
    this->correlativo = correlativo;
}

void Venta::setIdLibro(int idLibro) {
    this->idLibro = idLibro;
}

void Venta::setLibro(Libro *libro) {
    this->libro = libro;
}

void Venta::setIdCliente(int idCliente) {
    this->idCliente = idCliente;
}

void Venta::setCliente(Cliente *cliente) {
    this->cliente = cliente;
}

void Venta::setCantidadLibros(int cantidadLibros) {
    this->cantidadLibros = cantidadLibros;
}

void Venta::setMontoTotal(int montoTotal) {
    this->montoTotal = montoTotal;
}

void Venta::setVendedor(Vendedor *vendedor) {
    this->vendedor = vendedor;
}

void Venta::setFecha(Fecha *fecha) {
    this->fecha = fecha;
}

void Venta::setIdVendedor(int idVendedor) {
    this->idVendedor = idVendedor;
}

/****************************************
 GETTERS
 ****************************************/

int Venta::getIdCont() {
    return Venta::idCont;
}

int Venta::getId() {
    return this->id;
}

bool Venta::getCorrelativo() {
    return this->correlativo;
}

int Venta::getIdLibro() {
    return this->idLibro;
}

Libro *Venta::getLibro() {
    return this->libro;
}

int Venta::getIdCliente() {
    return this->idCliente;
}

Cliente *Venta::getCliente() {
    return this->cliente;
}

int Venta::getCantidadLibros() {
    return this->cantidadLibros;
}

int Venta::getMontoTotal() {
    return this->montoTotal;
}

Vendedor *Venta::getVendedor() {
    return this->vendedor;
}

Fecha *Venta::getFecha() {
    return this->fecha;
}

string Venta::getResumen(){
    stringstream resumen;
    //resumen << "corretalivo: " << (this->correlativo) << endl;
    resumen << "Libro: " << this->libro->getNombre() << endl;
    resumen << "Cliente: " << this->cliente->getNombre() << endl;
    resumen << "Rut Cliente: " << this->cliente->getRut() << endl;
    resumen << "Vendedor: " << this->vendedor->getNombre() << endl;
    resumen << "Rut vendedor: " << this->vendedor->getRut() << endl;
    resumen << "Fecha: " << this->fecha->getDia() << " - " << this->fecha->getMes() << " - " << (this->fecha->getAnno() + 1900) << endl;
    resumen << "Cantidad de libros: " << this->cantidadLibros << endl;
    resumen << "Monto total: " << this->montoTotal << endl;
    return resumen.str();
    }

int Venta::getIdVendedor() {
    return this->idVendedor;
}

/****************************************
 OPERADORES
 ****************************************/

bool Venta::operator <(const Venta& otraVenta) const {
    switch(Venta::numOrder) {
        case ORD_VENT_NOMBRELIB:
            if (this->libro->getNombre().compare(otraVenta.libro->getNombre()) < 0)
                return true;
            else
                return false;
        case ORD_VENT_CLIENTE:
            if (this->cliente->getNombre().compare(otraVenta.cliente->getNombre()) < 0)
                return true;
            else
                return false;
        case ORD_VENT_LIBRO:
            if (this->cantidadLibros < otraVenta.cantidadLibros)
                return true;
            else
                return false;
        case ORD_VENT_MONTO:
            if (this->montoTotal < otraVenta.montoTotal)
                return true;
            else
                return false;
        case ORD_VENT_VENDEDOR:
            if (this->vendedor->getNombre().compare(otraVenta.vendedor->getNombre()) < 0)
                return true;
            else
                return false;
        default:
            return false;
    }
}

bool Venta::operator >(const Venta& otraVenta) const {
    switch(Venta::numOrder) {
        case 1:
            if (this->id > otraVenta.id)
                return true;
            else
                return false;
        case 2:
            if (this->libro->getNombre().compare(otraVenta.libro->getNombre()) > 0)
                return true;
            else
                return false;
        case 3:
            if (this->cliente->getNombre().compare(otraVenta.cliente->getNombre()) > 0)
                return true;
            else
                return false;
        case 4:
            if (this->cantidadLibros > otraVenta.cantidadLibros)
                return true;
            else
                return false;
        case 5:
            if (this->montoTotal > otraVenta.montoTotal)
                return true;
            else
                return false;
        case 6:
            if (this->vendedor->getNombre().compare(otraVenta.vendedor->getNombre()) > 0)
                return true;
            else
                return false;
        default:
            return false;
    }
}

bool Venta::operator ==(const Venta& otraVenta) const {
    switch(Venta::numOrder) {
        case 1:
            if (this->id == otraVenta.id)
                return true;
            else
                return false;
        case 2:
            if (this->libro->getNombre().compare(otraVenta.libro->getNombre()) == 0)
                return true;
            else
                return false;
        case 3:
            if (this->cliente->getNombre().compare(otraVenta.cliente->getNombre()) == 0)
                return true;
            else
                return false;
        case 4:
            if (this->cantidadLibros == otraVenta.cantidadLibros)
                return true;
            else
                return false;
        case 5:
            if (this->montoTotal == otraVenta.montoTotal)
                return true;
            else
                return false;
        case 6:
            if (this->vendedor->getNombre().compare(otraVenta.vendedor->getNombre()) == 0)
                return true;
            else
                return false;
        default:
            return false;
    }
}
