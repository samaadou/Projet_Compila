# Projet_Compila
#Grammaire utilisee

PROGRAM -> program ID ; PART
PART -> ENTITY PROG 
ENTITY -> entity ID is PORT endentity
PORT -> port (ID  : DIRECTION TYPE ;) ; | ε
PORT ::= port ( DDRX : DIR ; { DDRX : DIR ; } { FONCT } PROGRAM endProgram
DDRX ::= DDR LETTER DIGIT
DIR ::= IN | OUT
DIRECTION -> in | out | iout
PROG-> program ID is newline BLOCK endprogram
BLOCK -> DECL COMPONENT PROCESS INSTANCE
DECL ->  CONST SIGN FONCT
CONST -> const ID 
SIGN -> signal  ID : TYPE AFFECT ;
FONCT ->  VARTYPE ID ( PARAM ) : BLOCKF endFonct
COMPONENT -> component ID  PORT endcomponent
PROCESS -> ID process ( TYPE ID T )  P endprocess ;
INSTANCE -> 
P-> VAR 
VAR -> variable ID{ ,ID } : TYPE AFFECT ; | ε
LOOP ::= WHILE | DO | FOR
WHILE ::= while ( EXP ) : INSTF endWhile
DO ::= do INSTF while ( EXP ) endDo
FOR ::= for ( NUM ; NUM ; { NUM ; } ) : INSTF endFor
IF ::= if ( EXP ) : INSTF { else INSTF } endIf
READ ::= read ( ID )
WRITE ::= write ( ID )
AFFECT -> := EXPR
FOR -> for ID in range STEP do INSTRUCTIONS
STEP -> with EXPR
STEP -> ''
COND -> EXPR OP EXPR
OPRELAT -> = | <| > |<= | >= | /=
OPARITH ->  - | + | * | / | mod  | //
OPLOGIC -> and |or |xor |nand |nor 
CONCAT -> &
EXPR -> 
TYPE -> integer
TYPE -> real
TYPE -> natural
TYPE -> boo
ID-> LETTRE {LETTRE | CHIFFRE}
NUM -> CHIFFRE{ CHIFFRE }
CHIFFRE->     0|..|9
LETTRE -> a|b|..|z|A|..|Z
