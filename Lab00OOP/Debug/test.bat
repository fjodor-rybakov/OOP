REM запуск программы без параметров
04.exe
IF ERRORLEVEL 1 GOTO err

REM запуск программы с одним нечисловым параметром
04.exe notANumber
IF NOT ERRORLEVEL 1 GOTO err

REM запуск программы с пустой строкой в качестве одного из параметров
04.exe ""
IF NOT ERRORLEVEL 1 GOTO err

REM запуск программы с одним числовым параметром (и проверяем результат)
04.exe -123 > output.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt -123.txt
IF ERRORLEVEL 1 GOTO err

REM запуск программы с двумя числовыми параметрами
04.exe 15 2 > output.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt 15+2=17.txt
IF ERRORLEVEL 1 GOTO err

REM запуск программы с тремя числовыми параметрами
04.exe 15 2 -8 > output.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt 15+2+-8=9.txt
IF ERRORLEVEL 1 GOTO err

ECHO Program testing succeeded :-)

EXIT

:err
ECHO Program testing failed :-(
EXIT
