
#ifndef CLIENTES_H_
#define CLIENTES_H_

#include "localidad.h"


typedef struct
{
	char calle[51];
	int numero;
}eDireccion;

typedef struct
{
	int idCliente;
	char nombreEmpresa[51];
	char cuit[14];
	eDireccion direccion;
	int idLocalidad;
	int isEmpty;
}eClientes;

/// @fn int AnalizarListadoDeClientes(eClientes[], int)
/// @brief Funcion que analiza si hay algun estado de cliente ocupado
/// @param clientes Puntero al Array de Estructura que tiene las variables donde se guardara la informacion de cada clientes
/// @param cantidad Copia del valor de la cantidad de clientes
/// @return Devuelve 1 si encontro un lugar ocupado, sino -1 si estan todos libres
int AnalizarListadoDeClientes(eClientes clientes[], int cantidad);

/// @fn int InicilizarClientes(eClientes[], int)
/// @brief Funcion que se encarga de recorrer el campo isEmpty de la estructura clientes para darle el valor inicial de 0
/// @param clientes Puntero al Array de Estructura que tiene las variables donde se guardara la informacion de cada clientes
/// @param cantidad Copia del valor de la cantidad de clientes
/// @return Devuelve 1 si la funcion realizo la inicializacion, sera -1 en el caso contrario
int InicilizarClientes(eClientes clientes[], int cantidad);

/// @fn int BuscarLugarLibreClientes(eClientes[], int)
/// @brief Funcion que busca en el array de estructura un lugar libre
/// @param clientes Puntero al Array de Estructura que tiene las variables donde se guardara la informacion de cada clientes
/// @param cantidad Copia del valor de la cantidad de clientes
/// @return Devuelve el valor de la posicion del lugar libre que encontro, si no hay lugar disponible devuelve -1
int BuscarLugarLibreClientes(eClientes clientes[], int cantidad);

/// @fn int AltaDeCliente(eClientes[], int, int*, eLocalidad[], int)
/// @brief Funcion que pedira la informacion de los clientes, luego que comprobar dara el alta del mismo
/// @param clientes Array de Estructura que tiene las variables donde se guarda la informacion de cada cliente
/// @param cantidad Copia del tamanio del array de clientes
/// @param idClientes Direccion de memoria donde se incrementara el valor inicial cada vez que se realice un alta
/// @param localidades Array de Estructura que tiene las variables donde se guarda la informacion de las localidades
/// @param tam_localidades Copia del tamanio del array de la estructura de localidades
/// @return Devuelve -1 si hubo un error o 1 si se realizo el alta
int AltaDeCliente(eClientes clientes[], int cantidad, int* idClientes, eLocalidad localidades[], int tam_localidades);

/// @fn int CargarInfoCliente(eClientes[], int, int, char[], char[], char[], int, int)
/// @brief funcion que cargara los datos ingresados del cliente al array de estructura de clientes
/// @param clientes Array de Estructura que tiene las variables donde se guarda la informacion de cada cliente
/// @param cantidad Copia del tamanio del array de clientes
/// @param idCliente Copia del valor incrementado para el id del nuevo cliente
/// @param nombre Copia de la cadena de caracteres para el nombre
/// @param cuit Copia de la cadena de caracteres para el cuit
/// @param calle Copia de la cadena de caracteres para la calle
/// @param numero Copia del valor numerico
/// @param idLocalidad Copia del valor numerico del id seleccionado para la localidad
/// @return Devuelve -1 si es NULL o 0 si es ok
int CargarInfoCliente(eClientes clientes[], int cantidad, int idCliente , char nombre[], char cuit[], char calle[], int numero, int idLocalidad);

/// @fn void MostrarInfoUnCliente(eClientes, eLocalidad[], int)
/// @brief Funcion que va a mostrar la informacion de un cliente
/// @param cliente Copia de la informacion de una posicion de la estructura de clientes
/// @param localidades Array de Estructura que tiene las variables donde se guarda la informacion de las localidades
/// @param tam_localidades Copia del tamanio del array de la estructura de localidades
void MostrarInfoUnCliente(eClientes cliente, eLocalidad localidades[], int tam_localidades);

/// @fn int MostrarListaClientes(eClientes[], int, eLocalidad[], int)
/// @brief Funcion que mostrara la lista de clientes
/// @param clientes Array de Estructura que tiene las variables donde se guarda la informacion de cada cliente
/// @param cantidad Copia del tamanio del array de clientes
/// @param localidades Array de Estructura que tiene las variables donde se guarda la informacion de las localidades
/// @param tam_localidades Copia del tamanio del array de la estructura de localidades
/// @return Devuelve -1 si es NULL o 0 si es ok
int MostrarListaClientes(eClientes clientes[], int cantidad, eLocalidad localidades[], int tam_localidades);

/// @fn int ModificacionDatosDeUnCliente(eClientes[], int, eLocalidad[], int)
/// @brief Funcion que va a modificar la informacion de un cliente
/// @param clientes Array de Estructura que tiene las variables donde se guarda la informacion de cada cliente
/// @param cantidad Copia del tamanio del array de clientes
/// @param localidades Array de Estructura que tiene las variables donde se guarda la informacion de las localidades
/// @param tam_localidades Copia del tamanio del array de la estructura de localidades
/// @return Devuelve -1 si es NULL o 0 si es ok
int ModificacionDatosDeUnCliente(eClientes clientes[], int cantidad, eLocalidad localidades[], int tam_localidades);

/// @fn int ElegirOpcionDeModificacion(eClientes[], int, int, eLocalidad[], int)
/// @brief Funcion que se encarga de procesar la opcion elegida para modificar la informacion de un cliente
/// @param clientes Array de Estructura que tiene las variables donde se guarda la informacion de cada cliente
/// @param opcion Copia del valor de la opcion elegida para modificar
/// @param index Copia de la posicion en el array de estructura del cliente que va a ser modificado
/// @param localidades Array de Estructura que tiene las variables donde se guarda la informacion de las localidades
/// @param tam_localidades Copia del tamanio del array de la estructura de localidades
/// @return Devuelve -1 si es NULL o 1 si es ok
int ElegirOpcionDeModificacion(eClientes clientes[], int opcion, int index, eLocalidad localidades[], int tam_localidades);

/// @fn int BuscarClientePorId(eClientes[], int, int)
/// @brief Funcion que va a buscar en la lista de clientes a un especifico
/// @param clientes Puntero al Array de Estructura que tiene las variables donde se guardara la informacion de cada clientes
/// @param cantidad Copia del valor de la cantidad de clientes
/// @param id Copia del Id que va a buscar en la lista de clientes
/// @return Devuelve en i la posicion del cliente que encontro con el id que recibio, sino hay un cliente con ese id sera -1
int BuscarClientePorId(eClientes clientes[], int cantidad, int id);

/// @fn int BajaDeCliente(eClientes[], int, eLocalidad[], int)
/// @brief Funcion que dara de baja a un cliente, es decir pondra la posicion de memoria de dicho cliente como libre
/// @param clientes Array de Estructura que tiene las variables donde se guarda la informacion de cada cliente
/// @param cantidad Copia del tamanio del array de clientes
/// @param localidades Array de Estructura que tiene las variables donde se guarda la informacion de las localidades
/// @param tam_localidades Copia del tamanio del array de la estructura de localidades
/// @return Devuelve -1 si es NULL o 0 si es ok
int BajaDeCliente(eClientes clientes[], int cantidad, eLocalidad localidades[], int tam_localidades);

#endif /* CLIENTES_H_ */
