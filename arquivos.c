#include "funcoes.h"
#include <stdio.h>

FILE *arquivo;

void salvar_veiculo(){
    arquivo = fopen("veiculoCadastrar.txt", "w+"); //Abre o txt para ler fopen 'r'

    if(arquivo != NULL)
        fwrite(registroV, sizeof(veiculo), 10, arquivo);

    printf("\t\tSalvou com sucesso\n");
    fclose(arquivo);
}

void salvar_motorista(){
    arquivo = fopen("motoristaCadastrar.txt", "w+"); //Abre o txt para ler fopen'r'

    if(arquivo != NULL)
        fwrite(registroM, sizeof(motorista), 10, arquivo);

    printf("\t\tSalvou com sucesso\n");
    fclose(arquivo);
}

void salvar_viagem(){
    arquivo = fopen("viagemCadastrar.txt", "w+"); //Abre o txt para ler fopen'r'

    if(arquivo != NULL)
        fwrite(registroViagem, sizeof(viagem), 30, arquivo);

    printf("\t\tSalvou com sucesso\n");
    fclose(arquivo);
}

void lertTosdosarquivos(){
    ler_veiculo();
    ler_motorista();
    ler_viagem();
}

void ler_veiculo(){
    arquivo = fopen("veiculoCadastrar.txt", "r"); //Abre o txt para ler fopen'r'

    if(arquivo != NULL)
        fread(registroV, sizeof(veiculo), 10, arquivo);

    printf("\t\tLeu com sucesso\n");
    fclose(arquivo);
}

void ler_motorista(){
    arquivo = fopen("motoristaCadastrar.txt", "r"); //Abre o txt para ler fopen'r'

    if(arquivo != NULL)
        fread(registroM, sizeof(motorista), 10, arquivo);

    printf("\t\tLeu com sucesso\n");
    fclose(arquivo);
}

void ler_viagem(){
    arquivo = fopen("viagemCadastrar.txt", "r"); //Abre o txt para ler fopen'r'

    if(arquivo != NULL)
        fread(registroViagem, sizeof(viagem), 30, arquivo);

    printf("\t\tLeu com sucesso\n");
    fclose(arquivo);
}
