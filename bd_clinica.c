#include <stdio.h>
#include <string.h>
#include "bd_clinica.h"

//Inicializa o banco de dados
void bd_iniciar(BDPaciente *bd) {
    bd->quantidade = 0;
}

// Abre o arquivo CSV e carrega os dados dos pacientes
void bd_arquivo(BDPaciente *bd, const char *bd_paciente_csv) {
    FILE *arquivo = fopen(bd_paciente_csv, "r");
    if (arquivo == NULL) {
        printf("Erro ao tentar abrir o arquivo %s\n", bd_paciente_csv);
        return;
    }

    char linha[256];
    while (fgets(linha, sizeof(linha), arquivo)) {
        if (bd->quantidade >= MAX_PACIENTES) {
            printf("Limite máximo de pacientes atingido.\n");
            break;
        }
        Paciente p;
        sscanf(linha, "%d,%[^,],%[^,],%d,%s", &p.id, p.cpf, p.nome, &p.idade, p.data_cadastro);
        bd->pacientes[bd->quantidade] = p;
        bd->quantidade++;
    }

    fclose(arquivo);
}

// Função para consultar paciente por nome e/ou prefixo
void consulta_nome(BDPaciente *bd, const char *prefixo) {
    printf("\nResultados para '%s':\n", prefixo);
    int achou = 0;
    for (int i = 0; i < bd->quantidade; i++) {
        if (strncmp(bd->pacientes[i].nome, prefixo, strlen(prefixo)) == 0) {
            visualizar_paciente(bd->pacientes[i]);
            achou = 1;
        }
    }
    
    if (!achou) {
        printf("Nenhum paciente encontrado.\n");
    }

}

// Função para consultar paciente por CPF e/ou prefixo
void consulta_cpf(BDPaciente *bd, const char *prefixo) {
    int achou = 0;
    printf("\nResultados para '%s':\n", prefixo);

    for (int i = 0; i < bd->quantidade; i++) {
        if (strncmp(bd->pacientes[i].cpf, prefixo, strlen(prefixo)) == 0) {
            visualizar_paciente(bd->pacientes[i]);
            achou = 1;
        }
    }
    if (!achou) {
        printf("Nenhum paciente encontrado.\n");
    }
}

// Função que lista todos os pacientes
void listar_pacientes(BDPaciente *bd) {
    printf("\n[Lista de Pacientes]\n");
    printf("-------------------------------------------------------------\n");
    printf("| ID | CPF           | Nome                | Idade | Cadastro   |\n");
    printf("-------------------------------------------------------------\n");
    for (int i = 0; i < bd->quantidade; i++) {
        visualizar_paciente(bd->pacientes[i]);
    }
}