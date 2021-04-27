#include "funcoes.h"
#include <stdio.h>

void editar_motorista(){

    int i = 0, aux_numViagem = 0;

    system("cls");
    printf("\n\t\tEDITAR MOTORISTAS");
    printf("\n\tMotoristas disponíveis");
    consultar_motorista_disponivel();

    do{
        printf("\n\tQual o número do ID motorista: ");
        printf("\n\tSelecionar: ");
        scanf("%d", &i);
        i--;
        aux_numViagem = registroM[i].num_viagens;

        if(registroM[i].status == 2 || registroM[i].status == 0){
            printf("\n\tNão é possivel alterar dados deste motorista!\n");
        }
        else
            break;
    }while(registroM[i].status != 1);

            insere_informacao_motoristas(i);
            registroM[i].num_viagens = aux_numViagem;
            salvar_motorista();
}

void editar_veiculo(){

    int i = 0, opcao_edita_veiculo = 0;

    system("cls");
    printf("\n\t\tEDITAR VEÍCULO");
    consultar_editar();

    printf("\n\t1. Informações do veículo");
    printf("\n\t2. Status do veículo (Manutenção)");
    printf("\n\t3. Sair");
    printf("\n\tOpção: ");
    scanf("%d", &opcao_edita_veiculo);

    switch (opcao_edita_veiculo){
        case 1:
            i = escolhe_veiculo();
            insere_cadastro_veiculos(i);
            salvar_veiculo();
            break;

        case 2:
            escolhe_veiculo();

            if(registroV[i].status == 1){
                printf("\n\tTransferindo veículo para manutenção..\n.");
                registroV[i].status = 3;
            }
            else if(registroV[i].status == 3){
                printf("\n\tTransferindo veículo para o pátio...\n");
                registroV[i].status = 1;
            }
            else{
                printf("\n\tVeículo em viagem, impossível transferi-lo para manutenção\n");
            }
            system("pause");
            salvar_veiculo();
            break;

        default:
            break;
    }
}

int escolhe_veiculo(){
    int i = 0;
    printf("\n\tID veículo: ");
    printf("\n\tSelecionar: ");
    scanf("%d", &i);
    i--;
    return i;
}

void editar_viagem(){

    int opcao = 0, opcao_veiculo = 0, opcao_motorista = 0, i = 0, aux_iDIA = 0, aux_iMES = 0, aux_iANO = 0;

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
                i = escolhe_viagem();
                printf("\n\tVeículos disponíveis: ");
                consultar_vDisponivel();

                do{
                    printf("\n\tTrocar por veículo ID: ");
                    scanf("%d", &opcao_veiculo);
                    opcao_veiculo--;

                    if(registroV[opcao_veiculo].status != 1)
                        printf("\n\tVeículo não disponível para viagem");

                }while(registroV[opcao_veiculo].status != 1);

                registroViagem[i].id_veiculo = opcao_veiculo;
                salvar_veiculo();
                salvar_viagem();
            break;

            case 2:
                i = escolhe_viagem();
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
                    registroM[registroViagem[i].id_motorista].status = 1;

                    //Atualiza o ID do motorista da viagem
                    registroViagem[i].id_motorista = opcao_motorista;

                    //Novo motorista muda status para "Em Viagem"
                    registroM[registroViagem[i].id_motorista].status = 2;
                salvar_motorista();
                salvar_viagem();
            break;

            case 3:
                i = escolhe_viagem();

                aux_iDIA = registroViagem[i].data_inicio_dia;
                aux_iMES = registroViagem[i].data_inicio_mes;
                aux_iANO = registroViagem[i].data_inicio_ano;
                printf("\n\tFinalizar Viagem: \n");

                int j = registroViagem[i].id_veiculo;

                printf("\n\t*DATA FIM (dd/mm/aa): ");
                scanf("%d/%d/%d", &registroViagem[i].data_fim_dia, &registroViagem[i].data_fim_mes, &registroViagem[i].data_fim_ano);

                registroViagem[i].duracao_dias = dist_dias(i);

                printf("\n\t*HORA FIM (hh:mm): ");
                scanf("%d:%d", &registroViagem[i].hora_fim_hh, &registroViagem[i].hora_fim_mm);

                //Atualiza status viagem
                registroViagem[i].status = 2;

                //Atualiza status motorista
                registroM[registroViagem[i].id_motorista].num_viagens = registroM[registroViagem[i].id_motorista].num_viagens + 1;
                registroM[registroViagem[i].id_motorista].status = 1;

                //Atualiza status veiculo
                registroV[i].quilometragem = registroV[j].quilometragem + registroViagem[i].percorrido;

                registroV[i].status = 1;

                printf("\n\tViagem realizada com sucesso!\n");

                registroViagem[i].data_inicio_dia = aux_iDIA; 
                registroViagem[i].data_inicio_mes = aux_iMES;  
                registroViagem[i].data_inicio_ano = aux_iANO; 

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

    printf("\n\tQual viagem deseja editar?");
    printf("\n\tSelecionar: ");
    scanf("%d", &opcao_viagem);
    opcao_viagem--;

    if(registroViagem[opcao_viagem].status != 1){
        printf("\n\tViagem selecionada inválida para edição!");
        menu();
    }
    return opcao_viagem;
}
