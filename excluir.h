int excluir(){
    int idb = 0, flag = 0, opc = 0;
    do{
        flag = 0;
        printf("Digite o ID do voo que deseja excluir: ");
        scanf("%i", &idb);
        for (int i = 0; i < 20; i++) {
            if (idb == voo[i].id) {
                voo[i].id = -1;
                strcpy(voo[i].partida, " ");
                strcpy(voo[i].destino, " ");
                strcpy(voo[i].hora, " ");
                voo[i].valor = 0;
                printf("Voo excluído com sucesso!\n");
                flag = 1;
                break;
            }
        }
        if (flag != 1) {
            printf("Voo nao encontrado!\n");
            printf("Deseja digitar novamente o ID do voo?\n[1]Sim\n[2]Nao: ");
            scanf("%i", &opc);
        } else {
            opc = 2;
        } 
    }while (opc != 2);
}