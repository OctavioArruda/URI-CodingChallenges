# -*- coding: utf-8 -*-

'''
Escreva a sua solução aqui
Code your solution here
Escriba su solución aquí
'''
risada = input()
vogais = []

for char in risada:
    if "a" == char:
        vogais.append("a")
    elif "e" == char: 
        vogais.append("e")
    elif "i" == char:
        vogais.append("i")
    elif "o" == char:
        vogais.append("o")
    elif "u" == char:
        vogais.append("u")

if (vogais == vogais[::-1]):
    print("S")
else:
    print("N")
