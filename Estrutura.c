/*
Instituição: Fatec Carapicuíba
Professor: Ciro Cirne Trindade
Disciplina: Linguagem de Programação
Curso: Análise e Desenvolvimento de Sistemas - Manhã
------------------------------------------------------------
2º Exercício para nota - Estruturas
Grupo:


▄▄▄█████▓ ▄▄▄      ▓█████▄  ██▓ ███▄    █  ██░ ██  ▒█████    ██████ 
▓  ██▒ ▓▒▒████▄    ▒██▀ ██▌▓██▒ ██ ▀█   █ ▓██░ ██▒▒██▒  ██▒▒██    ▒ 
▒ ▓██░ ▒░▒██  ▀█▄  ░██   █▌▒██▒▓██  ▀█ ██▒▒██▀▀██░▒██░  ██▒░ ▓██▄   
░ ▓██▓ ░ ░██▄▄▄▄██ ░▓█▄   ▌░██░▓██▒  ▐▌██▒░▓█ ░██ ▒██   ██░  ▒   ██▒
  ▒██▒ ░  ▓█   ▓██▒░▒████▓ ░██░▒██░   ▓██░░▓█▒░██▓░ ████▓▒░▒██████▒▒
  ▒ ░░    ▒▒   ▓▒█░ ▒▒▓  ▒ ░▓  ░ ▒░   ▒ ▒  ▒ ░░▒░▒░ ▒░▒░▒░ ▒ ▒▓▒ ▒ ░
    ░      ▒   ▒▒ ░ ░ ▒  ▒  ▒ ░░ ░░   ░ ▒░ ▒ ░▒░ ░  ░ ▒ ▒░ ░ ░▒  ░ ░
  ░        ░   ▒    ░ ░  ░  ▒ ░   ░   ░ ░  ░  ░░ ░░ ░ ░ ▒  ░  ░  ░  
               ░  ░   ░     ░           ░  ░  ░  ░    ░ ░        ░  
                    ░                                               

Autores:
Enzo G Mendes
Charles M Junior
João Victor H Palma
Daniel A França
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

//Def. das estruturas

typedef enum { MASCULINO = 1, FEMININO = 2 } tsexo;


typedef struct {
    int dia;
    int mes;
    int ano;
} tdata;


typedef struct {
    char nome[41];
    tsexo sexo;
    tdata nascimento;
} tpessoa;


tdata data_atual()
{
 time_t t = time(NULL);
 struct tm tm = *localtime(&t);
 tdata dt = { tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900 };
 return dt;
}


int main() {
    int n;
    
    //Recebendo cadastro de n pessoas
    printf("Informe o numero de pessoas a serem cadastradas: ");
    scanf("%d", &n);
    tpessoa pessoas[n];
    printf("Informe os dados das %d pessoas:\n", n);
    for (int i = 0; i < n; i++) {
        printf("\n%da. pessoa:\n", i + 1);
        printf("* Nome: ");
        scanf(" %30[^\n]", &pessoas[i].nome);
        printf("* Sexo (1 - M|2 - F): ");
        scanf("%d", &pessoas[i].sexo);
        if (pessoas[i].sexo == 1) {
            pessoas[i].sexo = MASCULINO;
        } else {
            pessoas[i].sexo = FEMININO;
        }
            
        printf("* Data de nascimento (DD/MM/AAAA): ");
        scanf("%d/%d/%d", &pessoas[i].nascimento.dia,&pessoas[i].nascimento.mes,&pessoas[i].nascimento.ano);
    }


    //Recebendo filtros de busca baseado nas informações recebidas no cadastro
    int idades;
    int morf;
    printf("Informe a idade superior a ser procurada: ");
    scanf("%d", &idades);
    printf("Informe o sexo a ser procurado (1 - M|2 - F): ");
    scanf("%d", &morf);
    
    if (morf == 1) {
        morf = MASCULINO;
    } else {
        morf = FEMININO;
    }
    
    //Calculando o ano atual
    int anoAtual;
    time_t data_ano;
    time(&data_ano);
    struct tm *data = localtime(&data_ano);
    anoAtual = (data->tm_year+1900);    
    printf("%d\n",anoAtual);

    

    //Imprimindo apenas pessoas que estão dentro dos parâmetros informados pelo usuário
    printf("\n\tPessoas cadastradas\n");
    printf("------------------------------------------\n");
    printf("Nome                      Sexo  Nascimento\n");
    printf("------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        if ( (anoAtual - pessoas[i].nascimento.ano > idades) && pessoas[i].sexo == morf ) {
            if (pessoas[i].sexo == 1) {
                printf("%-25.25s  M    %2d/%02d/%4d\n", 
                    pessoas[i].nome, pessoas[i].nascimento.dia, pessoas[i].nascimento.mes,pessoas[i].nascimento.ano);
        } else if (pessoas[i].sexo == 2) {
                printf("%-25.25s  F    %2d/%02d/%4d\n",
                    pessoas[i].nome, pessoas[i].nascimento.dia, pessoas[i].nascimento.mes,pessoas[i].nascimento.ano);
        }
      }
    }
    printf("------------------------------------------\n"); 
  
  
  return 0;
}
