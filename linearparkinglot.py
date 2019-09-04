motoristas = 100
max_vagas = 100
while(motoristas != 0 and max_vagas != 0):
    motoristas, max_vagas = input().split()
    fila_chegada = []
    pilha_saida = []
    for _ in range(motoristas):
        # Adicionando em duas pilhas os horários de 
        # Chegada e de saída, respectivamente:
        tempo = input().split()
        fila_chegada.append(tempo[0]) # queue
        pilha_saida.append(tempo[1]) # stack

    for _ in range(max_vagas):
        # Se o primeiro a chegar tentar sair antes de outro 
        # motorista, não irá funcionar.
        if (fila_chegada.popleft() < pilha_saida.pop()):
            print("Não")
        # ! Falta comparar os horários de saída de cada motorista com o próximo.
        # ! Se o horário de saída < hr entrada do próximo, pass

