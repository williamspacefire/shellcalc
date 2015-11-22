/**
* 
*    Shellcalc, Uma calculadora simples em C++
* 
*    Copyright (C) 2015  Spacefire, inc.
*
*    This program is free software; you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation; either version 2 of the License, or
*    (at your option) any later version.
*
*    This program is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.
*
*    You should have received a copy of the GNU General Public License along
*    with this program; if not, write to the Free Software Foundation, Inc.,
*    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*
* @copyright    Spacefire, inc.
* @author       William Spacefire
* @category     Calculadora
* @version      0.1
*/

#include <iostream>

using namespace std;

/**
* Protótipo das funções
*/
int soma(int x, int y);
int sub(int x, int y);
int mult(int x, int y);
int div(int x, int y);

/*
 * Inicio do Programa
 */
int main(int argc, char** argv) {
    
    /**
    * Todas as Variáveis a serem usadas no programa.
    */
    int* n = new int[2]; // Aloca memoria para dois inteiros
    char op;
    int ok;
    int ops[] = {'1','2','3','4','5'}; //Vetores com as opções a serem escolhidas
    char* iu = ">>> ";
    char sym;
    char* w;
    
    /**
    * Imprime a mensagem inicial do programa
    */
    cout << "Shellcalc, uma calculadora básica em linha de comando\nEscolha uma opção:\n1 - (+) Adição\n2 - (-) Subtração\n3 - (*x) Multiplicação\n4 - (/) Divisão\n5 - Sair\n\n";
    
    /**
    * Verifica se foi passado algum argumento, e armazena numa variável e vai para ARG: .
    */
    if(argc > 1){
        w = argv[1];
        if(w[0] == '+'){
            w[0] = '1';
        }else if(w[0] == '-'){
            w[0] = '2';
        }else if(w[0] == 'x'){ // Algo deu errado então no lugar de "*" coloca "x".
            w[0] = '3';
        }else if(w[0] == '/'){
            w[0] = '4';
        }else{
            goto OP;
        }
        op = w[0]; //Armazena a opção passada por argumento em op.
        goto ARG;
    }
    
    OP:
    cout << iu; // Imprime ">>>".
    cin >> op; //armazena a opção escolhida na variável op.
    
    ARG:
    
    /**
    * verifica a opção escolhida e armazena o símbolo dela em sym, se for escolhido 5
    * sai do programa
    */
    for(int c = 0; c <=4; c++){
        if(ops[c] == op){
            ok = op;
            if((char)op == '1'){
                sym = '+';
            }else if((char)op == '2'){
                sym = '-';
            }else if((char)op == '3'){
                sym = '*';
            }else if((char)op == '4'){
                sym = '/';
            }else if((char)op == '5'){
                cout << "Saindo...\n";
                return 0;
            }
            break;
        }
        if(c == 4) goto OP; // se nenhuma opção foi escolhida volta para OP: .
    }
    
    cout << "Digite o Primeiro número e pressione [Enter]\n" << iu;
    cin >> n[0];
    cout << iu << n[0] << " " << sym << " "; // Imprime o primeiro número mais o símbolo da opção escolhida
    cin >> n[1];
    
    /**
    * Verifica qual a opração a ser feita e imprime o resultado.
    */
    if(sym == '+'){
        cout << soma(n[0], n[1]);
    }else if(sym == '-'){
        cout << sub(n[0], n[1]);
    }else if(sym == '*'){
        cout << mult(n[0], n[1]);
    }else if(sym == '/'){
        cout << div(n[0], n[1]);
    }else{
        cout << "Oooops! Algo deu errado, verifique se você digitou tudo certo.";
    }
    cout << "\n";
    
    goto OP; // depois de imprimir o resultado volta para OP: , para escolher outra opção.
    return 0;
}

/*
* Retorna a soma
*/
int soma(int x, int y){
    return (x+y);
}

/*
* Retorna a Subtração
*/
int sub(int x, int y){
    return (x-y);
}

/*
* Retorna a Multiplicação
*/
int mult(int x, int y){
    return (x*y);
}

/*
* Retorna a Divisão
*/
int div(int x, int y){
    return (x/y);
}
