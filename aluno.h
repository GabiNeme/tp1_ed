#ifndef ALUNO_H
#define ALUNO_H

#include <string>
#include <iostream>

class Aluno{
private:
    int _ordemInscricao;
    std::string _nome;
    double _nota;
    int _cursos[2];
    int _codSit; //1- classificada 1ª opcao, 2- lista espera 1ª e classificada 2ª, 3- lista espera ambas

public:
    //construtor
    Aluno();
    Aluno(int ordemInscricao,std::string nome, double nota, int curso1, int curso2);

    //funções get
    int getOrdemInscricao();
    std::string getNome();
    double getNota();
    int getCurso(int opcao);
    int getCodSit();

    //set
    void setCodSit(int codigo);


};


#endif
