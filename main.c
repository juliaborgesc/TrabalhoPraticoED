#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "bd_clinica.h"

void menu_principal() {
     printf("[MENU]\n");
     printf("1 - Consultar paciente\n");
     //printf("2 - Atualizar paciente\n");
     //printf("3 - Excluir paciente\n");
     //printf("4 - Inserir pacientes\n");
     printf("5 - Listar pacientes\n");
     printf("Q - Sair\n");
     printf("Escolha uma opcao:\n ");

}

int main() {
     BDPaciente bd;
     bd_iniciar(&bd);
     bd_arquivo(&bd, "bd_clinica.csv");
     char opcao;
     char entrada[50];

     do {
          menu_principal();
          scanf(" %c", &opcao);
          
          switch (opcao) {
               case '1': {
                    int menu_secundario;
                    printf("[MENU]\n");
                    printf("Como deseja consultar?\n");
                    printf("1 - Por nome\n");
                    printf("2 - Por CPF\n");
                    printf("3 - Retornar ao menu principal\n");
                    printf("Escolha uma opcao:\n ");
                    scanf("%d", &menu_secundario);
                    getchar();
                    
                    if (menu_secundario == 1) {
                         printf("Digite o nome:\n ");
                         fgets(entrada, sizeof(entrada), stdin);
                         entrada[strcspn(entrada, "\n")] = '\0'; // Remove \n
                         consulta_nome(&bd, entrada);
                         break;
                    } else if (menu_secundario == 2) {
                         printf("Digite o CPF: ");
                         fgets(entrada, sizeof(entrada), stdin);
                         entrada[strcspn(entrada, "\n")] = '\0';
                         consulta_cpf(&bd, entrada);
                         break;
                    } else if (menu_secundario == 3) {
                         printf("Retornando ao menu principal...\n");
                         break;
                    } else {
                         printf("Opcao inválida. Tente novamente.\n");
                         break;
                    }
                    break;
               }
               case '5':
                    listar_pacientes(&bd);
                    break;
               case 'Q':
               case 'q':
                    printf("Saindo...\n");
                    break;
               default:
                    printf("Opcao inválida. Tente novamente.\n");
          }
     } while (opcao != 'Q' && opcao != 'q');
     
     return 0;
}