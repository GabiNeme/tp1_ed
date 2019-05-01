
#include "curso.h"
#include <iostream>


void verificaArgumentos(int argc);

void leNumeroDeCursosEAlunos(char ** argv, int & numCursos, int & numAlunos);

void preencheListaCursos(Curso listaCursos[], int numCursos, char ** argv);

void preencheListaAlunos(Aluno listaAlunos[], int numAlunos, int numCursos, char ** argv);

void ordenaAlunosPorNota(Aluno listaAlunos[], int numAlunos, int alunosOrdenados[]);