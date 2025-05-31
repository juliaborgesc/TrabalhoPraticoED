#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "bd_clinica.h"

/* Inicializa oa estrutura do banco de dados */
void bd_iniciar(BDPaciente *bd) {
    bd->quantidade = 0; /* No inicio não tem nenhum paciente carregado no sistema */
}

/* Abre o arquivo CSV e carrega os dados dos pacientes */
void bd_arquivo(BDPaciente *bd, const char *bd_paciente_csv) {
    FILE *arquivo = fopen(bd_paciente_csv, "r"); /* Abre o arquivo em modo leitura */
    if (arquivo == NULL) { 
        printf("Erro ao tentar abrir o arquivo %s\n", bd_paciente_csv); /* Tratamnto de erros */
        return;
    }

    char linha[256]; // Armazena cada linha lida do arquivo CSV
    fgets(linha, sizeof(linha), arquivo); /* Pula o cabeçalho */

    while (fgets(linha, sizeof(linha), arquivo)) { /* Lê cada linha do arquivo */
        if (bd->quantidade >= MAX_PACIENTES) { /* Verifica se o limite máximo de pacientes foi atingido */
            printf("Limite máximo de pacientes atingido.\n");
            break;
        }
        Paciente p; /* Cria uma variável do tipo Paciente pra armazenar os dados lidos */
        sscanf(linha, "%d,%[^,],%[^,],%d,%s", &p.id, p.cpf, p.nome, &p.idade, p.data_cadastro); /* Lê os dados do paciente da linha */
        bd->pacientes[bd->quantidade] = p; /* Armazena o paciente na estrutura do banco de dados */
        bd->quantidade++; /* Incrementa a quantidade de pacientes */
    }

    fclose(arquivo);
}

/* Função para consultar paciente por nome e/ou prefixo */
void consulta_nome(BDPaciente *bd, const char *prefixo) {
    printf("\nResultados para '%s':\n", prefixo);
    int achou_algum_paciente = 0; /* Variável pra verificar se algum paciente foi encontrado */
    char prefixo_maiusculo[50];
    strcpy(prefixo_maiusculo, prefixo);
     /* Copia a string original do prefixo para uma nova variável */
    for (int k = 0; prefixo_maiusculo[k] != '\0'; k++) {
        prefixo_maiusculo[k] = toupper(prefixo_maiusculo[k]); /* Converte o prefixo para maiúsculas */
    }
    
    for (int i = 0; i < bd->quantidade; i++) { /* Loop para percorrer todos os pacientes no banco de dados */
        char nome_paciente_maiusculo[50];
        strcpy(nome_paciente_maiusculo, bd->pacientes[i].nome); 
        
        /* Converte o nome do paciente para maiúsculas */
        for (int k = 0; nome_paciente_maiusculo[k] != '\0'; k++) { 
            nome_paciente_maiusculo[k] = toupper(nome_paciente_maiusculo[k]);
        }

        /* Compara o prefixo com o início do nome do paciente */
        if (strncmp(nome_paciente_maiusculo, prefixo_maiusculo, strlen(prefixo_maiusculo)) == 0) { 
            visualizar_paciente(bd->pacientes[i]); 
            achou_algum_paciente = 1; /* Altera pra indicar que pelo menos um foi encontrado */
        }
    }

    if (!achou_algum_paciente) { 
        printf("\nNenhum paciente encontrado.\n"); /* Se nenhum paciente foi encontrado, exibe mensagem */
    }
}

/* Função para consultar paciente por CPF e/ou prefixo */
void consulta_cpf(BDPaciente *bd, const char *prefixo) {
    int achou_algum_paciente = 0;
    printf("\nResultados para '%s':\n", prefixo);

    for (int i = 0; i < bd->quantidade; i++) {
        if (strncmp(bd->pacientes[i].cpf, prefixo, strlen(prefixo)) == 0) { /* Compara o prefixo com o início do CPF do paciente */
            visualizar_paciente(bd->pacientes[i]);
            achou_algum_paciente = 1;
        }
    }
    if (!achou_algum_paciente) { /* Se nenhum paciente foi encontrado, exibe mensagem */
        printf("Nenhum paciente encontrado.\n");
    }
}

/* Função que lista todos os pacientes */
void listar_pacientes(BDPaciente *bd) {
    printf("\n[Lista de Pacientes]\n");

    for (int i = 0; i < bd->quantidade; i++) { /* Loop para percorrer todos os pacientes no banco de dados */
        visualizar_paciente(bd->pacientes[i]);
    }
}