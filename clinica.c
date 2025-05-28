#include "clinica.h"
#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <time.h>
//#include <unistd.h>


void visualizar_paciente(Paciente paciente) {
    printf("[Dados do Paciente]\n");
    printf("ID: %d\n", paciente.id);
    printf("CPF: %s\n", paciente.cpf);
    printf("Nome: %s\n", paciente.nome);
    printf("Idade: %d\n", paciente.idade);
    printf("Data de Cadastro: %s\n", paciente.data_cadastro);
}