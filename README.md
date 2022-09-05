# UE14500GAL

This is the implementation of [UE14500](https://github.com/Nakazoto/UEVTC/wiki/UE14500-Processor) using two GAL20V8B chips.

WinCUPL is required to build the PLD files, but output JED files are provided as well.

`clk-high-latch` is an alternative version that uses registered output for `FL0`, `JMP`, `RTN` and `FLF`. It means the flags will go high on the rising edge of the clock, and will be cleared on the risign edge of the next instruction.

## Wiring

`clk-high-* (HIGH)` chip is executing on rising edge

`clk-low (LOW)` is executing on the falling edge of the clock

`HIGH.CLKO` is connected to the `CLK` and `CLKIN` of `LOW`.

`HIGH.OEN` => `LOW.OEN_IN`

`HIGH.IEN` => `LOW.IEN_IN`

`LOW.RR` => `HIGH.RR_IN`

`LOW.SKZ` => `LOW.SKZ_IN`

Pins 1 and 2 of both chips are tied together

`DATAIN` and `IR` are connected in parallel

`!OE` is tied to the ground

Do not connect `NC` pins. Remaining unlabeled input pins already have internal pullups



```
        ____________________
       |      clk-high      |
   ----|>1 CLK       VCC 24 |----
   ----|>2 CLKIN   RR_IN 23 |----
   ----| 3 DATAIN   CLKO 22 |----
   ----| 4 IR3       IEN 21 |----
   ----| 5 IR2       OEN 20 |----
   ----| 6 IR1     DATAO 19 |----
   ----| 7 IR0       FLF 18 |----
   ----| 8           RTN 17 |----
   ----| 9           JMP 16 |----
   ----| 10          FL0 15 |----
   ----| 11       SKZ_IN 14 |----
   ----| 12 GND      /OE 13 |o---
       |____________________|


        ____________________ 
       |      clk-low       |
   ---o|>1 /CLK      VCC 24 |----
   ---o|>2 /CLKIN IEN_IN 23 |----
   ----| 3 DATAIN     NC 22 |----
   ----| 4 IR3       WRT 21 |----
   ----| 5 IR2         C 20 |----
   ----| 6 IR1        RR 19 |----
   ----| 7 IR0       SKZ 18 |----
   ----| 8            NC 17 |----
   ----| 9            NC 16 |----
   ----| 10           NC 15 |----
   ----| 11       OEN_IN 14 |----
   ----| 12 GND      /OE 13 |o---
       |____________________|
```
