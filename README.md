# Projet_Compila
#Grammaire utilisee

**PROGRAM -> program ID ; PART

**PART -> ENTITY PROG 

**ENTITY -> entity ID is PORT endentity

**PORT -> port (ID  : DIRECTION TYPE ;) ; | ε

**PORT ::= port ( DDRX : DIR ; { DDRX : DIR ; } { FONCT } PROGRAM endProgram

**DDRX ::= DDR LETTER DIGIT

**DIR ::= IN | OUT

**DIRECTION -> in | out | iout

**PROG-> program ID is newline BLOCK endprogram

**BLOCK -> DECL COMPONENT PROCESS INSTANCE

**DECL ->  CONST SIGN FONCT

**CONST -> const ID 

**SIGN -> signal  ID : TYPE AFFECT ;

**FONCT ->  VARTYPE ID ( PARAM ) : BLOCKF endFonct

**COMPONENT -> component ID  PORT endcomponent

**PROCESS -> ID process ( TYPE ID T )  P endprocess ;
 
**P-> VAR 

**VAR -> variable ID{ ,ID } : TYPE AFFECT ; | ε

**LOOP ::= WHILE | DO | FOR

**WHILE ::= while ( EXP ) : INSTF endWhile

**DO ::= do INSTF while ( EXP ) endDo

**FOR ::= for ( NUM ; NUM ; { NUM ; } ) : INSTF endFor

**IF ::= if ( EXP ) : INSTF { else INSTF } endIf

**READ ::= read ( ID )

**WRITE ::= write ( ID )

**AFFECT -> := EXPR

**STEP -> with EXPR

**STEP -> ''

**COND -> EXPR OP EXPR

**OPRELAT -> = | <| > |<= | >= | /=

**OPARITH ->  - | + | * | / | mod  | //

**OPLOGIC -> and |or |xor |nand |nor

**CONCAT -> &

**TYPE -> integer

**TYPE -> real

**TYPE -> natural

**TYPE -> boo

**ID-> LETTRE {LETTRE | CHIFFRE}

**NUM -> CHIFFRE{ CHIFFRE }

**CHIFFRE->     0|..|9

**LETTRE -> a|b|..|z|A|..|Z
--------------------------------------------------------------------------------------------------------------
PORT ::= port ( DDRX : DIR ; { DDRX : DIR ; } ) { FONCT } PROGRAM endProgram
DDRX ::= DDR LETTER DIGIT
DIR ::= IN | OUT
FONCT ::= VARTYPE ID ( PARAM ) : BLOCKF endFonct 
PROGRAM ::= program : BLOCKF
PARAM ::= VARTYPE ID { , VARTYPE ID }
BLOCKF ::= DECLVAR |  INSTF ; | ɛ
DECLVAR ::= { static } { const } VARTYPE ID { = EXP } { , VARTYPE ID { = EXP } } ; BLOCKF
INSTF ::= INST | EXPR | RETURN { EXPR }
INST ::= BLOCKF | LOOP | IF | READ | WRITE | DELAY | ɛ
DELAY ::= wait ( NUM ) 
LOOP ::= WHILE | DO | FOR 
WHILE ::= while ( EXP ) : INSTF endWhile
DO ::= do INSTF while ( EXP ) endDo
FOR ::= for ( NUM ; NUM ; { NUM ; } ) : INSTF endFor
IF ::= if ( EXP ) : INSTF { else INSTF } endIf 
READ ::= read ( ID )
WRITE ::= write ( ID )
EXP ::= ID | AFFECT | AFFECTARITH | AFFECTLOG | CALLFONC | PORTX | PINX
PORTX ::= PORT LETTER DIGIT
PINX::= PIN LETTER DIGIT
AFFECT ::= EXP <- EXP
AFFECTARITH ::= EXP ARITH EXP | ~ EXP
ARITH ::= + | - | * | / | % 
AFFECTLOG ::= EXP LOG EXP | ! EXP COMP EXP 
LOG ::= && | || 
COMP ::= < | ≤ | > | ≥ | = | != 
CALLFONC ::= EXP ( EXP { , EXP } )
VARTYPE ::= { unsigned | signed } char | { unsigned | signed } int | float | double | void
ID ::= LETTER { LETTER | DIGIT }
NUM ::= DIGIT { DIGIT }
DIGIT ::= 0|..|9
LETTER ::= a|b|..|z|A|..|Z
