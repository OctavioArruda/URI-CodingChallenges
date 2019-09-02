import numpy

nroCasos = int(input())
total = 0
for caso in range(0, nroCasos):
	nroProdutos = int(input())
	i = 0
	produtosDicionario = numpy.empty(nroProdutos, dtype=object)
	for i in range(0, nroProdutos):
		produto = input()
		arrayProduto = produto.split(" ", 1)
		print(arrayProduto)
		produtosDicionario[i] = {
			arrayProduto[0] : arrayProduto[1]
		}
		print(produtosDicionario[i])
	i = 0
	nroProdutosASeremComprados = int(input())
	produtoASerCompradoDicionario = numpy.empty(nroProdutosASeremComprados, dtype=object)
	for produtoASerComprado in range(0, nroProdutosASeremComprados):
		produtoASerComprado = input()
		arrayProdutoASerComprado = produtoASerComprado.split(" ", 1) # Separa o produto a partir do primeiro espaço
		# se o nome do produto tiver espaço já era
		produtoASerCompradoDicionario[i] = {
			arrayProdutoASerComprado[0] : arrayProdutoASerComprado[1]
		}
		i = i + 1
		print(produtoASerCompradoDicionario[0])
