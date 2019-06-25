*TRABALHO DE SISTEMAS OPERACIONAIS 2019*
---

Foram utilizados 3 métodos(Gauss-Legendre, Monte Carlos, Borwein) para o cáculo de pi, utilizando programação sequencial e paralela nos 3 metódos.
Um modelo de BlackScholes utilizando o algoritmo de Monte Carlo foi implementado.
Foi utilizado a biblioteca GMP para trabalhar com BigNumbers e obter maior precisão.
Para o método paralelo foi utilizada a biblioteca #include <pthread.h>

---

*à quesito de compilação*
Para compilação no linux, foi utilizada tais comandos. 
 gcc nome_programa.c -o nome_programa -lm -lgmp -lpthread
 
 *à quesito de disposição de códigos*
 Cada pasta representa um método:
 - BS (BlasckScholes)
 - BW (Borwein)
 - GL (Gauss-Legendre)
 - MC (Monte Carlo)
 
 Dentro das pastas há duas pastas (sequencial e paralelo), no GL possui implementação dem a utilização dos BigNumbers, 
 mas para a avaliação considerar a versão com BigNumber.
