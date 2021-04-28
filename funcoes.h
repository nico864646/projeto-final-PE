#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>

typedef struct { //10 cadastros
    char marca[50];
    char modelo[50];
    char placa[10];
    int ano;
    float quilometragem;
    char tipo[25];// 1-Passeio, 2-Carga, 3-Transporte Passageiros
    int status;//    0-Disponivel para cadastro , 1-No patio(cadastrado), 2-Em viagem, 3-Em manutenção;
}veiculo;

typedef struct { //10 cadastros
    char nome[50];
    char telefone[10];
    char cpf[15];
    int num_viagens;
    int status; //    0-Disponivel para cadastro, 1-Cadastrado, 2-Em Viagem;
}motorista;

typedef struct { //30 cadastros;
    int id_veiculo;
    int id_motorista;
    float percorrido; //km
    char origem[50];
    char destino[50];
    int data_inicio_dia;
    int data_inicio_mes;
    int data_inicio_ano;
    int hora_inicio_hh;
    int hora_inicio_mm;
    int data_fim_dia;
    int data_fim_mes;
    int data_fim_ano;
    int hora_fim_hh;
    int hora_fim_mm;
    int duracao_dias;
    int status; //     0-Disponivel para cadastro, 1 - Em aberto, 2 - Realizada
}viagem;

veiculo *registroV;
motorista *registroM;
viagem *registroViagem;

enum tipoVeiculo {PASSEIO = 1, CARGA, TRANSPORTE};

void menu();
int inicializa_estruturas();

//      Cadastro
void cadastrar_veiculo();
void insere_cadastro_veiculos(int i);
void cadastrar_motorista();
void insere_informacao_motoristas(int i);
void cadastrar_viagem();

//      Editar
void editar_veiculo();
int escolhe_veiculo();
void editar_motorista();
void editar_viagem();
int escolhe_viagem();

//      Excluir
void excluir_veiculo();
void excluir_motorista();
void excluir_viagem();

//      Consultar veiculo
void consultar_veiculo();
void consultar_vDisponivel();
void consultar_editarVeiculo();
void prints_veiculo(int i);

//      Consulta motorista
void consultar_motorista();
void consultar_motorista_disponivel();
void prints_motorista(int i);

//      Consulta viagens
void consultar_viagens();
void consultar_vAndamento();
void consultar_vConcluida();
void prints_viagem(int i);
int dist_dias(int i);
void consultar_vDuracao();
void consultar_media_viagem();
void consultar_mais_viajou();

//      Controle de funções
void controle_cadastroVeiculos(int inicializa);
void controle_cadastroMotoristas(int inicializa);
void controle_cadastroViagem();
void controle_editarVeiculos();
void controle_editarMotoristas();
void controle_editarViagem();
void controle_excluirVeiculos();
void controle_excluirMotoristas();
void controle_excluirViagem();
void tratamento_placa(int i);
void tratamento_cpf(int i);

//         Salvar Arquivos
void salvar_veiculo();
void salvar_motorista();
void salvar_viagem();

//          Ler Arquivos
void ler_veiculo();
void ler_motorista();
void ler_viagem();
void lertTosdosarquivos();


#endif // FUNCOES_H_INCLUDED
