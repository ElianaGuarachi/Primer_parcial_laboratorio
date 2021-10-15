
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

/// @fn int ListadoDeClientesContandoSusPedidosPendientes(eClientes[], int, ePedidos[], int)
/// @brief Funcion inicial que llamara a varias funciones para terminar de mostrar la lista de clientes con la cantidad de pedidos en estado pendiente que tenga
/// @param clientes Array de Estructura que tiene las variables donde se guarda la informacion de cada cliente
/// @param tam_clientes Copia del tamanio del array de clientes
/// @param pedidos Array de Estructura con las variables que permitira guardar la informacion de cada pedido
/// @param tam_pedidos Copia del tamanio del array de la estructura de pedidos
/// @return Devuelve 0 si la funcion se realiza, sino sera -1
int ListadoDeClientesContandoSusPedidosPendientes(eClientes clientes[], int tam_clientes, ePedidos pedidos[], int tam_pedidos, eLocalidad localidades[], int tam_localidades);

/// @fn int ContadorDePedidosPendientePorCliente(ePedidos[], int, eAuxiliarContador[], int)
/// @brief funcion que se va a encangar de contar los pedidos pendientes que tenga cada cliente en una estructura auxiliar
/// @param pedidos Array de Estructura con las variables que permitira guardar la informacion de cada pedido
/// @param tam_pedidos Copia del tamanio del array de la estructura de pedidos
/// @param pedidosPendientes estrutura auxiliar que tiene la copia del id de los clientes y su estado isEmpty
/// @param tam_pendientes Copia del tamanio de la estructura de clientes, que ahora es de la estruta auxiliar
/// @return Devuelve 0 si la funcion se realiza, sino sera -1
int ContadorDePedidosPendientePorCliente(ePedidos pedidos[], int tam_pedidos, eAuxiliarContador pedidosPendientes[], int tam_pendientes);

/// @fn int InicializarAuxiliarContador(eClientes[], int, eAuxiliarContador[])
/// @brief Funcion que se encarga de inicializar la estructura auxiliar, el id con el de los clientes, contador y acumulador a 0, y el estado isEmpty como los clientes
/// @param clientes Array de Estructura que tiene las variables donde se guarda la informacion de cada cliente
/// @param tam_clientes Copia del tamanio del array de clientes
/// @param auxiliar estrutura auxiliar que tiene la copia del id de los clientes y su estado isEmpty
/// @return Devuelve 0 si la funcion se realiza, sino sera -1
int InicializarAuxiliarContador(eClientes clientes[], int tam_clientes, eAuxiliarContador auxiliar[]);

/// @fn int MostrarListaDeClientesConSusPedidosPendientes(eClientes[], int, eAuxiliarContador[])
/// @brief Funcion que mostrara la lista de clientes llamando a la funcion de mostrar por cliente
/// @param clientes Array de Estructura que tiene las variables donde se guarda la informacion de cada cliente
/// @param tam_clientes Copia del tamanio del array de clientes
/// @param pedidosPendiente estrutura auxiliar que tiene la copia del id de los clientes y su estado isEmpty
/// @return Devuelve 0 si la funcion se realiza, sino sera -1
int MostrarListaDeClientesConSusPedidosPendientes(eClientes clientes[], int tam_clientes, eAuxiliarContador pedidosPendiente[], eLocalidad localidades[], int tam_localidades);

/// @fn void MostrarClienteConSusPedidosPendientes(eClientes, int, eAuxiliarContador[])
/// @brief Funcion que matchea entre el id de la estructura auxiliar y el id cliente para combinar la informacion entre ambos tipos de estructura
/// @param cliente Array de Estructura que tiene las variables donde se guarda la informacion de cada cliente
/// @param tam_clientes Copia del tamanio del array de clientes
/// @param pedidosPendientes estrutura auxiliar que tiene la copia del id de los clientes y su estado isEmpty
void MostrarClienteConSusPedidosPendientes(eClientes cliente, int tam_clientes, eAuxiliarContador pedidosPendientes[], eLocalidad localidades);

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

/// @fn int CantidadPedidosPendientesPorLocalidad(ePedidos[], int, eClientes[], int)
/// @brief Funcion que se encarga de recorrer las listas de pedidos y clientes para contar los pedidos pendientes que hayan por localidad
/// @param pedidos Array de Estructura con las variables que permitira guardar la informacion de cada pedido
/// @param tam_pedidos Copia del tamanio del array de la estructura de pedidos
/// @param clientes Array de Estructura que tiene las variables donde se guarda la informacion de cada cliente
/// @param tam_clientes Copia del tamanio del array de clientes
/// @return Devuelve 0 si la funcion se realiza, sino sera -1
int CantidadPedidosPendientesPorLocalidad (ePedidos pedidos[], int tam_pedidos, eClientes clientes[], int tam_clientes);

/// @fn int VerificarIngresoDeLocalidad(eClientes[], int, char[])
/// @brief Funcion que verifica que la localidad ingresada este en la lista de clientes
/// @param clientes Array de Estructura que tiene las variables donde se guarda la informacion de cada cliente
/// @param tam_clientes Copia del tamanio del array de clientes
/// @param localidadIngresada Direccion de memoria donde se encuentra la cadena de caracteres de la localidad ingresada anteriormente
/// @return Devuelve 0 si la funcion se realiza, sino sera -1
int VerificarIngresoDeLocalidad(eClientes clientes[], int tam_clientes, char localidadIngresada[]);

/// @fn int ContarEnListaDeClientesLasLocalidadesConPedidosPendiente(ePedidos[], eClientes, int, char[])
/// @brief Funcion que recorre el listado de pedidos y clientes, cuando matchea con el id de clientes cuenta los pedidos que esten en la localidad ingresada
/// @param pedidos Array de Estructura con las variables que permitira guardar la informacion de cada pedido
/// @param clientes Array de Estructura que tiene las variables donde se guarda la informacion de cada cliente
/// @param tam_pedidos Copia del tamanio del array de la estructura de pedidos
/// @param localidadIngresada Direccion de memoria donde se encuentra la cadena de caracteres de la localidad ingresada anteriormente
/// @return Devuelve la cantidad de veces que conto los pedidos pendientes por la localidad ingresada, si no encontro devuelve 0
int ContarEnListaDeClientesLasLocalidadesConPedidosPendiente(ePedidos pedidos[], eClientes clientes, int tam_pedidos, char localidadIngresada[]);

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
int CalculoPromedioDePolipropileno(eAuxiliarContador auxiliar[], int tam_auxiliar);

/// @fn int AcumuladorDePolipropilenoConAuxiliar(ePedidos[], int, eAuxiliarContador[], int)
/// @brief
/// @param pedidos Direccion de memoria donde se encuetra la lisra de pedidos
/// @param tam_pedidos Copia del tamanio del array de estructura pedidos
/// @param auxiliar array de estructura auxiliar donde se encuentra la informacion para realizar el promedio
/// @param tam_auxiliar copia del tamanio del array de estructuras auxiliar
/// @return Devuelve 0 si la funcion realizo el proceso, sino es -1
int AcumuladorDePolipropilenoConAuxiliar(ePedidos pedidos[], int tam_pedidos, eAuxiliarContador auxiliar[], int tam_auxiliar);

#endif /* INFORMES_H_ */
