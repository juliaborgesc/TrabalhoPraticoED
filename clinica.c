#include "clinica.h"
#include <stdio.h>

/* Mostra os dados de um paciente na tela */
void visualizar_paciente(Paciente paciente) {
    printf("\n[Dados do Paciente]\n");
    printf("ID: %d\n", paciente.id);
    printf("CPF: %s\n", paciente.cpf);
    printf("Nome: %s\n", paciente.nome);
    printf("Idade: %d\n", paciente.idade);
    printf("Data de Cadastro: %s\n", paciente.data_cadastro);
}