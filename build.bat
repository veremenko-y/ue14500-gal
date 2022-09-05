@echo off
cupl -jalxfbusm2 c:\Wincupl\Shared\CUPL.DL .\clk-high.pld
if %errorlevel% neq 0 exit /b %errorlevel%
cupl -jalxfbusm2 c:\Wincupl\Shared\CUPL.DL .\clk-high-latch.pld
if %errorlevel% neq 0 exit /b %errorlevel%
cupl -jalxfbusm2 c:\Wincupl\Shared\CUPL.DL .\clk-low.pld
if %errorlevel% neq 0 exit /b %errorlevel%
rmdir out /S /Q  > nul
mkdir out  > nul
move *.abs out/  > nul
move *.doc out/  > nul
move *.jed out/  > nul
move *.lst out/  > nul
move *.pla out/  > nul
move *.sim out/  > nul
move *.so out/  > nul
move *.wo out/  > nul
echo Done
rem -kb  Optimize product term usage (overrides the DEMORGAN statement in file)
rem -kd  Demorganize all pins and pinnodes (overrides the DEMORGAN statement)
rem -ks  Force product term sharing (enable group reduction)
rem -kx  Do not exapnd XOR equations (virtual or fitter that supports XOR gates)
rem -m0  No minimization (no logic reduction)
rem -m1  Quick minimization (default. Lowest memory usage and fastest)
rem -m2  Quine-McCluskey minimization (highest memory usage and slowest.)
rem -m3  Presto minimization (good trade-off between memory and speed)
rem -m4  Espresso mimization (high memory usage and slow. Good for fitter designs)