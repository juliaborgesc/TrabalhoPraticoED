#ifndef BD_CLINICA_H
#define BD_CLINICA_H
#include "clinica.h"
#define MAX_PACIENTES 10 // Definindo o número máximo de pacientes

typedef struct {
    Paciente pacientes[MAX_PACIENTES];
    int quantidade;
} BDPaciente;

// Inicializa o banco de dados
void bd_iniciar(BDPaciente *bd);

// Carrega dados do arquivo CSV (bd_clinica.csv)
void bd_arquivo(BDPaciente *bd, const char *bd_paciente_csv);

// Consulta paciente por nome (prefixo)
void consulta_nome(BDPaciente *bd, const char *prefixo);

// Consulta paciente por CPF (prefixo)
void consulta_cpf(BDPaciente *bd, const char *prefixo);

// Lista todos os pacientes
void listar_pacientes(BDPaciente *bd);

#endif