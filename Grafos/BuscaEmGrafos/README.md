# Descrição da tarefa
Nessa tarefa iremos explorar a implementação de busca em grafos e seu uso para classificação de arestas.

Portanto, você deve implementar (na linguagem C, C++ ou Java) um programa que receba duas informações do usuário: (i) o nome do arquivo contendo as informações/dados sobre um grafo direcionado; e (ii) o número de um dos vértices do grafo descrito no arquivo.

Seu programa deverá realizar uma busca em profundidade (em ordem lexicográfica) no grafo direcionado fornecido, listando todas as arestas de árvore encontradas. Além disso, sua implementação deve classificar todas as arestas divergentes (que saem) do vértice escolhido pelo usuário. OBS.: É necessário produzir a classificação de todas as arestas apenas para o vértice informado.

# Formato do arquivo contendo os dados do grafo
Seu programa deverá ler as informações sobre o grafo a partir de um arquivo texto. A primeira linha desse arquivo contém o número n de vértices seguido do número m de arestas. Você deve considerar que os vértices são numerados (rotulados) de 1 a n. Depois disso, o arquivo contém uma lista com as m arestas (sendo uma aresta por linha) em que cada aresta é representada pelos seus vértices de origem e de destino.

Abaixo, você pode observa um esquema que representa a estrutura que deve ser esperada do arquivo:

  n	  m
 <Origem da Aresta 1>	 <Destino da Aresta 1>
 <Origem da Aresta 2>	 <Destino da Aresta 2>
                 
             
 <Origem da Aresta m>	 <Destino da Aresta m>