#include "analyse.h"
#include <string.h> 
#include <stdio.h>
#include <stdlib.h>
#include "sementique.h"


NbrIDFS=0;





char * trans(enum TOKENS* token){

switch(*token){

case 0: return "PROGRAM_TOKEN";break;
case 1: return "CONST_TOKEN";break;
case 2: return "VAR_TOKEN";break;
case 3: return "BEGIN_TOKEN";break;
case 4: return "END_TOKEN";break;
case 5: return "IF_TOKEN";break;
case 6: return "THEN_TOKEN";break;
case 7: return "WHILE_TOKEN";break;
case 8: return "DO_TOKEN";break;
case 9: return "READ_TOKEN";break;
case 10: return "WRITE_TOKEN,";break;
case 11: return "PV_TOKEN";break;
case 12: return "PT_TOKEN";break;
case 13: return "PLUS_TOKEN";break;
case 14: return "MOINS_TOKEN";break;
case 15: return "PMULT_TOKEN";break;
case 16: return "DIV_TOKEN";break;
case 17: return "VIR_TOKEN";break;
case 18: return "AFF_TOKEN";break;
case 19: return "EG_TOKEN";break;
case 20: return "INF_TOKEN";break;
case 21: return "INFEG_TOKEN";break;
case 22: return "SUP_TOKEN";break;
case 23: return "SUPEG_TOKEN";break;
case 24: return "DIFF_TOKEN";break;
case 25: return "PO_TOKEN";break;
case 26: return "PF_TOKEN";break;
case 27: return "FIN_TOKEN";break;
case 28: return "ID_TOKEN";break;
case 29: return "NUM_TOKEN";break;
case 30: return "ERREUR_TOKEN";break;
case 31: return "NULL_TOKEN";break;

case 32: return "GUIMO_TOKEN";break;

case 33: return "GUIMF_TOKEN";break;
 default:
            return" err";
}
}
 


void  Stockage(){
	
	

struct store * new_elem =NULL;
new_elem=(struct store *)malloc(sizeof(struct store));



new_elem->data=TOK_A;
new_elem->next=NULL;

if(head==NULL){
	
TOK_A=(struct code*)malloc(sizeof(struct code));
head=new_elem; 

}
else{
	TOK_A=(struct code*)malloc(sizeof(struct code));

struct store    *last=head;
  
while(last->next!=NULL){


   last=last->next;}

last->next=new_elem;
}

 return;
}