int consulta(){
    int opc = 0, idb, flag = 0, very = 0;
    printf("Deseja:\n[1]Filtrar a busca\n[2]Apresentar todos os voos\n[3]Cancelar\n->");
    scanf("%i", &opc);
    if(opc == 1){
        do{
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
                printf("Deseja buscar outro voo?\n[1]Sim\n[2]Nao\n->");
                scanf("%i", &very);
            }else{
                very = 2;
            }
        }while(very != 2);
    }else if(opc == 2){
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
    }else{
        return 0;
    }
}