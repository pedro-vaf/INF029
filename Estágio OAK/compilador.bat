@echo off
echo Compilando o programa...

:: Compilando os arquivos .c para .o
gcc -c main.c -o main.o
gcc -c produto/produto.c -o produto.o
chcp 1252

:: Criando o executável
gcc main.o produto.o -o programa.exe

:: Verifica se o executável foi criado com sucesso
if exist programa.exe (
    echo Compilado com sucesso!
    echo Executando o programa...
    programa.exe
) else (
    echo Falha na compilação.
)

pause
