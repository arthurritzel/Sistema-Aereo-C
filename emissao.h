int emissao(){
    int idb, i, linha, very = 0, flag = 0, very2 = 0;

        char assentos[9][28] = { "| 00 | 01 |   | 02 | 03 |",
                                "| 10 | 11 |   | 12 | 13 |",
                                "| 20 | 21 |   | 22 | 23 |",
                                "| 30 | 31 |   | 32 | 33 |",
                                "| 40 | 41 |   | 42 | 43 |",
                                "| 50 | 51 |   | 52 | 53 |",
                                "| 60 | 61 |   | 62 | 63 |",
                                "| 70 | 71 |   | 72 | 73 |",
                                "| 80 | 81 |   | 82 | 83 |",
                                "| 90 | 91 |   | 92 | 93 |",};

        char nome[40];
        int idade;

        FILE *passagem;

        passagem = fopen("passagem.txt", "w");

        if (passagem == NULL){
            printf("Problemas na CRIACAO do arquivo\n");
            return 0;

        }

        do{
            very = 1;
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
                            for(linha = 0; linha < 9; linha++){
                                printf("%s\n", assentos[linha]);
                            }
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
                            for(linha = 0; linha < 9; linha++){
                                fprintf(passagem, "%s\n", assentos[linha]);
                            }
                            fclose(passagem);
                            flag = 1;
                            very = 1;
                            printf("\nPassagem emitida com sucesso!\n");
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

