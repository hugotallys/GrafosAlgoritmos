# GrafosAlgoritmos
Implementação de algoritmos em grafos - ECOM033

Professor: Rian Gabriel Santos Pinheiro

Alunos: Hugo Tallys Martins Oliveira e João Arthur Gaia da Rocha Almeida

# Algoritmos 

Cada algoritmo tem um arquivo com o código fonte em C ou C++, um arquivo executável, com o código já compilado, um exemplo de entrada e um exemplo de saída.

Para os códigos em C++, para gerar cada arquivo executável basta entrar na linha de comando com:

    $ g++ <filename>.cpp ../Data_Structures/Graph.cpp ../Data_Structures/MinHeap.cpp ../Utility/Utils.cpp -o <filename>

E para gerar a saída:
    
    $ <filename>.exe < <filename>_in.txt > <filename>_out.txt (windows)
    $ ./<filename> < <filename>_in.txt > <filename>_out.txt

Para o código em C, basta compilar:
    
    $ gcc -o khan khan.c

O nome do arquivo de entrada deve ser khan_in.txt. O próprio programa gera a saída khan_out.txt, no mesmo diretório.
    
Fluxo Máximo

    Edmonds-Karp
    
    O algoritmo foi implementado em C++.
    
    Entrada:
    
    A primeira linha da entrada recebe o número de vértices (n) e o número de arestas (m)
    Em seguida, m linhas, cada uma contendo: vértice de origem, vértice de destino e capacidade da aresta.
    Um exemplo se encontra no arquivo edmonds_karp_in.txt
    
    Saída:
    
    Primeiro, mostra-se a lista de adjacência do grafo. 
    Em seguida, o valor do fluxo máximo entre o vértice fonte e o vértice sumidouro.
    Um exemplo se encontra no arquivo edmonds_karp_out.txt
    
Ordenação topológica

    Khan
    
    O algoritmo foi implementado em C, por default, o tamanho máximo do grafo está setado para 10000 vértices.
    Para entradas maiores, deverá ser alterada a variável global MAX_SIZE e recompilar o código
    
    Entrada:
    
    Uma sequência de m linhas contendo vértice de origem, vértice de destino de uma aresta.
    Um exemplo se encontra no arquivo khan_in.txt
    
    Saída:
    
    Uma linha com a ordem em que o grafo deve ser percorrido
    Um exemplo se encontra no arquivo khan_in.txt
    
Caminho Mínimo

    Dijkstra
    
    O algoritmo foi implementado em C++
    
    Entrada:
    
    A primeira linha da entrada recebe o número de vértices (n) e o número de arestas (m)
    Em seguida, m linhas, cada uma contendo: vértice de origem, vértice de destino e capacidade da aresta.
    Um exemplo se encontra no arquivo dijkstra_in.txt

    Saída:
    
    Primeiro, mostra-se a lista de adjacência do grafo. 
    Em seguida, a distância mínima entre cada vértice e a fonte.
    Depois a lista dos "pais" de cada vértice, para formar o menor caminho
    Um exemplo se encontra no arquivo dijkstra_out.txt

    
Árvore Geradora Minima

    Kruskal
    
    O algoritmo foi implementado em C++
    
    Entrada:
    
    A primeira linha da entrada recebe o número de vértices (n) e o número de arestas (m)
    Em seguida m linhas, cada uma contendo: vértice de origem, vértice de destino e capacidade da aresta.
    Um exemplo se encontra no arquivo kruskal_in.txt
    
    Saída:
    
    Primeiro, mostra-se a lista de adjacência do grafo. 
    Em seguida, o custo da árvore geradora mínima
    Depois as arestas que formam a árvore geradora mínima
    Um exemplo se encontra no arquivo kruskal_out.txt
    
