# ASA_Projeto2

Creates a Mximum Spanning Tree with Kruskal Algorithm & Compressed Weighted quick union


Gerador de grafos densos: dgg.c
Gera um grafo totalmente ligado, em que o vértice i liga a todos os vértices com índices superiores a i. O resultado correto que a vossa implementação deverá produzir para cada exemplo é igual a o número de arcos (segunda linha do ficheiro).
Compilação: gcc -O3 -Wall -o dgg dgg.c
Execução: ./dgg <número de vértices> > <nome ficheiro de teste>
<número de vértices>: substituir pelo número de vértices do grafo
<nome do ficheiro de teste>: substituir pelo nome do ficheiro de teste a gerar
Exemplo: ./dgg 10 > d10.txt

Gerador de grafos realistas: delaunator.hpp e delaunay2graph.cpp
Gera um grafo a partir da triangulação de Delaunay, com alguns parâmetros aleatórios
Compilação: g++ -std=c++11 -O3 -o d2g delaunay2graph.cpp -lm
Execução: ./d2g <número de vértices> <coordenada máxima> <probabilidade> <semente> > <nome ficheiro de teste>
<número de vértices>: substituir pelo número de vértices do grafo |V|
<coordenada máxima>: substituir por M, coordenada máxima (M,M), onde M >= |V|
<probabilidade>: substituir pela probabilidade para criar o novo grafo
<semente>: substituir pela semente aleatória (opcional)
Exemplo: ./d2g 10 100 0.8 15 > v10.txt
