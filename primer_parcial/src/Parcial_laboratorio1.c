/*
 ============================================================================
 Name        : Parcial_laboratorio1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "Informes.h"

#define CANT_CLIENTES 5
#define CANT_PEDIDOS 8
#define CANT_LOCALIDADES 3

int main(void) {

	setbuf(stdout, NULL);
	eClientes clientes[CANT_CLIENTES] = {{1, "Zara", "26-12458796-4", {"Mariano Acosta", 236}, 1, OCUPADO},
										 {2, "Forever 21", "27-31546987-8", {"Av Avellaneda" , 123}, 2, OCUPADO},
										 {3, "Pepsi", "30-45987621-3", {"Emilio Mitre"  , 654}, 3, OCUPADO},
										 {4, "Mala mia", "31-36926395-5", {"Agustin de Vedia", 789}, 3, OCUPADO},
										 {5, "Jumbo" , "32-12457214-4", {"Av Cordoba" ,1234},1, OCUPADO}};

	ePedidos pedidos[CANT_PEDIDOS]={{1, 123, {0,10,12}, 2, COMPLETADO, OCUPADO},
										{2, 12, {0,0,0}, 2, PENDIENTE, OCUPADO},
										{3, 78, {12,20,25}, 1, COMPLETADO, OCUPADO},
										{4, 19, {0,0,0}, 3, PENDIENTE, OCUPADO},
										{5, 165, {26,25,10}, 2, COMPLETADO, OCUPADO},
										{6, 198, {0,0,0}, 5, PENDIENTE, OCUPADO},
										{7, 210, {0,0,0}, 4, PENDIENTE, OCUPADO},
										{8, 312, {12,14,15}, 2, COMPLETADO, OCUPADO}};

	eLocalidad localidades[CANT_LOCALIDADES]= {{1, "Villa Soldati",OCUPADO},
												{2, "Flores", OCUPADO},
												{3, "Floresta", OCUPADO}};
	int opcion;
	int idClientes;
	int idPedidos;
	idClientes=0;
	idPedidos=0;

	/*if(InicilizarClientes(clientes, CANT_CLIENTES) == -1)
	{
		printf("\nNo se inicializaron las lista");
	}*/

	/*if(	InicializarListaDePedidos(pedidos, CANT_PEDIDOS)==-1)
	{
		printf("\nNo se inicializaron las lista");
	}*/

	/*if(InicializarListaLocalidades(localidades, CANT_LOCALIDADES)==-1)
	{
		printf("\nNo se inicializaron las lista");
	}*/

	printf("== EMPRESA DE RECOLECCION Y RECICLADO DE PLASTICOS==\n");
	do{
		printf("\nMENU PRINCIPAL\n");
		printf("\n1- Alta de clientes"
			   "\n2- Modificar datos de cliente"
			   "\n3- Baja de cliente"
			   "\n4- Crear pedido de recoleccion"
			   "\n5- Procesar residuos"
			   "\n6- Imprimir clientes con la cantidad de pedidos pendientes"
			   "\n7- Imprimir pedidos pendientes"
			   "\n8- Imprimir pedidos procesados"
			   "\n9- Pedidos pendientes por localidad"
			   "\n10- Promedio de polipropileno reciclado por cliente"
			   "\n11- Cliente con m�s pedidos pendientes."
			   "\n12- Cliente con m�s pedidos completados."
			   "\n\n13- Salir\n");

		ObtenerEntero(&opcion, "\nIngrese una opcion del menu: ",
				"\nError. La opcion no esta dentro del menu", 1, 13, 1);

		if(AnalizarListadoDeClientes(clientes, CANT_CLIENTES) == -1 && opcion > 1)
		{
			opcion = 14;
		}
		switch(opcion)
		{
			case 1:
				if(AltaDeCliente(clientes, CANT_CLIENTES,&idClientes, localidades, CANT_LOCALIDADES) == -1)
				{
					printf("\nNo se pudo realizar el alta del cliente\n");
				}
			break;

			case 2:
				if(ModificacionDatosDeUnCliente(clientes, CANT_CLIENTES, localidades, CANT_LOCALIDADES)==-1)
				{
					printf("\nNo se modifico la informacion de ningun cliente\n");
				}
				break;

			case 3:
				if(BajaDeCliente(clientes, CANT_CLIENTES, localidades, CANT_LOCALIDADES)==-1)
				{
					printf("\nNingun cliente fue dado de baja\n");
				}
				break;

			case 4:
				if(AltaPedidoDeRecoleccion(clientes, CANT_CLIENTES, pedidos, CANT_PEDIDOS, &idPedidos, localidades, CANT_LOCALIDADES)==-1)
				{
					printf("\nNo se pudo realizar el alta de pedido\n");
				}
				break;

			case 5:
				if(ProcesarResiduos(pedidos, CANT_PEDIDOS, clientes, CANT_CLIENTES) == -1)
				{
					printf("\nLos residuos no fueron procesados");
				}
				break;

			case 6:
				if(ListadoDeClientesContandoSusPedidosPendientes(clientes, CANT_CLIENTES, pedidos, CANT_PEDIDOS, localidades, CANT_LOCALIDADES)==-1)
				{
					printf("\nEl conteo no pudo realizarse");
				}
				break;

			case 7:
				if(MostrarListaDePedidosEnEstadoPendiente(pedidos, CANT_PEDIDOS,clientes, CANT_CLIENTES)==-1)
				{
					printf("\nNo se puede mostrar la lista\n");
				}
				break;

			case 8:
				if(ImprimirPedidosProcesadosEnEstadoCompletado(pedidos, CANT_PEDIDOS,clientes, CANT_CLIENTES)==-1)
				{
					printf("\nNo se puede mostrar la lista\n");
				}
				break;

			case 9:
				if(CantidadPedidosPendientesDeUnaLocalidad (pedidos, CANT_PEDIDOS,clientes, CANT_CLIENTES, localidades, CANT_LOCALIDADES)==-1)
				{
					printf("\nNo se pudo contar\n");
				}
				break;

			case 10:
				if(PromedioRecicladoDePolipropilenoPorCliente(clientes, CANT_CLIENTES, pedidos, CANT_PEDIDOS)==-1)
				{
					printf("\nNo se pudo sacar el promedio\n");
				}
				break;

			case 11:
				ObtenerClienteConMasPedidosPendientes(clientes, CANT_CLIENTES, pedidos, CANT_PEDIDOS, localidades, CANT_LOCALIDADES);
				break;

			case 12:
				MostrarClienteConMasPedidosCompletados(clientes, CANT_CLIENTES, pedidos, CANT_PEDIDOS, localidades, CANT_LOCALIDADES);
				break;

			case 13:
				printf("\nUsted salio del programa");
				break;

			case 14:
				printf("\nDebe dar de alta por lo menos a un clientes\n");
				break;

		}

	}while(opcion != 13);


	return EXIT_SUCCESS;
}
