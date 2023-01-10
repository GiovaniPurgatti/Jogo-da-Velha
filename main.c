#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>



enum menu{
    MENU_PVP = 1,
    MENU_IA,
    MENU_SAIR,
};

int menu(){
    printf("\n*1 - Player vs Player\n");
    printf("*2 - Contra a máquina\n");
    printf("*3 - Sair\n \n");
    return 0;
}

int main() {
    char matriz[3][3];
    int i, j, flag = 0, ant = 0, antI=0,antJ=0;
    char playerOne[20], playerTwo[20];
    char jogaNovamente;

    int opcao, opcaoIA, aux;
    int running = 1;


    while (1) {


        menu();

        printf("A opcao desejada: ");
        scanf("%i", &opcao);


        switch (opcao) {

            do {
                flag = 0;
                case MENU_PVP:

                    printf("Nome do primeiro jogador: \n");
                scanf("%s", playerOne);

                printf("Nome do segundo jogador: \n");
                scanf("%s", playerTwo);

                printf("   1  2  3");
                printf("\n");
                for (i = 1; i < 4; i++) {
                    printf("%d ", i);
                    for (j = 1; j < 4; j++) {
                        matriz[i][j] = ' ';
                        printf("[%c]", matriz[i][j]);

                    }
                    printf("\n");
                }
                printf("Use o formato 'linha,coluna' para definir o local da jogada"
                       "\nexemplo: 2,2 \n");


                while (flag < 9) {

                    if (flag == 0 || flag == 2 || flag == 4 || flag == 6 || flag == 8) {
                        printf("Vez de %s", playerOne);
                    }
                    if (flag == 1 || flag == 3 || flag == 5 || flag == 7) {
                        printf("Vez de %s", playerTwo);
                    }
                    printf("\n");
                    for (i = 1; i < 4; i++) {
                        for (j = 1; j < 4; j++) {
                            printf("Digite onde quer fazer sua jogada: ");
                            scanf("%d, %d", &i, &j);
                            if (matriz[i][j] == ' ' && i <= 3 && j <= 3) {
                                if (flag == 0) {
                                    printf("'X' OU 'O': ");
                                    scanf(" %c", &matriz[i][j]);
                                    if (matriz[i][j] == 'x') {
                                        ant = 1;
                                    } else {
                                        ant = 2;
                                    }
                                }
                                if (ant == 1) {
                                    if (flag == 1 || flag == 3 || flag == 5 || flag == 7) {
                                        matriz[i][j] = 'o';
                                    }
                                    if (flag == 2 || flag == 4 || flag == 6 || flag == 8) {
                                        matriz[i][j] = 'x';
                                    }
                                }
                                if (ant == 2) {
                                    if (flag == 1 || flag == 3 || flag == 5 || flag == 7) {
                                        matriz[i][j] = 'x';
                                    }
                                    if (flag == 2 || flag == 4 || flag == 6 || flag == 8) {
                                        matriz[i][j] = 'o';
                                    }
                                }
                            } else {
                                printf("Posicao invalida, selecione outra.\n");
                                continue;
                            }
#ifdef __WIN32
                            system("cls");
#elif __linux__
                            system("clear");
#endif
                            printf("\n");
                            printf("   1  2  3");
                            printf("\n");

                            for (i = 1; i < 4; i++) {
                                printf("%d ", i);
                                for (j = 1; j < 4; j++) {

                                    printf("[%c]", toupper(matriz[i][j]));

                                }
                                printf("\n");
                            }
                            //LOGICA DA LETRA X
                            if (matriz[1][1] == 'x' && matriz[1][2] == 'x' && matriz[1][3] == 'x') {
                                printf("Ganhou na linha 1");
                                flag += 9;
                            }
                            if (matriz[2][1] == 'x' && matriz[2][2] == 'x' && matriz[2][3] == 'x') {
                                printf("Ganhou na linha 2");
                                flag += 9;
                            }
                            if (matriz[3][1] == 'x' && matriz[3][2] == 'x' && matriz[3][3] == 'x') {
                                printf("Ganhou na linha 3");
                                flag += 9;
                            }
                            if (matriz[1][1] == 'x' && matriz[2][1] == 'x' && matriz[3][1] == 'x') {
                                printf("Ganhou na coluna 1");
                                flag += 9;
                            }
                            if (matriz[1][2] == 'x' && matriz[2][2] == 'x' && matriz[3][2] == 'x') {
                                printf("Ganhou na coluna 2");
                                flag += 9;
                            }
                            if (matriz[1][3] == 'x' && matriz[2][3] == 'x' && matriz[3][3] == 'x') {
                                printf("Ganhou na coluna 3");
                                flag += 9;
                            }
                            if (matriz[1][1] == 'x' && matriz[2][2] == 'x' && matriz[3][3] == 'x') {
                                printf("Ganhou na diagonal 1");
                                flag += 9;
                            }
                            if (matriz[1][3] == 'x' && matriz[2][2] == 'x' && matriz[3][1] == 'x') {
                                printf("Ganhou na diagonal 2");
                                flag += 9;
                            }

                            //LOGICA DA LETRA O

                            if (matriz[1][1] == 'o' && matriz[1][2] == 'o' && matriz[1][3] == 'o') {
                                printf("Ganhou na linha 1");
                                flag += 9;
                            }
                            if (matriz[2][1] == 'o' && matriz[2][2] == 'o' && matriz[2][3] == 'o') {
                                printf("Ganhou na linha 2");
                                flag += 9;
                            }
                            if (matriz[3][1] == 'o' && matriz[3][2] == 'o' && matriz[3][3] == 'o') {
                                printf("Ganhou na linha 3");
                                flag += 9;
                            }
                            if (matriz[1][1] == 'o' && matriz[2][1] == 'o' && matriz[3][1] == 'o') {
                                printf("Ganhou na coluna 1");
                                flag += 9;
                            }
                            if (matriz[1][2] == 'o' && matriz[2][2] == 'o' && matriz[3][2] == 'o') {
                                printf("Ganhou na coluna 2");
                                flag += 9;
                            }
                            if (matriz[1][3] == 'o' && matriz[2][3] == 'o' && matriz[3][3] == 'o') {
                                printf("Ganhou na coluna 3");
                                flag += 9;
                            }
                            if (matriz[1][1] == 'o' && matriz[2][2] == 'o' && matriz[3][3] == 'o') {
                                printf("Ganhou na diagonal 1");
                                flag += 9;
                            }
                            if (matriz[1][3] == 'o' && matriz[2][2] == 'o' && matriz[3][1] == 'o') {
                                printf("Ganhou na diagonal 2");
                                flag += 9;
                            }


                        }
                        printf("\n");
                        flag += 1;
                    }
                }
                if (flag == 9) {
                    printf("Deu velha\n");
                }
                printf("Deseja jogar novamente? (s/n)\n");
                scanf("%s", &jogaNovamente);
                if (jogaNovamente == 's') {
                    continue;
                } else {
                    printf("Saindo...");
                }

            } while (jogaNovamente == 's');

            return 0;

            do {
                flag = 0;
                case MENU_IA:

                    printf("Nome do primeiro jogador: \n");
                scanf("%s", playerTwo);

                printf("   1  2  3");
                printf("\n");
                for (i = 1; i < 4; i++) {
                    printf("%d ", i);
                    for (j = 1; j < 4; j++) {
                        matriz[i][j] = ' ';
                        printf("[%c]", matriz[i][j]);

                    }
                    printf("\n");
                }
                printf("Use o formato 'linha,coluna' para definir o local da jogada"
                       "\nexemplo: 2,2 \n");


                while (flag < 9) {

                    printf("\n");

                    if (flag == 0 || flag == 2 || flag == 4 || flag == 6 || flag == 8) {
                        printf("Vez de %s\n", playerTwo);


                        printf("Digite onde quer fazer sua jogada: ");
                        scanf("%d, %d", &i, &j);

                        if (matriz[i][j] == ' ' && i <= 3 && j <= 3) {
                            matriz[i][j] = 'x';
                        } else {
                            printf("Posicao invalida, selecione outra.\n");
                            continue;
                        }
                    }
                    aux =0;
                    if (flag == 1 || flag == 3 || flag == 5 || flag == 7) {
                       do{

                           //===============vitoria IA===================//
                           //===============linha 1======================//
                           if (matriz[1][1] == 'o' && matriz[1][2] == 'o' && matriz[1][3] == ' '){
                               matriz[1][3] = 'o';
                               aux =1;
                               break;
                           }
                           if (matriz[1][3] == 'o' && matriz[1][2] == 'o' &&  matriz[1][1] == ' '){
                               matriz[1][1] = 'o';
                               aux =1;
                               break;
                           }
                           if (matriz[1][1] == 'o' && matriz[1][3] == 'o' &&  matriz[1][2] == ' '){
                               matriz[1][2] = 'o';
                               aux =1;
                               break;
                           }
                           //================linha2=======================//
                           if (matriz[2][1] == 'o' && matriz[2][2] == 'o' &&  matriz[2][3] == ' ') {
                               matriz[2][3] = 'o';
                               aux =1;
                               break;
                           }
                           if (matriz[2][3] == 'o' && matriz[2][2] == 'o' &&  matriz[2][1] == ' ') {
                               matriz[2][1] = 'o';
                               aux =1;
                               break;
                           }
                           if (matriz[2][1] == 'o' && matriz[2][3] == 'o' &&  matriz[2][2] == ' ') {
                               matriz[2][2] = 'o';
                               aux =1;
                               break;
                           }
                           //================linha3=======================//
                           if (matriz[3][1] == 'o' && matriz[3][2] == 'o' &&  matriz[3][3] == ' '){
                               matriz[3][3] = 'o';
                               aux =1;
                               break;
                           }
                           if (matriz[3][3] == 'o' && matriz[3][2] == 'o' &&  matriz[3][1] == ' '){
                               matriz[3][1] = 'o';
                               aux =1;
                               break;
                           }
                           if (matriz[3][1] == 'o' && matriz[3][3] == 'o' &&  matriz[2][2] == ' '){
                               matriz[3][2] = 'o';
                               aux =1;
                               break;
                           }
                           //================coluna1=====================//
                           if (matriz[1][1] == 'o' && matriz[2][1] == 'o' &&  matriz[3][1] == ' '){
                               matriz[3][1] = 'o';
                               aux =1;
                               break;
                           }
                           if (matriz[3][1] == 'o' && matriz[2][1] == 'o' &&  matriz[1][1] == ' '){
                               matriz[1][1] = 'o';
                               aux =1;
                               break;
                           }
                           if (matriz[1][1] == 'o' && matriz[3][1] == 'o' &&  matriz[2][1] == ' '){
                               matriz[2][1] = 'o';
                               aux =1;
                               break;
                           }
                           //===============coluna2=======================//
                           if (matriz[1][2] == 'o' && matriz[2][2] == 'o' &&  matriz[3][2] == ' ') {
                               matriz[3][2] = 'o';
                               aux =1;
                               break;
                           }
                           if (matriz[3][2] == 'o' && matriz[2][2] == 'o' &&  matriz[1][2] == ' ') {
                               matriz[1][2] = 'o';
                               aux =1;
                               break;
                           }
                           if (matriz[1][2] == 'o' && matriz[3][2] == 'o' &&  matriz[2][2] == ' ') {
                               matriz[2][2] = 'o';
                               aux =1;
                               break;
                           }
                           //==============coluna3========================//
                           if (matriz[1][3] == 'o' && matriz[2][3] == 'o' &&  matriz[3][3] == ' '){
                               matriz[3][3] = 'o';
                               aux =1;
                               break;
                           }
                           if (matriz[3][3] == 'o' && matriz[2][3] == 'o' &&  matriz[1][3] == ' '){
                               matriz[1][3] = 'o';
                               aux =1;
                               break;
                           }
                           if (matriz[1][3] == 'o' && matriz[3][3] == 'o' &&  matriz[2][3] == ' '){
                               matriz[2][3] = 'o';
                               aux =1;
                               break;
                           }
                           //===============diagonal1=====================//
                           if (matriz[1][1] == 'o' && matriz[2][2] == 'o' &&  matriz[3][3] == ' ') {
                               matriz[3][3] = 'o';
                               aux =1;
                               break;
                           }
                           if (matriz[3][3] == 'o' && matriz[2][2] == 'o' &&  matriz[1][1] == ' ') {
                               matriz[1][1] = 'o';
                               aux =1;
                               break;
                           }
                           if (matriz[1][1] == 'o' && matriz[3][3] == 'o' &&  matriz[2][2] == ' ') {
                               matriz[2][2] = 'o';
                               aux =1;
                               break;
                           }
                           //==============diagonal2======================//
                           if (matriz[1][3] == 'o' && matriz[2][2] == 'o' &&  matriz[3][1] == ' ') {
                               matriz[3][1] = 'o';
                               aux =1;
                               break;
                           }
                           if (matriz[3][1] == 'o' && matriz[2][2] == 'o' &&  matriz[1][3] == ' ') {
                               matriz[1][3] = 'o';
                               aux =1;
                               break;
                           }
                           if (matriz[1][3] == 'o' && matriz[3][1] == 'o' &&  matriz[2][2] == ' ') {
                               matriz[2][2] = 'o';
                               aux =1;
                               break;
                           }
                           //============================================//
                           //===============velha========================//
                           //===============linha 1======================//
                           if (matriz[1][1] == 'x' && matriz[1][2] == 'x' && matriz[1][3] == ' '){
                               matriz[1][3] = 'o';
                               aux =1;
                               break;
                           }
                           if (matriz[1][3] == 'x' && matriz[1][2] == 'x' && matriz[1][1] == ' '){
                               matriz[1][1] = 'o';
                               aux =1;
                               break;
                           }
                           if (matriz[1][1] == 'x' && matriz[1][3] == 'x' && matriz[1][2] == ' '){
                               matriz[1][2] = 'o';
                               aux =1;
                               break;
                           }
                           //================linha2=======================//
                           if (matriz[2][1] == 'x' && matriz[2][2] == 'x' && matriz[2][3] == ' ') {
                               matriz[2][3] = 'o';
                               aux =1;
                               break;
                           }
                           if (matriz[2][3] == 'x' && matriz[2][2] == 'x' && matriz[2][1] == ' ') {
                               matriz[2][1] = 'o';
                               aux =1;
                               break;
                           }
                           if (matriz[2][1] == 'x' && matriz[2][3] == 'x' && matriz[2][2] == ' ') {
                               matriz[2][2] = 'o';
                               aux =1;
                               break;
                           }
                           //================linha3=======================//
                           if (matriz[3][1] == 'x' && matriz[3][2] == 'x' && matriz[3][3] == ' '){
                               matriz[3][3] = 'o';
                               aux =1;
                               break;
                           }
                           if (matriz[3][3] == 'x' && matriz[3][2] == 'x' && matriz[3][1] == ' '){
                               matriz[3][1] = 'o';
                               aux =1;
                               break;
                           }
                           if (matriz[3][1] == 'x' && matriz[3][3] == 'x' && matriz[3][2] == ' '){
                               matriz[3][2] = 'o';
                               aux =1;
                               break;
                           }
                           //================coluna1=====================//
                           if (matriz[1][1] == 'x' && matriz[2][1] == 'x' && matriz[3][1] == ' '){
                               matriz[3][1] = 'o';
                               aux =1;
                               break;
                           }
                           if (matriz[3][1] == 'x' && matriz[2][1] == 'x' && matriz[1][1] == ' '){
                               matriz[1][1] = 'o';
                               aux =1;
                               break;
                           }
                           if (matriz[1][1] == 'x' && matriz[3][1] == 'x' && matriz[2][1] == ' '){
                               matriz[2][1] = 'o';
                               aux =1;
                               break;
                           }
                           //===============coluna2=======================//
                           if (matriz[1][2] == 'x' && matriz[2][2] == 'x' && matriz[3][2] == ' ') {
                               matriz[3][2] = 'o';
                               aux =1;
                               break;
                           }
                           if (matriz[3][2] == 'x' && matriz[2][2] == 'x' && matriz[1][2] == ' ') {
                               matriz[1][2] = 'o';
                               aux =1;
                               break;
                           }
                           if (matriz[1][2] == 'x' && matriz[3][2] == 'x' && matriz[2][2] == ' ') {
                               matriz[2][2] = 'o';
                               aux =1;
                               break;
                           }
                           //==============coluna3========================//
                           if (matriz[1][3] == 'x' && matriz[2][3] == 'x' && matriz[3][3] == ' '){
                               matriz[3][3] = 'o';
                               aux =1;
                               break;
                           }
                           if (matriz[3][3] == 'x' && matriz[2][3] == 'x' && matriz[1][3] == ' '){
                               matriz[1][3] = 'o';
                               aux =1;
                               break;
                           }
                           if (matriz[1][3] == 'x' && matriz[3][3] == 'x' && matriz[2][3] == ' '){
                               matriz[2][3] = 'o';
                               aux =1;
                               break;
                           }
                           //===============diagonal1=====================//
                           if (matriz[1][1] == 'x' && matriz[2][2] == 'x' && matriz[3][3] == ' ') {
                               matriz[3][3] = 'o';
                               aux =1;
                               break;
                           }
                           if (matriz[3][3] == 'x' && matriz[2][2] == 'x' && matriz[1][1] == ' ') {
                               matriz[1][1] = 'o';
                               aux =1;
                               break;
                           }
                           if (matriz[1][1] == 'x' && matriz[3][3] == 'x' && matriz[2][2] == ' ') {
                               matriz[2][2] = 'o';
                               aux =1;
                               break;
                           }
                           //==============diagonal2======================//
                           if (matriz[1][3] == 'x' && matriz[2][2] == 'x' && matriz[3][1] == ' ') {
                               matriz[3][1] = 'o';
                               aux =1;
                               break;
                           }
                           if (matriz[3][1] == 'x' && matriz[2][2] == 'x' && matriz[1][3] == ' ') {
                               matriz[1][3] = 'o';
                               aux =1;
                               break;
                           }
                           if (matriz[1][3] == 'x' && matriz[3][1] == 'x' && matriz[2][2] == ' ') {
                               matriz[2][2] = 'o';
                               aux =1;
                               break;
                           }
                           //============================================//

                           if(aux ==0) {
                               srand((unsigned) time(NULL));
                               opcaoIA = 1 + rand() % 8;
                               switch (opcaoIA) {
                                   case 1:
                                       if (matriz[1][1] == ' ') {
                                           matriz[1][1] = 'o';
                                       } else {
                                           continue;
                                       }
                                       aux = 1;
                                       break;

                                   case 2:
                                       if (matriz[1][2] == ' ') {
                                           matriz[1][2] = 'o';
                                       } else {
                                           continue;
                                       }
                                       aux = 1;
                                       break;

                                   case 3:
                                       if (matriz[1][3] == ' ') {
                                           matriz[1][3] = 'o';
                                       } else {
                                           continue;
                                       }
                                       aux = 1;
                                       break;

                                   case 4:
                                       if (matriz[2][1] == ' ') {
                                           matriz[2][1] = 'o';
                                       } else {
                                           continue;
                                       }
                                       aux = 1;
                                       break;

                                   case 5:
                                       if (matriz[2][2] == ' ') {
                                           matriz[2][2] = 'o';
                                       } else {
                                           continue;
                                       }
                                       aux = 1;
                                       break;

                                   case 6:
                                       if (matriz[2][3] == ' ') {
                                           matriz[2][3] = 'o';
                                       } else {
                                           continue;
                                       }
                                       aux = 1;
                                       break;

                                   case 7:
                                       if (matriz[3][1] == ' ') {
                                           matriz[3][1] = 'o';
                                       } else {
                                           continue;
                                       }
                                       aux = 1;
                                       break;

                                   case 8:
                                       if (matriz[3][2] == ' ') {
                                           matriz[3][2] = 'o';
                                       } else {
                                           continue;
                                       }
                                       aux = 1;
                                       break;

                                   case 9:
                                       if (matriz[3][3] == ' ') {
                                           matriz[3][3] = 'o';
                                       } else {
                                           continue;
                                       }
                                       aux = 1;
                                       break;

                                   default:
                                       printf("\n");
                               }
                           }

                       }while(aux == 0);

                    }




#ifdef __WIN32
                    system("cls");
#elif __linux__
                    system("clear");
#endif
                    printf("\n");
                    printf("   1  2  3");
                    printf("\n");

                    for (i = 1; i < 4; i++) {
                        printf("%d ", i);
                        for (j = 1; j < 4; j++) {

                            printf("[%c]", toupper(matriz[i][j]));

                        }
                        printf("\n");
                    }
                    //LOGICA DA LETRA X
                    if (matriz[1][1] == 'x' && matriz[1][2] == 'x' && matriz[1][3] == 'x') {
                        printf("Ganhou na linha 1");
                        flag += 9;
                    }
                    if (matriz[2][1] == 'x' && matriz[2][2] == 'x' && matriz[2][3] == 'x') {
                        printf("Ganhou na linha 2");
                        flag += 9;
                    }
                    if (matriz[3][1] == 'x' && matriz[3][2] == 'x' && matriz[3][3] == 'x') {
                        printf("Ganhou na linha 3");
                        flag += 9;
                    }
                    if (matriz[1][1] == 'x' && matriz[2][1] == 'x' && matriz[3][1] == 'x') {
                        printf("Ganhou na coluna 1");
                        flag += 9;
                    }
                    if (matriz[1][2] == 'x' && matriz[2][2] == 'x' && matriz[3][2] == 'x') {
                        printf("Ganhou na coluna 2");
                        flag += 9;
                    }
                    if (matriz[1][3] == 'x' && matriz[2][3] == 'x' && matriz[3][3] == 'x') {
                        printf("Ganhou na coluna 3");
                        flag += 9;
                    }
                    if (matriz[1][1] == 'x' && matriz[2][2] == 'x' && matriz[3][3] == 'x') {
                        printf("Ganhou na diagonal 1");
                        flag += 9;
                    }
                    if (matriz[1][3] == 'x' && matriz[2][2] == 'x' && matriz[3][1] == 'x') {
                        printf("Ganhou na diagonal 2");
                        flag += 9;
                    }

                    //LOGICA DA LETRA O

                    if (matriz[1][1] == 'o' && matriz[1][2] == 'o' && matriz[1][3] == 'o') {
                        printf("Ganhou na linha 1");
                        flag += 9;
                    }
                    if (matriz[2][1] == 'o' && matriz[2][2] == 'o' && matriz[2][3] == 'o') {
                        printf("Ganhou na linha 2");
                        flag += 9;
                    }
                    if (matriz[3][1] == 'o' && matriz[3][2] == 'o' && matriz[3][3] == 'o') {
                        printf("Ganhou na linha 3");
                        flag += 9;
                    }
                    if (matriz[1][1] == 'o' && matriz[2][1] == 'o' && matriz[3][1] == 'o') {
                        printf("Ganhou na coluna 1");
                        flag += 9;
                    }
                    if (matriz[1][2] == 'o' && matriz[2][2] == 'o' && matriz[3][2] == 'o') {
                        printf("Ganhou na coluna 2");
                        flag += 9;
                    }
                    if (matriz[1][3] == 'o' && matriz[2][3] == 'o' && matriz[3][3] == 'o') {
                        printf("Ganhou na coluna 3");
                        flag += 9;
                    }
                    if (matriz[1][1] == 'o' && matriz[2][2] == 'o' && matriz[3][3] == 'o') {
                        printf("Ganhou na diagonal 1");
                        flag += 9;
                    }
                    if (matriz[1][3] == 'o' && matriz[2][2] == 'o' && matriz[3][1] == 'o') {
                        printf("Ganhou na diagonal 2");
                        flag += 9;
                    }


                    printf("\n");
                    flag += 1;
                }

                if (flag == 9) {
                    printf("Deu velha\n");
                }
                printf("Deseja jogar novamente? (s/n)\n");
                scanf("%s", &jogaNovamente);
                if (jogaNovamente == 's') {
                    continue;
                } else {
                    printf("Saindo...");
                }

            } while (jogaNovamente == 's');

            return 0;

            case MENU_SAIR:
                printf("Volte logo!");
                return 0;
        }
    }


}

