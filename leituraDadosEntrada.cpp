
#include "leituraDadosEntrada.h"
#include <fstream>
#include <sstream>
#include <iostream>


void verificaArgumentos(int argc){
    if (argc != 3){
        std::cout << "São necessários exatamente dois argumentos, o arquivo de entrada e saída." << std::endl;
        exit(1);
    }
}

void leNumeroDeCursosEAlunos(char ** argv, int & numCursos, int & numAlunos){
    std::ifstream arquivoEntrada;
    arquivoEntrada.open(argv[1]);
    if (!arquivoEntrada) {
        std::cout << "Não foi possível ler o arquivo de entrada. " << argv[1] << " não encontrado."  << std::endl;
        exit(1);
    }
    
    arquivoEntrada >> numCursos;
    arquivoEntrada >> numAlunos;
    arquivoEntrada.close();
}

void preencheListaCursos(Curso listaCursos[], int numCursos, char ** argv){
    std::ifstream arquivoEntrada;
    arquivoEntrada.open(argv[1]);

    std::string nomeCurso, vagas;
    int numVagas;
    getline(arquivoEntrada,nomeCurso);//ignora primeira linha
    for (int i=0; i<numCursos;i++)
    {
        getline(arquivoEntrada,nomeCurso);
        getline(arquivoEntrada,vagas);
        numVagas = std::stoi(vagas);
        listaCursos[i].setNome(nomeCurso);
        listaCursos[i].setVagas(numVagas);
    }


    arquivoEntrada.close();
}



void preencheListaAlunos(Aluno listaAlunos[], int numAlunos, int numCursos, char ** argv){

    std::ifstream arquivoEntrada;
    arquivoEntrada.open(argv[1]);

    std::string nomeAluno, infos;

    //pula as primeiras linhas, de cursos
    for (int i=0; i<=2*numCursos;i++) {
        getline(arquivoEntrada,nomeAluno);
    }

    //obtém os alunos
    for (int i=0; i<numAlunos;i++){
        getline(arquivoEntrada,nomeAluno);
        getline(arquivoEntrada,infos);

        std::istringstream iss(infos);
        double nota;
        int opCurso1, opCurso2;

        iss >> nota;
        iss >> opCurso1;
        iss >> opCurso2;
        
        Aluno aluno(i, nomeAluno, nota, opCurso1, opCurso2);
        listaAlunos[i] = aluno;
    }
    arquivoEntrada.close();
}

void ordenaAlunosPorNota(Aluno listaAlunos[], int numAlunos, int alunosOrdenados[]){
    
    ListaAlunos listaAux;

    for(int i = 0; i < numAlunos; i++){
        listaAux.insereAlunoOrdenado(i, listaAlunos);
    }  

    node_t *atual = listaAux.getCelCabeca()->proximo;
    int j = 0;
    while(atual != nullptr){
        alunosOrdenados[j] = atual->idAluno;
        atual = atual->proximo;
        j++;
    }

}