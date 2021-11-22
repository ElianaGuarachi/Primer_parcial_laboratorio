
#include "Informes.h"

int ListadoDeClientesContandoSusPedidosPendientes(eClientes clientes[], int tam_clientes, ePedidos pedidos[], int tam_pedidos, eLocalidad localidades[], int tam_localidades)
{
	int retorno = -1;
	eAuxiliarContador pedidosPendientes[tam_clientes];

	if(pedidos != NULL && clientes != NULL && tam_pedidos > 0 && tam_clientes > 0 && localidades != NULL && tam_localidades > 0)
	{
		if(InicializarAuxiliarContador(clientes, tam_clientes, pedidosPendientes) == 0 &&
			BuscarPedidosPendientesPorCliente(pedidos, tam_pedidos, pedidosPendientes, tam_clientes) == 0)
		{
			MostrarListaDeClientesConSusPedidosPendientes(clientes, tam_clientes, pedidosPendientes,localidades, tam_localidades);
			retorno=0;
		}
	}

	return retorno;
}

int BuscarPedidosPendientesPorCliente(ePedidos pedidos[], int tam_pedidos, eAuxiliarContador pedidosPendientes[], int tam_pendientes)
{
	int retorno=-1;
	int j;
	if(pedidos != NULL && tam_pedidos > 0 && tam_pendientes > 0 && pedidosPendientes != NULL)
	{
		for(j=0; j<tam_pedidos; j++)
		{
			if(pedidos[j].isEmpty == OCUPADO && pedidos[j].estado == PENDIENTE &&
				ContarPedidosPendientesPorCliente(pedidos[j], pedidosPendientes, tam_pendientes)==0)
			{
				retorno=0;
			}
		}
	}
	return retorno;
}

int ContarPedidosPendientesPorCliente(ePedidos pedidos, eAuxiliarContador pedidosPendientes[],  int tam_pendientes)
{
	int retorno=-1;
	int i;
	if(pedidosPendientes != NULL && tam_pendientes > 0)
	{
		for(i=0; i<tam_pendientes; i++)
		{
			if(pedidosPendientes[i].isEmpty == OCUPADO && pedidosPendientes[i].id == pedidos.idCliente)
			{
				pedidosPendientes[i].contador++;
				retorno = 0;
			}
		}
	}
	return retorno;
}

int InicializarAuxiliarContador(eClientes clientes[], int tam_clientes, eAuxiliarContador auxiliar[])
{
	int retorno = -1;
	int i;
	if(clientes != NULL && auxiliar != NULL && tam_clientes > 0)
	{
		for(i=0; i<tam_clientes; i++)
		{
			auxiliar[i].id = clientes[i].idCliente;
			auxiliar[i].contador = 0;
			auxiliar[i].acumulador = 0;
			auxiliar[i].isEmpty = clientes[i].isEmpty;
			retorno = 0;
		}
	}
	return retorno;
}


int MostrarListaDeClientesConSusPedidosPendientes(eClientes clientes[], int tam_clientes, eAuxiliarContador pedidosPendiente[], eLocalidad localidades[], int tam_localidades)
{
	int retorno=-1;
	int i;
	if(clientes != NULL && tam_clientes > 0  && pedidosPendiente != NULL)
	{
		for(i=0; i<tam_clientes; i++)
		{
			if(clientes[i].isEmpty == OCUPADO &&
				BuscarLocalidadDelCliente(clientes[i], tam_clientes, pedidosPendiente, localidades, tam_localidades)==0)
			{
				retorno=0;
			}
		}
	}

	return retorno;
}

int BuscarLocalidadDelCliente(eClientes cliente, int tam_pendientes, eAuxiliarContador pedidosPendiente[], eLocalidad localidades[], int tam_localidades)
{
	int retorno=-1;
	int j;
	if(pedidosPendiente != NULL && localidades != NULL && tam_pendientes > 0 && tam_localidades > 0)
	{
		for(j=0; j < tam_localidades; j++)
		{
			if(localidades[j].isEmpty == OCUPADO && cliente.idLocalidad == localidades[j].idLocalidad)
			{
				MostrarClienteConSusPedidosPendientes(cliente, tam_pendientes, pedidosPendiente, localidades[j]);
				retorno = 0;
			}
		}
	}
	return retorno;
}


void MostrarClienteConSusPedidosPendientes(eClientes cliente, int tam_pendientes, eAuxiliarContador pedidosPendientes[], eLocalidad localidades)
{
	int i;
	if(pedidosPendientes != NULL && tam_pendientes > 0)
	{
		for(i=0; i < tam_pendientes; i++)
		{
			if(pedidosPendientes[i].id == cliente.idCliente && pedidosPendientes[i].isEmpty == OCUPADO)
			{
				printf("\n%5d \t\t%20s \t%20s \t%25s %5d \t%15s \t\t%d", cliente.idCliente, cliente.nombreEmpresa, cliente.cuit,
						cliente.direccion.calle, cliente.direccion.numero, localidades.nombreLocalidad, pedidosPendientes[i].contador);
			}
		}
	}
}

/*
 * 7) Imprimir Pedidos pendientes: Se imprimirá una lista de los pedidos que se encuentren en estado “Pendiente”
 * con la información: Cuit del cliente, dirección del cliente, cantidad de kilos a recolectar.
 *
 * */

int MostrarListaDePedidosEnEstadoPendiente(ePedidos pedidos[], int tam_pedidos, eClientes clientes[], int tam_clientes)
{
	int retorno=-1;
	int i;
	if(pedidos != NULL && clientes != NULL && tam_pedidos>0 && tam_clientes>0)
	{
		printf("\nID PEDIDO PENDIENTE \t\tCUIT EMPRESA \t\t\tDIRECCION \t\t TOTAL KG. DE RESIDUOS\n");
		for(i=0;i<tam_pedidos;i++)
		{
			if(pedidos[i].isEmpty == OCUPADO && pedidos[i].estado == PENDIENTE)
			{
				PedidoEnEstadoPerdienteConSuCliente(pedidos[i], tam_clientes, clientes);
				retorno=0;
			}
		}
		printf("\n");
	}
	return retorno;
}

void PedidoEnEstadoPerdienteConSuCliente(ePedidos pedidos, int tam_clientes, eClientes clientes[])
{
	int j;
	if(clientes != NULL && tam_clientes > 0)
	{
		for(j=0; j < tam_clientes; j++)
		{
			if(clientes[j].isEmpty == OCUPADO && clientes[j].idCliente == pedidos.idCliente)
			{
				printf("\n\t%d \t\t%20s \t%25s %5d \t%15.2f", pedidos.idPedido, clientes[j].cuit,
						clientes[j].direccion.calle, clientes[j].direccion.numero, pedidos.cantidadKilos);
			}
		}
	}
}

/*
 * 8) Imprimir Pedidos procesados: Se imprimirá una lista de los pedidos que se encuentren en estado “Completado”
 * con la información: Cuit del cliente, dirección del cliente, cantidad de kilos reciclados de cada tipo de plástico.
 *
 * */

int ImprimirPedidosProcesadosEnEstadoCompletado(ePedidos pedidos[], int tam_pedidos, eClientes clientes[], int tam_clientes)
{
	int retorno=-1;
	int i;
	if(pedidos != NULL && clientes != NULL && tam_pedidos>0 && tam_clientes>0)
	{
		printf("\nID PEDIDO COMPLETADO \t\tCUIT EMPRESA \t\t\tDIRECCION \t\t KG. HDPE \tKG. HDLE \t KG. PP\n");
		for(i=0;i<tam_pedidos;i++)
		{
			if(pedidos[i].isEmpty == OCUPADO && pedidos[i].estado == COMPLETADO)
			{
				PedidoEnEstadoCompletadoConInfoDeSuCliente(pedidos[i], tam_clientes, clientes);
				retorno=0;
			}
		}
		printf("\n");
	}
	return retorno;
}

void PedidoEnEstadoCompletadoConInfoDeSuCliente(ePedidos pedidos, int tam_clientes, eClientes clientes[])
{
	int j;
	if(clientes != NULL && tam_clientes > 0)
	{
		for(j=0; j < tam_clientes; j++)
		{
			if(clientes[j].isEmpty == OCUPADO && clientes[j].idCliente == pedidos.idCliente)
			{
				printf("\n\t %d \t\t%20s \t%25s %5d %15.2f %15.2f %15.2f", pedidos.idPedido, clientes[j].cuit,
						clientes[j].direccion.calle, clientes[j].direccion.numero, pedidos.tiposResiduos.pAltaDensidad,
						pedidos.tiposResiduos.pBajaDensidad, pedidos.tiposResiduos.polipropileno);
			}
		}
	}
}

//9) Ingresar una localidad e indicar la cantidad de pedidos pendientes para dicha localidad.

int CantidadPedidosPendientesDeUnaLocalidad (ePedidos pedidos[], int tam_pedidos, eClientes clientes[], int tam_clientes, eLocalidad localidades[], int tam_localidades)
{
	int contador=-1;
	int auxLocalidad;
	int index;

	if(pedidos != NULL && tam_pedidos > 0 && clientes != NULL && tam_clientes > 0 && localidades != NULL && tam_localidades > 0)
	{
		contador=0;
		MostrarListaDeLocalidades(localidades, tam_localidades);
		printf("\n");
		if(ObtenerEntero(&auxLocalidad, "\nIngrese una localidad que desee buscar: ", "\nError. Ingrese la localidad nuevamente: ",1, 100,2)==0 &&
				VerificarIdLocalidadIngresado(localidades, tam_localidades, auxLocalidad)==1)
		{
			for(int i=0; i<tam_localidades; i++)
			{
				if(localidades[i].isEmpty == OCUPADO && localidades[i].idLocalidad == auxLocalidad &&
						BuscarEnListaDeClientes(localidades[i], pedidos, tam_pedidos, clientes, tam_clientes, &contador)==0)
				{
					break;
				}
			}
			index = BuscarLocalidadPorId(localidades, tam_localidades, auxLocalidad);
			if(index != -1)
			{
				printf("\nLa localidad: %s tiene %d pedidos pendientes.\n", localidades[index].nombreLocalidad, contador);
			}
		}
		else
		{
			printf("\nNo hay una localidad con el id ingresado\n");
		}
	}
	return contador;
}

int BuscarEnListaDeClientes(eLocalidad localidad, ePedidos pedidos[], int tam_pedidos, eClientes clientes[], int tam_clientes, int* contador)
{
	int retorno=-1;
	if(pedidos != NULL && clientes != NULL)
	{
		for(int j=0; j<tam_clientes;j++)
		{
			if(clientes[j].isEmpty == OCUPADO && localidad.idLocalidad == clientes[j].idLocalidad &&
					BuscarEnListaDePedidos(clientes[j], pedidos, tam_pedidos, contador)==0)
			{
				retorno=0;
			}
		}
	}
	return retorno;
}

int BuscarEnListaDePedidos(eClientes cliente, ePedidos pedidos[],int tam_pedidos, int*contador)
{
	int retorno=-1;
	if(pedidos != NULL && tam_pedidos> 0)
	{
		for(int k=0; k<tam_pedidos;k++)
		{
			if(pedidos[k].isEmpty == OCUPADO && pedidos[k].idCliente == cliente.idCliente && pedidos[k].estado == PENDIENTE)
			{
				*contador+=1;
				retorno=0;
			}
		}
	}
	return retorno;
}
//10) Cantidad de kilos de polipropileno reciclado promedio por cliente. (kilos totales / cantidad de clientes)

int PromedioRecicladoDePolipropilenoPorCliente(eClientes clientes[], int tam_clientes, ePedidos pedidos[], int tam_pedidos)
{
	int retorno = -1;
	eAuxiliarContador acumulador[tam_clientes];
	if(pedidos != NULL && clientes != NULL && tam_pedidos > 0 && tam_clientes > 0)
	{
		if(InicializarAuxiliarContador(clientes, tam_clientes, acumulador) == 0 &&
			CalcularCantidadDePolipropilenoReciclado(pedidos, tam_pedidos, acumulador, tam_clientes) == 0 &&
			CalcularPromedioDePolipropileno(acumulador, tam_clientes)==0)
		{
			MostrarElPromedioDePolipropilenoPorCliente(acumulador, tam_clientes, clientes);
			retorno=0;
		}
	}

	return retorno;
}

void MostrarElPromedioDePolipropilenoPorCliente(eAuxiliarContador auxiliar[], int tam_clientes, eClientes clientes[])
{
	int i;
	if(tam_clientes > 0 && auxiliar != NULL)
	{
		printf("\nID \t\tCLIENTE \t\tKG RECICLADOS PP");
		for(i=0; i< tam_clientes; i++)
		{
			if(auxiliar[i].isEmpty==OCUPADO)
			{
				printf("\n%2d %20s %25.2f ", auxiliar[i].id, clientes[i].nombreEmpresa, auxiliar[i].promedio);
			}
		}
	}
}

int CalcularPromedioDePolipropileno(eAuxiliarContador auxiliar[], int tam_auxiliar)
{
	int retorno = -1;
	int i;
	if(auxiliar != NULL && tam_auxiliar > 0)
	{
		for(i=0; i<tam_auxiliar; i++)
		{
			if(auxiliar[i].isEmpty == OCUPADO && auxiliar[i].acumulador > 0 && auxiliar[i].contador > 0)
			{
				auxiliar[i].promedio = auxiliar[i].acumulador/auxiliar[i].contador;
				retorno=0;
			}
		}
	}
	return retorno;
}

int CalcularCantidadDePolipropilenoReciclado(ePedidos pedidos[], int tam_pedidos, eAuxiliarContador auxiliar[], int tam_auxiliar)
{
	int retorno=-1;
	int j;
	if(pedidos != NULL && tam_pedidos > 0 && tam_auxiliar > 0 && auxiliar != NULL)
	{
		for(j=0; j<tam_pedidos; j++)
		{
			if(pedidos[j].isEmpty == OCUPADO && pedidos[j].estado == COMPLETADO &&
				AcumularPolipropilenoRecicladoPorCliente(pedidos[j], auxiliar, tam_auxiliar)==0)
			{
				retorno=0;
			}
		}
	}
	return retorno;
}

int AcumularPolipropilenoRecicladoPorCliente(ePedidos pedido, eAuxiliarContador auxiliar[], int tam_auxiliar)
{
	int retorno = -1;
	int i;
	if(auxiliar != NULL && tam_auxiliar > 0)
	{
		for(i=0; i<tam_auxiliar; i++)
		{
			if(auxiliar[i].isEmpty == OCUPADO && auxiliar[i].id == pedido.idCliente )
			{
				auxiliar[i].acumulador += pedido.tiposResiduos.polipropileno;
				auxiliar[i].contador++;
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

//"\n11- Cliente con más pedidos pendientes."

int ObtenerClienteConMasPedidosPendientes(eClientes clientes[], int tam_clientes, ePedidos pedidos[], int tam_pedidos, eLocalidad localidades[], int tam_localidades)
{
	int retorno = -1;
	int cantidadPedidosPendientes;
	eAuxiliarContador pedidosPendientes[tam_clientes];
	if(pedidos != NULL && clientes != NULL && tam_pedidos > 0 && tam_clientes > 0)
	{
		retorno =0;
		if(InicializarAuxiliarContador(clientes, tam_clientes, pedidosPendientes) == 0 &&
			BuscarPedidosPendientesPorCliente(pedidos, tam_pedidos, pedidosPendientes, tam_clientes) == 0)
		{
			for(int i=0; i < tam_clientes; i++)
			{
				if(pedidosPendientes[i].isEmpty == OCUPADO && (retorno == 0 || pedidosPendientes[i].contador > cantidadPedidosPendientes))
				{
					cantidadPedidosPendientes = pedidosPendientes[i].contador;
					retorno=1;
				}
			}
			printf("\nEl/los cliente/s con mas pedidos pendientes es/son: \n");
			BuscarClienteConMasPedidos(pedidosPendientes, tam_clientes, clientes, localidades, tam_localidades, cantidadPedidosPendientes);
		}
	}
	return retorno;
}

int BuscarClienteConMasPedidos(eAuxiliarContador auxPedidos[], int tam_clientes, eClientes clientes[],eLocalidad localidades[], int tam_localidades, int cantidad)
{
	int retorno=-1;
	if(clientes != NULL && tam_clientes > 0 && auxPedidos != NULL)
	{
		retorno=0;
		for(int i=0; i<tam_clientes; i++)
		{
			if(clientes[i].isEmpty == OCUPADO)
			{
				MostrarClienteConMasPedidos(clientes[i], auxPedidos, tam_clientes, localidades, tam_localidades, cantidad);
				retorno=0;
			}
		}
	}
	return retorno;
}

int MostrarClienteConMasPedidos(eClientes cliente, eAuxiliarContador auxPedidos[], int tam_auxPedidos, eLocalidad localidades[], int tam_localidades, int cantidad)
{
	int retorno=-1;
	if(auxPedidos != NULL && tam_auxPedidos > 0 && localidades != NULL && tam_localidades > 0)
	{
		for(int j=0; j<tam_auxPedidos; j++)
		{
			if(auxPedidos[j].isEmpty == OCUPADO && auxPedidos[j].contador == cantidad && auxPedidos[j].id == cliente.idCliente)
			{
				MostrarInfoUnCliente(cliente, localidades,tam_localidades);
				printf("\n");
				retorno=0;
			}
		}
	}
	return retorno;
}

//"\n12- Cliente con más pedidos completados."

int MostrarClienteConMasPedidosCompletados(eClientes clientes[], int tam_clientes, ePedidos pedidos[], int tam_pedidos, eLocalidad localidades[], int tam_localidades)
{
	int retorno = -1;
	int cantidadPedidosCompletos;
	eAuxiliarContador pedidosCompletos[tam_clientes];

	if(pedidos != NULL && clientes != NULL && tam_pedidos > 0 && tam_clientes > 0 && localidades != NULL && tam_localidades > 0)
	{
		retorno=0;
		if(InicializarAuxiliarContador(clientes, tam_clientes, pedidosCompletos) == 0 &&
			BuscarPedidosCompletadosPorCliente(pedidos, tam_pedidos, pedidosCompletos, tam_clientes) == 0)
		{
			for(int i=0; i < tam_clientes; i++)
			{
				if(pedidosCompletos[i].isEmpty == OCUPADO && (retorno == 0 || pedidosCompletos[i].contador > cantidadPedidosCompletos))
				{
					cantidadPedidosCompletos = pedidosCompletos[i].contador;
					retorno=1;
				}
			}
			printf("\nEl/los cliente/s con mas pedidos completados es/son: \n");
			BuscarClienteConMasPedidos(pedidosCompletos, tam_clientes, clientes, localidades, tam_localidades, cantidadPedidosCompletos);
		}
	}

	return retorno;
}

int BuscarPedidosCompletadosPorCliente(ePedidos pedidos[], int tam_pedidos, eAuxiliarContador pedidosCompletos[], int tam_completos)
{
	int retorno=-1;
	int j;
	if(pedidos != NULL && tam_pedidos > 0 && tam_completos > 0 && pedidosCompletos != NULL)
	{
		for(j=0; j<tam_pedidos; j++)
		{
			if(pedidos[j].isEmpty == OCUPADO && pedidos[j].estado == COMPLETADO &&
				ContarPedidosCompletadosPorCliente(pedidos[j], pedidosCompletos, tam_completos)==0)
			{
				retorno=0;
			}
		}
	}
	return retorno;
}

int ContarPedidosCompletadosPorCliente(ePedidos pedidos, eAuxiliarContador pedidosCompletos[],  int tam_completos)
{
	int retorno=-1;
	int i;
	if(pedidosCompletos != NULL && tam_completos > 0)
	{
		for(i=0; i<tam_completos; i++)
		{
			if(pedidosCompletos[i].isEmpty == OCUPADO && pedidosCompletos[i].id == pedidos.idCliente)
			{
				pedidosCompletos[i].contador++;
				retorno = 0;
			}
		}
	}
	return retorno;
}


