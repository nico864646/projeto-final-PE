#include "funcoes.h"
#include <stdio.h>

void editar_motorista(){

    int opcao_motorista = 0, aux_numViagem = 0;

    system("cls");
    printf("\n\t\tEDITAR MOTORISTAS");
    printf("\n\tMotoristas disponíveis");
    consultar_motorista_disponivel();

    do{
        printf("\n\tQual o número do ID motorista: ");
        printf("\n\tSelecionar: ");
        scanf("%d", &opcao_motorista);
        opcao_motorista--;
        aux_numViagem = registroM[opcao_motorista].num_viagens;

        if(registroM[opcao_motorista].status != 1){
            printf("\n\tNão é possivel alterar dados deste motorista!\n");
        }
        else
            break;
    }while(registroM[opcao_motorista].status != 1);

            insere_informacao_motoristas(opcao_motorista);
            registroM[opcao_motorista].num_viagens = aux_numViagem;
            salvar_motorista();
}

void editar_veiculo(){

    int opcao_veiculo = 0, opcao_edita_veiculo = 0;

    system("cls");
    printf("\n\t\tEDITAR VEÍCULO");
    consultar_editarVeiculo();

    printf("\n\t1. Informações do veículo");
    printf("\n\t2. Status do veículo (Manutenção)");
    printf("\n\t3. Sair");
    printf("\n\tOpção: ");
    scanf("%d", &opcao_edita_veiculo);

    switch (opcao_edita_veiculo){
        case 1:
            opcao_veiculo = escolhe_veiculo();
            insere_cadastro_veiculos(opcao_veiculo);
            salvar_veiculo();
            break;

        case 2:
            escolhe_veiculo();

            if(registroV[opcao_veiculo].status == 1){
                printf("\n\tTransferindo veículo para manutenção..\n.");
                registroV[opcao_veiculo].status = 3;
            }
            else if(registroV[opcao_veiculo].status == 3){
                printf("\n\tTransferindo veículo para o pátio...\n");
                registroV[opcao_veiculo].status = 1;
            }
            else{
                printf("\n\tVeículo em viagem, impossível transferi-lo para manutenção\n");
                system("cls");
                printf("\n\t\tCADASTRO DE VIAGENS");
                printf("\n\n\tVeículos disponíveis para edição:");
                consultar_editarVeiculo();
            }
            system("pause");
            salvar_veiculo();
            break;

        default:
            break;
    }
}

int escolhe_veiculo(){
    int opcao_veiculo = 0;
    printf("\n\tID veículo: ");
    printf("\n\tSelecionar: ");
    scanf("%d", &opcao_veiculo);
    opcao_veiculo--;
    return opcao_veiculo;
}

void editar_viagem(){

    int opcao = 0, opcao_veiculo = 0, opcao_motorista = 0, opcao_viagem = 0, aux_iDIA = 0, aux_iMES = 0, aux_iANO = 0;

    system("cls");
    printf("\n\t\tEDITAR VIAGENS");
    printf("\n\tLista de viagens cadastradas");
    consultar_vAndamento();


        printf("\n\t1. Editar veículo da viagem");
        printf("\n\t2. Editar motorista da viagem");
        printf("\n\t3. Finalizar status da viagem");
        printf("\n\t4. Sair\n");
        printf("\n\tSelecionar: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                opcao_viagem = escolhe_viagem();
                printf("\n\tVeículos disponíveis: ");
                consultar_vDisponivel();

                do{
                    printf("\n\tTrocar por veículo ID: ");
                    scanf("%d", &opcao_veiculo);
                    opcao_veiculo--;

                    if(registroV[opcao_veiculo].status != 1)
                        printf("\n\tVeículo não disponível para viagem");

                }while(registroV[opcao_veiculo].status != 1);

                registroViagem[opcao_viagem].id_veiculo = opcao_veiculo;
                salvar_veiculo();
                salvar_viagem();
            break;

            case 2:
                opcao_viagem = escolhe_viagem();
                printf("\n\tMotoristas disponíveis: ");
                consultar_motorista_disponivel();

                do{
                    printf("\n\tTrocar por motorista ID: ");
                    scanf("%d", &opcao_motorista);
                    opcao_motorista--;

                    if(registroM[opcao_motorista].status != 1)
                    printf("\n\tMotorista não disponível para viagem");

                }while(registroM[opcao_motorista].status != 1);

                    //Motorista anterior volta estar disponivel para viagens
                    registroM[registroViagem[opcao_viagem].id_motorista].status = 1;

                    //Atualiza o ID do motorista da viagem
                    registroViagem[opcao_viagem].id_motorista = opcao_motorista;

                    //Novo motorista muda status para "Em Viagem"
                    registroM[registroViagem[opcao_viagem].id_motorista].status = 2;
                salvar_motorista();
                salvar_viagem();
            break;

            case 3:
                opcao_viagem = escolhe_viagem();

                aux_iDIA = registroViagem[opcao_viagem].data_inicio_dia;
                aux_iMES = registroViagem[opcao_viagem].data_inicio_mes;
                aux_iANO = registroViagem[opcao_viagem].data_inicio_ano;

                printf("\n\tFinalizar Viagem: \n");

                int j = registroViagem[opcao_viagem].id_veiculo;

                printf("\n\t*DATA FIM (dd/mm/aa): ");
                scanf("%d/%d/%d", &registroViagem[opcao_viagem].data_fim_dia, &registroViagem[opcao_viagem].data_fim_mes, &registroViagem[opcao_viagem].data_fim_ano);

                registroViagem[opcao_viagem].duracao_dias = dist_dias(opcao_viagem);

                printf("\n\t*HORA FIM (hh:mm): ");
                scanf("%d:%d", &registroViagem[opcao_viagem].hora_fim_hh, &registroViagem[opcao_viagem].hora_fim_mm);

                //Atualiza status viagem
                registroViagem[opcao_viagem].status = 2;

                //Atualiza status motorista
                registroM[registroViagem[opcao_viagem].id_motorista].num_viagens = registroM[registroViagem[opcao_viagem].id_motorista].num_viagens + 1;
                registroM[registroViagem[opcao_viagem].id_motorista].status = 1;

                //Atualiza status veiculo
                registroV[opcao_viagem].quilometragem = registroV[j].quilometragem + registroViagem[opcao_viagem].percorrido;

                registroV[opcao_viagem].status = 1;

                printf("\n\tViagem realizada com sucesso!\n");

                registroViagem[opcao_viagem].data_inicio_dia = aux_iDIA; 
                registroViagem[opcao_viagem].data_inicio_mes = aux_iMES;  
                registroViagem[opcao_viagem].data_inicio_ano = aux_iANO; 

                //Salvar
                salvar_veiculo();
                salvar_motorista();
                salvar_viagem();
                system("pause");
            break;
        }
}

int escolhe_viagem(){
    int opcao_viagem = 0;

do{
    printf("\n\tQual viagem deseja editar?");
    printf("\n\tSelecionar: ");
    scanf("%d", &opcao_viagem);
    opcao_viagem--;

    if(registroViagem[opcao_viagem].status != 1){
        printf("\n\tViagem selecionada inválida para edição!\n");
        system("pause");
        printf("\n\t\tEDITAR VIAGENS");
        printf("\n\tLista de viagens cadastradas");
        consultar_vAndamento();
    }

}while(registroViagem[opcao_viagem].status != 1);
    return opcao_viagem;
}
