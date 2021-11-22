
#ifndef INFORMES_H_
#define INFORMES_H_
#include "Clientes.h"
#include "Pedidos.h"
#include "localidad.h"

typedef struct
{
	int id;
	int contador;
	float acumulador;
	float promedio;
	int isEmpty;
}eAuxiliarContador;

/// @fn int ListadoDeClientesContandoSusPedidosPendientes(eClientes[], int, ePedidos[], int, eLocalidad[], int)
/// @brief Funcion que mostrara la lista de clientes con sus pedidos pendientes
/// @param clientes Array de Estructura que tiene las variables donde se guarda la informacion de cada cliente
/// @param tam_clientes Copia del tamanio del array de clientes
/// @param pedidos Array de Estructura con las variables que permitira guardar la informacion de cada pedido
/// @param tam_pedidos Copia del tamanio del array de la estructura de pedidos
/// @param localidades Array de Estructura que tiene las variables donde se guarda la informacion de las localidades
/// @param tam_localidades Copia del tamanio del array de la estructura de localidades
/// @return Devuelve 0 si la funcion se realiza, sino sera -1
int ListadoDeClientesContandoSusPedidosPendientes(eClientes clientes[], int tam_clientes, ePedidos pedidos[], int tam_pedidos, eLocalidad localidades[], int tam_localidades);

/// @fn int BuscarPedidosPendientesPorCliente(ePedidos[], int, eAuxiliarContador[], int)
/// @brief Funcion que recorrera la lista de pedidos buscando los que se encuentren como pendientes
/// @param pedidos Array de Estructura con las variables que permitira guardar la informacion de cada pedido
/// @param tam_pedidos Copia del tamanio del array de la estructura de pedidos
/// @param pedidosPendientes array de estructura auxiliar donde se guardara la informacion de recuento
/// @param tam_pendientes tamanio del array de estructura auxiliar
/// @return Devuelve 0 si la funcion se realiza, o -1 si es NULL
int BuscarPedidosPendientesPorCliente(ePedidos pedidos[], int tam_pedidos, eAuxiliarContador pedidosPendientes[], int tam_pendientes);

/// @fn int ContarPedidosPendientesPorCliente(ePedidos, eAuxiliarContador[], int)
/// @brief Funcion que contara los pedidos pendientes de cada cliente recorriendo el array auxiliar
/// @param pedidos Pasaje por valor de una estructura de pedidos
/// @param pedidosPendientes Array de estructura del auxiliar que contara los pedidos pendientes
/// @param tam_pendientes tamnio del array de estructura auxiliar
/// @return Devuelve 0 si la funcion se realiza, o -1 si es NULL
int ContarPedidosPendientesPorCliente(ePedidos pedidos,eAuxiliarContador pedidosPendientes[],  int tam_pendientes);

/// @fn int InicializarAuxiliarContador(eClientes[], int, eAuxiliarContador[])
/// @brief Funcion que se encarga de inicializar la estructura auxiliar, el id con el de los clientes, contador y acumulador a 0, y el estado isEmpty como los clientes
/// @param clientes Array de Estructura que tiene las variables donde se guarda la informacion de cada cliente
/// @param tam_clientes Copia del tamanio del array de clientes
/// @param auxiliar estrutura auxiliar que tiene la copia del id de los clientes y su estado isEmpty
/// @return Devuelve 0 si la funcion se realiza, sino sera -1
int InicializarAuxiliarContador(eClientes clientes[], int tam_clientes, eAuxiliarContador auxiliar[]);

/// @fn int MostrarListaDeClientesConSusPedidosPendientes(eClientes[], int, eAuxiliarContador[], eLocalidad[], int)
/// @brief funcion que muestra la lista de clientes con la cantidad de pedidos pendientes de los mismos
/// @param clientes Array de Estructura que tiene las variables donde se guarda la informacion de cada cliente
/// @param tam_clientes Copia del tamanio del array de clientes
/// @param pedidosPendiente Array de estructura auxiliar de pedidos pendientes
/// @param localidades Array de Estructura que tiene las variables donde se guarda la informacion de las localidades
/// @param tam_localidades Copia del tamanio del array de la estructura de localidades
/// @return Devuelve 0 si la funcion se realiza, o -1 si es NULL
int MostrarListaDeClientesConSusPedidosPendientes(eClientes clientes[], int tam_clientes, eAuxiliarContador pedidosPendiente[], eLocalidad localidades[], int tam_localidades);

/// @fn int BuscarLocalidadDelCliente(eClientes, int, eAuxiliarContador[], eLocalidad[], int)
/// @brief Funcion que recorre el array de estructura para matchear con los clientes
/// @param cliente Pasaje por valor de una estructura de cliente
/// @param tam_pendientes tamanio del array de estructura auxiliar
/// @param pedidosPendientes Array de estructura auxiliar de pedidos pendientes
/// @param localidades Array de Estructura que tiene las variables donde se guarda la informacion de las localidades
/// @param tam_localidades Copia del tamanio del array de la estructura de localidades
/// @return Devuelve 0 si la funcion se realiza, o -1 si es NULL
int BuscarLocalidadDelCliente(eClientes cliente, int tam_pendientes, eAuxiliarContador pedidosPendiente[], eLocalidad localidades[], int tam_localidades);

/// @fn void MostrarClienteConSusPedidosPendientes(eClientes, int, eAuxiliarContador[], eLocalidad)
/// @brief Funcion que mostrara la informacion de un cliente
/// @param cliente Pasaje por valor de una estructura de cliente
/// @param tam_pendientes tamanio del array de estructura auxiliar
/// @param pedidosPendientes Array de estructura auxiliar de pedidos pendientes
/// @param localidades Pasaje por valor de una estructua de localidades
void MostrarClienteConSusPedidosPendientes(eClientes cliente, int tam_pendientes, eAuxiliarContador pedidosPendientes[], eLocalidad localidades);

/// @fn void PedidoEnEstadoPerdienteConSuCliente(ePedidos, int, eClientes[])
/// @brief Funcion que va a matchaer entre la estrutura de pedidos y la de clientes a traves del id de clientes para combinar informaciones
/// @param pedidos estructura de tipo pedidos
/// @param tam_clientes Copia del tamanio del array de clientes
/// @param clientes Array de Estructura que tiene las variables donde se guarda la informacion de cada cliente
void PedidoEnEstadoPerdienteConSuCliente(ePedidos pedidos, int tam_clientes, eClientes clientes[]);

/// @fn int MostrarListaDePedidosEnEstadoPendiente(ePedidos[], int, eClientes[], int)
/// @brief Funcion que mostrara la lista de los pedidos en estado pendiente con informacion del cliente a traves de la llamada a otra funcion
/// @param pedidos Array de Estructura con las variables que permitira guardar la informacion de cada pedido
/// @param tam_pedidos Copia del tamanio del array de la estructura de pedidos
/// @param clientes Array de Estructura que tiene las variables donde se guarda la informacion de cada cliente
/// @param tam_clientes Copia del tamanio del array de clientes
/// @return  Devuelve 0 si la funcion se realiza, sino sera -1
int MostrarListaDePedidosEnEstadoPendiente(ePedidos pedidos[], int tam_pedidos, eClientes clientes[], int tam_clientes);

/// @fn int ImprimirPedidosProcesadosEnEstadoCompletado(ePedidos[], int, eClientes[], int)
/// @brief Funcion que imprimira los pedidos en estado completado a traves de un matcheo entre las estructuras pedidos y clientes, por el id clientes
/// @param pedidos Array de Estructura con las variables que permitira guardar la informacion de cada pedido
/// @param tam_pedidos Copia del tamanio del array de la estructura de pedidos
/// @param clientes Array de Estructura que tiene las variables donde se guarda la informacion de cada cliente
/// @param tam_clientes Copia del tamanio del array de clientes
/// @return  Devuelve 0 si la funcion se realiza, sino sera -1
int ImprimirPedidosProcesadosEnEstadoCompletado(ePedidos pedidos[], int tam_pedidos, eClientes clientes[], int tam_clientes);

/// @fn void PedidoEnEstadoCompletadoConInfoDeSuCliente(ePedidos, int, eClientes[])
/// @brief Funcion que recorre la lista de clientes para matchear con pedidos y asi poder combinar la informacion entre ambas estructuras
/// @param pedidos Estructura del tipo pedidos, con la que se realizara el matcheo
/// @param tam_clientes Copia del tamanio del array de clientes
/// @param clientes Array de Estructura que tiene las variables donde se guarda la informacion de cada cliente
void PedidoEnEstadoCompletadoConInfoDeSuCliente(ePedidos pedidos, int tam_clientes, eClientes clientes[]);

/// @fn int CantidadPedidosPendientesPorLocalidad(ePedidos[], int, eClientes[], int, eLocalidad[], int)
/// @brief Funcion que recorre el array de localidad buscando el id de la localidad ingresada luego de ser validada
/// @param clientes Array de Estructura que tiene las variables donde se guarda la informacion de cada cliente
/// @param tam_clientes Copia del tamanio del array de clientes
/// @param pedidos Array de Estructura con las variables que permitira guardar la informacion de cada pedido
/// @param tam_pedidos Copia del tamanio del array de la estructura de pedidos
/// @param localidades Array de Estructura que tiene las variables donde se guarda la informacion de las localidades
/// @param tam_localidades Copia del tamanio del array de la estructura de localidades
/// @return Devuelve -1 si es NULL, 0 si no hay pedidos para la localidad seleccionada o devuelve la cantidad que encontro
int CantidadPedidosPendientesDeUnaLocalidad (ePedidos pedidos[], int tam_pedidos, eClientes clientes[], int tam_clientes, eLocalidad localidades[], int tam_localidades);

/// @fn int BuscarEnListaDeClientes(eLocalidad, ePedidos[], int, eClientes[], int, int*)
/// @brief funcion que recorre el array de estructura de clientes para buscar los que tengan la localidad elegida
/// @param localidad Pasaje por valor de una estructura de localidad
/// @param pedidos Array de Estructura con las variables que permitira guardar la informacion de cada pedido
/// @param tam_pedidos Copia del tamanio del array de la estructura de pedidos
/// @param clientes Array de Estructura que tiene las variables donde se guarda la informacion de cada cliente
/// @param tam_clientes Copia del tamanio del array de clientes
/// @param contador Puntero a direccion donde se guardara la cantidad de pedidos por localidad
/// @return Devuelve 0 si la funcion se realiza, o -1 si es NULL
int BuscarEnListaDeClientes(eLocalidad localidad, ePedidos pedidos[], int tam_pedidos, eClientes clientes[], int tam_clientes, int* contador);

/// @fn int BuscarEnListaDePedidos(eClientes, ePedidos[], int, int*)
/// @brief funcion que recorre el array de estructura de pedidos, para condicionar los qe esten en estado pendiente
/// @param cliente Pasaje por valor de una estructura de cliente
/// @param pedidos Array de Estructura con las variables que permitira guardar la informacion de cada pedido
/// @param tam_pedidos Copia del tamanio del array de la estructura de pedidos
/// @param contador Puntero a direccion donde se guardara la cantidad de pedidos por localidad
/// @return Devuelve 0 si la funcion se realiza, o -1 si es NULL
int BuscarEnListaDePedidos(eClientes cliente, ePedidos pedidos[],int tam_pedidos, int*contador);

/// @fn int PromedioRecicladoDePolipropilenoPorCliente(eClientes[], int, ePedidos[], int)
/// @brief Funcion que se encargara de declarar una variable de tipo eAuxiliar para poder realizar el promedio al llamar a otras funciones
/// @param clientes Direccion de memoria donde se encuentra la lista de clientes
/// @param tam_clientes Copia del tamanio del array de estructura clientes
/// @param pedidos Direccion de memoria donde se encuetra la lisra de pedidos
/// @param tam_pedidos Copia del tamanio del array de estructura pedidos
/// @return Devuelve 0 si la funcion realizo el proceso, sino es -1
int PromedioRecicladoDePolipropilenoPorCliente(eClientes clientes[], int tam_clientes, ePedidos pedidos[], int tam_pedidos);

/// @fn void MostrarKilosTotalesPorClienteMasPromedio(eAuxiliarContador[], int, eClientes[])
/// @brief  Funcion que mostrara el promedio de los kilos reciclados de polipropileno por cliente
/// @param auxiliar estructura donde se encuentra el acumulador de kilos y contador de clientes
/// @param tam_clientes copia del tamanio del array de estructuras auxiliar
/// @param clientes Direccion de memoria donde esta la lista de clientes
void MostrarElPromedioDePolipropilenoPorCliente(eAuxiliarContador auxiliar[], int tam_clientes, eClientes clientes[]);

/// @fn int CalculoPromedioDePolipropileno(eAuxiliarContador[], int)
/// @brief Funcion que calcula el promedio de residuos de un tipo de plastico
/// @param auxiliar array de estructura auxiliar donde se encuentra la informacion para realizar el promedio
/// @param tam_auxiliar copia del tamanio del array de estructuras auxiliar
/// @return Devuelve 0 si la funcion realizo el proceso, sino es -1
int CalcularPromedioDePolipropileno(eAuxiliarContador auxiliar[], int tam_auxiliar);

/// @fn int CalcularCantidadDePolipropilenoReciclado(ePedidos[], int, eAuxiliarContador[], int)
/// @brief Funcion que va a evaluar que los pedidos se encuentre en estado completado para llamar a la funcion que los contara
/// @param pedidos Direccion de memoria donde se encuetra la lisra de pedidos
/// @param tam_pedidos Copia del tamanio del array de estructura pedidos
/// @param auxiliar array de estructura auxiliar donde se encuentra la informacion para realizar el promedio
/// @param tam_auxiliar copia del tamanio del array de estructuras auxiliar
/// @return Devuelve 0 si la funcion realizo el proceso, sino es -1
int CalcularCantidadDePolipropilenoReciclado(ePedidos pedidos[], int tam_pedidos, eAuxiliarContador auxiliar[], int tam_auxiliar);

/// @fn int AcumularPolipropilenoRecicladoPorCliente(ePedidos, eAuxiliarContador[], int)
/// @brief Funcion que va a acumular la cantidad de plastico de polipropileno por cliente
/// @param pedido Pasaje por valor de una estructura de pedido
/// @param auxiliar array de estructura auxiliar
/// @param tam_auxiliar tamanio del array de estructura auxiliar
/// @return Devuelve 0 si la funcion se realiza, o -1 si es NULL
int AcumularPolipropilenoRecicladoPorCliente(ePedidos pedido, eAuxiliarContador auxiliar[], int tam_auxiliar);

/// @fn int ObtenerClienteConMasPedidosPendientes(eClientes[], int, ePedidos[], int, eLocalidad[], int)
/// @brief funcion que busca al cliente con mayor cantidad de pedidos pendientes
/// @param clientes Array de Estructura que tiene las variables donde se guarda la informacion de cada cliente
/// @param tam_clientes Copia del tamanio del array de clientes
/// @param pedidos Array de Estructura con las variables que permitira guardar la informacion de cada pedido
/// @param tam_pedidos Copia del tamanio del array de la estructura de pedidos
/// @param localidades Array de Estructura que tiene las variables donde se guarda la informacion de las localidades
/// @param tam_localidades Copia del tamanio del array de la estructura de localidades
/// @return Devuelve 1 si la funcion se realiza, o -1 si es NULL
int ObtenerClienteConMasPedidosPendientes(eClientes clientes[], int tam_clientes, ePedidos pedidos[], int tam_pedidos, eLocalidad localidades[], int tam_localidades);

/// @fn int BuscarClienteConMasPedidos(eAuxiliarContador[], int, eClientes[], eLocalidad[], int, int)
/// @brief Funcion que recorre el array de clientes
/// @param auxPedidos Array de estructura auxiliar
/// @param tam_clientes Copia del tamanio del array de clientes
/// @param clientes Array de Estructura que tiene las variables donde se guarda la informacion de cada cliente
/// @param localidades Array de Estructura que tiene las variables donde se guarda la informacion de las localidades
/// @param tam_localidades Copia del tamanio del array de la estructura de localidades
/// @param cantidad Pasaje por valor de una cantidad maxima
/// @return Devuelve 0 si la funcion se realiza, o -1 si es NULL
int BuscarClienteConMasPedidos(eAuxiliarContador auxPedidos[], int tam_clientes, eClientes clientes[],eLocalidad localidades[], int tam_localidades, int cantidad);

/// @fn int MostrarClienteConMasPedidos(eClientes, eAuxiliarContador[], int, eLocalidad[], int, int)
/// @brief funcion que mostrara a los clientes con mas pedidos
/// @param cliente Pasaje por valor de una estructura de cliente
/// @param auxPedidos Array de estructura auxiliar
/// @param tam_auxPedidos tamanio del array de estructura auxiliar
/// @param localidades Array de Estructura que tiene las variables donde se guarda la informacion de las localidades
/// @param tam_localidades Copia del tamanio del array de la estructura de localidades
/// @param cantidad Pasaje por valor de una cantidad maxima
/// @return Devuelve 0 si la funcion se realiza, o -1 si es NULL
int MostrarClienteConMasPedidos(eClientes cliente, eAuxiliarContador auxPedidos[], int tam_auxPedidos, eLocalidad localidades[], int tam_localidades, int cantidad);

/// @fn int MostrarClienteConMasPedidosCompletados(eClientes[], int, ePedidos[], int, eLocalidad[], int)
/// @brief Funcion que mostrara al cliente con mas pedidos completados
/// @param clientes Array de Estructura que tiene las variables donde se guarda la informacion de cada cliente
/// @param tam_clientes Copia del tamanio del array de clientes
/// @param pedidos Array de Estructura con las variables que permitira guardar la informacion de cada pedido
/// @param tam_pedidos Copia del tamanio del array de la estructura de pedidos
/// @param localidades Array de Estructura que tiene las variables donde se guarda la informacion de las localidades
/// @param tam_localidades Copia del tamanio del array de la estructura de localidades
/// @return Devuelve 1 si la funcion se realiza, o -1 si es NULL
int MostrarClienteConMasPedidosCompletados(eClientes clientes[], int tam_clientes, ePedidos pedidos[], int tam_pedidos, eLocalidad localidades[], int tam_localidades);

/// @fn int BuscarPedidosCompletadosPorCliente(ePedidos[], int, eAuxiliarContador[], int)
/// @brief Funcion que busca los pedidos completos del array de pedidos para luego llamar a la funcion que los contara
/// @param pedidos Array de Estructura con las variables que permitira guardar la informacion de cada pedido
/// @param tam_pedidos Copia del tamanio del array de la estructura de pedidos
/// @param pedidosCompletos Array de estructura auxiliar de pedidos completos
/// @param tam_completos tamanio del array de estructura
/// @return Devuelve 0 si la funcion se realiza, o -1 si es NULL
int BuscarPedidosCompletadosPorCliente(ePedidos pedidos[], int tam_pedidos, eAuxiliarContador pedidosCompletos[], int tam_completos);

/// @fn int ContarPedidosCompletadosPorCliente(ePedidos, eAuxiliarContador[], int)
/// @brief Funcion que cuenta los pedidos completos por cliente
/// @param pedidos Pasaje por valor de una estructura de pedidos
/// @param pedidosCompletos Array de estructura auxiliar de pedidos completos
/// @param tam_completos tamanio del array de estructura
/// @return Devuelve 0 si la funcion se realiza, o -1 si es NULL
int ContarPedidosCompletadosPorCliente(ePedidos pedidos, eAuxiliarContador pedidosCompletos[],  int tam_completos);


#endif /* INFORMES_H_ */
