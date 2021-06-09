/*
 * =====================================================================================
 *
 *       Filename:  AtividadeDeEstudo1.c
 *
 *    Description:  Atividade de Estudo 1 Algorítmos e Lógica de Programação II
 *
 *        Version:  1.0
 *        Created:  24/05/2021
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Bruno Franco (brnfra), devlabbr@gmail.com
 *   Organization:   *
 * =====================================================================================
 */
/* PREPROCESSOR DEFINITIONS {{{*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
/* }}} */
/*     Constants   {{{    */

#define EXIT_SUCCESS 0

#define NVEREADORES 3
#define NPREFEITOS 2
#define V_JOAO_DO_FRETE 111
#define V_MARIA_DA_PAMONHA 222
#define V_ZE_DA_FARMACIA 333
#define V_NULO 444
#define P_DR_ZURETA 11
#define P_SENHOR_GOMES 22
#define P_NULO 44
#define VOTAR 1
#define APURACAO 2
#define SAIR 3
/*}}}*/
/*      Procedures {{{*/
/*            Limpa tela{{{  */
void clrscr()
{
    system("@cls||clear");
}
/*}}}*/
/* Limpa carriage return{{{ */
void clear()
{
    while ( getchar() != '\n' );
}
/* }}} */
/*      Vereadores{{{*/
void Vereadores() {
    printf("\n%s\n", "Digite o número correspondente ao candidato a Vereador(a);");
    printf("\n\t%s", "Vote 111 votar em Joao do Frete para vereador(a)");
    printf("\n\t%s", "Vote 222 votar em Maria da Pamonha para vereador(a)");
    printf("\n\t%s", "Vote 333 votar em Ze da Farmacia para vereador(a)es");
    printf("\n\t%s", "Vote 444 votar NULO");
    printf("\n\n%s","Seu voto: ");
}
/*}}}*/
/*      Prefeitos{{{*/
void Prefeitos() {
    printf("\n%s\n", "Digite o número correspondente ao candidato a Prefeito(a);");
    printf("\n\t%s", "Vote 11 para votar em Dr. Zureta para Prefeito(a)");
    printf("\n\t%s", "Vote 22 para votar em Senhor Gomes para Prefeito(a)");
    printf("\n\t%s", "Vote 44 para votar NULO");
    printf("\n\n%s","Seu voto: ");

}
/*}}}*/
/*      Opções{{{*/
void Opcoes() {
    printf("\n%s\n", "Bem vindo a eleição para Prefeito(a) e Vereador(a) da cidade;");
    printf("\n\t%s", "1 - Para VOTAR digite");
    printf("\n\t%s", "2 - Para ver a APURAÇÃO atual dos votos digite");
    printf("\n\t%s", "3 - Para SAIR digite");
    printf("\n\n%s","Escolha-");
}
/*}}}*/
/*      Apuração {{{*/
void Apuracao(int nCandidato, int nVotosCandidato, int totalVotos) {

    switch (nCandidato)
    {
        case P_DR_ZURETA:
            //prefeito(a);
            if ((nCandidato > 0) && (nVotosCandidato > 0) && (totalVotos > 0)) {
                printf("\n\n%-50s%-3.1f%s", "Dr. Zureta: ", ((float)nVotosCandidato / totalVotos) * 100, "\%");
                printf("\n%-50s%d%s","",  nVotosCandidato, " votos");
            }
            else {
                printf("\n\n%-50s%s", "Dr. Zureta: ","0\%");
                printf("\n%-50s%d%s","",  nVotosCandidato, " votos");
            }

            break;
        case P_SENHOR_GOMES:
            //prefeito(a);
            if ((nCandidato > 0) && (nVotosCandidato > 0) && (totalVotos > 0)) {
                printf("\n\n%-50s%-3.1f%s", "Sr. Gomes: ", ((float)nVotosCandidato / totalVotos) * 100, "\%");
                printf("\n%-50s%d%s","",  nVotosCandidato, " votos");
            }
            else {
                printf("\n\n%-50s%s", "Sr. Gomes: ", "0\% ");
                printf("\n%-50s%d%s","",  nVotosCandidato, " votos");
            }

            break;
        case P_NULO:
            //prefeito(a) nulo;
            if ((nCandidato > 0) && (nVotosCandidato > 0) && (totalVotos > 0)) {
                printf("\n\n%-50s%-3.1f%s", "Votos NULOS: ", ((float)nVotosCandidato / totalVotos) * 100, "\%");
                printf("\n%-50s%d%s","",  nVotosCandidato, " votos");

            }
            else {
                printf("\n\n%-50s%s", "Votos NULOS prefeito: ", "0\%");
                printf("\n%-50s%d%s","",  nVotosCandidato, " votos");
            }

            break;
        case V_JOAO_DO_FRETE:
            //vereador(a);
            if ((nCandidato > 0) && (nVotosCandidato > 0) && (totalVotos > 0)) {
                printf("\n\n%-50s%-3.1f%s", "Joao do Frete: ", ((float)nVotosCandidato / totalVotos) * 100, "\%");
                printf("\n%-50s%d%s","",  nVotosCandidato, " votos");
            }
            else {
                printf("\n\n%-50s%s", "Joao do Frete: ", "0\%");
                printf("\n%-50s%d%s","",  nVotosCandidato, " votos");
            }

            break;
        case V_MARIA_DA_PAMONHA:
            //vereador(a);
            if ((nCandidato > 0) && (nVotosCandidato > 0) && (totalVotos > 0)) {
                printf("\n\n%-50s%-3.1f%s", "Maria da Pamonha: ",((float)nVotosCandidato / totalVotos) * 100, "\%");
                printf("\n%-50s%d%s","",  nVotosCandidato, " votos");
            }
            else {
                printf("\n\n%-50s%s", "Maria da Pamonha: ", "0\%");
                printf("\n%-50s%d%s", "", nVotosCandidato, " votos ");
            }
            break;
        case V_ZE_DA_FARMACIA:        
            // vereador(a);
            if ((nCandidato > 0) && (nVotosCandidato > 0) && (totalVotos > 0)) {
                printf("\n\n%-50s%-3.1f%s", "Ze da Farmacia: ",((float)nVotosCandidato / totalVotos) * 100, "\%");
                printf("\n%-50s%d%s","",  nVotosCandidato, " votos");
            }
            else {
                printf("\n\n%-52s%s", "Zé da Farmácia: ", "0\%");
                printf("\n%-50s%d%s", "", nVotosCandidato, " votos");
            }
            break;
        case V_NULO:
            //vereador(a) nulo;
            if ((nCandidato > 0) && (nVotosCandidato > 0) && (totalVotos > 0)) {
                printf("\n\n%-50s%-3.1f%s", "Votos NULOS: ",((float)nVotosCandidato / totalVotos) * 100, "\%");
                printf("\n%-50s%d%s","",  nVotosCandidato, " votos");

            }
            else {
                printf("\n\n%-50s%s", "Votos NULOS vereador: ","0\%");
                printf("\n%-50s%d%s", "", nVotosCandidato, " votos");
            }
            break;

    }
}
//}}}

/*}}}*/


int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    int nVotosP = 0, nVotosV = 0, candidato = 0, opcao = 0, temp = 0, i = 0, j = 0;
    int vJFrete = 0, vMPamonha = 0, vZFarmacia = 0, pZureta = 0, pSGomes = 0, vNULO = 0, pNULO = 0;
    // pause var
    char hangOn[1];
    // voto candidaros + 1 voto nulo.  para ordenação na exibição
    int ver[NVEREADORES + 1];
    int auxV[NVEREADORES + 1];
    int pre[NPREFEITOS + 1];
    int auxP[NPREFEITOS + 1];
    for (i = 0; i <= NVEREADORES; i++) {
        auxV[i] = 0;
    }
    for (i = 0; i <= NPREFEITOS; i++) {
        auxP[i] = 0;
    }
    //restart
    i = 0;
    j = 0;
    do {
        clrscr();
        Opcoes();
        /*aux var buff created, get opcao var from stdin*/
        scanf( "%d" , &opcao);/*validate and check*/

        fflush(stdin);

        switch (opcao)
        {
           /*Case 1- Votar{{{*/
            case 1:
                clrscr();
                //opcao1 VOTAR;
                Vereadores();
                scanf("%d",&candidato);
                fflush(stdin);
                switch (candidato)
                {
                    case V_JOAO_DO_FRETE: 
                        vJFrete++;
                        nVotosV++;
                    break;
                    case V_ZE_DA_FARMACIA: 
                        vZFarmacia++;
                        nVotosV++;
                    break;
                    case V_MARIA_DA_PAMONHA: 
                        vMPamonha++;
                        nVotosV++;
                    break;
                    case V_NULO:
                        vNULO++;
                        nVotosV++;
                    break;
                }
                //limpa
                clrscr();
                //critica a entrada invalida
                if(candidato != V_NULO && candidato != V_JOAO_DO_FRETE && candidato != V_ZE_DA_FARMACIA && candidato != V_MARIA_DA_PAMONHA) {
                    printf("\nVoto para Vereador Inválido\n");
                }
                    candidato = 0;
                    Prefeitos();
                    scanf("%d",&candidato);
                    fflush(stdin);
                    clear();
                switch (candidato)
                    {
                case P_DR_ZURETA: 
                    pZureta++;
                    nVotosP++;
                    break;
                case P_SENHOR_GOMES: 
                    pSGomes++;
                    nVotosP++;
                    break;
                case P_NULO: 
                    pNULO++;
                    nVotosP++;
                    break;
                }
                               
                clrscr();
                if(candidato != P_NULO && candidato != P_DR_ZURETA && candidato != P_SENHOR_GOMES) {
                    printf("\nVoto para Prefeito Inválido\n");
                    scanf("%1[^\n]s", hangOn);

                }

                //encerra votacao
                candidato = 0;
                opcao=0;
                break;
                /*}}}*/
                /*Case 2- Parcial dos votos{{{*/
            case 2:
                clrscr();
                printf("%s", "\n##########################   PREFEITO   ##########################\n");
                printf("\n%-50s%s", "Nome", "Quantidade de");
                printf("\n%-50s%s\n", "do Candidato", "Votos recebidos");

                //PREFEITO
                //cod dos prefeitos
                pre[0] = P_DR_ZURETA;
                pre[1] = P_SENHOR_GOMES;
                pre[2] = P_NULO;
                //votos recebidos
                auxP[0] = pZureta;
                auxP[1] = pSGomes;
                auxP[2] = pNULO;
                // ordenar pelo num de votos crescente com indice

                for (j = NPREFEITOS; j >= 0; j--) {

                    for (i = 0; i <= NPREFEITOS; i++) {
                        if ((auxP[i] > auxP[j]) && (j > i)) {
                            temp = auxP[j];
                            auxP[j] = auxP[i];
                            auxP[i] = temp;

                            temp = pre[j];
                            pre[j] = pre[i];
                            pre[i] = temp;

                        }
                    }
                }
                //restart

                for (j = NPREFEITOS; j >= 0; j--) {
                    if (nVotosP > 0) {
                        Apuracao(pre[j], auxP[j], nVotosP);
                    }

                }
                //restart
                printf("\n\n%s\n", "\n\n##########################   VEREADOR   ##########################\n");
                printf("\n%-50s%s", "Nome", "Quantidade de");
                printf("\n%-50s%s\n", "do Candidato", "Votos recebidos");

                //VEREADOR
                ver[0] = V_JOAO_DO_FRETE;
                ver[1] = V_ZE_DA_FARMACIA;
                ver[2] = V_MARIA_DA_PAMONHA;
                ver[3] = V_NULO;
                auxV[0] = vJFrete;
                auxV[1] = vZFarmacia;
                auxV[2] = vMPamonha;
                auxV[3] = vNULO;
                // ordenar crescente com indice
                for (j = NVEREADORES; j >= 0; j--) {

                    for (i = 0; i <= NVEREADORES; i++) {
                        if ((auxV[i] > auxV[j]) && ( j > i)) {
                            temp = auxV[j];
                            auxV[j] = auxV[i];
                            auxV[i] = temp;

                            temp = ver[j];
                            ver[j] = ver[i];
                            ver[i] = temp;
                        }
                    }
                }
                //restart
                for (j = NVEREADORES; j >= 0; j--) {
                    if (nVotosV > 0) {
                        Apuracao(ver[j], auxV[j], nVotosV);
                    }
                }

                //encerra a exibicao da apuracao implementar limpa tela
                //restart
                clear();
                printf("\n\n%s","Pressione Enter para voltar ao menu.");
                scanf("%1[^\n]s", hangOn);

                opcao=0;
                break;
                /*}}}*/
                               /*Case 3 {{{*/
            case 3:
                //opcao3 SAIR;
                /*Encerramento   */
                //msg + pause
                printf("\n%s","Opção SAIR. Obrigado por votar.");
                scanf("%1[^\n]s", hangOn);
                return EXIT_SUCCESS;

                break;

        }
        /*}}}*/

    } while ((opcao != 1) && (opcao != 2) && (opcao != 3));

    return EXIT_SUCCESS;
}
