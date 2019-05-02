#ifndef CURSO_H
#define CURSO_H

#include <string>

#include "listaAlunos.h"

class Curso{
private:
    std::string _nome;
    int _vagas;
    double _notaCorte;
    int _numInscritos;
    int _ultimaNotaAluno;

public:

    ListaAlunos inscritosCurso;

    //construtor
    Curso();
    Curso(std::string nome, int vagas);

    //funções get
    std::string getNome();
    int getVagas();
    double getNotaCorte();
    int getNumInscritos();
    int getUltimaNotaAluno();
    node_t * getListaInscritos();

    //funções set
    void setNome(std::string novoNome);
    void setVagas(int vagas);


    bool adicionaAluno(Aluno novoAluno, int posicao);
    std::string imprimeCurso( Aluno listaAlunos[]);

};


#endif