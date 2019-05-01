#include "aluno.h"

Aluno::Aluno(int ordemInscricao,std::string nome, double nota, int curso1, int curso2){
    this->_ordemInscricao = ordemInscricao;
    this->_nome = nome;
    this->_nota = nota;
    this->_cursos[0] = curso1;
    this->_cursos[1] = curso2;
}

Aluno::Aluno(){
    this->_ordemInscricao = 0;
    this->_nome = "";
    this->_nota = 0;
    this->_cursos[0] = -1;
    this->_cursos[1] = -1;
}

//funções get
int Aluno::getOrdemInscricao(){
    return this->_ordemInscricao;
}

std::string Aluno::getNome(){
    return this->_nome;
}

double Aluno::getNota(){
    return this->_nota;
}

int Aluno::getCurso(int opcao){
    //TODO Tratar se opcao <0 ou >1
    return this->_cursos[opcao];
}


int Aluno::getCodSit(){
    return this->_codSit;
}


void Aluno::setCodSit(int codigo){
    this->_codSit = codigo;
}