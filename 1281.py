qnt_idas = int(input())
for i in range(qnt_idas):
	nro_produtos = int(input())
	produtos_dicionario = {}
	total = 0.00
	for j in range(nro_produtos):
		produto = input().split()
		produtos_dicionario[produto[0]] = produto[1] # Dicionário com nome - valor do produto
	nro_compras = int(input())
	for _ in range(nro_compras):
		produto_a_ser_comprado = input().strip().split()
		valor_produto = produtos_dicionario[produto_a_ser_comprado[0]]
		total = total + (float(valor_produto) * float(produto_a_ser_comprado[1]))
	print("R$ {:.2f}".format(total))
		

