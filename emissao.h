
int emissao(){
    int idb, i, linha, very = 0, flag = 0, very2 = 0, cons, esc2;
    char nome[40];
    int idade;
    int assentos[7][4], k = 0, esc, very3;

    for (int i = 0; i < 7; i++){
        for (int j = 0; j < 4; j++){
            k++;
            assentos[i][j] = k;
        }
    }

    FILE *passagem;
    passagem = fopen("passagem.txt", "w");
    if (passagem == NULL){
        printf("Problemas na CRIACAO do arquivo\n");
        return 0;
    }

    do{
        very = 1;
        printf("Deseja consultar os voos\n[1]Sim\n[2]Nao\n[3]Cancelar\n->");
        scanf("%i", &cons);
        if (cons == 1){
            consulta();
        }else if(cons == 3){
            return 0;
        }
        
        printf("Digite o id da passagem para emiti-la: ");
        scanf("%i", &idb);
        
        for (i = 0; i < 20; i++){
            if(idb == voo[i].id){
                fflush(stdin);
                printf("Digite seu nome completo: ");
                gets(nome);
                fflush(stdin);
                do{
                    printf("Digite sua idade: ");
                    scanf("%i", &idade);
                    if(0 < idade){
                    
                    for (int i = 0; i < 7; i++){
                        for (int j = 0; j < 4; j++){   
                            if (j == 2){
                                printf("  ");
                            }
                            printf("| %.2i |", assentos[i][j]);   
                        }
                        printf("\n");
                    }
                    do{
                        fflush(stdin);
                        printf("Qual assento deseja: ");
                        scanf("%i", &esc);
                        if (esc >= 1 && esc <= 28){
                            very3 = 0;
                            for (int i = 0; i < 7; i++){
                                for (int j = 0; j < 4; j++){
                                    if(esc == assentos[i][j]){
                                        assentos[i][j] = 0;
                                    }
                                }
                            }

                        }else{
                            printf("Valor invalido!\n");
                            very3 = 1;
                        }
                    }while(very3 != 0);
                        very2 = 1;
                        printf("----------------------------------------\n");
                        printf("|         FLYPIG INTERNATIONAL         |\n");
                        printf("----------------------------------------\n\n");
                        printf("----------------------------------------\n");
                        printf("NOME: %s\n", nome);
                        printf("IDADE: %i\n", idade);
                        printf("----------------------------------------\n\n");
                        printf("-------------------\n");
                        printf("id: %i\n", voo[i].id);
                        printf("Partida: %s\n", voo[i].partida);
                        printf("Destino: %s\n", voo[i].destino);
                        printf("Horario: %s\n", voo[i].hora);
                        printf("Valor: %.2f\n", voo[i].valor);
                        printf("-------------------\n\n");
                        printf("----------------------------------------\n");
                        printf("|           MAPA DE POLTRONAS          |\n");
                        printf("----------------------------------------\n\n");
                        for (int i = 0; i < 7; i++){
                                for (int j = 0; j < 4; j++){   
                                    if (j == 2){
                                        printf("  ");
                                    }
                                    if(assentos[i][j] != 0){
                                        printf("| %.2i |", assentos[i][j]);   
                                    }else{
                                        printf("| xx |");
                                    }
                                }
                                printf("\n");
                            }  
                        printf("Confirmar Passagem?\n[1]Sim\n[2]Nao\n->");
                        scanf("%i", &esc2);
                        if (esc2 == 1){
                            fprintf(passagem, "----------------------------------------\n");
                            fprintf(passagem, "|         FLYPIG INTERNATIONAL         |\n");
                            fprintf(passagem, "----------------------------------------\n\n");
                            fprintf(passagem, "----------------------------------------\n");
                            fprintf(passagem, "NOME: %s\n", nome);
                            fprintf(passagem, "IDADE: %i\n", idade);
                            fprintf(passagem, "----------------------------------------\n\n");
                            fprintf(passagem, "-------------------\n");
                            fprintf(passagem, "id: %i\n", voo[i].id);
                            fprintf(passagem, "Partida: %s\n", voo[i].partida);
                            fprintf(passagem, "Destino: %s\n", voo[i].destino);
                            fprintf(passagem, "Horario: %s\n", voo[i].hora);
                            fprintf(passagem, "Valor: %.2f\n", voo[i].valor);
                            fprintf(passagem, "-------------------\n\n");
                            fprintf(passagem, "----------------------------------------\n");
                            fprintf(passagem, "|           MAPA DE POLTRONAS          |\n");
                            fprintf(passagem, "----------------------------------------\n\n");
                            for (int i = 0; i < 7; i++){
                                    for (int j = 0; j < 4; j++){   
                                        if (j == 2){
                                            fprintf(passagem, "  ");
                                        }
                                        if(assentos[i][j] != 0){
                                            fprintf(passagem, "| %.2i |", assentos[i][j]);   
                                        }else{
                                            fprintf(passagem, "| xx |");
                                        }
                                    }
                                    fprintf(passagem, "\n");
                                }  
                            fclose(passagem);
                            flag = 1;
                            very = 1;
                            printf("\nPassagem emitida com sucesso!\n");
                        }else{
                            printf("Passagem cancelada\n");
                            very = 1;
                            flag = 1;
                        }
                        break;
                    }else{
                        printf("Idade invalida!\n");
                        very2 = 0;
                    }
                }while(very2 != 1);
            }
        }
        if(flag != 1){
            system("clear");
            printf("\nId invalido, tente novamente!\n");
            very = 0;
        }

    }while(very != 1);
}

