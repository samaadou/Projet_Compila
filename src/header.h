#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <string.h>
#include <ctype.h>

#define Malloc(type) (type*)malloc(sizeof(type))

#define TRUE    1
#define FALSE   0

#define NUMKEYWORDTOKEN 35
#define NUMSPECIALTOKEN 19
#define NUMPORTTOKEN 27
#define NUMPCIETOKEN 46

typedef enum 
{
	ENDPROGRAM, IN, OUT, RETURN, ENDFONCT, PROGRAM, SEI, EINTERRUPT, PCINTERRUPT, ENDINTER, UP, DOWN, INT0, INT1, WAIT, WHILE, ENDWHILE, DO, ENDDO, FOR, ENDFOR, IF, ELSE, ENDIF, READ, WRITE, CHAR, UNSINT, SINT, INT, FLOAT, DOUBLE, VOID, STATIC, CONST 
} keyword_token;
typedef enum 
{
	DDRB, DDRB0, DDRB1, DDRB2, DDRB3, DDRB4, DDRB5, DDRB6, DDRB7, DDRD, DDRD0, DDRD1, DDRD2, DDRD3, DDRD4, DDRD5, DDRD6, DDRD7, DDRC, DDRC0, DDRC1, DDRC2, DDRC3, DDRC4, DDRC5, DDRC6
} port_token;
typedef enum 
{
	PV, MOD, PLUS, MOINS, MULT, DIV, VIR, AFF, INF, INFEG, SUP, SUPEG, DIFF, PO, PF, EG, AND, OR, DP
} special_token;
typedef enum 
{
	PCINT0, PB0, PCINT1, PB1, PCINT2, PB2, PCINT3, PB3, PCINT4, PB4, PCINT5, PB5, PCINT6, PB6, PCINT7, PB7, PCINT8, PC0, PCINT9, PC1, PCINT10, PC2, PCINT11, PC3, PCINT12, PC4, PCINT13, PC5, PCINT14, PC6, PCINT16, PD0, PCINT17, PD1, PCINT18, PD2, PCINT19, PD3, PCINT20, PD4, PCINT21, PD5, PCINT22, PD6, PCINT23, PD7
} pcie_token;
typedef enum 
{
	PORT, PORTB, PORTB0, PORTB1, PORTB2, PORTB3, PORTB4, PORTB5, PORTB6, PORTB7, PORTD, PORTD0, PORTD1, PORTD2, PORTD3, PORTD4, PORTD5, PORTD6, PORTD7, PORTC, PORTC0, PORTC1, PORTC2, PORTC3, PORTC4, PORTC5, PORTC6
} por_token;
typedef enum 
{
	PINB, PINB0, PINB1, PINB2, PINB3, PINB4, PINB5, PINB6, PINB7, PIND, PIND0, PIND1, PIND2, PIND3, PIND4, PIND5, PIND6, PIND7, PINC, PINC0, PINC1, PINC2, PINC3, PINC4, PINC5, PINC6
} pin_token;

FILE* fichier ;

#define codeTaille    20
#define nomTaille     20

typedef struct{
	int line;
    char code[codeTaille];
    char nom[nomTaille];
} Token;
//Structure to store tokens
typedef struct {
	int numLigne;
	char nomToken[nomTaille]; 
	char codeToken[codeTaille]; 
	int ifNum;
}chaineToken;

typedef struct _noeud {
	chaineToken *infos;
	struct _noeud *suivant;
}noeud;

typedef noeud *listeSequence;

listeSequence L;

#define MAXNUM 	 11
#define MAXCHAR  20

char car_cour;
Token token_cour;
// ########################################Lexical####################################################################

extern void SymboleSuiv();
extern char CarSuiv();
extern void Erreur();
extern void Separateur();
extern bool lire_mot();
extern bool lire_nombre();
extern bool lire_car();
extern chaineToken* importToken(int nligne, char *nom, char *code);
extern listeSequence insererSequence(chaineToken *seq,listeSequence liste);
extern void afficherSequences(listeSequence list);

// ########################################Syntaxique####################################################################

bool verifyToken(char *code);
void Port();
void VarTypeId();
void Fonct();
void DeclarVar();
void BlockF();
void Exp();
void Expr();
bool Inst();
void If();
void Write();
void Read();
void Wait();
void Do();
void For();
void Aff();
void CallF();
void eInterrupt();
void pcInterrupt();
void While();
void Program();
#endif
