
#ifndef PEDIDOS_H_
#define PEDIDOS_H_

#include "Clientes.h"
#define PENDIENTE 1
#define COMPLETADO 2

typedef struct
{
	float pAltaDensidad;
	float pBajaDensidad;
	float polipropileno;

}eTiposResiduos;

typedef struct
{
	int idPedido;
	float cantidadKilos;
	eTiposResiduos tiposResiduos;
	int idCliente;
	int estado;
	int isEmpty;
}ePedidos;

/// @fn int InicializarListaDePedidos(ePedidos[], int)
/// @brief Funcion que se encarga de recorrer el campo isEmpty de la estructura clientes para darle el valor inicial de 0
/// @param pedidos Estructura con las variables que permitira guardar la informacion de cada pedido
/// @param cantidad Copia del tamanio del array de pedidos
/// @return Devuelve 1 si la funcion es ok, sino -1
int InicializarListaDePedidos(ePedidos pedidos[], int cantidad);

/// @fn int BuscarLugarLibrePedidos(ePedidos[], int)
/// @brief Funcion que busca un lugar libre en el array de estructura de pedidos
/// @param pedidos Estructura con las variables que permitira guardar la informacion de cada pedido
/// @param cantidad Copia del tamanio del array de pedidos
/// @return Devuelve el indice de la posicion libre encontrada, sino encontro una devuelve -1
int BuscarLugarLibrePedidos(ePedidos pedidos[], int cantidad);

/// @fn int BuscarPedidosPorId(ePedidos[], int, int)
/// @brief Funcion que se encarga de buscar en la estructura de pedidos en el campo id el valor del id que quiero
/// @param pedidos Estructura con las variables que permitira guardar la informacion de cada pedido
/// @param cantidad Copia del tamanio del array de pedidos
/// @param id Copia del id que quiero buscar
/// @return Devuelve el valor del indice que se encontro (de esta manera tambien valida que el id existe)
int BuscarPedidosPorId(ePedidos pedidos[], int cantidad, int id);

/// @fn int AltaPedidoDeRecoleccion(eClientes[], int, ePedidos[], int, int*)
/// @brief Funcion que se encargara de dar de alta un pedido de residuos, cambiando el estado de esa posicion a ocupado
/// @param clientes Array de Estructura que tiene las variables donde se guarda la informacion de cada cliente
/// @param tam_clientes Copia del tamanio del array de clientes
/// @param pedidos Estructura con las variables que permitira guardar la informacion de cada pedido
/// @param tam_pedidos Copia del tamanio del array de pedidos
/// @param idPedidos Direccion de memoria en donde se incrementara el valor a +1 cada vez que se realice un alta de pedido
/// @return Devuelve 1 si el alta se realizo, sino sera -1
int AltaPedidoDeRecoleccion(eClientes clientes[], int tam_clientes, ePedidos pedidos[], int tam_pedidos, int* idPedidos,  eLocalidad localidades[], int tam_localidades);

/// @fn int MostrarInfoUnPedido(ePedidos, eClientes[], int)
/// @brief Funcion que matchea la lista de pedidos con la lista de clientes con el id, a partir de eso mostrara una combinacion de informacion de las dos estructuras
/// @param pedidos Estructura con las variables que permitira guardar la informacion de cada pedido
/// @param clientes Array de Estructura que tiene las variables donde se guarda la informacion de cada cliente
/// @param tam_clientes Copia del tamanio del array de clientes
/// @return Devuelve 0 si se realizo un matcheo y mostro la informacion, de lo contrario es -1
int MostrarInfoUnPedido(ePedidos pedidos, eClientes clientes[], int tam_clientes);

/// @fn int MostrarListaDePedidos(ePedidos[], int, eClientes[], int)
/// @brief funcion que se encargara de mostrar toda la lista de pedido que se encuentren en estado ocupado
/// @param pedidos Array de Estructura con las variables que permitira guardar la informacion de cada pedido
/// @param tam_pedidos Copia del tamanio del array de pedidos
/// @param clientes Array de Estructura que tiene las variables donde se guarda la informacion de cada cliente
/// @param tam_clientes Copia del tamanio del array de clientes
/// @return Devuelve 0 si la funcion es ok, sino sera -1
int MostrarListaDePedidos(ePedidos pedidos[], int tam_pedidos, eClientes clientes[], int tam_clientes);

/// @fn int ProcesarResiduos(ePedidos[], int, eClientes[], int)
/// @brief Funcion que se encargara de procesar los residuos, es decir que cambia el estado de pendiente a completado, completando la clasificacion de los tipos de plastico
/// @param pedidos Array de Estructura con las variables que permitira guardar la informacion de cada pedido
/// @param tam_pedidos Copia del tamanio del array de pedidos
/// @param clientes Array de Estructura que tiene las variables donde se guarda la informacion de cada cliente
/// @param tam_clientes Copia del tamanio del array de clientes
/// @return Devuelve 0 si la funcion se realiza, sino sera -1
int ProcesarResiduos(ePedidos pedidos[], int tam_pedidos, eClientes clientes[], int tam_clientes);

/// @fn int VerificarIngresoDeTiposDeResiduos(ePedidos[], int)
/// @brief Funcion que se encargara de que la suma de las cantidad de los tipos de plastico no supere a la totalidad de residuos que se ingreso
/// @param pedidos Estructura con las variables que permitira guardar la informacion de cada pedido
/// @param index Valor de la posicion de array de la estructura de pedidos con la que esta realizando la verificacion
/// @return Devuelve 0 si la funcion se realiza, sino sera -1
int VerificarIngresoDeTiposDeResiduos(ePedidos pedidos[], int index);

/// @fn void PedirIngresoDeTiposDeResiduosReciclados(ePedidos[], int)
/// @brief Funcion que va a pedir el ingreso de los tipos de plasticos
/// @param pedidos Estructura con las variables que permitira guardar la informacion de cada pedido
/// @param index Valor de la posicion de array de la estructura de pedidos en la que se va a guardar el ingreso
void PedirIngresoDeTiposDeResiduosReciclados (ePedidos pedidos[], int index);

/// @fn int MostrarListaDePedidosPendientes(ePedidos[], int, eClientes[], int)
/// @brief Funcion que mostrara el listado de pedidos en situacion de pendientes
/// @param pedidos Direccion de memoria de la estructura donde estan las variables que permitira guardar la informacion de cada pedido
/// @param tam_pedidos Copia del valor del array de pedidos
/// @param clientes Direccion de memoria donde esta la informacion de cada cliente
/// @param tam_clientes copia del valor del array de clientes
/// @return Devuelve 0 si la funcion se realiza, sino sera -1
int MostrarListaDePedidosPendientes(ePedidos pedidos[], int tam_pedidos, eClientes clientes[], int tam_clientes);

#endif /* PEDIDOS_H_ */
