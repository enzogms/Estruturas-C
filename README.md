

<h1 align="center"><img src="https://raw.githubusercontent.com/abrahamcalf/programming-languages-logos/master/src/c/c_256x256.png" alt="drawing" width="200"/> <br> Exercício para Nota - Estruturas (2°Semestre de 2021)
</h1>


Escreva um programa em C que dadas N pessoas, cada pessoa representada por uma estrutura do tipo tpessoa, imprima uma listagem no formato de tabela de todas as pessoas (nome e data de nascimento) de um determinado sexo (masculino ou feminino) que tenham idade superior a um determinado valor, onde o sexo e a idade são informados pelo usuário.

<p align="center">
   <br>
   <img src="http://img.shields.io/static/v1?label=STATUS&message=CONCLUIDO&color=GREEN&style=for-the-badge"/>
   <br>
</p>

## 🙋  Requisições
Considere os tipos de dados definidos abaixo:
```c
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
```
Utilize a função abaixo para obter a data atual. Para utilizar essa função é necessário incluir o arquivo de cabeçalho time.h.
```c
tdata data_atual() {
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	tdata dt = { tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900 };
	return dt;
}
```
## 🌐 Avaliação e Autores

| Autores:            |
| :------------------ |
| Enzo G Mendes       |
| Charles M Junior    |
| João Victor H Palma |
| Daniel A França     |

    ㅤ

| Professor  | Ciro Cirne Trindade                   |
| :--------- | :------------------------------------ |
| Disciplina | Linguagem de Programação              |
| Curso      | Análise e Desenvolvimento de Sistemas |



