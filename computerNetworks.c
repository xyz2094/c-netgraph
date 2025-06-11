#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define V 8

int grafo[V][V];

void inicializarGrafo();
void adicionarAresta(int u, int v, int peso);
void removerAresta(int u, int v);
void imprimirMatriz();
void DFS_util(int v, int visitado[]);
void DFS(int v);

void inicializarGrafo()
{
  for (int i = 0; i < V; i++)
  {
    for (int j = 0; j < V; j++)
    {
      grafo[i][j] = 0;
    }
  }
}

void adicionarAresta(int u, int v, int peso)
{
  if (u >= 0 && u < V && v >= 0 && v < V)
  {
    grafo[u][v] = peso;
    grafo[v][u] = peso;
    printf("\n");
    printf("Conexao entre os computadores %d e %d com custo %d foi adicionada.\n", u, v, peso);
  }
  else
  {
    printf("Erro: Vertice invalido! Use valores entre 0 e %d.\n", V - 1);
  }
}

void removerAresta(int u, int v)
{
  if (u >= 0 && u < V && v >= 0 && v < V)
  {
    if (grafo[u][v] == 0)
    {
      printf("Nenhuma conexao para remover entre %d e %d.\n", u, v);
    }
    else
    {
      grafo[u][v] = 0;
      grafo[v][u] = 0;
      printf("Conexao entre os computadores %d e %d foi removida.\n", u, v);
    }
  }
  else
  {
    printf("Erro: Vertice inválido!\n");
  }
}

void imprimirMatriz()
{
  printf("\n--- Matriz de Adjacencia da Rede (Custos) ---\n");
  printf("     ");
  for (int i = 0; i < V; i++)
  {
    printf("[%d]  ", i);
  }
  printf("\n");
  printf("---------------------------------------------\n");

  for (int i = 0; i < V; i++)
  {
    printf("[%d] | ", i);
    for (int j = 0; j < V; j++)
    {
      printf(" %-3d ", grafo[i][j]);
    }
    printf("\n");
  }
  printf("---------------------------------------------\n");
}

void DFS_util(int v, int visitado[])
{
  visitado[v] = 1;
  printf("%d -> ", v);

  for (int i = 0; i < V; i++)
  {
    if (grafo[v][i] != 0 && !visitado[i])
    {
      DFS_util(i, visitado);
    }
  }
}

void DFS(int v)
{
  if (v < 0 || v >= V)
  {
    printf("Erro: Vertice inicial invalido!\n");
    return;
  }

  int visitado[V] = {0};

  printf("\nCaminho da Busca em Profundidade (DFS) a partir do computador %d:\n", v);
  DFS_util(v, visitado);
  printf("FIM\n");
}

int main()
{
  int opcao, u, v, peso, inicio_dfs;

  setlocale(LC_ALL, "");

  inicializarGrafo();

  adicionarAresta(0, 1, 5);
  adicionarAresta(0, 2, 10);
  adicionarAresta(1, 3, 8);
  adicionarAresta(2, 4, 15);
  adicionarAresta(2, 5, 4);
  adicionarAresta(3, 4, 7);
  adicionarAresta(4, 6, 9);
  adicionarAresta(5, 7, 12);
  adicionarAresta(6, 7, 3);

  printf("\n*** Sistema de Gerenciamento de Rede de Computadores ***\n");

  do
  {
    printf("\n--- MENU DE OPCOES ---\n\n");
    printf("1. Adicionar Conexao (Aresta)\n");
    printf("2. Remover Conexao (Aresta)\n");
    printf("3. Visualizar Matriz da Rede\n");
    printf("4. Rastrear Conectividade (Busca em Profundidade)\n");
    printf("0. Sair\n");
    printf("\nEscolha uma opcao: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
      printf("Digite o computador de origem (0 a %d): ", V - 1);
      scanf("%d", &u);
      printf("Digite o computador de destino (0 a %d): ", V - 1);
      scanf("%d", &v);
      printf("Digite o custo da conexao: ");
      scanf("%d", &peso);
      adicionarAresta(u, v, peso);
      break;
    case 2:
      printf("Digite o computador de origem (0 a %d): ", V - 1);
      scanf("%d", &u);
      printf("Digite o computador de destino (0 a %d): ", V - 1);
      scanf("%d", &v);
      removerAresta(u, v);
      break;
    case 3:
      imprimirMatriz();
      break;
    case 4:
      printf("Digite o computador inicial para a busca (0 a %d): ", V - 1);
      scanf("%d", &inicio_dfs);
      DFS(inicio_dfs);
      break;
    case 0:
      printf("\nSaindo do programa. Ate logo!\n");
      break;
    default:
      printf("\nOpcao inválida! Por favor, tente novamente.\n");
    }
  } while (opcao != 0);

  return 0;
}