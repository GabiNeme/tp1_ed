#include "curso.h"

Curso::Curso(std::string nome, int vagas){
    this->_nome = nome;
    this->_vagas = vagas;
    this->_notaCorte = 0;
    this->_inscritos = 0;
}


std::string Curso::getNome(){
    return this->_nome;
}

int Curso::getVagas(){
    return this->_vagas;
}

double Curso::getNotaCorte(){
    return this->_notaCorte;
}

int Curso::getNumInscritos(){
    return this->_inscritos;
}