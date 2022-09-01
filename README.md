# UE14500GAL

This is the implementation of [UE14500](https://github.com/Nakazoto/UEVTC/wiki/UE14500-Processor) using two GAL20V8B chips.

WinCUPL is required to build the PLD files, but output JED files are provided as well.

## Wiring

`clk-high (HIGH)` chip is executing on rising edge while

`clk-low (LOW)` is executing on the falling edge of the clock

`HIGH.CLKO` is connected to the `CLK` and `CLKIN` of `LOW`.

`HIGH.OEN` => `LOW.OEN_IN`

`HIGH.IEN` => `LOW.IEN_IN`

`LOW.RR` => `HIGH.RR_IN`

`LOW.SKZ` => `LOW.SKZ_IN`

Pins 1 and 2 of both chips are tied together

`DATAIN` and `IR` are connected in parallel

`!OE` is tied to the ground


```
        __________________
       |     clk-high     |
   x---|1    CLK VCC    24|---x
   x---|2  CLKIN RR_IN  23|---x
   x---|3 DATAIN CLKO   22|---x
   x---|4    IR3 IEN    21|---x
   x---|5    IR2 OEN    20|---x
   x---|6    IR1 DATAO  19|---x
   x---|7    IR0 FLF    18|---x
   x---|8        RTN    17|---x
   x---|9        JMP    16|---x
   x---|10       FL0    15|---x
   x---|11       SKZ_IN 14|---x
   x---|12   GND !OE    13|---x
       |__________________|


        __________________
       |     clk-low      |
   x---|1    CLK VCC    24|---x
   x---|2  CLKIN IEN_IN 23|---x
   x---|3 DATAIN        22|---x
   x---|4    IR3 WRT    21|---x
   x---|5    IR2 C      20|---x
   x---|6    IR1 RR     19|---x
   x---|7    IR0 SKZ    18|---x
   x---|8               17|---x
   x---|9               16|---x
   x---|10              15|---x
   x---|11       OEN_IN 14|---x
   x---|12   GND !OE    13|---x
       |__________________|
```
