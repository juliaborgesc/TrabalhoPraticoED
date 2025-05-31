#ifndef CLINICA_H
#define CLINICA_H

/* Estrutura do paciente */
typedef struct paciente {
    int id; /* Identificador único do paciente */
    char cpf[15]; /* CPF do paciente no formato XXX.XXX.XXX-XX */
    char nome[80]; /* Nome completo do paciente */
    int idade; /* Idade do paciente */
    char data_cadastro[11]; /* Formato AAAA-MM-DD */
} Paciente; /* Nome da estrutura */

/* Declaração da função que imprime os dados do paciente */
void visualizar_paciente(Paciente paciente);

#endif