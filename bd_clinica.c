#include <stdio.h>
#include <string.h>
#include "bd_clinica.h"

void bd_iniciar(BDPaciente *bd) {
    bd->quantidade = 0;
}

void bd_arquivo(BDPaciente *bd, const char *bd_paciente_csv) {
    FILE *arquivo = fopen(bd_paciente_csv, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s\n", bd_paciente_csv);
        return;
    }

    char linha[256];
    while (fgets(linha, sizeof(linha), arquivo) && bd->quantidade < MAX_PACIENTES) {
        Paciente p;
        sscanf(linha, "%d,%[^,],%[^,],%d,%s", 
               &p.id, p.cpf, p.nome, &p.idade, p.data_cadastro);
        bd->pacientes[bd->quantidade] = p;
        bd->quantidade++;
    }

    fclose(arquivo);
}

void consulta_nome(BDPaciente *bd, const char *prefixo) {
    printf("\nResultados para '%s':\n", prefixo);
    int encontrado = 0;
    for (int i = 0; i < bd->quantidade; i++) {
        if (strncmp(bd->pacientes[i].nome, prefixo, strlen(prefixo)) == 0) {
            visualizar_paciente(bd->pacientes[i]);
            encontrado++;
        }
    }
    
    if (encontrado == 0) {
        printf("Nenhum paciente encontrado com o prefixo '%s'.\n", prefixo);
    }

}

void consulta_cpf(BDPaciente *bd, const char *prefixo) {
    printf("\nResultados para '%s':\n", prefixo);

    for (int i = 0; i < bd->quantidade; i++) {
        if (strncmp(bd->pacientes[i].cpf, prefixo, strlen(prefixo)) == 0) {
            visualizar_paciente(bd->pacientes[i]);
        }
    }
}

void listar_pacientes(BDPaciente *bd) {
    printf("\nLista de Pacientes:\n");
    printf("-------------------------------------------------------------\n");
    printf("| ID | CPF           | Nome                | Idade | Cadastro   |\n");
    printf("-------------------------------------------------------------\n");
    for (int i = 0; i < bd->quantidade; i++) {
        visualizar_paciente(bd->pacientes[i]);
    }
    printf("-------------------------------------------------------------\n");
}