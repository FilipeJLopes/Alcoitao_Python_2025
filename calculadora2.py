a=0
b=0
operacao="operador"
erro = "Ocorreu erro: "

def obter_primeiro_valor():
    try:
        global a
        a=float(input("Escreva um número para a próxima operação: "))

    except Exception as e:
        print(erro + str(e))
        print("Por favor, digite um valor válido.")
        obter_primeiro_valor()

    else:
        print(f"Primeiro valor: {a}")
        escolher_operacao()

def escolher_operacao():
    try:
        global operacao
        operacao=str(input("Que operação pretende realizar?\n" \
        "soma >> +\n" \
        "subtração >> -\n" \
        "multiplicação >> *\n" \
        "divisão >> /\n" \
        "Utilize os símbolos para escolher: "))

    except Exception as e:
        print(erro + str(e))
        print("Por favor, digite um símbolo válido.")
        escolher_operacao()
    
    else:
        print(f"\nEscolheu: {operacao}\n")
        obter_segundo_valor()

def obter_segundo_valor():
    try:
        global b
        b=float(input(f"Escreva o segundo número para a operação escolhida:\n{a} {operacao} "))

    except Exception as e:
        print(erro + str(e))
        print("Por favor, digite um valor válido.")
        obter_segundo_valor()

    else:
        print(f"Segundo valor: {b}")
        realizar_operacao()

def realizar_operacao():
    if operacao=="+":
        resultado=a+b
        print(f"Resultado da soma: {a} + {b} = {resultado}")
    elif operacao=="-":
        resultado=a-b
        print(f"Resultado da subtração: {a} - {b} = {resultado}")
    elif operacao=="*":
        resultado=a*b
        print(f"Resultado da multiplicação: {a} * {b} = {resultado}")
    elif operacao=="/":
        if b!=0:
            resultado=a/b
            print(f"Resultado da divisão: {a} / {b} = {resultado}")
        else:
            print("Não é possível dividir por zero! Tente de novo.")
            escolher_operacao()

def calculadora():
    obter_primeiro_valor()

calculadora()