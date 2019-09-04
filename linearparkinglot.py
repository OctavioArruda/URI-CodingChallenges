motoristas = 100
max_vagas = 100
while(motoristas != 0 and max_vagas != 0):
    motoristas, max_vagas = input().split()
    lista_chegada = []
    pilha_saida = []
    chegada_saida = []
    motoristas_consecutivos = []

    chegada_saida = input().strip().split()
    lista_chegada.append(int(chegada_saida[0])) # queue
    pilha_saida.append(int(chegada_saida[1])) # stack
    motoristas_consecutivos.append(int(chegada_saida[1]))
    for _ in range(int(motoristas)):
        # Adicionando em duas pilhas os horários de 
        # Chegada e de saída, respectivamente:

        # Comparar se o motorista atual vai sair antes do próximo, o que faria continuar as iteraçoes,
        # subtraindo um
        chegada_saida_proximo_motorista = input().strip().split()
        print(chegada_saida_proximo_motorista)
        # Nessa lista haverão sempre o horário de motorista de saída e o de chegada do próximo
        motoristas_consecutivos.append(int(chegada_saida_proximo_motorista[1]))
        motoristas_consecutivos.append(int(chegada_saida_proximo_motorista[0]))

        # Comparar se o primeiro a chegar é o último a sair:
        lista_chegada.append(int(chegada_saida_proximo_motorista[0])) # queue
        pilha_saida.append(int(chegada_saida_proximo_motorista[1])) # stack

    fila_chegada = lista_chegada.reverse()
    count = 0 
    print(lista_chegada)
    print(pilha_saida)
    while (count < int(max_vagas)):
        # Se o primeiro a chegar tentar sair antes de outro 
        # motorista, não irá funcionar.

        if (fila_chegada.pop() < pilha_saida.pop()):
            erro = True
        
        if (motoristas_consecutivos[count] <= motoristas_consecutivos[count + 1]):
            # Se um motorista sair antes de outro entrar, o número de vagas livres diminui
            count = count - 1
        else:
            count = count + 1

    if (erro):
        print("Não")
    else:
        print("Sim")

