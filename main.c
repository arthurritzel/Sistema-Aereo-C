#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "consulta.h"

int main(){
    struct dados{
        int id;
        char partida[50];
        char destino[50];
        char hora[6];
        float valor;
    }voo[20];
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
   

    int escolha, very = 0, very2, opc, idb, flag = 0;
    int idcad = 0;
    int veryc = 1;
    do{
        do{
            printf("----------------------------------------\n");
            printf("|         FLYPIG INTERNATIONAL         |\n");
            printf("----------------------------------------\n");
            printf("Escolha sua acao!\n[1]Consultar voos\n[2]Cadastrar voos\n[3]Atualizar voo voo\n[4]Excluir voo\n[5]Emitir passagem\n->");
            scanf("%i", &escolha);
            switch (escolha){
            case 1:
                /* Consulta */
                system("cls");
                very = 0;
                printf("----------------------------------------\n");
                printf("|           Consulta de voos           |\n");
                printf("----------------------------------------\n");
                printf("Deseja:\n[1]Filtrar a busca\n[2]Apresentar todos os voos\n->");
                scanf("%i", &opc);
                if(opc == 1){
                    printf("Digite o id do voo: ");
                    scanf("%i", &idb);
                    for (int i = 0; i < 20; i++){
                        if(idb == voo[i].id){
                            printf("-------------------\n");
                            printf("id: %i\n", voo[i].id);
                            printf("Partida: %s\n", voo[i].partida);
                            printf("Destino: %s\n", voo[i].destino);
                            printf("Horario: %s\n", voo[i].hora);
                            printf("Valor: %.2f\n", voo[i].valor);
                            printf("-------------------\n");
                            flag = 1;
                        }
                    }
                    if(flag != 1){
                        printf("\nVoo nao encontrado!\n");
                    }
                }else{
                    for (int i = 0; i < 20; i++){
                        if (voo[i].id != -1){
                        printf("Id: %i\n", voo[i].id);
                        printf("Ponto de partida: %s\n", voo[i].partida);
                        printf("Destino: %s\n", voo[i].destino);
                        printf("Horario: %s\n", voo[i].hora);
                        printf("Valor: %.2f\n", voo[i].valor);
                        printf("-----------------------------\n\n");
                        }
                    }
                }
                break;
            case 2:
                
                /* Cadastro */
                system("cls");
                very = 0;
                printf("----------------------------------------\n");
                printf("|           Cadastro de voo            |\n");
                printf("----------------------------------------\n");
                do{
                    printf("Digite o id do voo: ");
                    scanf("%i", &idcad);
                    for (int i = 0; i < 20; i++){
                        if(idcad == voo[i].id){
                            printf("Esse id ja esta cadastrado!\n");
                            veryc = 0;
                            break;
                        }else{
                            veryc = 1;
                        }
                    }
                }while(veryc != 1);
                for (int i = 0; i < 20; i++){
                    if (voo[i].id == -1){
                        voo[i].id = idcad;
                        fflush(stdin);
                        printf("Digite o ponto de partida do voo: ");
                        gets(voo[i].partida);
                        fflush(stdin);
                        printf("Digite o destino do voo: ");
                        gets(voo[i].destino);
                        fflush(stdin);
                        printf("Digite o horario do voo: ");
                        gets(voo[i].hora);
                        fflush(stdin);
                        printf("Digite o valor do voo: ");
                        scanf("%f", &voo[i].valor);
                        fflush(stdin);
                        printf("VOO CADASTRADO COM SUCESSO!");
                        break;
                    }
                    
                }
                break;
            case 3:
                /* Atualizacao */
                system("cls");
                very = 0;
                printf("----------------------------------------\n");
                printf("|           Atualizacao de voo         |\n");
                printf("----------------------------------------\n");

                break;
            case 4:
                /* Excluir */
                system("cls");
                very = 0;
                printf("----------------------------------------\n");
                printf("|              Excluir voo             |\n");
                printf("----------------------------------------\n");

                break;
            case 5:
                /* Emitir */
                system("cls");
                very = 0;
                printf("----------------------------------------\n");
                printf("|           Emitir passagem            |\n");
                printf("----------------------------------------\n");

                break;
            default:
                system("cls");
                printf("Opcao invalida!\n");
                very = 1;
                break;
            }
        }while(very != 0);
        printf("\n[1]Realizar nova operacao\n[2]Sair\n->");
        scanf("%i", &very2);
    }while(very2 != 2);
}   