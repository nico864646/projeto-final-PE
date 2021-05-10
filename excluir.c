#include "funcoes.h"

void excluir_veiculo(){

    system("cls");
    printf("\n\t\tEXCLUIR VEÍCULOS");

    printf("\n\tVeículos disponíveis");
    consultar_veiculo();

    int posicao = 0;

    do{
        printf("\n\tQual veículo deseja excluir dos registros?");
        printf("\n\tSelecionar: ");
        scanf("%d", &posicao);
        posicao--;

        if(registroV[posicao].status == 2){
            printf("\n\tVeículo em viagem! Impossível apagar cadastro.");
        }

    }while(registroV[posicao].status == 1 && registroV[posicao].status == 3);

    registroV[posicao].status = 0;
    registroV[posicao].marca[0] = '\0';
    registroV[posicao].modelo[0] = '\0';
    registroV[posicao].placa[0] = '\0';
    registroV[posicao].ano = 0;
    registroV[posicao].quilometragem = 0;
    registroV[posicao].tipo[0] = '\0';

    salvar_veiculo();
    printf("\n");
    system("pause");
}

void excluir_motorista(int *num_motoristas){

    system("cls");
    printf("\n\t\tEXCLUIR motoristas:");

    printf("\n\tMotoristas disponíveis");
    consultar_motorista_disponivel();

    int posicao = 0;

    do{
        printf("\n\tQual motorista deseja excluir dos registros?");
        printf("\n\tSelecionar: ");
        scanf("%d", &posicao);
        posicao--;

        if(registroM[posicao].status == 2)
            printf("\n\tMotorista em viagem! Impossível apagar cadastro.");

    }while(registroM[posicao].status != 1);

    registroM[posicao].status = 0;
    registroM[posicao].nome[0] = '\0';
    registroM[posicao].telefone[0] = '\0';
    registroM[posicao].cpf[0] = '\0';
    registroM[posicao].num_viagens = 0;

    salvar_motorista();
    printf("\n");
    system("pause");
}

void excluir_viagem(){

    system("cls");
    printf("\n\t\tEXCLUIR viagens:");

    printf("\n\tViagens disponíveis");
    consultar_vConcluida();

    int posicao = 0;
    
    printf("\n\tQual viagem deseja excluir dos registros?");
    printf("\n\tSelecionar: ");
    scanf("%d", &posicao);
    posicao--;

    if(registroViagem[posicao].status != 2){
        printf("\n\tEssa viagem não está cadastrada ou não pode ser excluida");
    }else{

    registroViagem[posicao].status = 0;
        
        registroViagem[posicao].id_veiculo = 0;
        registroViagem[posicao].id_motorista = 0;
        registroViagem[posicao].percorrido = 0;
        registroViagem[posicao].origem[0] = '\0';
        registroViagem[posicao].destino[0] = '\0';
        registroViagem[posicao].data_inicio_dia = 0;
        registroViagem[posicao].data_inicio_mes = 0;
        registroViagem[posicao].data_inicio_ano = 0;
        registroViagem[posicao].hora_inicio_hh = 0;
        registroViagem[posicao].hora_inicio_mm = 0;
        registroViagem[posicao].data_fim_dia  = 0;
        registroViagem[posicao].data_fim_mes = 0;
        registroViagem[posicao].data_fim_ano = 0;
        registroViagem[posicao].hora_fim_hh = 0;
        registroViagem[posicao].hora_fim_mm = 0;
        registroViagem[posicao].duracao_dias = 0;

        salvar_viagem();
        printf("\n");
        system("pause");
    }      
}
