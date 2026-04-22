#ifndef ALUNO_H
#define ALUNO_H

typedef struct{
    int dia;
    int mes;
    int ano;
}Data;

typedef struct{
    char nome[51];
    Data nascimento;
    char sexo;
    char cpf[12];
    long long matricula;
}Aluno;

void menu_aluno();
int Cadastrar_aluno(Aluno alunos[], int qntd);
void Listar_alunos(Aluno alunos[], int qntd);
void Atualizar_aluno(Aluno alunos[], int qntd);
int Remover_aluno(Aluno alunos[], int qntd);
void Ordena_alunos(Aluno alunos[], int qntd);

#endif