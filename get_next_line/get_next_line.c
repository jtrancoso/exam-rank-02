#include "get_next_line.h"

int		ft_strlen(char *str)						/////***************StrLen basico***************/////
{
	int count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

char		*ft_strchr(char *str, int ch_find)		/////***************StrChr basico***************/////
{
	int		count = 0;

	if (str == NULL)										//Comprobación o segmentation fault primera iteracion
		return (NULL);
	while (str[count] != '\0')								//Recorremos hasta encontrar caracter deseado
	{
		if (str[count] == ch_find)
			return (str + count);
		count++;
	}
	return (NULL);
}

char		*ft_strdup(char *str)						/////***************StrDup básico***************/////
{
	int 	count = 0;
	char	*ret;

	if ((ret = (char *)malloc(sizeof(char) * ft_strlen(str) + 1)) == NULL)		//Alocamos tamaño + 1
		return (NULL);
	while (str[count] != '\0')								//Recorremos todo guardando
	{
		ret[count] = str[count];
		count++;
	}
	ret[count] = '\0';										//Guardamos el \0
	return (ret);
}

char		*ft_strjoin(char *s1, char *s2)		/////***************StrJoin basico***************/////
{
	char	*ret;
	int 	count = 0;

	if (s1 == NULL || s2 == NULL)							//Comprobamos nulos
		return (NULL);
	if ((ret = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1)) == NULL)
		return (NULL);										//Alocamos tamaño de ambos + 1
	while (*s1)										//Alcamos primera
	{
		ret[count] = *s1;
		++count;
		++s1;
	}
	while (*s2)										//Alocamos segunda detras de la primera
	{
		ret[count] = *s2;
		++count;
		++s2;
    }
	ret[count] = '\0';										//Guardamos el \0
	return (ret);
}

int			get_next_line(char **line)						/////***************Creamos Func Principal***************/////
{
	static char	*mem;				//Para almacenar lo leido
	char		buffer[257];	    //Para leer
	char		*tmp, *aux1, *aux2;	//Para pasar el join antes de mem y para separar mem hasta el \n luego
	int			b_read;				//Para calcular bytes leidos

	if (!line)
		return (-1);
	while (ft_strchr(mem, '\n') == NULL)	//Mientras que no este \n avanzamos guardandolo y vemos si \n de la anterior iteracion
	{
		b_read = read(0, buffer, 256);			//Guardamos 0-256 caracteres a buffer de std_imput y en ret el n leido
		if (b_read < 0)						//Comprobacion si da error read
			return (-1);					//Devolver error (-1)
		if (b_read == 0)						//Cero bytes leidos
			break ;
		buffer[b_read] = '\0';					//Guardamos 0 de fin de read
		if (!mem)							//Si nada guardado de antes guardamos buffer
			mem = ft_strdup(buffer);
		else								//Si ya guardado algo
		{
			tmp = ft_strjoin(mem, buffer);	//Unimos en tmp buffer con lo guardado
			free(mem);						//Liberamos
			mem = tmp;						//Podemos guardar
		}
	}						/////***************EN ESTE PUNTO LINEA GUARDA EN MEM***************/////
							/////***************SOLO QUEDA STRDUP EN LINE DE MEM***************/////
	if (!mem && !b_read)
	{
		*line = ft_strdup("");				//Guardamos un \0, no hemos leido nada
		return (0);							//Devolver lectura completada (0)
	}
	else if ((aux1 = ft_strchr(mem, '\n')))	//Comprobamos si queda guardado algun \n en mem
	{
		*aux1 = 0;							//Para que al hacer el strdup pare en donde este el \n
		*line = ft_strdup(mem);				//Guardarmos en line la linea
		aux2 = ft_strdup(++aux1);			//Para la siguiente iteracion guardamos lo siguiente al antiguo \n, actual \0
		free(mem);							//Liberamos
		mem = aux2;							//Guardamos en mem lo sobrante
	}
	else
	{
		*line = ft_strdup(mem);				//Guardamos todo lo que quede
		free(mem);							//Liberamos
		mem = NULL;							//Lo ponemos nulo
		return (0);							//Devolvemos lectura completada (0)
	}
	return (1);								//Fin de linea leida (1)
}
