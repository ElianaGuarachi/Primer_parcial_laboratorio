
#include "Clientes.h"

int InicilizarClientes(eClientes clientes[], int cantidad)
{
	int retorno=-1;
	if(clientes != NULL && cantidad > 0)
	{
		for(int i=0; i<cantidad; i++)
		{
			clientes[i].isEmpty = LIBRE;
			retorno=1;
		}
	}
	return retorno;
}

int AnalizarListadoDeClientes(eClientes clientes[], int cantidad)
{
	int retorno=-1;
	if(clientes != NULL && cantidad > 0)
	{
		for(int i=0; i<cantidad; i++)
		{
			if(clientes[i].isEmpty == OCUPADO)
			{
				retorno=1;
			}
		}
	}
	return retorno;
}

int BuscarLugarLibreClientes(eClientes clientes[], int cantidad)
{
	int index;
	int i;
	index = -1;
	if(clientes != NULL && cantidad > 0)
	{
		for(i=0; i< cantidad; i++)
		{
			if(clientes[i].isEmpty == LIBRE)
			{
				index=i;
				break;
			}
		}
	}
	return index;
}

int AltaDeCliente(eClientes clientes[], int cantidad, int* idClientes, eLocalidad localidades[], int tam_localidades)
{
	int retorno=-1;
	char nombre[51];
	char cuit[14];
	char calle[21];
	int numero;
	int idLocalidad;
	int idClienteAux;

		if(ObtenerNumerosLetras(nombre, sizeof(nombre), "\nIngrese el nombre de la empresa: ", "Error. Ingrese nuevamente (letras y numeros): ",2) &&
		ObtenerCuitCuil(cuit, "\nIngrese el CUIT de la empresa (xx-xxxxxxxx-x): ", "\nError. Ingrese el cuit nuevamente: ", 2) &&
		ObtenerPalabras(calle, "\nIngrese la direccion (calle) de la empresa: ", "\nError. Ingrese solo la calle: ", 2) &&
		ObtenerEntero(&numero, "\nIngrese altura de la calle (direccion): ", "\nError. Ingrese solo la altura: ", 1,99999,3) == 0)
		{
			MostrarListaDeLocalidades(localidades, tam_localidades);
			printf("\n");
			if(ObtenerEntero(&idLocalidad, "\nIngrese el id de una localidad que figura en la lista: ",
					"\nError. Ingrese la localidad nuevamente: ", 1, 9999, 2)==0 &&
					VerificarIdLocalidadIngresado(localidades, tam_localidades, idLocalidad) == 1)
			{
				FormatearCadenaConNumeros(nombre);
				FormatearCadena(calle);
				*idClientes += 1;
				idClienteAux = *idClientes;
				if(CargarInfoCliente(clientes, cantidad, idClienteAux, nombre, cuit,calle, numero,idLocalidad)==0)
				{
					printf("\nEl alta del cliente ha sido un exito.\n");
					retorno=0;
				}
			}
			else
			{
				printf("\nEl id de localidad ingresado no figura en la lista\n");
			}
		}
	return retorno;
}

int CargarInfoCliente(eClientes clientes[], int cantidad, int idCliente , char nombre[], char cuit[], char calle[], int numero, int idLocalidad)
{
	int retorno=-1;
	int index;
	if(clientes != NULL && cantidad > 0)
	{
		index=BuscarLugarLibreClientes(clientes, cantidad);
		if(index != -1)
		{
			clientes[index].idCliente = idCliente;
			strcpy(clientes[index].nombreEmpresa, nombre);
			strcpy(clientes[index].cuit, cuit);
			strcpy(clientes[index].direccion.calle, calle);
			clientes[index].direccion.numero = numero;
			clientes[index].idLocalidad = idLocalidad;
			clientes[index].isEmpty = OCUPADO;
			retorno=0;
		}
	}
	return retorno;
}

void MostrarInfoUnCliente(eClientes cliente, eLocalidad localidades[], int tam_localidades)
{
	if(localidades != NULL && tam_localidades > 0)
	{
		for(int i=0; i<tam_localidades; i++)
		{
			if(localidades[i].isEmpty == OCUPADO && localidades[i].idLocalidad == cliente.idLocalidad)
			{
				printf("\n%5d %20s %20s %20s %5d %20s", cliente.idCliente, cliente.nombreEmpresa, cliente.cuit, cliente.direccion.calle,
						cliente.direccion.numero, localidades[i].nombreLocalidad);
			}
		}
	}
}

int MostrarListaClientes(eClientes clientes[], int cantidad, eLocalidad localidades[], int tam_localidades)
{
	int retorno =-1;
	int i;
	if(clientes != NULL && cantidad > 0)
	{
		for(i=0; i<cantidad; i++)
		{
			if(clientes[i].isEmpty == OCUPADO)
			{
				MostrarInfoUnCliente(clientes[i], localidades, tam_localidades);
				retorno=0;
			}
		}
	}
	return retorno;
}

int ModificacionDatosDeUnCliente(eClientes clientes[], int cantidad, eLocalidad localidades[], int tam_localidades)
{
	int retorno =-1;
	char confirmar;
	int auxiliarId;
	int opcion;
	int index;

	ObtenerCaracterDosOpciones(&confirmar,"\nEsta seguro que desea modificar la informacion de un cliente? s/n: ",
			"Error. Ingrese s - n",'s', 'n', 1);
	if(confirmar == 's')
	{
		MostrarListaClientes(clientes, cantidad, localidades, tam_localidades);
		printf("\n");
		if(ObtenerEntero(&auxiliarId, "\nIngrese el id del cliente que desea modificar: ",
				"\nError. Ingrese nuevamente un id",1,100, 1)==0)
		{
			index = BuscarClientePorId(clientes, cantidad, auxiliarId);
			if(index != -1)
			{
				if(ObtenerEntero(&opcion,"\nIngrese 1 si quiere modificar la direccion"
										  "\nIngrese 2 si quiere modificar la localidad\n"
										  "\n Opcion: ", "\nError. La opcion no es correcta." , 1, 2, 1)==0)
				{
					if(ElegirOpcionDeModificacion(clientes, opcion, index, localidades, tam_localidades)==1)
					{
						retorno=0;
					}
				}
			}
			else
			{
				printf("\nNo hay un empresa con el id ingresado\n");
			}
		}
	}

	return retorno;
}

int ElegirOpcionDeModificacion(eClientes clientes[], int opcion, int index, eLocalidad localidades[], int tam_localidades)
{
	int retorno=-1;
	int idLocal;
	char auxCalle[21];
	int auxNum;
	if(clientes != NULL)
	{
		switch(opcion)
		{
			case 1:
				if(ObtenerPalabras(auxCalle, "\nIngrese la direccion (calle) de la empresa: ", "\nError. Ingrese solo la calle: ", 1) &&
					ObtenerEntero(&auxNum, "\nIngrese altura de la calle (direccion): ",
													"\nError. Ingrese solo la altura: ", 1,99999,1)==0)
				{
					FormatearCadena(auxCalle);
					strcpy(clientes[index].direccion.calle, auxCalle);
					clientes[index].direccion.numero = auxNum;
					printf("\nLa direccion de la empresa fue modificada.\n");
					retorno=1;
				}
				break;

			case 2:
				MostrarListaDeLocalidades(localidades, tam_localidades);
				printf("\n");
				if(ObtenerEntero(&idLocal, "\nIngrese el id de una localidad que figura en la lista: ",
						"\nError. Ingrese la localidad nuevamente: ",1,9999, 3)==0 &&
						VerificarIdLocalidadIngresado(localidades, tam_localidades, idLocal) == 1)
				{
					clientes[index].idLocalidad = idLocal;
					printf("\nLa localidad de la empresa fue modificada.\n");
					retorno=1;
				}
				else
				{
					printf("\nEl id de localidad ingresado no esta la lista\n");
				}
				break;
		}
	}

	return retorno;
}



int BuscarClientePorId(eClientes clientes[], int cantidad, int id)
{
	int index = -1;
	int i;
	if(clientes != NULL && cantidad>0)
	{
		for(i=0; i< cantidad; i++)
		{
			if(clientes[i].isEmpty == OCUPADO && clientes[i].idCliente == id)
			{
				index=i;
				break;
			}
		}
	}
	return index;
}

int BajaDeCliente(eClientes clientes[], int cantidad, eLocalidad localidades[], int tam_localidades)
{
	int retorno=-1;
	char confirmar;
	int auxiliarId;
	int index;
	if(clientes != NULL && cantidad)
	{
		ObtenerCaracterDosOpciones(&confirmar,"\nEsta seguro que desea dar de baja un cliente? s/n: ",
					"Error. Ingrese s - n",'s', 'n', 0);
			if(confirmar == 's')
			{
				MostrarListaClientes(clientes, cantidad, localidades, tam_localidades);
				printf("\n");
				ObtenerEntero(&auxiliarId, "\nIngrese el id del cliente que desea dar de baja: ",
						"\nError. Ingrese nuevamente un id",1,100, 1);
				index = BuscarClientePorId(clientes, cantidad, auxiliarId);
				if(index != -1)
				{
					ObtenerCaracterDosOpciones(&confirmar,"\nQuiere confirmar la dar de baja? s/n: ",
										"Error. Ingrese s - n",'s', 'n', 0);
					if(confirmar=='s')
					{
						clientes[index].isEmpty=LIBRE;
						retorno=0;
					}
				}
				else
				{
					printf("\nNo hay un empresa con el id ingresado\n");
				}
			}
	}
	return retorno;
}




