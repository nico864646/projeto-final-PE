#include "funcoes.h"
//Informações dos veículos
void consultar_veiculo(){
    printf("\n- - - - - - - - - - - - - - - - - - ");
    for(int i = 0; i < 10; i++){
        if(registroV[i].status > 0){
            prints_veiculo(i);
        }
    }
    printf("\n- - - - - - - - - - - - - - - - - - ");
    system("pause");
}

void consultar_vDisponivel(){
    printf("\n- - - - - - - - - - - - - - - - - - ");
    for(int i = 0; i < 10; i++){
        if(registroV[i].status == 1){
            prints_veiculo(i);
        }
    }
    printf("\n- - - - - - - - - - - - - - - - - - ");
    system("pause");
}

void consultar_editarVeiculo(){
    printf("\n- - - - - - - - - - - - - - - - - - ");
    for(int i = 0; i < 10; i++){
        if(registroV[i].status == 1 || registroV[i].status == 3 ){
            prints_veiculo(i);
        }
    }
    printf("\n- - - - - - - - - - - - - - - - - - ");
    system("pause");
}

//Informações dos motoristas
void consultar_motorista(){
    printf("\n- - - - - - - - - - - - - - - - - - ");
    for(int i = 0; i < 10; i++){
        if(registroM[i].status > 0){
            prints_motorista(i);
        }
    }
    printf("\n- - - - - - - - - - - - - - - - - - ");
    system("pause");
}

void consultar_motorista_disponivel(){
    printf("\n- - - - - - - - - - - - - - - - - - ");
    for(int i = 0; i < 10; i++){
        if(registroM[i].status == 1){
            prints_motorista(i);
        }
    }
    printf("\n- - - - - - - - - - - - - - - - - - ");
    system("pause");
}

void consultar_mais_viajou(){
    printf("\n- - - - - - - - - - - - - - - - - - ");
    int mais_viagens = 0, id = 0;
    for(int i = 0; i < 10; i++){
        if(registroM[i].num_viagens > mais_viagens){
            mais_viagens = registroM[i].num_viagens;
            id = i;
        }
    }
    printf("\n\tMOTORISTA COM MAIS VIAGENS: %s.\n", registroM[id].nome);
    system("pause");
}

//Informações das viagens
void consultar_viagens(){
    printf("\n- - - - - - - - - - - - - - - - - - ");
    for(int i = 0; i < 10; i++){
        if(registroViagem[i].status > 0){
            prints_viagem(i);
        }
    }
    printf("\n- - - - - - - - - - - - - - - - - - ");
    system("pause");
}

 void consultar_vAndamento(){
    printf("\n- - - - - - - - - - - - - - - - - - ");
    for(int i = 0; i < 10; i++){
        if(registroViagem[i].status == 1){
            prints_viagem(i);
         }
    }
    printf("\n- - - - - - - - - - - - - - - - - - ");
    system("pause");
 }

void consultar_vConcluida(){
    printf("\n- - - - - - - - - - - - - - - - - - ");
    for(int i = 0; i < 10; i++){
        if(registroViagem[i].status == 2){
            prints_viagem(i);
        }
    }
    printf("\n- - - - - - - - - - - - - - - - - - ");
    system("pause");
}

void consultar_media_viagem(){

    //Soma a quantidade de viagens e divide pela quantidade de motoristas
    int total_viagens = 0;
    int total_motorista = 0;
    int i = 0;

    for(i = 0; i < 30; i++){
        if(registroViagem[i].status > 0)
            total_viagens++;
    }

    for(i = 0; i < 10; i++){
        if(registroM[i].status > 0)
            total_motorista++;
    }

    float media = (float)total_viagens / (float)total_motorista;
    printf("\n- - - - - - - - - - - - - - - - - - - - - - -");
    printf("\n\tMÉDIA DE VIAGENS: %.1f\n", media);
    system("pause");
}


void consultar_vDuracao(){
    int maior_duracao = 0, id = 0;

    for(int i = 0; i < 30; i++){
        if(registroViagem[i].status == 2){
            if(registroViagem[i].duracao_dias > maior_duracao){
                maior_duracao = registroViagem[i].duracao_dias;
                id = i;
            }
        }
    }
    printf("\n- - - - - - - - - - - - - - - - - - ");
    printf("\n\t\tVIAGEM COM MAIOR DURAÇÃO");
    printf("\n\tID: %d", id+1);
    printf("\n\tDia inicial: %d/%d/%d", registroViagem[id].data_inicio_dia, registroViagem[id].data_inicio_mes, registroViagem[id].data_inicio_ano);
    printf("\n\tHora inicial: %d:%d ", registroViagem[id].hora_inicio_hh, registroViagem[id].hora_inicio_mm);
    printf("\n\tDia final: %d/%d/%d", registroViagem[id].data_fim_dia, registroViagem[id].data_fim_mes, registroViagem[id].data_fim_ano);
    printf("\n\tHora final: %d:%d ", registroViagem[id].hora_fim_hh, registroViagem[id].hora_fim_mm);
    printf("\n\tDuração da viagem: %d dias\n",  registroViagem[id].duracao_dias);
    system("pause");
}

//Funções de informações
void prints_veiculo(int i){
    printf("\n\tID: %d", i+1);
    printf("\n\tMarca: %s", registroV[i].marca);
    printf("\n\tModelo: %s", registroV[i].modelo);
    printf("\n\tPlaca: %s", registroV[i].placa);
    printf("\n\tAno: %d", registroV[i].ano);
    printf("\n\tQuilometragem: %.2f", registroV[i].quilometragem);
    printf("\n\tTipo: %s", registroV[i].tipo);
    printf("\n\tStatus: %d\n", registroV[i].status);
}

void prints_motorista(int i){
    printf("\n\tID: %d", i+1);
    printf("\n\tMotorista: %s", registroM[i].nome);
    printf("\n\tTelefone: %s", registroM[i].telefone);
    printf("\n\tViagens realizadas: %d", registroM[i].num_viagens);
    printf("\n\tStatus: %d\n", registroM[i].status);
}


void prints_viagem(int i){
    printf("\n\t\tViagem");
    printf("\n\tID: %d", i+1);
    printf("\n\tTamanho do percurso: %.1f Km", registroViagem[i].percorrido);
    printf("\n\tOrigem da viagem: %s", registroViagem[i].origem);
    printf("\n\tDestino da viagem: %s", registroViagem[i].destino);
    printf("\n\tData início: %d/%d/%d", registroViagem[i].data_inicio_dia, registroViagem[i].data_inicio_mes, registroViagem[i].data_inicio_ano);
    printf("\n\tHora início: %d:%d ", registroViagem[i].hora_inicio_hh, registroViagem[i].hora_inicio_mm);
    if(registroViagem[i].status == 2){
        printf("\n\tData fim: %d/%d/%d", registroViagem[i].data_fim_dia, registroViagem[i].data_fim_mes, registroViagem[i].data_fim_ano);
        printf("\n\tHora de fim: %d:%d ", registroViagem[i].hora_fim_hh, registroViagem[i].hora_fim_mm);
        printf("\n\tDuração da viagem: %d dias", registroViagem[i].duracao_dias);
    }
    printf("\n\tStatus: %d ", registroViagem[i].status);
    printf("\n\t- - - - - - - - - - - - - - ");
    printf("\n\t\tVeículo");
    printf("\n\tID: %d", registroViagem[i].id_veiculo + 1);
    printf("\n\tMarca: %s",registroV[registroViagem[i].id_veiculo].marca);
    printf("\n\tModelo: %s",registroV[registroViagem[i].id_veiculo].modelo);
    printf("\n\tPlaca: %s",registroV[registroViagem[i].id_veiculo].placa);
    printf("\n\t- - - - - - - - - - - - - - ");
    printf("\n\t\tMotorista");
    printf("\n\tID: %d", registroViagem[i].id_motorista + 1);
    printf("\n\tNome: %s", registroM[registroViagem[i].id_motorista].nome);
    printf("\n\tCPF: %s", registroM[registroViagem[i].id_motorista].cpf);
    printf("\n\tTelefone: %s\n", registroM[registroViagem[i].id_motorista].telefone);
}

