# Atividade Pratica

## Prática de programação em C

- Programa que simula esquema de votação de urna eletrônica simplificada
- Contabiliza e exibe porcentagens de votos de cada candidato e voto nulo em ordem decrescente de votos

A cada iteração do usuário é solicitado novo voto com opção para exibir placar atual de votos.

As disputas para uma eleição de prefeitos e vereadores em uma cidade estavam muito acirradas, foi então que a imprensa local lançou a ideia de criar algumas urnas de pesquisa pela cidade para fazer uma pesquisa eleitoral sobre o panorama da votação. Você como funcionário de TI da imprensa responsável pela ideia foi designado para fazer um programa eleitoral em C para simular uma votação.

Os vereadores que serão pesquisados são:

| Número  |  Nome do Candidato |
| --- | --- |
| 111 | Vereador Joao do Frete|
| 222 | Vereador Maria da Pamonha|
| 333 | Vereador Ze da Farmacia|
| 444 | Voto Nulo|

Para prefeito:

| Número  |  Nome do Candidato |
| --- | --- |
|11|Prefeito Dr. Zureta|
|22|Prefeito Senhor Gomes|
|44|Voto Nulo|
     

O programa deve apresentar um menu com 3 opções, são elas:

| Opções|Ação|
| --- | --- |
|    1 |	Votar|
|    2 |	Apuração dos votos|
|    3 | Sair|

- Na opção 1, os candidatos devem ser votados através do número, se o número digitado estiver fora dos números apontados, este voto deve ser invalidado.
- Na opcao 2, será mostrado a soma de todos os votos computados
- Na opcao 3, o programa se encerrará