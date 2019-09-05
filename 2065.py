# dados:
n, m = input().split() # n = nro funcionários, m = nro clientes na fila
dic_n = [] # dicionario com o tempo dos funcionarios e seu numero
list_m = [] # lista de itens dos m-ésimos clientes
tempo_total = 0.00 # tempo total de processamento

for i in range(int(n)):
    dic_n[i] = 0 # Para cada funcionario, inicializa seu tempo de ocupação em zero.
for _ in range(int(m)):
    list_m.append(int(input()))

count = int(n)
while (count > int(m)):
    # Enquanto houverem funcionários livres, ocupa todos:
