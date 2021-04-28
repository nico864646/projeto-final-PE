#include "funcoes.h"

int dias_mes[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                       {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

int bissexto (int ano) {
	return (ano % 4 == 0) && ((ano % 100 != 0) || (ano % 400 == 0));
}

int dist_dias(int i){
	int idias, fdias;	//guarda qtos dias tem da data ate o comeco do ano

	int def_anos = 0;	//guarda diferenca entre anos das datas inicio e fim medida em dias 
	register int j;
	int dbissexto;

	idias = registroViagem[i].data_inicio_dia;
	dbissexto = bissexto(registroViagem[i].data_inicio_ano);
	for (j = registroViagem[i].data_inicio_mes - 1; j > 0; --j)
		idias += dias_mes[dbissexto][j];

	fdias = registroViagem[i].data_fim_dia;
	dbissexto = bissexto(registroViagem[i].data_fim_ano);
	for (j = registroViagem[i].data_fim_mes - 1; j > 0; --j)
		fdias += dias_mes[dbissexto][j];

	while (registroViagem[i].data_inicio_ano < registroViagem[i].data_fim_ano)
		def_anos += 365 + bissexto(registroViagem[i].data_inicio_ano++);

	return def_anos - idias + fdias;
}
