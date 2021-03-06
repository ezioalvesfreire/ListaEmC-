# Estrutura de dados - Alocação de memória, listas, pilhas

## Função malloc na linguagem de programação C

 A função malloc()(memory allocation), nos possibilita alocar um espaço em memória de forma dinâmica, ou seja em tempo de execução, entre as funções de alocação de memória de forma dinâmica ainda temos a função, (calloc e realoc), com isso veremos a grande utilidade dos ponteiros em C que será usado em nossos estudos sobre listas encadeadas, filas e pilhas.

 É necessário incluir a biblioteca de cabeçalho stdlib.h, para fazer uso da função malloc em programação C. veja a seguir um exemplo de uso da função malloc:
 
 void *malloc(size_t numero_de_bytes);
 
função que recebe como argumento: size_t numero_de_bytes, que equivale a um número inteiro positivo, que representa o espaço que será alocado na memória, e retorna um ponteiro do tipo void (void *malloc) que representa o endereço de memória na qual o espaço foi alocado. é de suma importância saber para que tipo de dado que o ponteiro irá apontar.
sizeof, que do português significa tamanho de: que pode ser por EX: sizeof(int), sizeof(double) ou qualquer outro tipo de dado; é importante ressaltar que um tipo de dado pode sofrer variações de tamanho de acordo com arquitetura do sistema, ou Sistema Operacional etc.
ex: em uma arquitetura 32 bits um inteiro pode ter 4 bytes já em um sistema 64 bits o mesmo inteiro pode ter 8 bytes, portanto a melhor forma de se expressar é dizer que se tem um sizeof de um determinado tipo. 

Porque de se usar alocação de memória de forma dinâmica? Essa é uma técnica de se economizar memória, e deixar o programa mais rápido.

#### Veja com mais detalhes acessando a página que foi usada como referência, clicando no botão a seguir [clique aqui]( https://www.cprogressivo.net/2013/04/Como-usar-a-funcao-malloc-para-alocar-memoria-em-linguagem-C.html)

## Pilhas

 Pilhas é uma das estruturas de dados mais simples e comum, inclusive sendo implementada diretamente no hardware das maquinas modernas, a ideia de pilha é literalmente uma pilha em que os objetos são sobrepostos uns aos outros, em nosso caso de estrutura de dados são de informações (dados), onde um dado sobrepõe o outro através de seu topo, e a ordem de retirada é inversa a ordem que foram colocados, para isso utilizamos o termo LIFO (last in, first out) que do português significa o primeiro a entrar é o último a sair,  e lembra muito uma pilha de pratos.

 Empilhar e desempilhar são duas operações básicas que devem ser implementadas em uma estrutura de pilha: sendo a operação empilhar que é comum usar o termo em inglês (push)  que insere o elemento no topo, e a operação desempilhar retira do topo e o termo comumente usado em inglês é o (pop).
 
<img src='https://raw.githubusercontent.com/ezioalvesfreire/ListaEmC-/master/638586109_prato_de_prity1.png.png' width='180'><img src='https://github.com/ezioalvesfreire/ListaEmC-/blob/master/seta.svg' width='80'><img src='https://github.com/ezioalvesfreire/ListaEmC-/blob/master/stack-pop.gif' width='280'><img src='https://github.com/ezioalvesfreire/ListaEmC-/blob/master/stack-push.gif' width='280'>
  
 ## Interface do tipo pilha
 
 Neste artigo será apresentado duas formas de implementação de pilhas: usando vetor e usando lista encadeada, vamos considerar a implementação de cinco operações:
 
    -criar uma estrutura de pilha;
    -inserir um elemento no topo (push);
    -remover o elemento do topo (pop);
    -verificar se a pilha está vazia;
    -liberar a estrutura de pilha.

 O arquivo pilha.h, que representa a interface do tipo, pode conter o seguinte código:

      typedef struct pilha Pilha;
      
      Pilha* cria (void);
      void push (Pilha* p, float v);
      float pop (Pilha* p);
      int vazia (Pilha* p);
      void libera (Pilha* p);
      
A função cria aloca dinamicamente a estrutura da pilha, inicializa seus campos e
retorna seu ponteiro; as funções push e pop inserem e retiram, respectivamente, um
valor real na pilha; a função vazia informa se a pilha está ou não vazia; e a função
libera destrói a pilha, liberando toda a memória usada pela estrutura.

## Implementação de pilha com vetor

 Quando se sabe de antemão o número máximo de elementos a serem armazenados em uma pilha de dados, a implementação pode ser feita utilizando vetor, por se tratar de uma implementação bastante simples.
 A exemplo teremos um vetor chamado(vet) podendo armazenar n elementos na pilha, o elemento vet[n-1] representa o elemento do topo.
 
 ### Estrutura que representa pilha utilizando vetor, contendo o número máximo de elementos que pode ser armazenados
     #define MAX 50
     
     struct pilha {
        int n;
        float vet[MAX];
     };

### Função para criar a pilha alocada dinamicamente, essa estrutura e inicializa a pilha como sendo vazia

     Pilha* cria (void)
     {
        Pilha* p = (Pilha*) malloc(sizeof(Pilha));
        p->n = 0; /* inicializa com zero elementos */
        return p;
     }
### Função para inserir um elemento na pilha, usamos a próxima posição livre, devemos certificar de que existe espaço para inserção, pois se trata de um vetor com dimensão fixa.

    void push (Pilha* p, float v)
    {
       if (p->n == MAX) { /* capacidade esgotada */
           printf("Capacidade da pilha estourou.\n");
           exit(1); /* aborta programa */
       }
      /* insere elemento na próxima posição livre */
       p->vet[p->n] = v;
       p->n++;
    }
### Função verifica se a pilha não está vazia e retira o elemento do topo da pilha função (pop), fornecendo seu valor como retorno.

    float pop (Pilha* p)
    {
       float v;
       if (vazia(p)) {
           printf("Pilha vazia.\n");
           exit(1); /* aborta programa */
       }
       /* retira elemento do topo */
       v = p->vet[p->n-1];
       p->n--;
       return v;
    }
    
### Função que verifica se a pilha está vazia:
      int vazia (Pilha* p)
      {
         return (p->n == 0);
      }
       
### Função para liberar a memória alocada pela pilha:
      void libera (Pilha* p)
      {
         free(p);
      }
      
### Implementação de pilha com lista

Quando não se sabe o número máximo de elementos a serem armazenados na pilha, devemos implementar a pilha usando estrutura de dados dinâmica, empregando uma lista encadeada. Os elementos são armazenados na lista e a pilha pode ser representada por um ponteiro para o primeiro nó da lista.

### O nó da lista para armazenar valores reais:
      
      struct no {
         float info;
         struct no* prox;
     };
     typedef struct no No;
     
### A estrutura da pilha é:
     struct pilha {
        No* prim;
     };
     
### A função cria aloca a estrutura da pilha e inicializa a lista como sendo vazia.

      Pilha* cria (void)
      {
         Pilha* p = (Pilha*) malloc(sizeof(Pilha));
         p->prim = NULL;
         return p;
      }
      
 O topo da pilha representa o primeiro elemento da lista, e cada novo elemento é inserido no inicio da lista e sempre que necessário retirar também é retirado do início da lista, para que se possa inserir no inicio e remover do início, precisamos de duas funções auxiliares, ambas retornam o novo primeiro nó da lista.
     
     /* função auxiliar: insere no início */
     No* ins_ini (No* l, float v)
    {
        No* p = (No*) malloc(sizeof(No));
        p->info = v;
        p->prox = l;
        return p;
    }
    
    /* função auxiliar: retira do início */
    No* ret_ini (No* l)
    {
        No* p = l->prox;
        free(l);
        return p;
    }
    
### As funções que manipulam a pilha fazem uso dessas funções de lista:

     void push (Pilha* p, float v)
     {
         p->prim = ins_ini(p->prim,v);
     }
     float pop (Pilha* p)
    {
        float v;
       if (vazia(p)) {
          printf("Pilha vazia.\n");
          exit(1); /* aborta programa */
       }
       v = p->prim->info;
       p->prim = ret_ini(p->prim);
       return v;
    }
    
### A pilha estará vazia se a lista estiver vazia:

        int vazia (Pilha* p)
       {
            return (p->prim==NULL);
       }
       
### Função que libera a pilha deve antes liberar todos os elementos da lista.
void libera (Pilha* p)
{
 No* q = p->prim;
 while (q!=NULL) {
 No* t = q->prox;
 free(q);
 q = t;
 }
 free(p);
}
    

#### Veja com mais detalhes acessando a página que foi usada como referência, clicando no botão a seguir [clique aqui](http://www.ic.uff.br/~cbraga/ed/apostila/ed11-pilhas.pdf)
