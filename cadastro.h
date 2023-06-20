int cadastro(){
    int idcad = 0;
    int veryc = 1;
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
                        strcat(voo[i].partida, "\n");
                        fflush(stdin);
                        printf("Digite o destino do voo: ");
                        gets(voo[i].destino);
                        strcat(voo[i].destino, "\n");
                        fflush(stdin);
                        printf("Digite o horario do voo: ");
                        gets(voo[i].hora);
                        strcat(voo[i].hora, "\n");
                        fflush(stdin);
                        printf("Digite o valor do voo: ");
                        scanf("%f", &voo[i].valor);
                        fflush(stdin);
                        printf("VOO CADASTRADO COM SUCESSO!\n");
                        break;
                    }
                    
                }
}