#include "listaAlunos.h"


ListaAlunos::ListaAlunos(){
    node_t *no_cabeca = new node_t();
    this->inicio = no_cabeca;
    no_cabeca->proximo = nullptr;
    this->fim = no_cabeca;
    this->num_elementos_lista = 0;
}


ListaAlunos::~ListaAlunos(){
    node_t *atual = this->inicio;
    node_t *prox = nullptr;
    while (atual != nullptr){
        prox = atual->proximo;
        delete atual;
        atual = prox;
    }
}


void ListaAlunos::insereAluno(int idNovoAluno){
    node_t *no_a_inserir = new node_t();
    no_a_inserir->idAluno = idNovoAluno;
    no_a_inserir->proximo = nullptr;

    this->fim->proximo = no_a_inserir;
    this->fim = no_a_inserir;

    this->num_elementos_lista++;
}


void ListaAlunos::insereAlunoPosicao(int idNovoAluno, int posicao){
  node_t *no_a_inserir = new node_t();
    no_a_inserir->idAluno = idNovoAluno;
    no_a_inserir->proximo = nullptr;

    this->num_elementos_lista++;

    node_t *anterior = this->inicio;
    node_t *atual = this->inicio->proximo;
    int i = 1;
    while(atual != nullptr){
        //encontrou posicao
        if(i == posicao){
            no_a_inserir->proximo = anterior->proximo;
            anterior->proximo = no_a_inserir;
            return;
        }else{
            anterior = atual;
            atual = atual->proximo;
        }
        i++;
    }

    //insere na ultima posicao
    this->fim->proximo = no_a_inserir;
    this->fim = no_a_inserir;
}

void ListaAlunos::insereAlunoOrdenado(int idNovoAluno, Aluno listaAluno[]){
    node_t *no_a_inserir = new node_t();
    no_a_inserir->idAluno = idNovoAluno;
    no_a_inserir->proximo = nullptr;

    this->num_elementos_lista++;

    node_t *anterior = this->inicio;
    node_t *atual = this->inicio->proximo;
    while(atual != nullptr){
        //encontrou posicao
        if(listaAluno[idNovoAluno].getNota() > listaAluno[atual->idAluno].getNota()){
            no_a_inserir->proximo = anterior->proximo;
            anterior->proximo = no_a_inserir;
            return;
        }else{
            anterior = atual;
            atual = atual->proximo;
        }
    }

    //insere na ultima posicao
    this->fim->proximo = no_a_inserir;
    this->fim = no_a_inserir;
}

node_t *ListaAlunos::getCelCabeca(){
    return this->inicio;
}

node_t *ListaAlunos::getUltimo(){
    return this->fim;
}

