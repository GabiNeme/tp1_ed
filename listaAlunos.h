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
    void removeAluno(int idAluno);

    node_t *getCelCabeca();

    std::string imprimeLista(Aluno listaAlunos[]);

};

#endif/* LISTAALUNOS_H */