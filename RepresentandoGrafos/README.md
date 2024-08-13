# Descrição da tarefa
Nessa tarefa iremos explorar a implementação de estruturas de dados para representação de grafos e seu uso para obtenção de informações sobre grau e vizinhança dos vértices.

Portanto, você deve implementar (na linguagem C++) um programa que receba duas informações do usuário: (i) o nome do arquivo contendo as informações/dados sobre um grafo direcionado; e (ii) o número de um dos vértices do grafo descrito no arquivo.

Seu programa deverá ler o conteúdo do arquivo e representar o grafo direcionado em memória utilizando uma das estruturas discutidas em nossas aulas. Depois disso, sua implementação deve utilizar a estrutura escolhida para produzir as seguintes informações para o vértice informado pelo usuário: (i) grau de saída; (ii) grau de entrada; (iii) conjunto de sucessores; e (iv) conjunto de predecessores. OBS.: É necessário produzir tais informações apenas para o vértice informado.

A escolha da estrutura faz parte da tarefa e deverá ser feita levando-se em conta o tipo do grafo (que é direcionado), o tamanho do grafo (que poderá ter centenas de milhares de vértices e dezenas de milhões de arestas) e as operações necessárias que serão realizadas sobre o mesmo (para se obter/calcular tanto o grau quanto a vizinhança de um vértice).

# Formato do arquivo contendo os dados do grafo
Seu programa deverá ler as informações sobre o grafo a partir de um arquivo texto. A primeira linha desse arquivo contém o número n de vértices seguido do número m de arestas. Você deve considerar que os vértices são numerados (rotulados) de 1 a n. Depois disso, o arquivo contém uma lista com as m arestas (sendo uma aresta por linha) em que cada aresta é representada pelos seus vértices de origem e de destino.

Abaixo, você pode observa um esquema que representa a estrutura que deve ser esperada do arquivo:

  n	  m
 <Origem da Aresta 1>	 <Destino da Aresta 1>
 <Origem da Aresta 2>	 <Destino da Aresta 2>
                 
             
 <Origem da Aresta m>	 <Destino da Aresta m>

### Resultado:
