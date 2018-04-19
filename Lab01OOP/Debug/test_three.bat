@ECHO OFF

ECHO 1) Check empty params
multmatrix.exe
IF NOT ERRORLEVEL 1 GOTO err

ECHO 2) Check one params
multmatrix.exe matrixOne.txt
IF NOT ERRORLEVEL 1 GOTO err

ECHO 3) Check right params
multmatrix.exe matrixOne.txt emptyMatrix.txt
IF NOT ERRORLEVEL 1 GOTO err

ECHO 4) Expected result check
multmatrix.exe matrixOne.txt matrixTwo.txt > output.txt
IF ERRORLEVEL 1 GOTO err
FC output.txt mult1.txt
IF ERRORLEVEL 1 GOTO err

ECHO 5) Expected result check
multmatrix.exe matrixTwo.txt matrixOne.txt > output.txt
IF ERRORLEVEL 1 GOTO err
FC output.txt mult2.txt
IF ERRORLEVEL 1 GOTO err

ECHO 6) Expected result check
multmatrix.exe matrixTwo.txt matrixO.txt > output.txt
IF ERRORLEVEL 1 GOTO err
FC output.txt mult3.txt
IF ERRORLEVEL 1 GOTO err

ECHO Program testing succeeded :-)
EXIT

:err
ECHO Program testing failed :-(
EXIT