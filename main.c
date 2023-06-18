#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dados{
        int id;
        char partida[50];
        char destino[50];
        char hora[6];
        float valor;
    }voo[20];
    int atr(){
        voo[0].id = 1;
        strcpy(voo[0].partida, "Sao Paulo");
        strcpy(voo[0].destino, "Rio de Janeiro");
        strcpy(voo[0].hora, "11:30");
        voo[0].valor = 1000;

        voo[1].id = 2;
        strcpy(voo[1].partida, "Belo Horizonte");
        strcpy(voo[1].destino, "Salvador");
        strcpy(voo[1].hora, "14:45");
        voo[1].valor = 1500;

        voo[2].id = 3;
        strcpy(voo[2].partida, "Recife");
        strcpy(voo[2].destino, "Fortaleza");
        strcpy(voo[2].hora, "09:20");
        voo[2].valor = 1200;

        voo[3].id = 4;
        strcpy(voo[3].partida, "Porto Alegre");
        strcpy(voo[3].destino, "Curitiba");
        strcpy(voo[3].hora, "08:30");
        voo[3].valor = 800;

        voo[4].id = 5;
        strcpy(voo[4].partida, "Brasília");
        strcpy(voo[4].destino, "Manaus");
        strcpy(voo[4].hora, "13:15");
        voo[4].valor = 1800;

        voo[5].id = 6;
        strcpy(voo[5].partida, "Porto Seguro");
        strcpy(voo[5].destino, "Natal");
        strcpy(voo[5].hora, "10:40");
        voo[5].valor = 1300;

        voo[6].id = 7;
        strcpy(voo[6].partida, "Florianópolis");
        strcpy(voo[6].destino, "Foz do Iguaçu");
        strcpy(voo[6].hora, "15:50");
        voo[6].valor = 900;

        voo[7].id = 8;
        strcpy(voo[7].partida, "São Luís");
        strcpy(voo[7].destino, "Belém");
        strcpy(voo[7].hora, "12:20");
        voo[7].valor = 1100;

        voo[8].id = 9;
        strcpy(voo[8].partida, "Goiânia");
        strcpy(voo[8].destino, "Cuiabá");
        strcpy(voo[8].hora, "14:00");
        voo[8].valor = 950;

        voo[9].id = 10;
        strcpy(voo[9].partida, "João Pessoa");
        strcpy(voo[9].destino, "Maceió");
        strcpy(voo[9].hora, "17:30");
        voo[9].valor = 1200;

    for (int i = 10; i < 20; i++){
        voo[i].id = -1;
        strcpy(voo[i].partida, " ");
        strcpy(voo[i].destino, " ");
        strcpy(voo[i].hora, " ");
        voo[i].valor = 0;
    }
}

#include "consulta.h"
#include "cadastro.h"
#include "excluir.h"
#include "atualizar.h"
#include "emissao.h"

int main(){

    atr();

    int escolha, very = 0, very2;
    
    do{
        do{
            system("clear");
            printf("          ____________________________________________________________ \n");
            printf("         /  ________   __     __     __    _______   __   _______    /|\n");
            printf("        /  / ______// / //   | ||   / //  / ___  // /_// / _____//  / / \n");
            printf("       /  / /___     / //    | ||  / //  / /__/ // / // / //___    / /  /\n");
            printf("      /  / ____//   / //      | Y_/ //  / _____// / // / //_  //  / /  /\n");
            printf("     /  / //       / //_____   |   //  / //      / // / /__/ //  / /  /\n");
            printf("    /  /_//       /_______//   /__//  /_//      /_// /______//  / /  /\n");
            printf("   /___________________________________________________________/ /  /\n");
            printf("   |_____________________|INTERNATIONAL|_______________________|/  /\n");
            printf("      /                                                        /  /\n");
            printf("     /                      ( )___( )                         /  /\n");
            printf("    /   _______XYX_________Y         Y_______XYX_________    /  /\n");
            printf("   /   /______X=*=X_______|   @   @   |_____X=*=X_______/   /  /\n");
            printf("  /            XYX---------Y  (* *)  Y-------XYX           /  /\n");
            printf(" /                          Y______ Y                     /  /\n");
            printf("/________________________________________________________/__/\n");
            printf("Escolha sua acao!\n[1]Consultar voos\n[2]Cadastrar voos\n[3]Atualizar voo voo\n[4]Excluir voo\n[5]Emitir passagem\n[6]Sair\n->");
            scanf("%i", &escolha);
            switch (escolha){
            case 1:
                /* Consulta */
                system("clear");
                very = 0;
                printf("----------------------------------------\n");
                printf("|           Consulta de voos           |\n");
                printf("----------------------------------------\n");
                consulta();

                break;
            case 2:
                /* Cadastro */
                system("clear");
                very = 0;
                printf("----------------------------------------\n");
                printf("|           Cadastro de voo            |\n");
                printf("----------------------------------------\n");
                cadastro();

            break;
            case 3:
                /* Atualizacao */
                system("clear");
                very = 0;
                printf("----------------------------------------\n");
                printf("|           Atualizacao de voo         |\n");
                printf("----------------------------------------\n");
                atualizar();

            break;
            case 4:
                /* Excluir */
                system("clear");
                very = 0;
                printf("----------------------------------------\n");
                printf("|              Excluir voo             |\n");
                printf("----------------------------------------\n");
                excluir();

            break;
            case 5:
                /* Emitir */
                system("clear");
                very = 0;
                printf("----------------------------------------\n");
                printf("|           Emitir passagem            |\n");
                printf("----------------------------------------\n");
                emissao();
                break;
            case 6:
                printf("Até a proxima!");
                return 0;
                break;
            default:
                system("clear");
                printf("Opcao invalida!\n");
                very = 1;
            break;
            }
        }while(very != 0);
        printf("\n[1]Voltar\n->");
        scanf("%i", &very2);
    }while(very2 != 2);
}   