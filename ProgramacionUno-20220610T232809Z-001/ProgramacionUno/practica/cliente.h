#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED


typedef struct{

    int id;
    char nombreCliente[21];
    char sexo;
    int isEmpty;

}eCliente;


#endif // CLIENTE_H_INCLUDED

int cargarNombreCliente(eCliente arrayClientes[], int tamCliente, int idCliente, char descripcionNombre[]);

int inicializarClientes(eCliente arrayClientes[], int tamCliente);

int buscarIndiceLibre(eCliente arrayClientes[], int tamCliente);

int altaCliente(eCliente arrayClientes[], int tamCliente, int* pIdCliente);

int mostrarUnCliente(eCliente unCliente, int tamCliente);

int mostrarClientes(eCliente arrayClientes[], int tamCliente);

int buscarClientePorId(eCliente arrayClientes[], int tamCliente, int idCliente);
