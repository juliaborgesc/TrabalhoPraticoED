#ifndef BD_CLINICA_H
#define BD_CLINICA_H

#include "clinica.h"

/* Número máximo de pacientes */
#define MAX_PACIENTES 50 

/* Estrutura referente ao banco de dados do paciente */
typedef struct bdpaciente {
    Paciente pacientes[MAX_PACIENTES]; /* Vetor de pacientes */
    int quantidade; /* Contador de pacientes cadastrados */
} BDPaciente; /* Nome da estrutura */

/* Declaração das funções utilizadas em bd_clinica.c */
/* Inicializa o banco de dados */
void bd_iniciar(BDPaciente *bd);

/* Carrega dados do arquivo CSV (bd_paciente.csv) */
void bd_arquivo(BDPaciente *bd, const char *bd_paciente_csv);

/* Consulta paciente por nome (e prefixo) */
void consulta_nome(BDPaciente *bd, const char *prefixo);

/* Consulta paciente por CPF (prefixo) */
void consulta_cpf(BDPaciente *bd, const char *prefixo);

/* Lista todos os pacientes */
void listar_pacientes(BDPaciente *bd);

#endif