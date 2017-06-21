#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

#include <stdlib.h>

typedef struct grafo {
   char *nome;
   int n;       // N�mero de v�rtices
   int m;       // N�mero de arestas
   int **adj;   // Ponteiro para a matriz de adjac�ncias
} Grafo;

int **gerarMatriz(int n) {

   int i, j;

   // Aloca um vetor de n ponteiros (do tipo int) na mem�ria
   int **m = malloc( n * sizeof (int *));

   // Para cada ponteiro, aloca n elementos (do tipo int) na mem�ria
   for (i = 0; i < n; i++)
      m[i] = malloc( n * sizeof (int));

   // Preenche cada c�lula da matriz com valor 0
   for (i = 0; i < n; i++)
      for (j = 0; j < n; j++)
         m[i][j] = 0;

   return m;
}

void inicializar(Grafo *g, char *nome, int n) {

    // Inicializa os par�metros da estrutura Grafo
    g->nome = nome;
    g->n = n;
    g->m = 0;
    g->adj = gerarMatriz(n);

}

void inserirAresta(Grafo g, int v, int w) {

    if (g.adj[v][w] == 0) { // Verifica se a aresta n�o existe
      // � necess�rio preencher as duas c�lulas com 1
      g.adj[v][w] = 1;
      g.adj[w][v] = 1;
      g.m++;
    }

}

void removerAresta(Grafo g, int v, int w) {

    if (g.adj[v][w] == 1) { // Verifica se a aresta j� existe
      // � necess�rio preencher as duas c�lulas com 1
      g.adj[v][w] = 0;
      g.adj[w][v] = 0;
      g.m--;
    }

}

void exibir(Grafo *g) {

   int v, w;


    printf("\n=================");
    printf("\n%s", g->nome);
    printf("\n=================");

    // Imprime o conjunto de v�rtices
    printf("\nV = {");

    for(v = 0; v < g->n; v++ )
        printf("%d, ", v);

    if(g->n > 0)
        printf("\b\b");
    printf("}");


    // Imprime o conjunto de arestas
    printf("\nA = {");
    for (v = 0; v < g->n; v++)
        for (w = 0; w < g->n; w++)
            if (g->adj[v][w] == 1)                  // Se os v�rtices s�o vizinhos
                if (v < w)                          // Considera apenas a regi�o superior � diagonal principal
                    printf("(%2d, %2d); ", v, w);   // Imprime

    if(g->m > 0)
        printf("\b\b");
    printf("}");

    printf("\n=================\n");
}

#endif // GRAFO_H_INCLUDED
