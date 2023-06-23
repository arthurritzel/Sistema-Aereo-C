#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dados{
        int id;
        char partida[20];
        char destino[20];
        char hora[20];
        float valor;
    }voo[20];

void logo(){
    //funcao apenas para mostrar a logo ao usuario
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
}
int init(){
    //le os dados do arquivo banco-voos.txt e armazena na struct, o arquivo esta sendo usado como banco de dados
    FILE *file;
    file = fopen("banco-voos.txt", "r");
    if (file == NULL){
        printf("Problemas na consulta do banco de dados\n");
        return 0;
    }

    char vet[20], aux[20];
    int cont = 0, i = 0, i2 = 0, i3 = 0, i4 = 0, i5 = 0;

    while (fgets(vet, 20, file) != NULL){
        if(cont == 0){
        strcpy(aux, vet);
        voo[i].id = atoi(aux);
        i++;
        }

        if(cont == 1){
        strcpy(aux, vet);
        strcpy(voo[i2].partida, aux);
        i2++;
        }
        if(cont == 2){
        strcpy(aux, vet);
        strcpy(voo[i3].destino, aux);
        i3++;
        }
        if(cont == 3){
        strcpy(aux, vet);
        strcpy(voo[i4].hora, aux);
        i4++;
        }
        if(cont == 4){
        strcpy(aux, vet);
        voo[i5].valor = atof(aux);
        i5++;
        }
        cont++;
        if (cont >=5){
            cont = 0;
        }   
    }
    fclose(file);
    return 0;
}

int finit(){
    //armazena todos os dados da struct voos no arquivo banco-voos.txt
    FILE *file;
    file = fopen("banco-voos.txt", "w");
    if (file == NULL){
        printf("Problemas na gravacao do banco de dados\n");
        return 0;
    } 
    for (int i = 0; i < 20; i++)
    {
        fprintf(file, "%i\n", voo[i].id);
        fprintf(file, "%s", voo[i].partida);
        fprintf(file, "%s", voo[i].destino);
        fprintf(file, "%s", voo[i].hora);
        fprintf(file, "%f\n", voo[i].valor);
    }
    fclose(file);
    return 0;
}

#include "consulta.h"
#include "cadastro.h"
#include "excluir.h"
#include "atualizar.h"
#include "emissao.h"

int main(){

    init();

    int escolha, very = 0, very3 = 0, esc = 0, flag = 0, very4 = 0, esc_cl;
    char senha[15], confsenha[15] = "12345";
    
        do{//laco de repeticao do sistema
            system("cls");
            logo();

            // Primeira perguta ao usuario
            printf("Selecione sua opcao\n[1]Cliente\n[2]ADM\n[3]Sair\n->");
            scanf("%i", &esc);
            switch (esc){
            case 1:
                do{//laco de repeticao das escolhas do cliente
                    very4 = 1;
                    very = 1;
                    flag = 0;
                    system("cls");
                    logo();

                    printf("Seja bem vindo!\n\nSelecione sua acao\n[1]Consultar voos\n[2]Emitir passagem\n[3]Voltar\n->");
                    scanf("%i", &esc_cl);
                    switch (esc_cl){
                    case 1:
                        system("cls");
                        printf("----------------------------------------\n");
                        printf("|           Consulta de voos           |\n");
                        printf("----------------------------------------\n");
                        //Inicia a funcao consluta que esta no aqruivo consulta.h
                        consulta();

                        break;
                    case 2:
                        system("cls");
                        printf("----------------------------------------\n");
                        printf("|            Emitir passagem           |\n");
                        printf("----------------------------------------\n");
                        //Inicia a funcao emissao que esta no aqruivo emissao.h
                        emissao();

                        break;
                    case 3:
                        very4 = 0;
                        flag = 1;
                    default:
                        break;
                    }
                    if(flag != 1){
                        printf("[1]Voltar\n->");
                        scanf("%i", &very4);
                    }
                }while(very4 != 0);
                break;
            case 2:
                do{//laco de repeticao para conferencia da senha
                    flag = 0;
                    fflush(stdin);
                    //realizando a leitura e conferencia da senha
                    printf("Digite a senha de acesso: ");
                    gets(senha);
                    fflush(stdin);
                    if(!strcmp(senha, confsenha)){
                        do{//laco de repeticao para crud
                            very3 = 2;
                            very4 = 0;
                            flag = 0;
                            system("cls");
                            logo();

                            printf("Escolha sua acao!\n[1]Consultar voos\n[2]Cadastrar voos\n[3]Atualizar voo\n[4]Excluir voo\n[5]Voltar\n->");
                            scanf("%i", &escolha);
                            switch (escolha){
                            case 1:
                                /* Consulta */
                                system("cls");
                                very = 1;
                                printf("----------------------------------------\n");
                                printf("|           Consulta de voos           |\n");
                                printf("----------------------------------------\n");
                                //Inicia a funcao consulta que esta no aqruivo consulta.h
                                consulta();

                                break;
                            case 2:
                                /* Cadastro */
                                system("cls");
                                very = 1;
                                printf("----------------------------------------\n");
                                printf("|           Cadastro de voo            |\n");
                                printf("----------------------------------------\n");
                                //Inicia a funcao cadastro que esta no aqruivo cadastro.h
                                cadastro();

                            break;
                            case 3:
                                /* Atualizacao */
                                system("cls");
                                very = 1;
                                printf("----------------------------------------\n");
                                printf("|           Atualizacao de voo         |\n");
                                printf("----------------------------------------\n");
                                //Inicia a funcao atualizar que esta no aqruivo atualizar.h
                                atualizar();

                            break;
                            case 4:
                                /* Excluir */
                                system("cls");
                                very = 1;
                                printf("----------------------------------------\n");
                                printf("|              Excluir voo             |\n");
                                printf("----------------------------------------\n");
                                //Inicia a funcao excluir que esta no aqruivo excluir.h
                                excluir();

                            break;
                            case 5:
                                very = 1;
                                very4 = 0;
                                flag = 1;
                                break;
                            default:
                                system("cls");
                                printf("Opcao invalida!\n");
                                very = 1;
                                break;
                            }
                            if(flag != 1){
                                printf("[1]Voltar\n->");
                                scanf("%i", &very4);
                            }
                        }while(very4 != 0);
                    }else{
                        printf("Senha Invalida!\n");
                        printf("Tentar novamente?\n[1]Sim\n[2]Nao\n->");
                        scanf("%i", &very3);
                    }
                }while(very3 != 2);
                break;

            case 3:
                printf("Ate a proxima!");
                very = 0;
                break;
            default:
                break;
            }
        }while(very != 0);
        finit();
}   