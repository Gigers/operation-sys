# Aula - 13/11/2017

<!-- Criar três vms e realizar a sincronização entre elas-->

## Exercícios sobre sistemas de arquivos

- <code>3</code> - Diferencie os métodos de acesso a registros sequencial, direto e indexado
R: A recuperação dos arquivos pode variar de acordo com a organização dos arquivos, e existem alguns métodos para fazer os acessos.
- Sequencial:
    - Na recuperação sequêncial os arquivos serão lidos na ordem em que foram gravados, e todo novo arquivo será escrito na última posição. Seu grande problema é o desempenho, exatamente por conta de ter que percorrer todos os arquivos para realizar um novo registro
- Direto:
    - No registro direto é utilizado ponteiros e acesso direto. Os ponteiros servem para que um arquivo seja acessado diretamente. E então desse o acesso sequencial pode ser feito para chegar a outros arquivos.
- Indexado:
    - A indexação é uma forma sofisticada de acessar os arquivos, nele o arquivo deve conter uma área para guardar registros de ponteiros. Assim toda vez que a aplicação for acessar algum arquivo deverá ser fornecido uma chave, a qual será utilizada. 

- <code>4</code> - Qual a função das system calls de E/S ?
R: A system call de E/S pode ser entendida como uma interface entre a aplicação e o hardware, esta torna este tipo de operação menos complexo, encapsulando as maiores dificuldades.

- <code>5</code> - Quais as diferentes formas de implementação de uma estrutura de diretório ? 
R: Existem diversas formas de aplicação da estrutura de diretórios
- Single-level directory
    - Todos os arquivos ficam em um único diretório. Seu grande problema é a limitação que ele traz, onde não poderão existir nomes de arquivos iguais.
- User File Directory (UDF)
    - Cada usuário tem se diretório, o que resolveu o problema de conflitos, onde, não era mais necessário saber o nome de todos os arquivos do sistema, já que os aruqivos criados pelos usuários estariam dentro de diretórios separados
    - Utiliza o Master File Directory (MFD) para trabalhar, este que faz referência a um diretório raiz onde todos os demais de usuário são gravados.
- Árvore
    -   Com a implementação do MFD, foi possível criar uma estrutura conhecida como árvore, onde existem vários níveis de diretórios;
    -   Esta é uma implementação bastante utilizada nos sistemas atuais;
    -   Existem subníveis de diretórios.

- <code>6</code> - Descreva as vantagens e desvantagens das técnicas para gerência de espaços livres ?
R: Para que o sistema saiba onde pode ser armazenados informações, é necessário ele saber quais espaços estão ocupados. Para isso existem várias técnicas, são elas:
-   Bit Map:
    - Cada bloco do disco é registrado em uma tabela, quando há arquivos o bloco referente a aquele espaço é preenchido com bit 1.
    - Pode ser implementado através de lista encadeada
        - Problemas: Terá de haver um espaço no arquivo para salvar o registro do próximo endereço.
            - A lista terá de ser percorrida de forma sequêncial
-   Tabela de bloco livre:
    - Esta é uma técnica que leva em consideração que blocos contigos são liberados simultaneamente;
    - Com essa consideração é possível visualizar o disco como um segmento de blocos livres;
    - Desta forma é possível manter uma tabela com o primeiro endereço do bloco alocado e o número de blocos livres contíguos.