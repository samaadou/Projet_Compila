#include "header.h"

const char* keyword_token_list[]={ "ENDPROGRAM", "IN", "OUT", "RETURN", "ENDFONCT", "PROGRAM", "STATIC", "CONST", "SEI", "EINTERRUPT", "PCINTERRUPT", "ENDINTER", "UP", "DOWN", "INT0", "INT1", "WAIT", "WHILE", "ENDWHILE", "DO", "ENDDO", "FOR", "ENDFOR", "IF", "ELSE", "ENDIF", "READ", "WRITE", "CHAR", "UNSINT", "SINT", "INT", "FLOAT", "DOUBLE", "VOID"};
const char* special_token_list[]={"PV", "MOD", "PLUS", "MOINS", "MULT", "DIV", "VIR", "AFF", "INF", "INFEG", "SUP", "SUPEG", "DIFF", "PO", "PF", "EG", "AND", "OR", "DP"};
const char* port_token_list[]={"DDRB", "DDRB0", "DDRB1", "DDRB2", "DDRB3", "DDRB4", "DDRB5", "DDRB6", "DDRB7", "DDRD", "DDRD0", "DDRD1", "DDRD2", "DDRD3", "DDRD4", "DDRD5", "DDRD6", "DDRD7", "DDRC", "DDRC0", "DDRC1", "DDRC2", "DDRC3", "DDRC4", "DDRC5", "DDRC6"};
const char* por_token_list[]={"PORT", "PORTB", "PORTB0", "PORTB1", "PORTB2", "PORTB3", "PORTB4", "PORTB5", "PORTB6", "PORTB7", "PORTD", "PORTD0", "PORTD1", "PORTD2", "PORTD3", "PORTD4", "PORTD5", "PORTD6", "PORTD7", "PORTC", "PORTC0", "PORTC1", "PORTC2", "PORTC3", "PORTC4", "PORTC5", "PORTC6"};
const char* pin_token_list[]={"PINB", "PINB0", "PINB1", "PINB2", "PINB3", "PINB4", "PINB5", "PINB6", "PINB7", "PIND", "PIND0", "PIND1", "PIND2", "PIND3", "PIND4", "PIND5", "PIND6", "PIND7", "PINC", "PINC0", "PINC1", "PINC2", "PINC3", "PINC4", "PINC5", "PINC6"};
const char* special_symbols_list[]={";", "%", "+", "-", "*", "/", "," , "<-", "<", "<=",  ">", ">=", "!=", "(", ")", "=", "&", "|", ":"};
const char* pcie_token_list[]={"PCINT0", "PB0", "PCINT1", "PB1", "PCINT2", "PB2", "PCINT3", "PB3", "PCINT4", "PB4", "PCINT5", "PB5", "PCINT6", "PB6", "PCINT7", "PB7", "PCINT8", "PC0", "PCINT9", "PC1", "PCINT10", "PC2", "PCINT11", "PC3", "PCINT12", "PC4", "PCINT13", "PC5", "PCINT14", "PC6", "PCINT16", "PD0", "PCINT17", "PD1", "PCINT18", "PD2", "PCINT19", "PD3", "PCINT20", "PD4", "PCINT21", "PD5", "PCINT22", "PD6", "PCINT23", "PD7"};

int ligne = 1 ;
int lex = 0 ;
// ########################################Lexical####################################################################
void SymboleSuiv(){
	
	memset(token_cour.code, '\0', codeTaille);
    memset(token_cour.nom, '\0', nomTaille);
    //ignore anything that doesn't belong to the tokens lists
    Separateur();
    token_cour.line = ligne;
    if( car_cour == EOF ){
    	strcpy(token_cour.code, "EOF");
    }
    else if ( lire_mot() ){}
    else if ( lire_nombre() ){}
    else if ( lire_car() ) {}
    else{Erreur("Invalid");}
}

char CarSuiv(){
	return car_cour = fgetc(fichier);
}

void Erreur(char *erreur){
	lex = 1;
	int er = ligne;
	er++;
	printf("line %d %s\n", er, erreur);
}

void Separateur(){
	//ignore blank space, newline, tabulation
	while((car_cour == ' ') || (car_cour =='\n') || (car_cour == '\t') || (car_cour == '#')){
		//number of lines
		if( car_cour == '\n'){
			ligne++;
		}
		CarSuiv();
		//ignore comments
		if( car_cour == '#'){
			CarSuiv();
            if(car_cour == '#'){
                while(1){
                	CarSuiv();
                	if(car_cour == '#'){
                		CarSuiv();
                		break;
                	}
                	else if (car_cour == EOF)
                		break;
                }
            }
            else 
                Erreur("Error in comment");
            if(car_cour != '#')
                Erreur("Error in comment 2");
            CarSuiv();
        }
	}
}

bool lire_mot(){
	int pp = 0;
	if( isalpha(car_cour) == 0)
		return FALSE;
	char mot[MAXCHAR];
	int countM = 0, countL = 0, comp = 0;
	mot[0] = toupper(car_cour);

	do{
		countM++;
	}while(countM<MAXCHAR && (isalnum(mot[countM] = car_cour = toupper(CarSuiv()))|| mot[countM] == '_' ));

	if( countM >= MAXCHAR )
		Erreur("Number of characters exceed");
	mot[countM] = '\0';
	if(mot[0]=='D' && mot[1]=='D' && mot[2]=='R'){
		while( (comp = strcmp(mot, port_token_list[countL++])) !=0 && countL < NUMPORTTOKEN );
		pp=1;
	}
	else if (mot[0]=='P' && mot[1]=='O' && mot[2]=='R' && mot[3]=='T'){
		while( (comp = strcmp(mot, por_token_list[countL++])) !=0 && countL < NUMPORTTOKEN );
		pp=2;
	}
	else if (mot[0]=='P' && mot[1]=='I' && mot[2]=='N'){
		while( (comp = strcmp(mot, pin_token_list[countL++])) !=0 && countL < NUMPORTTOKEN );
		pp=3;
	}
	else
		while( (comp = strcmp(mot, keyword_token_list[countL++])) !=0 && countL < NUMKEYWORDTOKEN );
	if( comp == 0 && pp==0){
		strcpy(token_cour.code, keyword_token_list[countL-1]);
		strcpy(token_cour.nom, mot);
	}
	else if( comp == 0 && pp == 1){
		strcpy(token_cour.code, port_token_list[countL-1]);
		strcpy(token_cour.nom, mot);
	}
	else if( comp == 0 && pp == 2){
		strcpy(token_cour.code, por_token_list[countL-1]);
		strcpy(token_cour.nom, mot);
	}
	else if( comp == 0 && pp == 3){
		strcpy(token_cour.code, pin_token_list[countL-1]);
		strcpy(token_cour.nom, mot);
	}

	else{
		strcpy(token_cour.code, "ID");
		strcpy(token_cour.nom, mot);
	}
	pp=0;
	return TRUE;
}

bool lire_nombre(){
	if (isdigit(car_cour) == 0)
		return FALSE;
	char num[MAXNUM];
	int count = 0;
	num[0] = car_cour;
	do{
		count++;
	}while(count<MAXNUM && isdigit(num[count] = car_cour = CarSuiv()));
	if( count >= MAXNUM)
		Erreur("Number of digits exceed");
	num[count] = '\0';
	strcpy(token_cour.code, "NUM");
	strcpy(token_cour.nom, num);
	car_cour = CarSuiv();
	return TRUE;
}

bool lire_car(){
	int count = 0, comp = 0;
    char spec[3];
    memset(spec,'\0',sizeof(spec));

    spec[0] = car_cour;
    spec[1] = car_cour = CarSuiv() ;
    if(spec[1] != '-' && spec[1] != '=')
        spec[1] =  '\0';
    else
        CarSuiv();
     
    while( (comp = strcmp(spec, special_symbols_list[count++]) != 0) && count < NUMSPECIALTOKEN);

    if(comp != 0)
        return FALSE;

    strcpy(token_cour.code, special_token_list[count-1]); 
    strcpy(token_cour.nom, spec);

    return TRUE;
}

//to import token
 chaineToken* importToken(int nligne, char *nom, char *code){
 	char num[MAXNUM];
	int count = 0;
	chaineToken *p=Malloc(chaineToken);
	p->numLigne = nligne;
	strcpy(p->nomToken,nom);
	strcpy(p->codeToken,code);
	if (isdigit(nom[0]) != 0){
		num[0] = car_cour;
		do{
			num[count] = nom[count];
			count++;
		}while(nom[count] != '\0');

		p->ifNum = atoi(num);
	}
	strcpy(token_cour.code, "NUM");
	strcpy(token_cour.nom, num);
	return p;
}
//insert the imported token at the end of the list
listeSequence insererSequence(chaineToken *seq,listeSequence liste){
	noeud *nouveau=Malloc(noeud);
	nouveau->infos=seq;
	noeud *p;
	if(!liste){
		liste=nouveau;
		nouveau->suivant=NULL;
		return liste;
	}
	p=liste;
	while(p->suivant){
		p=p->suivant;
	}
	p->suivant=nouveau;
	nouveau->suivant=NULL;
	return liste;
}

int ch = 0;
static char *current;
void afficherSequences(listeSequence liste){
	int stop = 0;
	listeSequence li;
	li = liste;
	while(li != NULL){
		printf("%d\t%s\t : %s  %d\n",li->infos->numLigne,li->infos->nomToken,li->infos->codeToken, li->infos->ifNum);
		li=li->suivant;
	}
	return;
}
