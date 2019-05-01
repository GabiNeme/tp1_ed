#include "saidaDados.h"
#include <iostream>
#include <fstream>  


void criaArquivoSaida(Curso listaCurso[], Aluno listaAlunos[], char ** argv, int numCursos){

    std::ofstream arquivoSaida (argv[2]);

    for(int i = 0 ; i<numCursos;i++){
        arquivoSaida << listaCurso[i].imprimeCurso(listaAlunos) ;
        if (i != numCursos -1){
            arquivoSaida << std::endl;
        }
    }

    arquivoSaida.close();
    
}