#include "distribuiAlunos.h"

void distribuiAlunosCursos(Curso listaCursos[], Aluno listaAlunos[], int alunosOrdenados[], int numCursos, int numAlunos){

    //para cada aluno, ordenado
    for (int i = 0; i < numAlunos; i++){
        Aluno aluno = listaAlunos[alunosOrdenados[i]];
        int ultimaPosicao;
        bool classOp1;

        //caso a nota desse aluno seja igual à nota do aluno com última posição no curso será necessário verificar a lista
        //de desempate. No entanto, só é preciso verificar na primeira opção de curso do aluno pois caso seja a segunda,
        //esse aluno necessariamente ficará após o último, pois têm a mesma nota, é a segunda opção de curso e esse aluno
        //se inscreveu depois.
        if (listaCursos[aluno.getCurso(0)].getUltimaNotaAluno() == aluno.getNota() ){
            classOp1 = verificaEmpate(listaCursos, aluno.getCurso(0), aluno, listaAlunos, numAlunos);

        }else{
            ultimaPosicao = listaCursos[aluno.getCurso(0)].getNumInscritos() + 1 ;

            classOp1 = listaCursos[aluno.getCurso(0)].adicionaAluno(aluno, ultimaPosicao);
        }

        if (!classOp1){
            ultimaPosicao = listaCursos[aluno.getCurso(1)].getNumInscritos() + 1;
            listaCursos[aluno.getCurso(1)].adicionaAluno(aluno, ultimaPosicao);
        }

    }

}

bool verificaEmpate(Curso listaCursos[], int idCurso, Aluno aluno, Aluno listaAlunos[], int numAlunos){
    //pega cada aluno da lista do curso
    node_t *pAluno = listaCursos[idCurso].getListaInscritos();

    int pos = 1;
    while (pAluno != nullptr){
        Aluno alunoComp = listaAlunos[pAluno->idAluno];
        if(alunoComp.getNota() == aluno.getNota()){ //se eles têm a mesma nota
            if(alunoComp.getCurso(1) == aluno.getCurso(0)){ //e o aluno atual ganha do anterior pela opção de curso

                return listaCursos[idCurso].adicionaAluno(aluno, pos); //então esse aluno pega essa posição
            }
        }
        pAluno = pAluno->proximo;
        pos++;
    }
    //se não foi inserido no meio, será no final
    return listaCursos[idCurso].adicionaAluno(aluno, listaCursos[idCurso].getNumInscritos()+1);
}
