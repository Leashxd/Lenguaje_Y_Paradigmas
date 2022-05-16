import random 
import os




def tablero(fila, columna, valor):
    """ Partimos con una  """
    tablero =[]

    for i in range(fila):
        """ Agregamos una lista nueva para las filas, simplemente una matriz """
        tablero.append([])
        for j in range(columna):
            """ Agregamos las columnas """
            tablero[i].append(valor)
    return tablero

def printT(tablero):
    for fila in tablero:
        for elemento in fila:
            print(elemento, end=" ")
        print()

def coloca_minas(tablero,minas,fila,columna):
    
    minas_off=[]
    numero=0

    while numero < minas:
        y= random.randint(0,fila-1)
        x= random.randint(0,columna-1)
        if tablero[y][x] != 9:
            tablero[y][x] = 9
            numero += 1
            minas_off.append((y,x))
    return tablero, minas_off


def startmenu():
    os.system("cls")


    print("************************************")
    print("*                                  *")
    print("*                                  *")
    print("*                                  *")
    print("*                                  *")
    print("*                                  *")
    print("*                                  *")
    print("*                                  *")
    print("*                                  *")
    print("*                                  *")
    print("*                                  *")
    print("*                                  *")
    print("************************************")
    input(" enter")

def menu():
    print()
    opcion = input("w/s/a/d - m - b/v")
    return opcion



def colocar_pistas (tablero,fila,columna):
    """ recorremos cada una de las filas del tablero para verificar el valor a evaluar """
    for y in range(fila):
        for x in range(columna): 
            if tablero[y][x] == 9:
                for i in [-1,0,1]:
                    for j in [-1,0,1]:
                        if 0<= y+i <= fila-1 and 0 <= x+j <= columna-1:
                            if tablero[y+i][x+j] !=9:
                                tablero[y+i][x+j]+=1
    return tablero
    
   

columna=16
fila=12

visible = tablero(fila, columna, "-")
oculto = tablero(fila, columna, 0)
oculto,minas_off = coloca_minas(oculto, 15, fila, columna)
oculto= colocar_pistas (oculto,fila, columna)
startmenu()
y=random.randint(2,fila-3)
x= random.randint(2,columna-3)
real=visible[y][x]
visible[y][x] ="x"
os.system("cls")


printT(visible)

minas_marcadas = []

jugando =True

while jugando:
    mov= menu()
    printT(visible)
    if mov =="w":
        if y==0:
            y=0
        else:
            visible[y][x] = real
            y -=1
            real=visible[y][x]
            visible[y][x] ="x"
    elif mov =="s":
        if y== fila-1:
            y= fila-1
        else:
            visible[y][x] = real
            y +=1
            real=visible[y][x]
            visible[y][x] ="x"
    elif mov =="a":
        if x== 0:
            x= 0
        else:
            visible[y][x] = real
            x -=1
            real=visible[y][x]
            visible[y][x] ="x"
    elif mov =="d":
        if x== columna-1:
            x= columna-1
        else:
            visible[y][x] = real
            x +=1
            real=visible[y][x]
            visible[y][x] ="x"
    elif mov =="b":
        if real== "-":
            visible[y][x]="#"
            real= visible[y][x]
            if (y,x) not in minas_marcadas:
                minas_marcadas.append((y,x))
    elif mov =="v":
        if real== "#":
            visible[y][x]="-"
            real= visible[y][x]
            if (y,x) in minas_marcadas:
                minas_marcadas.remove((y,x))
os.system("cls")
printT(oculto)



    
    
