#ifndef BD_CLINICA_H
#define BD_CLINICA_H

#include "clinica.h"
#define MAX_PACIENTES 20 // Definindo o número máximo de pacientes

typedef struct bdpaciente {
    Paciente pacientes[MAX_PACIENTES];
    int quantidade;
} BDPaciente; //TAD

// Declaração das funções utilizadas em bd_clinica.c

// Inicializa o banco de dados
void bd_iniciar(BDPaciente *bd);

// Carrega dados do arquivo CSV (bd_paciente.csv)
void bd_arquivo(BDPaciente *bd, const char *bd_paciente_csv);

// Consulta paciente por nome (e prefixo)
void consulta_nome(BDPaciente *bd, const char *prefixo);

// Consulta paciente por CPF (prefixo)
void consulta_cpf(BDPaciente *bd, const char *prefixo);

// Lista todos os pacientes
void listar_pacientes(BDPaciente *bd);

#endif