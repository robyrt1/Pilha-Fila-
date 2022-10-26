#include <stdio.h>
#include "aula25_10.cpp"

main()
{

    Pilha pilha1, pilha2;

    iniciarPilha(&pilha1);
    iniciarPilha(&pilha2);

    empilhar(&pilha1, 11);
    empilhar(&pilha1, 4);
    empilhar(&pilha1, 1);
    empilhar(&pilha1, 6);
    empilhar(&pilha1, 8);

    comparacao(&pilha1, &pilha2);

    maiorMenorMedia(&pilha1);

    exibirParImpar(&pilha1);

    transferir(&pilha1, &pilha2);

    
}