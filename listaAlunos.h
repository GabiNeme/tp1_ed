#ifndef LISTAALUNOS_H
#define LISTAALUNOS_H

#include "aluno.h"


struct node_t {
	int idAluno;
	node_t *proximo;
};

class ListaAlunos {
private:
    node_t *inicio;
    node_t *fim;
    int num_elementos_lista;

public:
    ListaAlunos();
    ~ListaAlunos();
    void insereAluno(int idNovoAluno);
    void insereAlunoPosicao(int idNovoAluno, int posicao);
    void insereAlunoOrdenado(int idNovoAluno, Aluno listaAluno[]);


    node_t *getCelCabeca();
    node_t *getUltimo();

};

#endif/* LISTAALUNOS_H */