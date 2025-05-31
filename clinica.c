#include "clinica.h" /* Onde está inclusa a estrutura Paciente*/
#include <stdio.h>

/* Função com o objetivo de imprimir os dados de um paciente na tela */
void visualizar_paciente(Paciente paciente) {
    printf("\n[Dados do Paciente]\n");
    printf("ID: %d\n", paciente.id); /* Imprime o ID do paciente */
    printf("CPF: %s\n", paciente.cpf); /* Imprime o CPF do paciente */
    printf("Nome: %s\n", paciente.nome); /* Imprime o nome do paciente */
    printf("Idade: %d\n", paciente.idade); /* Imprime a idade do paciente */
    printf("Data de Cadastro: %s\n", paciente.data_cadastro); /* Imprime a data de cadastro do paciente */
}