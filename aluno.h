#ifndef ALUNO_H
#define ALUNO_H

#include <string>

class Aluno{
private:
    int _ordemInscricao;
    std::string _nome;
    double _nota;
    int _cursos[2];

public:
    //construtor
    Aluno(int ordemInscricao,std::string nome, double nota, int curso1, int curso2);

    //funções get
    int getOrdemInscricao();
    std::string getNome();
    double getNota();
    int getCurso(int opcao);


};


#endif
