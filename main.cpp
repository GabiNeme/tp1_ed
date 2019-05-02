#include "curso.h"
#include "lista.h"
#include "leituraDadosEntrada.h"
#include "distribuiAlunos.h"
#include "saidaDados.h"

#include <fstream>
#include <iostream>


int main(int argc, char *argv[]){

    verificaArgumentos(argc);


    int numCursos, numAlunos;
    leNumeroDeCursosEAlunos(argv, numCursos, numAlunos);

    Curso listaCursos[numCursos];
    preencheListaCursos(listaCursos, numCursos, argv);

    Aluno listaAlunos[numAlunos];
    preencheListaAlunos(listaAlunos, numAlunos, numCursos, argv);

    int alunosOrdenados[numAlunos];
    ordenaAlunosPorNota(listaAlunos, numAlunos, alunosOrdenados);

    distribuiAlunosCursos(listaCursos,listaAlunos,alunosOrdenados,numCursos,numAlunos);

    criaArquivoSaida(listaCursos, listaAlunos, argv, numCursos);

}
