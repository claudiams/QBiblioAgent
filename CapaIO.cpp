/* 
 * File:   CapaIO.cpp
 * Author: victor
 * 
 * Created on 30 de septiembre de 2010, 21:51
 */

#include "CapaIO.h"

string CapaIO::archVentas = "ventas.txt";
string CapaIO::archClientes = "clientes.txt";
string CapaIO::archUsuarios = "usuarios.txt";
string CapaIO::archLibros = "libros.txt";
int CapaIO::VENTA = 1;
int CapaIO::CLIENTE = 2;
int CapaIO::USUARIO = 3;
int CapaIO::LIBRO = 4;

CapaIO::CapaIO() {
    this->fVentas->open(CapaIO::archVentas.c_str(), fstream::in | fstream::out);
    this->fClientes->open(CapaIO::archClientes.c_str(), fstream::in | fstream::out);
    this->fUsuarios->open(CapaIO::archUsuarios.c_str(), fstream::in | fstream::out);
    this->fLibros->open(CapaIO::archLibros.c_str(), fstream::in | fstream::out);
    
}


CapaIO::~CapaIO(){
    this->fVentas->close();
    this->fClientes->close();
    this->fUsuarios->close();
    this->fLibros->close();
}

int CapaIO::stringToId(string linea)
{   if (linea.find("<id") != string::npos)
    {   size_t posInicioId = linea.find("\"", 0);
        size_t posFinalId = linea.find("\"", posInicioId);
        return atoi(linea.substr(posInicioId, posFinalId).c_str());
    }
    else
        return 1;
}
Venta *CapaIO::stringToVenta(string linea)
{   if (linea.find("<Venta") != string::npos)
    {   int id, idLibro, idCliente, idVendedor, cantidadLibros, montoTotal;
        bool correlativo;
        Fecha *fecha;


        Venta *ventaCreada = new Venta(id, correlativo, idLibro, idCliente, idVendedor, cantidadLibros, montoTotal, fecha);
        return ventaCreada;
    }
    else
        return NULL;
    /* linea << "id=\"" << venta->getId() << "\" ";
    linea << "correlativo=\"" << venta->getCorrelativo() << "\" ";
    linea << "idLibro=\"" << venta->getIdLibro() << "\" ";
    linea << "idCliente=\"" << venta->getIdCliente() << "\" ";
    linea << "cantidadLibros=\"" << venta->getCantidadLibros() << "\" ";
    linea << "montoTotal=\"" << venta->getMontoTotal() << "\" ";
    linea << "vendedor=\"" << venta->getIdVendedor() << "\" ";
    //linea << "fecha=\"" << venta->getFecha();
    linea <<  "\" >";*/
}
Cliente *CapaIO::stringToCliente(string linea)
{
    return NULL;
}

Vendedor *CapaIO::stringToVendedor(string linea)
{
    return NULL;
}

Libro *CapaIO::stringToLibro(string linea)
{
    return NULL;
}
string CapaIO::idToString(int id, int tipoId)
{   stringstream lineaId;
    if (tipoId == CapaIO::CLIENTE)
    {   lineaId << "<idCliente=\"" << id << "\" >";
        return lineaId.str();
    }
    if (tipoId == CapaIO::VENTA)
    {   lineaId << "<idVenta=\"" << id << "\" >";
        return lineaId.str();
    }
    if (tipoId == CapaIO::USUARIO)
    {   lineaId << "<idUsuario=\"" << id << "\" >";
        return lineaId.str();
    }
    if (tipoId == CapaIO::LIBRO)
    {   lineaId << "<idLibro=\"" << id << "\" >";
        return lineaId.str();
    }
    //Si el código id indicado como argumento no es válido entonces retorno NULL
    return NULL;
}

string CapaIO::ventaToString(Venta *venta)
{   stringstream linea;
    linea << "<Venta ";
    linea << "id=\"" << venta->getId() << "\" ";
    linea << "correlativo=\"" << venta->getCorrelativo() << "\" ";
    linea << "idLibro=\"" << venta->getIdLibro() << "\" ";
    linea << "idCliente=\"" << venta->getIdCliente() << "\" ";
    linea << "cantidadLibros=\"" << venta->getCantidadLibros() << "\" ";
    linea << "montoTotal=\"" << venta->getMontoTotal() << "\" ";
    linea << "vendedor=\"" << venta->getIdVendedor() << "\" ";
    linea << "fecha=\"" << venta->getFecha();
    linea <<  "\" >";
    return linea.str();
}

string CapaIO::clienteToString(Cliente *cliente)
{   stringstream linea;
    int i;
    ListaEnlazada *listaCompras;
    ListaEstatica *listaTelefonos;
    linea << "<Cliente ";
    linea << "id=\"" << cliente->getId() <<"\" ";
    linea << "rut=\"" << cliente->getRut() << "\" ";
    linea << "nombre=\"" << cliente->getNombre() << "\" ";
    linea << "edad=\"" << cliente->getEdad() << "\" ";
    linea << "direccion=\"" << cliente->getDireccion() << "\" ";
    linea << "telefonos=\"";
    listaTelefonos = cliente->getTelefonos();
    for (i = 0; i < listaTelefonos->longitud(); i++)
        linea << *(static_cast<int *>(listaTelefonos->recuperar(i))) << "|";
    linea << "\" "<< "email=\"" << cliente->getEmail() << "\" ";
    listaCompras = cliente->getComprasHechas();
    linea << "idComprasHechas=\"";
    for (i = 0; i < listaCompras->longitud(); i++)
        linea << (static_cast<Venta *>(listaCompras->recuperar(i)))->getId() << "|";
    linea  << "\" >";
    return linea.str();
}

string CapaIO::vendedorToString(Vendedor *vendedor)
{   stringstream linea;
    int i;
    ListaEnlazada *listaVentas;
    ListaEstatica *listaTelefonos;
    linea << "Vendedor ";
    linea << "id=\"" << vendedor->getId() << "\" ";
    linea << "rut=\"" << vendedor->getRut() << "\" ";
    linea << "nombre=\"" << vendedor->getNombre() << "\" ";
    linea << "edad=\"" << vendedor->getEdad() << "\" ";
    linea << "direccion=\"" << vendedor->getDireccion() << "\" ";
    linea << "telefonos=\"";
    listaTelefonos = vendedor->getTelefonos();
    for (i = 0; i < listaTelefonos->longitud(); i++)
        linea << *(static_cast<int *>(listaTelefonos->recuperar(i))) << "|";
    linea << "\" "<< "ventas=\"";
    listaVentas = vendedor->getVentas();
    for (i = 0; i < listaVentas->longitud(); i++)
        linea << (static_cast<Venta *>(listaVentas->recuperar(i)))->getId() << "|";
    linea << "\" >";
    return linea.str();
}

string CapaIO::libroToString(Libro *libro)
{   stringstream linea;
    linea << "Libro ";
    linea << "id=\"" << libro->getId() << "\" ";
    linea << "isbn=\"" << libro->getIsbn() << "\" ";
    linea << "precio=\"" << libro->getPrecio() << "\" ";
    linea << "nombre=\"" << libro->getNombre() << "\" ";
    linea << "autor=\"" << libro->getAutor() << "\" ";
    linea << "paginas=\"" << libro->getPaginas() << "\" ";
    linea << "peso=\"" << libro->getPeso() << "\" ";
    linea << "stock=\"" << libro->getStock() << "\" ";
    linea << " >";
    return linea.str();
}

