#include "funcoes.h"
//                                          ---- CADASTRO ----
void controle_cadastroVeiculos(int inicializa){
    if(inicializa == 0){
        inicializa = inicializa_estruturas();//iniciliza status
        cadastrar_veiculo();
    }
    else{
        cadastrar_veiculo();
    }
}

void controle_cadastroMotoristas(int inicializa){
    if(inicializa == 0){
        inicializa = inicializa_estruturas();//iniciliza status
        cadastrar_motorista();
    }
    else{
        cadastrar_motorista();
    }
}

void controle_cadastroViagem(){
    int contador = 0, i = 0;

    for(i = 0; i < 10; i++){
        if(registroM[i].status == 1){
        contador++;
        break;
        }
    }

    for(i = 0; i < 10; i++){
        if(registroV[i].status == 1){
        contador++;
        break;
        }
    }

    if(contador == 2){
        cadastrar_viagem();
    }
    else{
        printf("\n\tAVISO: necessário UM MOTORISTA e UM VEÍCULO dísponível para cadastrar uma VIAGEM!\n");
        system("pause");
    }
}

//                                          ---- EDITAR ----
void controle_editarMotoristas(){
    int contador = 0;

        for(int i = 0; i < 10; i++){
            if(registroM[i].status == 1){
                contador++;
                break;
            }
        }

        if(contador >= 1)
            editar_motorista();
        
        else{
            printf("\n\tAVISO: Não há motoristas disponíveis para edição!\n");
            system("pause");
        }
}

void controle_editarVeiculos(){
    int contador = 0;

        for(int i = 0; i < 10; i++){
            if(registroV[i].status == 1 || registroV[i].status == 3){
                contador++;
                break;
            }
        }

        if(contador >= 1)
            editar_veiculo();
    
        else{
            printf("\n\tAVISO: Não há veículos disponíveis para edição!\n");
            system("pause");
        }
}

void controle_editarViagem(){
    int contador = 0;

        for(int i = 0; i < 30; i++){
            if(registroViagem[i].status > 0){
                contador++;
                break;
            }
        }

        if(contador >= 1)
            editar_viagem();
        
        else{
            printf("\n\tAVISO: Não há viagens disponíveis para edição!\n");
            system("pause");
        }
}

//                                          ---- EXCLUIR ----
void controle_excluirMotoristas(){
    int contador = 0;

        for(int i = 0; i < 10; i++){
            if(registroM[i].status == 1){
                contador++;
                break;
            }
        }

        if(contador >= 1)
            excluir_motorista();
        
        else{
            printf("\n\tAVISO: Não há motoristas disponíveis para exclusão!\n");
            system("pause");
        }
}

void controle_excluirVeiculos(){
    int contador = 0;

        for(int i = 0; i < 10; i++){
            if(registroV[i].status == 1 || registroV[i].status == 3){
                contador++;
                break;
            }
        }

        if(contador >= 1)
            excluir_veiculo();
    
        else{
            printf("\n\tAVISO: Não há veículos disponíveis para exclusão!\n");
            system("pause");
        }
}

void controle_excluirViagem(){
    int contador = 0;

        for(int i = 0; i < 30; i++){
            if(registroViagem[i].status == 2){
                contador++;
                break;
            }
        }

        if(contador >= 1)
            excluir_viagem();
        
        else{
            printf("\n\tAVISO: Não há viagens disponíveis para exclusão!\n");
            system("pause");
        }
}