/*
 * File:   vendedor.h
 * Author: AirZs
 *
 * Creado el 25 de septiembre de 2010, 10:42
 */

#include "Vendedor.h"
#pragma GCC visibility push(default)



/****************************************
 *
 * Variables Estaticas
 * 
 ****************************************/

int Vendedor::idCont = 1;
int Vendedor::numOrder = 3;
int Vendedor::ORD_RUT = 1;
int Vendedor::ORD_NOM = 2;
int Vendedor::ORD_EDAD = 3;
int Vendedor::ORD_CANTVENT = 4;

/****************************************
 *
 * Funciones Iniciadores y Obligatorios
 *
 ****************************************/

Vendedor::Vendedor(int numRut){
    this->id = Vendedor::idCont++;
    this->rut = numRut;
    this->telefonos = new ListaEstatica();
    this->ventas = new ListaEnlazada();
    this->nombre = "";
    this->direccion = "";
}

Vendedor::Vendedor(const Vendedor& orig){

}

Vendedor::~Vendedor(){
    //Revisar despues
}

bool Vendedor::operator <(Vendedor *otroVend){
    switch(Vendedor::numOrder){ // Codigos: 1->Rut / 2->Nombre / 3-> Edad / 4-> Cantidad de Ventas
    case 1:
        if (this->rut < otroVend->rut){
            return true;
        }
        else
            return false;
    case 2:
        if (this->nombre.compare(otroVend->nombre) < 0){
            return true;
        }
        else
            return false;
    case 3:
        if (this->edad < otroVend->edad){
            return true;
        }
        else
            return false;
    case 4:
        if (this->ventas->longitud() < otroVend->ventas->longitud()){
            return true;
        }
        else
            return false;
    default:
        return false;
    }
}

bool Vendedor::operator >(Vendedor *otroVend){
    switch(Vendedor::numOrder){
    case 1:
        if (this->rut>otroVend->rut){
            return true;
        }
        else
            return false;
    case 2:
        if (this->nombre.compare(otroVend->nombre)>0){
            return true;
        }
        else
            return false;
    case 3:
        if (this->edad>otroVend->edad){
            return true;
        }
        else
            return false;
    case 4:
        if (this->ventas->longitud()>otroVend->ventas->longitud()){
            return true;
        }
        else
            return false;
    default:
        return false;
    }
}

bool Vendedor::operator ==(Vendedor *otroVend){
    switch(Vendedor::numOrder){
    case 1:
        if (this->rut==otroVend->rut){
            return true;
        }
        else
            return false;
    case 2:
        if (this->nombre.compare(otroVend->nombre)==0){
            return true;
        }
        else
            return false;
    case 3:
        if (this->edad==otroVend->edad){
            return true;
        }
        else
            return false;
    case 4:
        if (this->ventas->longitud()==otroVend->ventas->longitud()){
            return true;
        }
        else
            return false;
    default:
        return false;
    }
}

/****************************************
 *
 * Funciones Setters
 *
 ****************************************/

void Vendedor::setNombre(string strNombre){
    this->nombre = strNombre;
}

void Vendedor::setEdad(int intEdad){
    this->edad = intEdad;
}

void Vendedor::setDireccion(string strDireccion){
    this->direccion = strDireccion;
}

int Vendedor::setEmail(string strEmail){
    size_t pos;
    if (strEmail[0] == '@'){
        this->email = "";
        return 1;
    }
    pos = strEmail.find("@");
    if (pos == string::npos){
        this->email = "";
        return 1;
    }
    pos = strEmail.find("@", pos+1);
    if (pos != string::npos){
        this->email = "";
        return 1;
    }
    this->email = strEmail;
    return 0;
}

void Vendedor::addTelefono(int telefonoAgregado){
    this->telefonos->agregar(&telefonoAgregado); 
}

void Vendedor::addVenta(Venta *ventaAgregada){
    this->ventas->agregar(ventaAgregada);
}

void Vendedor::setIdCont(int intId){
    Vendedor::idCont=intId;
}

/****************************************
 *
 * Funciones Getters
 *
 ****************************************/

int Vendedor::getId(){
    return this->id;
}

int Vendedor::getRut(){
    return this->rut;
}

string Vendedor::getResumen(){
    stringstream resumen;
    resumen << "Nombre: " << this->nombre << endl;
    resumen << "Direcci�n: " << this->direccion << endl;
    resumen << "Edad: " << this->edad << endl;
    resumen << "E-Mail: " << this->email << endl;

    //return this->nombre + "||" + str(this->edad) + "||" + this->direccion + str(this->telefonos)"||" + this->email;
    return resumen.str();
}

string Vendedor::getNombre(){
    return this->nombre;
}

int Vendedor::getEdad(){
    return this->edad;
}

string Vendedor::getDireccion(){
    return this->direccion;
}

ListaEstatica *Vendedor::getTelefonos(){
    return this->telefonos;
}

ListaEnlazada *Vendedor::getVentas(){
    return this->ventas;
}

int Vendedor::getIdCont(){
    return Vendedor::idCont;
}

/****************************************
 *
 * Funciones Adicionales
 *
 ****************************************/

Cliente *Vendedor::ingresaCliente(){

    return NULL;
}

string Vendedor::verInfoCliente(Cliente *cliente){

    return NULL;
}

Venta *Vendedor::verHistorialCliente(Cliente  *cliente){

    return NULL;
}

Cliente *Vendedor::editarCliente(Cliente *cliente){

    return NULL;
}

Libro *Vendedor::ingresaLibro(){

    return NULL;
}

void Vendedor::realizarVenta(){

}


