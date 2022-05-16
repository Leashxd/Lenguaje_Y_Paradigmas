from pickle import FALSE
from traceback import print_tb
import pandas as pd
from sqlalchemy import table, true
import random




global jugando
jugando = True

# plantilla = {'Index': [1, 2, 3, 4, 5, 6, 7, 8], 'A': ['O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'], 'B': ['O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'], 'C': ['O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'], 'D': ['O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'], 
# 'E': ['O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'], 'F': ['O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'], 'G': ['O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'], 'H': ['O', 'O', 'O', 'O', 'O', 'O', 'O', 'O']}
# tablero = pd.DataFrame(data=plantilla)
# plantilla = pd.DataFrame(data=plantilla)
# print(tablero)
# print(plantilla)
# ###
def mapa():
    plantilla = {'A': ['O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'], 'B': ['O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'], 'C': ['O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'], 'D': ['O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'], 
    'E': ['O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'], 'F': ['O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'], 'G': ['O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'], 'H': ['O', 'O', 'O', 'O', 'O', 'O', 'O', 'O']}

    plantilla_bombas = {'A': [0, 0, 0, 0, 0, 0, 0, 0], 'B':  [0, 0, 0, 0, 0, 0, 0, 0], 'C':  [0, 0, 0, 0, 0, 0, 0, 0], 'D':  [0, 0, 0, 0, 0, 0, 0, 0], 
    'E':  [0, 0, 0, 0, 0, 0, 0, 0], 'F':  [0, 0, 0, 0, 0, 0, 0, 0], 'G':  [0, 0, 0, 0, 0, 0, 0, 0], 'H':  [0, 0, 0, 0, 0, 0, 0, 0]}
    tablero = pd.DataFrame(data=plantilla)
    tablero_bombas = pd.DataFrame(data=plantilla_bombas)
    return(tablero, tablero_bombas)


def buscaminas(plantilla_base):
    for i in range(8):
        posicion_horizontal= random.randint(0,7)
        posicion_vertical = random.randint (0,7)
        lista_letras=['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H']
        posicion_horizontal = lista_letras[posicion_horizontal]
        print(posicion_horizontal, posicion_vertical)
        while(plantilla_base[posicion_horizontal][posicion_vertical] == "X"):
            posicion_horizontal= random.randint(0,7)
            posicion_vertical = random.randint (0,7)
            posicion_horizontal = lista_letras[posicion_horizontal]
        plantilla_base[posicion_horizontal][posicion_vertical] = "X"
    print(plantilla_base)

    return(plantilla_base)

###
def ingresar_casilla():

    print("Selecciona la casilla que quieres abrir:")
    while true:
        lista_input = ['A', 'a', 'B', 'b', 'C', 'c', 'D', 'd', 'E', 'e', 'F', 'f', 'G', 'g', 'H', 'h']
        coord_horizontal = input("Ingresa letra de la coordenada de la A a la H:")
        if coord_horizontal in lista_input:
            break
        else:
            print('Ingrese un caracter valido')

    while true:
        lista_input = [1, 2, 3, 4, 5, 6, 7, 8]
        coord_vertical = int(input("Ingresa número de la coordenada del 1 al 8:"))
        if coord_horizontal in lista_input:
            break
        else:
            print('Ingrese un caracter valido')

    while true:
        lista_input = ['A', 'a', 'B', 'b']
        accion = input("Ingresa la accion que quieres hacer, bandera (b) o abrir (a):")
        if coord_horizontal in lista_input:
            break
        else:
            print('Ingrese un caracter valido')

    return (coord_horizontal, coord_vertical, accion)

def modificacion(tablero, plantilla, col, fila, accion):
    col = col.upper()
    fila = fila-1
    accion = accion.lower()

    if accion == 'a':
        plantilla.loc[fila, col] = tablero[col][fila]

        if tablero == 'X':
            jugando = False
    
    elif accion == 'b':
        plantilla.loc[fila, col] = 'b'
    
    return(plantilla)

def juego(tablero, plantilla):
    while jugando:
        col, fila, accion = ingresar_casilla()
        plantilla = modificacion(tablero, plantilla, col, fila, accion)
        temp = plantilla.copy()
        temp = temp.replace({'b': 'X', 'O': 'X'})
        if temp == tablero:
            jugando = 1
        print(plantilla)
    if jugando == False:
        print('Perdiste')
    else:
        print('Ganaste')

def main():
    plantilla, tablero_bombas = mapa()
    buscaminas(tablero_bombas)
    juego(tablero_bombas, plantilla)
main()