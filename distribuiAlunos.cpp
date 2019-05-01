#include "distribuiAlunos.h"

void distribuiAlunosCursos(Curso listaCursos[], Aluno listaAlunos[], int alunosOrdenados[], int numCursos, int numAlunos){
    ListaAlunos alunosModificados;

    //para cada aluno, ordenado
    for (int i = 0; i < numAlunos; i++){
        Aluno aluno = listaAlunos[alunosOrdenados[i]];
        //std::cout << i << " " << aluno.getNome() << std::endl;

        bool classOp1 = listaCursos[aluno.getCurso(0)].adicionaAluno(aluno);

        if (classOp1){
            aluno.setCodSit(1);
        }else{
            bool classOp2 = listaCursos[aluno.getCurso(1)].adicionaAluno(aluno);
            if (classOp2){
                aluno.setCodSit(2);
            }else{
                aluno.setCodSit(3);
            }
        }

    }

}