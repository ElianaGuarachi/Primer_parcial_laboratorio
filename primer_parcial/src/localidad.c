/*
 * localidad.c
 *
 *  Created on: 15 oct. 2021
 *      Author: Eliana
 */

#include "localidad.h"

int InicializarListaLocalidades(eLocalidad localidades[], int cantidad)
{
	int retorno=-1;
	if(localidades != NULL && cantidad > 0)
	{
		for(int i=0; i<cantidad; i++)
		{
			localidades[i].isEmpty = LIBRE;
			retorno=1;
		}
	}
	return retorno;
}

int VerificarIdLocalidadIngresado(eLocalidad localidades[], int cantidad, int id)
{
	int retorno=-1;
	if(localidades != NULL && cantidad > 0)
	{
		for(int i=0; i<cantidad; i++)
		{
			if(localidades[i].isEmpty == OCUPADO && localidades[i].idLocalidad == id)
			{
				retorno=1;
			}
		}
	}
	return retorno;
}

int MostrarListaDeLocalidades(eLocalidad localidades[], int cantidad)
{
	int retorno =-1;
	int i;
	if(localidades != NULL && cantidad > 0)
	{
		for(i=0; i<cantidad; i++)
		{
			if(localidades[i].isEmpty == OCUPADO)
			{
				MostrarInfoUnaLocalidad(localidades[i]);
				retorno=0;
			}
		}
	}
	return retorno;
}

void MostrarInfoUnaLocalidad(eLocalidad localidad)
{
	printf("\n%5d %20s", localidad.idLocalidad, localidad.nombreLocalidad);
}


int  BuscarLocalidadPorId(eLocalidad localidades[], int cantidad, int id)
{
	int index = -1;
		int i;
		if(localidades != NULL && cantidad>0)
		{
			for(i=0; i< cantidad; i++)
			{
				if(localidades[i].isEmpty == OCUPADO && localidades[i].idLocalidad == id)
				{
					index=i;
					break;
				}
			}
		}
		return index;
}
