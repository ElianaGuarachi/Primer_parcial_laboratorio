
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

/// @fn eClientes InformacionDeUnCliente()
/// @brief Funcion que se encarga de pedir los datos de los clientes
/// @return Devuelve la estructura con la informacion cargada
eClientes InformacionDeUnCliente(eLocalidad localidades[], int tam_localidades);

/// @fn int AltaDeCliente(eClientes[], int, int*)
/// @brief Funcion que se encarga de guardar en un lugar libre del array de estructura de clientes la informacion de un cliente
/// @param clientes Puntero al Array de Estructura que tiene las variables donde se guardara la informacion de cada clientes
/// @param cantidad Copia del valor de la cantidad de clientes
/// @param idClientes Direccion de memoria de donde se obtiene el valor del id para sumarle el cliente que se da alta
/// @return Devuelve 0 si el alta fue efectivo, o -1 si no se pudo hacer
int AltaDeCliente(eClientes clientes[], int cantidad, int* idClientes, eLocalidad localidades[],int tam_localidades);

/// @fn void MostrarInfoUnCliente(eClientes)
/// @brief Funcion que muestra toda la informacion de un solo cliente
/// @param cliente Estructura de un cliente de donde se obtendra los campos de la misma
void MostrarInfoUnCliente(eClientes cliente, eLocalidad localidades[], int tam_localidades);

/// @fn int MostrarListaClientes(eClientes[], int)
/// @brief Funcion que se encarga de mostrar la lista de todas las empresas que estan dadas de alta (menos las bajas)
/// @param clientes Puntero al Array de Estructura que tiene las variables donde se guardara la informacion de cada clientes
/// @param cantidad Copia del valor de la cantidad de clientes
/// @return Devuelve 0 si la funcion se realizo, o -1 si no pudo
int MostrarListaClientes(eClientes clientes[], int cantidad, eLocalidad localidades[], int tam_localidades);

/// @fn int ModificacionDatosDeUnCliente(eClientes[], int)
/// @brief Funcion que va a modificar la direccion o la localidad de un cliente
/// @param clientes Puntero al Array de Estructura que tiene las variables donde se guardara la informacion de cada clientes
/// @param cantidad Copia del valor de la cantidad de clientes
/// @return Si la funcion se realizo devuelve 0, sino -1
int ModificacionDatosDeUnCliente(eClientes clientes[], int cantidad, eLocalidad localidades[], int tam_localidades);

/// @fn int ElegirOpcionDeModificacion(eClientes[], int, int)
/// @brief Funcion que va a dar las opciones de medificacion a traves de un switch de un cliente ya seleccionado
/// @param clientes Puntero al Array de Estructura que tiene las variables donde se guardara la informacion de cada clientes
/// @param opcion copia del numero que se opcion en el switch
/// @param index Copia de la ubicacion en el array de estructuras que se va a modificar
/// @return Devuelve 1 si realizo los cambios, sino -1
int ElegirOpcionDeModificacion(eClientes clientes[], int opcion, int index, eLocalidad localidades[], int tam_localidades);

/// @fn int BuscarClientePorId(eClientes[], int, int)
/// @brief Funcion que va a buscar en la lista de clientes a un especifico
/// @param clientes Puntero al Array de Estructura que tiene las variables donde se guardara la informacion de cada clientes
/// @param cantidad Copia del valor de la cantidad de clientes
/// @param id Copia del Id que va a buscar en la lista de clientes
/// @return Devuelve en i la posicion del cliente que encontro con el id que recibio, sino hay un cliente con ese id sera -1
int BuscarClientePorId(eClientes clientes[], int cantidad, int id);

/// @fn int BajaDeCliente(eClientes[], int)
/// @brief Funcion que se encargara de dar de baja a un cliente, es decir que pondra una posicion como LIBRE
/// @param clientes Puntero al Array de Estructura que tiene las variables donde se guardara la informacion de cada clientes
/// @param cantidad Copia del valor de la cantidad de clientes
/// @return Si devuelve 0 esta bien, sino devolvera -1
int BajaDeCliente(eClientes clientes[], int cantidad, eLocalidad localidades[], int tam_localidades);

#endif /* CLIENTES_H_ */
