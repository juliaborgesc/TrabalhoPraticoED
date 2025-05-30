#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "bd_clinica.h"

/* Mostra o menu principal na tela */
void menu_principal() {
     printf("\n[MENU]\n");
     printf("1 - Consultar paciente\n");
     /* printf("2 - Atualizar paciente\n"); */
     /* printf("3 - Excluir paciente\n"); */
     /* printf("4 - Inserir pacientes\n"); */
     /* printf("5 - Listar pacientes\n"); */
     printf("Q - Sair\n"); 
     printf("Escolha uma opcao:\n ");

}

int main() {
     BDPaciente bd;
     bd_iniciar(&bd); /* Inicia com 0 pacientes */
     bd_arquivo(&bd, "bd_paciente.csv");
     char opcao;
     char entrada[50];

     do {
          menu_principal();
          scanf(" %c", &opcao);
          
          if (opcao == '1') {
               int menu_secundario;
               printf("[CONSULTA DE PACIENTE]\n");
               printf("1 - Consultar por nome\n");
               printf("2 - Consultar por CPF\n");
               printf("3 - Retornar ao menu principal\n");
               printf("Escolha uma opcao:\n ");
               scanf("%d", &menu_secundario);
               getchar();
                    
               if (menu_secundario == 1) {
                    printf("Digite o nome:\n ");
                    fgets(entrada, sizeof(entrada), stdin);
                    entrada[strcspn(entrada, "\n")] = '\0'; /* Remove \n */
                    consulta_nome(&bd, entrada);
         
               } else if (menu_secundario == 2) {
                    printf("Digite o CPF: ");
                    fgets(entrada, sizeof(entrada), stdin);
                    entrada[strcspn(entrada, "\n")] = '\0';
                    consulta_cpf(&bd, entrada);

               } else if (menu_secundario == 3) {
                    printf("Retornando ao menu principal...\n");

               } else {
                    printf("Opcao inválida. Tente novamente.\n");
               }

          }else if (opcao == '5'){
               listar_pacientes(&bd);

          } else if (opcao == 'Q' || opcao == 'q') {
               printf("Encerrando o programa...\n");

          } else {
               printf("Opção inválida. Tente de novo.\n");
          }
     } while (opcao != 'Q' && opcao != 'q');
     
     return 0;
}