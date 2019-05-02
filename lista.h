#ifndef LISTA_H
#define LISTA_H

#include "aluno.h"


struct node_t {
	int idAluno;
	node_t *proximo;
};

class Lista {
private:
    node_t *inicio;
    node_t *fim;

public:
    Lista();
    ~Lista();
    void insereAluno(int idNovoAluno);
    void insereAlunoPosicao(int idNovoAluno, int posicao);
    void insereAlunoOrdenado(int idNovoAluno, Aluno listaAluno[]);


    node_t *getCelCabeca();
    node_t *getUltimo();

};

#endif/* LISTA_H */