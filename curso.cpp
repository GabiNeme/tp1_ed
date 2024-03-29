#include "curso.h"
	
#include <iomanip>
#include <iostream>
#include <sstream>

Curso::Curso(){
    this->_nome = "";
    this->_vagas = 0;
    this->_notaCorte = 0;
    this->_numInscritos = 0;
    this->_ultimaNotaAluno = 0;
}

Curso::Curso(std::string nome, int vagas){
    this->_nome = nome;
    this->_vagas = vagas;
    this->_notaCorte = 0;
    this->_numInscritos = 0;
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
    return this->_numInscritos;
}

int Curso::getUltimaNotaAluno(){
    return this->_ultimaNotaAluno;
}


node_t * Curso::getListaInscritos(){
    return this->inscritosCurso.getCelCabeca()->proximo;
}

void Curso::setNome(std::string novoNome){
    this->_nome = novoNome;
}

void Curso::setVagas(int vagas){
    this->_vagas = vagas;
}


bool Curso::adicionaAluno(Aluno novoAluno, int posicao){
    if(posicao == _numInscritos+1){
        this->inscritosCurso.insereAluno(novoAluno.getOrdemInscricao());
    }else{
        this->inscritosCurso.insereAlunoPosicao(novoAluno.getOrdemInscricao(), posicao);
    }

    this->_ultimaNotaAluno = novoAluno.getNota();
    _numInscritos ++;
    if(posicao > _vagas){
        return false;
    }else{
        if (posicao == _vagas){
            this->_notaCorte = novoAluno.getNota();
        }
        return true;
    }
}



std::string Curso::imprimeCurso(Aluno listaAlunos[]){

    std::stringstream stream;
    stream << this->_nome << " ";
    stream << std::fixed << std::setprecision(2) << this->_notaCorte;
    stream << "\nClassificados\n" ;

    node_t *alunoAtual = this->inscritosCurso.getCelCabeca()->proximo;
    int cont = 0;
    while(alunoAtual != nullptr){
        if ( cont == this->_vagas ){
            stream <<   "Lista de espera" << std::endl;
        }
        Aluno aluno = listaAlunos[alunoAtual->idAluno];
        stream <<  aluno.getNome() << ' ' << aluno.getNota() << std::endl;
        alunoAtual = alunoAtual->proximo;
    
        cont ++;
    }
    if(cont == 0 || cont <= this->_vagas){
        stream <<   "Lista de espera" << std::endl;
    }
    std::string s = stream.str();
    return s;
}
