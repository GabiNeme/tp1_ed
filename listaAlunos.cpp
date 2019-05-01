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
/**
int ListaAlunos::insereAlunoOrdemNota(Aluno novoAluno){
    node_t *no_a_inserir = new node_t();
    no_a_inserir->aluno = novoAluno;
    no_a_inserir->proximo = nullptr;

    this->num_elementos_lista++;

    node_t *anterior = this->inicio;
    node_t *atual = this->inicio->proximo;
    while(atual != nullptr){
        //encontrou posicao
        if(atual->aluno.getNota() < novoAluno.getNota() ||
           (atual->aluno.getNota() == novoAluno.getNota() && atual->aluno.getOrdemInscricao() > novoAluno.getOrdemInscricao())){
            no_a_inserir->proximo = anterior->proximo;
            anterior->proximo = no_a_inserir;
            if (atual->aluno.getNota() == novoAluno.getNota()){
                return 1; //código que é preciso avaliar os dois alunos, pois têm nota igual
            }
            return 0;
        }else{
            anterior = atual;
            atual = atual->proximo;
        }
    }

    //insere na ultima posicao
    this->fim->proximo = no_a_inserir;
    this->fim = no_a_inserir;

}
**/
void ListaAlunos::removeAluno(int idAluno){
    node_t *anterior = this->inicio;
    node_t *atual = this->inicio->proximo;
    while(atual != nullptr){
        //encontrou posicao
        if(atual->idAluno == idAluno ){
            anterior->proximo = atual->proximo;
            delete atual;
            return;
        }
    }
}

node_t *ListaAlunos::getCelCabeca(){
    return this->inicio;
}

std::string ListaAlunos::imprimeLista(Aluno listaAlunos[]){
    std::string texto;

    node_t *atual = this->inicio->proximo;
    while(atual != nullptr){
        Aluno aluno = listaAlunos[atual->idAluno];
        texto.append(aluno.getNome()+'\n');
        atual = atual->proximo;
    }
    return texto;
}