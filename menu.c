#include "funcoes.h"

void menu(){

    int opcao = 0;
    int sub_opcao = 0;
    int inicializa = 0;

    do{
        //Menu Principal
        system("cls");
        printf("\n\tCONTROLE DE FROTAS\n");
        printf("- - - - - - - - - - - - - - - - - -\n");
        printf("\t\tMENU\n");
        printf("\t1. Cadastrar\n");
        printf("\t2. Editar\n");
        printf("\t3. Excluir\n");
        printf("\t4. Consultar\n");
        printf("\t5. Recuperar registros\n");
        printf("\t6. Sair\n");
        printf("\tOpção: ");
        scanf("%d",&opcao);

        switch(opcao){
            //Sub-Menus
            case 1: //Realizar cadastros
                printf("\t1-> Cadastrar");
                printf("\n\t\t1. Cadastrar veiculos");
                printf("\n\t\t2. Cadastrar motorista");
                printf("\n\t\t3. Cadastrar viagem");
                printf("\n\t\t4. Sair");
                printf("\n\t\tOpção: ");
                scanf("%d",&sub_opcao);
                switch (sub_opcao){
                    case 1:
                        controle_cadastroVeiculos(inicializa);
                        break;
                    case 2:
                        controle_cadastroMotoristas(inicializa);
                        break;
                    case 3:
                        controle_cadastroViagem();
                        break;
                    case 4:
                    break;
                }
            break;  //fim do subSwitch

            case 2: //Editar cadastros
                printf("\t2-> Editar");
                printf("\n\t\t1. Editar veiculo");
                printf("\n\t\t2. Editar motorista");
                printf("\n\t\t3. Editar viagem");
                printf("\n\t\t4. Sair");
                printf("\n\t\tOpção: ");
                scanf("%d",&sub_opcao);
                switch (sub_opcao){
                case 1:
                    controle_editarVeiculos();
                    break;
                case 2:
                    controle_editarMotoristas();
                    break;
                case 3:
                    controle_editarViagem();
                    break;
                case 4:
                    break;
                default:
                    break;
                }
            break;//fim do subSwitch

            case 3: //Excluir cadastros
                printf("\t3-> Excluir");
                printf("\n\t\t1. Excluir veiculo");
                printf("\n\t\t2. Excluir motorista");
                printf("\n\t\t3. Excluir viagem");
                printf("\n\t\t4. Sair");
                printf("\n\t\tOpção: ");
                scanf("%d",&sub_opcao);
                switch (sub_opcao){
                case 1:
                    controle_excluirVeiculos();
                    break;
                case 2:
                    controle_excluirMotoristas();
                    break;
                case 3:
                    controle_excluirViagem();
                    break;
                case 4:
                    break;
                default:
                    break;
                }
            break;//fim do subSwitch

            case 4://Fazer consultas de dados cadastrados
                printf("\t4-> Consultar");
                printf("\n\t\t1. Consultar veiculo");
                printf("\n\t\t2. Consultar motorista");
                printf("\n\t\t3. Consultar viagens");
                printf("\n\t\t4. Consultar viagem em andamento");
                printf("\n\t\t5. Consultar viagem concluídas");
                printf("\n\t\t6. Consultar viagem com maior duração");
                printf("\n\t\t7. Consultar motorista que mais viajou");
                printf("\n\t\t8. Consultar média de viagens por motorista");
                printf("\n\t\t9. Sair");
                printf("\n\t\tOpção: ");
                scanf("%d",&sub_opcao);
                switch (sub_opcao){
                case 1:
                    consultar_veiculo();
                    break;
                case 2:
                    consultar_motorista();
                    break;
                case 3:
                    consultar_viagens();
                    break;
                case 4:
                    consultar_vAndamento();
                    break;
                case 5:
                    consultar_vConcluida();
                    break;
                case 6:
                    consultar_vDuracao();
                    break;
                case 7:
                    consultar_mais_viajou();
                    break;
                case 8:
                    consultar_media_viagem();
                    break;
                case 9:
                    break;
                default:
                    break;
                }
        break;//fim do subSwitch

            case 5:
                lertTosdosarquivos();
            break;

            case 6:
            break;
        }
    }while(opcao != 6);
}
