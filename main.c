#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include "funcoes.h"


int main(void){
                //INICIO
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
                //inicializa struct
    registroV = calloc(10, sizeof(veiculo));
    registroM = calloc(10, sizeof(motorista));
    registroViagem = calloc(30,sizeof(viagem));

    menu();

    free(registroM);
    free(registroV);
    free(registroViagem);

    SetConsoleOutputCP(CPAGE_DEFAULT); 
                //FIM
}
