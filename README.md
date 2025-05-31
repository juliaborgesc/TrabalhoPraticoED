# Trabalho Prático da disciplina Estrutura de Dados

Este trabalho consiste em implementar um sistema de gerenciamento de dados de pacientes de uma clínica em linguagem C. Os dados são armazenados em um arquivo texto CSV e carregados em uma estrutura de dados específica para execução do sistema. O sistema, até então, permite consulta de pacientes por nome ou cpf e listagem de todos os pacientes cadastrados.

## Estrutura do Projeto

O Projeto conta com os seguintes arquivos principais: 

- **main.c** -	Contém o menu principal e secundário.    
- **clinica.h/c** - 	Define a *struct* Paciente e função de exibição de pacientes.    
- **bd_clinica.h/c** - Define a *struct* BDPaciente, declara as funções do sistema e gerencia o banco de dados em memória.    
- **bd_paciente.csv** - Arquivo CSV (tabela) com os dados dos pacientes (id, cpf, nome, idade e data de cadastro).    
- **Makefile** -  Especifica os passos necessários para compilar e executar o programa.     

## TADs (Tipos Abstratos de Dados)

- **Paciente** - A estrutura Paciente armazena os dados: id (inteiro), cpf (15 caracteres por conta dos sinais de pontuação), nome (nome completo com até 80 caracteres para evitar erros), idade (inteiro) e data de cadastro (11 caracteres por conta dos sinais de pontuação).     
- **BDPaciente** - É uma abstração para o armazenamento e a manipulação dos dados dos pacientes. Recebe o número maximo de pacientes e tem um contador para gerenciar registros.    


# Como executar o programa

Primeiramente é válido dizer que o programa foi feito em Windows, mas pensado para ser executado também em Linux Ubuntu.

###  Usando o Makefile (recomendado)
```bash
# Clone o repositório 
git clone https://github.com/juliaborgesc/TrabalhoPraticoED.git
cd TrabalhoPraticoED-P1

# Compile e execute o programa
make
