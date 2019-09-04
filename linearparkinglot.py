#!python
erro = False
while True:
    erro = False
    n, k = input().split()
    if int(n) == 0 and int(k) == 0:
        break
    stack = []
    for _ in range(int(n)):
        chegada, saida = input().split()
        if len(stack) == 0:
            # primeiro carro
            stack.append([chegada, saida])
        elif int(chegada) > int(stack[-1][1]):
            # chegou depois que o anterior saiu
            stack.pop()                     # tira anterior
            stack.append([chegada, saida])  # estaciona atual
        elif int(saida) <= int(stack[-1][1]):
            stack.append([chegada, saida])  # vai sair antes que o anterior, estaciona atual
            # check qt de carros
            if len(stack) > int(k):
                erro = True
                break
        else:
            # deu ruim
            erro = True
            break
    # confere situação final
    if len(stack) > 1 and int(stack[-1][1]) > int(stack[-2][1]) and erro == True:
        print("Nao")
        continue
    else:
        print("Sim")
