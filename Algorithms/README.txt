Arquivos base para implementação de uma biblioteca de 
vetor dinâmico em C. 
A biblioteca é definida nos arquivos 
`array_list_int.c` e `array_list_int.h`. 

É fornecido um arquivo de teste básico chamado `teste01.c`, 
que contém uma sequencia de inserções de números lidos da  
entrada padrão no vetor dinâmico. O programa mostra 
na saída de erro o tempo total necessário para inserir 
os elementos lidos da entrada padrão.

Para compilar o teste01:
  gcc -Wall -o teste01 teste01.c array_list_int.c

Para executar:
  ./teste01 < e1.txt

São fornecidos 5 arquivos de base para o programa de teste 
`teste01`: e1.txt, e2.txt, e3.txt , e4.txt e e5.txt. 
A primeira  linha de cada  arquivo contém um inteiro `n` 
com a quantidade  total de números do arquivo. 
A segunda linha  contém `n` números inteiros separados por um espaço.
Estes arquivos contém uma sequencia de números gerados de forma
aleatória através do programa `gen_array.c`. 

Para compilar o programa gen_array.c: 
  gcc -Wall -o gen_array gen_array.c

O programa `gen_array` recebe um valor inteiro `n`
como parâmetro e gera um arquivo com `n` números 
gerados de forma aleatória. Para gerar um arquivo 
com nome `meu_teste.txt`, com 1000 números inteiros:
  ./gen_array 1000 > meu_teste.txt 

O arquivo gerado `meu_teste.txt` terá 2 linhas, 
a primeira com o valor 1000 e a segunda com 
1000 valores inteiros gerados aleatoriamente. 
