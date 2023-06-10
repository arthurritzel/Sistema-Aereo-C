#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    struct dados{
        int id;
        char partida[50];
        char destino[50];
        char hora[6];
        float valor;
    }voo[20];
    
    int escolha, very = 0;
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

            break;
        case 2:
            /* Cadastro */
            system("cls");
            very = 0;
            printf("----------------------------------------\n");
            printf("|           Cadastro de voo            |\n");
            printf("----------------------------------------\n");

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
}