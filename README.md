Grammaire Utilise :

**PORTT ::= port ( DDRX : DIR ; { DDRX : DIR ; } ) { FONCT } PROGRAM endProgram

**DDRX ::= DDR LETTER DIGIT
**DIR ::= IN | OUT
**FONCT ::= VARTYPE ID ( PARAM ) : BLOCKF return EXP endFonct
**PROGRAM ::= program : BLOCKF
**PARAM ::= VARTYPE ID { , VARTYPE ID }
**BLOCKF ::= DECLVAR | INSTFF
**INSTFF ::= INSTF ;
**DECLVAR ::= { static } { const } VARTYPE ID { <- EXP } { , VARTYPE ID { <- EXP } } ;
**BLOCKF
**INSTF ::= INST
**INST ::= LOOP | IF | READ | WRITE | DELAY | INTERRUPT | ID X | ε
**X ::= AFFECT | CALLFONC
**INTERRUPT ::= sei() ; EXTINTERRUPT | PCINTERRUPT
**EXTINTERRUPT ::= eInterrupt ( FRONT , INT , DIGIT ) ( INSTFF ) endInter
**FRONT ::= up | down
**PCINTERRUPT ::= pcInterrupt ( PCX , PCINTX , DIGIT ) ( INSTFF ) endInter
**PCX ::= PC NUM
**PCINTX ::= PCINT NUM
**INT ::= INT0 | INT1
**DELAY ::= wait ( NUM )
**LOOP ::= WHILE | DO | FOR
**WHILE ::= while ( EXP ) : INST endWhile
**DO ::= do INST ( EXP ) endDo
**FOR ::= for ( NUM ; NUM ; { NUM ; } ) : INST endFor
**IF ::= if ( EXP ) : INST { else INST } endIf
**READ ::= read ( PINX )
**WRITE ::= write ( PORTX )
**EXP ::= EXPR RELOP
**EXPR ::= ID | NUM | ( EXP )
**RELOP ::= AFFECTARITH | AFFECTLOG | ε
**PORTX ::= PORT LETTER DIGIT
**PINX::= PIN LETTER DIGIT
**AFFECT ::= <- EXPR
**AFFECTARITH ::= + | - | * | / | %
**AFFECTLOG ::= LOG | COMP
**LOG ::= && | ||
**COMP ::= < | ≤ | > | ≥ | = | !=
**CALLFONC ::= ( ID )
**VARTYPE ::= char | { unsigned | signed } int | float | double | void
**ID ::= LETTER { LETTER | DIGIT }
**NUM ::= DIGIT { DIGIT }
**DIGIT ::= 0|..|9
**LETTER ::= a|b|..|z|A|..|Z
**PORTT port
**DDRX DDR
**DIR IN, OUT
**FONCT Char, unsigned , signed , int
**float, double, void
**PROGRAM program
**PARAM Char, unsigned , signed , int
**float, double, void
**BLOCKF Static, const, char, unsigned ,
**signed , int float, double, void,
**While, wait, for, do, sei(), if,
**write, read, a|b|..|z|A|..|Z, ε
**INSTFF While, wait, for, do, sei(), if,
**write, read, a|b|..|z|A|..|Z, ε
**DECLARVAR Static, const, char, unsigned ,
**signed , int float, double, void
**INSTF While, wait, for, do, sei(), if,
**write, read, a|b|..|z|A|..|Z, ε
**INST While, wait, for, do, sei(), if,
**write, read, a|b|..|z|A|..|Z, ε
**X ←, (
**INTERRUPT sei()
**EXTINTERRUPT eInterrupt
**FRONT Up, down
**PCINTERRUPT pcInterrupt
**PCX PC
**PCINTX PCINT
**INT INT0, INT1
**DELAY wait
**LOOP While, do, for
**WHILE while
**DO do
**FOR for
**IF if
**READ read
**WRITE write
**EXP a|b|..|z|A|..|Z, 0|..|9, (
**EXPR a|b|..|z|A|..|Z, 0|..|9, (
**RELOP +, -, *, %,< , ≤ , > , ≥ , = , != ,
**&&, || ε
**PORTX PORT
**PINX PIN
**AFFECT <-
**AFFECTARITH +, -, *, %
**AFFECTLOG &&, ||, < , ≤ , > , ≥ , = , !=
**LOG &&, ||
**COMP < , ≤ , > , ≥ , = , !=
**CALLFONC (
**VARTYPE Char, unsigned, signed, int, float,
**double, void
**ID a|b|..|z|A|..|Z
**NUM 0|..|9
**DIGIT 0|..|9
**LETTER a|b|..|z|A|..|Z
