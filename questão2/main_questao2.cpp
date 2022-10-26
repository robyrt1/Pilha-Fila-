#include <stdio.h>
#include "fila_questao2.cpp"

main()
{
    Fila f1,f2;

    iniciarFila(&f1);
    iniciarFila(&f2);

    enfileira(&f1, 11);
    enfileira(&f1, 4);
    enfileira(&f1, 3);
    enfileira(&f1, 6);
    enfileira(&f1, 8);

    comparacao(&f1,&f2);

    maiorMenorMedia(&f1);

    exibirParImpar(&f1);

    transferir(&f1, &f2);
}