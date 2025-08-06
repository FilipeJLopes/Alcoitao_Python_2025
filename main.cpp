#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

int ler_inteiro() {
    int numero;

    while (true) {
        cout<<"Insira o numero inteiro: "<<endl;

        cin>>numero;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout<<"Invalido."<<endl;
        } else if (numero%1 != 0) {
            cout<<"nao e inteiro!"<<endl;
        } else return numero;
    }

}

float ler_float() {
    float numero;

    while (true) {
        cout<<"Insira o numero: "<<endl;

        cin>>numero;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout<<"Invalido."<<endl;
        } else return numero;
    }

}

int menu() {
    ifstream ficheiro("menu_calculadora.txt");

    if (!ficheiro) {
        cerr << "Ficheiro nao encontrado!" << endl;
        exit(0);
    }

    string linha;

    while (getline(ficheiro, linha)) {
        cout << linha << endl;
    }

    ficheiro.close();

    int opcao=0;
    while (opcao <1 || opcao > 15) {
        cout<<"\nQue operacao deseja realizar?(1-15) "<<endl;
        cin>>opcao;

        if (opcao <1 || opcao > 15 || cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout<<"Opcao invalida! Escolha entre 1 e 15"<<endl;
        }
    }

    return opcao;

}

float somar() {
    float soma=0.0;
    float num1 = ler_float();
    float num2 = ler_float();
    soma=num1+num2;

    return soma;
}

float subtrair() {
    float subtracao=0.0;
    float num1 = ler_float();
    float num2 = ler_float();
    subtracao=num1-num2;

    return subtracao;
}

float multiplicar() {
    float multiplicacao=0.0;
    float num1 = ler_float();
    float num2 = ler_float();
    multiplicacao=num1*num2;

    return multiplicacao;
}

float dividir() {
    float divisao=0.0;
    float num1 = ler_float();
    float num2 = ler_float();

    while (num2==0.0) {
        cout<<"Nao e possivel dividir por zero! Escolha outro numero." << endl;
        num2=ler_float();
    };

    divisao=num1/num2;

    return divisao;
}

float potencia(int num1, int num2) {
    int potencia=num1;

    if (num2==0) {
        return 1;
    }

    for (int i=2; i<=num2; i++) {
        potencia=potencia*num1;
    }

    return potencia;
}

double raiz(int num1, int num2) {
    double raiz;

    if (num2==2) {
        raiz=sqrt(num1);
    }
    else if (num2==3) {
        raiz=cbrt(num1);
    }

    return raiz;
}

float absoluto() {
    float num1=ler_float();
    float absoluto=abs(num1);
    return absoluto;
}

int fatorial() {
    int num1=ler_inteiro();

    int fatorial=num1;

    for (int i=1; i<num1; i++) {
        fatorial=fatorial*(num1-i);
    }

    return fatorial;
}

double logaritmo(float base=10) {
    float numero=ler_float();
    double log;

    if (base==10) {
        log=log10(numero);
    }
    else log=log10(numero)/log10(base);

    return log;
}

float hipotenusa() {
    cout<<"Qual o valor do cateto a? ";
    float a = ler_float();
    cout<<"Qual o valor do cateto b? ";
    float b = ler_float();

    return sqrt(potencia(a,2)+potencia(b,2));
}

void formula_resolvente() {
    cout<<"Qual o valor de a? ";
    float a = ler_float();
    cout<<"Qual o valor de b? ";
    float b = ler_float();
    cout<<"Qual o valor de c? ";
    float c = ler_float();

    float pot= potencia(b,2);

    float independente=4*a*c;

    if (pot-independente<0) {
        cout<<"A equacao nao tem raizes reais"<<endl;
    }
    else {
        float raiz= sqrt(pot-independente);

        float x_positivo=(-b+raiz)/(2*a);
        float x_negativo=(-b-raiz)/(2*a);

        cout<<"O resultado e: {"<<x_positivo<<", "<<x_negativo<<"}"<<endl;
    }
}

int main() {
    float resultado;

    string continuar="";
    while (continuar!="n") {
        switch (int opcao_main = menu()) {
            case 1: {
                resultado = somar();

                cout<<"O resultado da soma e : "<<resultado<<endl;
                break;
            }
            case 2: {
                resultado = subtrair();

                cout<<"O resultado da subtracao e : "<<resultado<<endl;
                break;
            }
            case 3: {
                resultado = multiplicar();

                cout<<"O resultado da multiplicacao e : "<<resultado<<endl;
                break;
            }
            case 4: {
                resultado = dividir();

                cout<<"O resultado da divisao e : "<<resultado<<endl;
                break;
            }
            case 5: {
                int num=ler_inteiro();
                resultado = potencia(num,2);

                cout<<"O quadrado de "<<num<<" e : "<<resultado<<endl;
                break;
            }
            case 6: {
                int num=ler_inteiro();
                resultado = raiz(num,2);

                cout<<"A raiz quadrada de "<<num<<" e : "<<resultado<<endl;
                break;
            }
            case 7: {
                int num=ler_inteiro();
                resultado = potencia(num,3);

                cout<<"O cubo de "<<num<<" e : "<<resultado<<endl;
                break;
            }
            case 8: {
                int num=ler_inteiro();
                resultado = raiz(num,3);

                cout<<"A raiz cubica de "<<num<<" e : "<<resultado<<endl;
                break;
            }
            case 9: {
                int num=ler_inteiro();
                int num_2=ler_inteiro();
                resultado = potencia(num,num_2);

                cout<<num<<" elevado a "<<num_2<<" e : "<<resultado<<endl;
                break;
            }
            case 10: {
                resultado = absoluto();

                cout<<"O valor absoluto e : "<<resultado<<endl;
                break;
            }
            case 11: {
                resultado = fatorial();

                cout<<"O fatorial e : "<<resultado<<endl;
                break;
            }
            case 12: {
                resultado = logaritmo();

                cout<<"O logaritmo de base 10 e : "<<resultado<<endl;
                break;
            }
            case 13: {
                cout<< "Qual o valor da base? ";
                float num2=ler_float();
                resultado = logaritmo(num2);

                cout<<"O logaritmo de base "<< num2 <<" e : "<<resultado<<endl;
                break;
            }
            case 14: {
                resultado = hipotenusa();

                cout<<"A hipotenusa e : "<<resultado<<endl;
                break;
            }
            case 15: {
                formula_resolvente();

                break;
            }
            default: {
                cout<<"Opcao invalida!"<<endl;
            }
        }

        continuar="";
        while (continuar!="n" && continuar!="s") {
            cout<<"\nDeseja realizar outra operacao?(s/n) "<<endl;
            cin >> continuar;
            if (continuar!="n" && continuar!="s") {
                cout<<"Resposta invalida. Responda com 's' ou 'n', por favor."<<endl;
            }
            else if (continuar=="n") {
                cout<<"\nAte a proxima!\n\nFim da calculadora."<<endl;
            }
        }

    }

    return 0;
}
