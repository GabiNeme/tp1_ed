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
    ListaAlunos inscritosCurso;

public:

    //construtor
    Curso();
    Curso(std::string nome, int vagas);

    //funções get
    std::string getNome();
    int getVagas();
    double getNotaCorte();
    int getNumInscritos();

    //funções set
    void setNome(std::string novoNome);
    void setVagas(int vagas);


    bool adicionaAluno(Aluno novoAluno);
    std::string imprimeCurso( Aluno listaAlunos[]);

};


#endif