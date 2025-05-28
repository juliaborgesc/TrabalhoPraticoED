#ifndef CLINICA_H
#define CLINICA_H


typedef struct paciente {
    int id; // Identificador único do paciente
    char cpf[15];
    char nome[50];
    int idade;
    char data_cadastro[11]; // Formato AAAA-MM-DD
} Paciente;

// Função que mostra os dados do paciente
void visualizar_paciente(Paciente paciente);

#endif