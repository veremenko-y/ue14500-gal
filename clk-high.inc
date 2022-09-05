/* Inputs */

Pin 1 = CLK ;
Pin 2 = CLKIN ;
Pin 3 = DATAIN ;
Pin [4..7] = [IR3..0] ;
Pin 23 = RR_IN ;
Pin 14 = SKZ_IN ;
Field IR = [IR3..0] ;

Pin 12 = GND ;
Pin 24 = VCC ;

/* Outputs */

Pin 15 = FL0 ;
Pin 16 = JMP ;
Pin 17 = RTN ;
Pin 18 = FLF ;
Pin 19 = DATAOUT ;
Pin 20 = OEN ;
Pin 21 = IEN ;
Pin 22 = CLKOUT ;

$IFDEF LATCHED_FLAGS

$DEFINE FL0Out FL0.D
$DEFINE JMPOut JMP.D
$DEFINE RTNOut RTN.D
$DEFINE FLFOut FLF.D

$ELSE

$DEFINE FL0Out FL0
$DEFINE JMPOut JMP
$DEFINE RTNOut RTN
$DEFINE FLFOut FLF

$ENDIF

/* Intermediate */

Field IRGated = [IRG3..0] ;
IRGated = IR & !SKZ_IN # 'b'1111 & SKZ_IN;

/* Definition */

/* NOP0 */
FL0Out = IRGated:'b'0000 ;

/* JMP */
JMPOut = IRGated:'b'1100 ;

/* RTN */
RTNOut = IRGated:'b'1101 ;

/* FLF */
FLFOut = IRGated:'b'1111 & !SKZ_IN ;

/* STO */
Append
DATAOUT = IRGated:'b'1000 & OEN & RR_IN ;

/* STOC */
Append
DATAOUT = IRGated:'b'1001 & OEN & !RR_IN ;

/* IEN */
IEN.D = IRGated:'b'1010 & DATAIN 
    # !(IRGated:'b'1010) & IEN ;

/* OEN */
OEN.D = IRGated:'b'1011 & DATAIN # !(IRGated:'b'1011) & OEN ;

/* Misc. Inverted clock for the second stage */
CLKOUT = !CLKIN;
