# Aula - 09/11/201

* Aula de explicação do conteúdo de sistemas de arquivos;

## RAID 1 e RAID 5

* O que é ?
    * "Conjunto redundante de discos que visa obter vantagens na utilização de subsistemas de dois ou mais discos". Infortrend Brasil

* RAID 1
    * Neste RAID é realizado o espelhamento entre os discos
    * Características:
        * Necessário mínimo dois discos;
        * Boa performance, por não possuir paridade nem divide os dados;
        * Boa redundância.
* RAID 5
    * Divide as informações entre os HDs, e no último tem-se os bits de paridade.
    * Características:
        * Mínimo três HDs;
        * Boa redundância;
        * Boa performance.

### Exercícios

* <code>7</code> - O que é alocação contígua de blocos e quais benefícios a desfragmentação pode proporcionar quando esta técnica é utilizada ? 

R: A alocação contígua de blocos consiste na alocação do arquivo em um bloco contíguo de memória.

Nesta alocação, apenas o primeiro endereço do bloco é referênciado, assim o disco pode ser visto como um grande vetor.

Os segmentos são divididos em espaços livres e alocados, onde para fazer novas definições será necessário 

* <code>10</code> - O que é a técnica denominada buffer cache ?

R: Vamos entender como funciona primeiro o cache e o buffer.

- Cache: Faz armazenamento temporário de informações;
- Buffer: Espaço de memória para alocação temporário de fluxos.

Sendo assim o buffer cache é uma tecnica que é implementada por alguns sistemas operacionais, nele as informações dos arquivos envolvidos nas operações recentes ficam armazenados para que nas próximas operações o processador não volte até o disco secundário. Isso logicamente se a informação necessária está no buffer cache.

### chmod - Alteração de permissões no linux

0 == --- == no access
1 == --x == execute
2 == -w- == write
3 == -wx == write / execute
4 == r-- == read
5 == r-x == read / execute
6 == rw- == read / write
7 == rwx == read / write / execute