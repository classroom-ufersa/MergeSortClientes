# Ordenação de clientes com Merge Sort

## Súmario
<div>
  <ul>
    <li><a href="#sobre-o-algoritmo">Sobre o algoritmo</a></li>
    <li><a href="#como-funciona-o-merge-sort">Como funciona o Merge Sort?</a></li>
    <li><a href="#implementacao">Implementação</a></li>
    <li><a href="#complexidade">Complexidade</a></li>
    <li><a href="#referencia">Referência</a></li>
    <li><a href="#colaboradores">Colaboradores</a></li>
  </ul>
</div>

## Sobre o algoritmo

<p></p>

## Como funciona o Merge Sort?

<p> Merge sort é um algoritmo recursivo que divide continuamente o array ao meio até que ele não possa ser dividido, a matriz tem apenas um elemento à esquerda (uma matriz com um elemento é sempre classificada). Em seguida, os subarrays classificados são mesclados em um array classificado.</p>

<p align="center">
  <img src="https://upload.wikimedia.org/wikipedia/commons/c/cc/Merge-sort-example-300px.gif" alt="Sobre Merge Sort GIF" width="720" height="480">
  <br>
  <a href="https://en.m.wikipedia.org/wiki/File:Merge-sort-example-300px.gif">Referência do gif</a>
</p>

## Implementação

<p>
Primeiro ele recebe um array de clientes e três índices que delimitam as partes a serem mescladas. Ela calcula os tamanhos dos subarrays e cria dois arrays temporários para armazenar esses subarrays. Em seguida, copia os elementos relevantes do array original para esses arrays temporários. Depois, mescla os arrays temporários de volta ao array original, garantindo que os elementos estejam em ordem crescente com base em um campo específico (neste caso, codigo_de_cliente). Por fim, quaisquer elementos restantes nos arrays temporários são copiados de volta para o array original, completando assim o processo de mesclagem e ordenação dos dados.
</p>

```
void merge(clientes *usuarios, int esquerda, int meio, int direita)
{
    int i, j, k; 
    int tamanho_esquerda = meio - esquerda + 1;   //Armazenam o tamanho do subarray Esquerda
    int tamanho_direita = direita - meio;         //Armazenam o tamanho do subarray Direita

    clientes Esquerda[tamanho_esquerda], Direita[tamanho_direita];

    for (i = 0; i < tamanho_esquerda; i++)
        Esquerda[i] = usuarios[esquerda + i];
    for (j = 0; j < tamanho_direita; j++)
        Direita[j] = usuarios[meio + 1 + j];

    i = 0;
    j = 0;
    k = esquerda;

    while (i < tamanho_esquerda && j < tamanho_direita)
    {
        if (Esquerda[i].codigo_de_cliente <= Direita[j].codigo_de_cliente)
        {
            usuarios[k] = Esquerda[i];
            i++;
        }
        else
        {
            usuarios[k] = Direita[j];
            j++;
        }
        k++;
    }

    while (i < tamanho_esquerda)
    {
        usuarios[k] = Esquerda[i];
        i++;
        k++;
    }

    while (j < tamanho_direita)
    {
        usuarios[k] = Direita[j];
        j++;
        k++;
    }
}
```

<p>
Primeiro ele divide o array em metades menores, ordena essas metades recursivamente e depois combina as partes ordenadas para obter o array completamente ordenado. A condição de parada verifica se o subarray tem mais de um elemento, evitando chamadas recursivas desnecessárias. A função divide o problema em subproblemas menores, conquistando cada subproblema individualmente e depois combinando as soluções para obter a solução do problema original.
</p>


```
void mergeSort(clientes *usuarios, int esquerda, int direita)
{
    if (esquerda < direita)
    {
        int meio = esquerda + (direita - esquerda) / 2;

        mergeSort(usuarios, esquerda, meio);
        mergeSort(usuarios, meio + 1, direita);

        merge(usuarios, esquerda, meio, direita);
    }
}
```

## Complexidade

> Complexidade de tempo: **O(n*Log n)** em todos os 3 casos (pior, médio e melhor), pois o merge sort sempre divide a matriz em duas metades e leva tempo linear para mesclar as duas metades.

> Complexidade de espaço: **O(n)**


## Referência
<div>
  <ul>
    <li><a href="https://www.geeksforgeeks.org/merge-sort/">Referência do Algoritmo</a></li>
    <li><a href="https://www.geeksforgeeks.org/time-and-space-complexity-analysis-of-merge-sort/">Complexidade do Algoritmo</a></li>
</div>

## Colaboradores
<div>
  <ul>
    <li><a href="https://github.com/thyagofab" >@thyagofab👾</a></li>
    <li><a href="https://github.com/marcelohenrique0" >@marcelohenrique0🤓</a></li>
    <li><a href="https://github.com/AntonioErick" >@AntonioErick🤠</a></li>
    <li><a href="https://github.com/babias059" >@babias059🌷</a></li>
  </ul>
</div>
