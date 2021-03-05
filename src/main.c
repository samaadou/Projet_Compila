#include "header.h"


int main(){
	int x =0;
    listeSequence list;
    list = NULL;
    fichier = fopen("fich.pop", "r");
    CarSuiv();
    SymboleSuiv();
    do{
        L=insererSequence(importToken(token_cour.line, token_cour.nom,token_cour.code),L);
        SymboleSuiv();
    }while(strcmp(token_cour.code,"EOF"));
    afficherSequences(L);
    return 1;
} 