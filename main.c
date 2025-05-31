#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <ctype.h>   /* Biblioteca para transformar caracteres em maiúsculas */
#include "bd_clinica.h"

/* Mostra o menu principal na tela, funcionando somente as funções 1 e 5 */
void menu_principal() {
     printf("\n[MENU]\n");
     printf("1 - Consultar paciente\n");
     /* printf("2 - Atualizar paciente\n"); */
     /* printf("3 - Excluir paciente\n"); */
     /* printf("4 - Inserir pacientes\n"); */
     printf("5 - Imprimir lista de pacientes\n"); 
     printf("Q - Sair\n"); 
     printf("Escolha uma opcao:\n ");

}

int main() {
     BDPaciente bd; /* Cria uma variável para armazenar os dados dos pacientes */
     bd_iniciar(&bd); /* Chama a função para inicializar o banco de dados (aqui zera a quantidade de pacientes)*/
     bd_arquivo(&bd, "bd_paciente.csv"); /* Chama a função para carregar os dados do arquivo CSV para a estrutura de dados */
     char opcao; /* Variável pra guardar a opção que o usuário digitou */
     char entrada[50]; /* Variável para armazenar a entrada do usuário */


     /* Aqui o programa entra em um loop do-while
     * isso garante que o menu seja exibido pelo menos uma vez e que o programa
     * continue rodando até que o usuário escolha a opção 'Q' (Sair) */
     do {
          menu_principal(); /* Chama a função para exibir o menu na tela  */
          scanf(" %c", &opcao);
          opcao = toupper(opcao); /* Converte a entrada para maiúscula para facilitar a comparação */
          
          if (opcao == '1') {
               int menu_secundario;
               printf("[CONSULTA DE PACIENTE]\n");
               printf("1 - Consultar por nome\n");
               printf("2 - Consultar por CPF\n");
               printf("3 - Retornar ao menu principal\n");
               printf("Escolha uma opcao:\n ");
               scanf("%d", &menu_secundario);
               getchar(); /* Ignora o ('\n') */
                    
               if (menu_secundario == 1) {
                    printf("Digite o nome:\n ");
                    fgets(entrada, sizeof(entrada), stdin); /* Lê a entrada do usuário */
                    entrada[strcspn(entrada, "\n")] = '\0'; /* Remove o caractere de nova linha */
                    consulta_nome(&bd, entrada); /* Chama a função */
         
               } else if (menu_secundario == 2) {
                    printf("Digite o CPF: ");
                    fgets(entrada, sizeof(entrada), stdin);
                    entrada[strcspn(entrada, "\n")] = '\0';
                    consulta_cpf(&bd, entrada);

               } else if (menu_secundario == 3) {
                    printf("Retornando ao menu principal...\n");
                    menu_principal(); /* Retorna ao menu principal */

               } else {
                    printf("Opcao inválida. Tente novamente.\n");
               }

          }else if (opcao == '5'){
               listar_pacientes(&bd); /* Chama a função que lista todos os pacientes */

          } else if (opcao == 'Q' || opcao == 'q') {
               printf("Encerrando o programa...\n");

          } else {
               printf("Opção inválida. Tente de novo.\n"); /* Tratamento de erro para opções inválidas */
          }
     } while (opcao != 'Q' && opcao != 'q'); /* O loop continua enquanto o usuário não digitar 'Q' ou 'q' */
     
     return 0;
}