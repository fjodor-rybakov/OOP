@ECHO OFF

ECHO 1) Check empty params
findtext.exe
IF NOT ERRORLEVEL 1 GOTO err

ECHO 2) Check one params
findtext.exe "text.txt"
IF NOT ERRORLEVEL 1 GOTO err

ECHO 3) Expected result check
findtext.exe "text.txt" ores > output.txt
IF ERRORLEVEL 1 GOTO err
FC output.txt one_text.txt
IF ERRORLEVEL 1 GOTO err

ECHO 4) Expected result check
findtext.exe "text.txt" work > output.txt
IF ERRORLEVEL 1 GOTO err
FC output.txt two_text.txt
IF ERRORLEVEL 1 GOTO err

ECHO 5) Check for a non-existent result
findtext.exe "text.txt" blood > output.txt
IF NOT ERRORLEVEL 1 GOTO err
FC output.txt text_not_found.txt
IF ERRORLEVEL 1 GOTO err

ECHO 6) Expected result check
findtext.exe "text.txt" of > output.txt
IF ERRORLEVEL 1 GOTO err
FC output.txt third_text.txt
IF ERRORLEVEL 1 GOTO err

ECHO Program testing succeeded :-)
EXIT

:err
ECHO Program testing failed :-(
EXIT