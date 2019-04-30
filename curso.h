#ifndef CURSO_H
#define CURSO_H

#include <string>

#include "aluno.h"

class Curso{
private:
    std::string _nome;
    int _vagas;
    double _notaCorte;
    int _inscritos;
    //TODO ListaAlunos inscritosCurso;

public:
    //construtor
    Curso(std::string nome, int vagas);

    //funções get
    std::string getNome();
    int getVagas();
    double getNotaCorte();
    int getNumInscritos();

    void adicionaAluno(Aluno* alunoLista);
    void imprimeCurso();



};


#endif