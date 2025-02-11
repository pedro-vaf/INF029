@echo off
echo Compilando o programa...

:: Compilando os arquivos .c para .o
gcc -c mainTesteArquivos.c -o mainTesteArquivos.o
gcc -c EstruturaVetores.c -o EstruturaVetores.o
chcp 1252

:: Criando o executável
gcc mainTesteArquivos.o EstruturaVetores.o -o programa.exe

:: Verifica se o executável foi criado com sucesso
if exist programa.exe (
    echo Compilado com sucesso!
    echo Executando o programa...
    programa.exe
) else (
    echo Falha na compilação.
)

pause
