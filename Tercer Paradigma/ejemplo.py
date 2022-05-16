def  suma(number_1, number_2):
  suma = number_1 + number_2
  return suma

def  resta(number_1, number_2):
  resta = number_1 - number_2
  return resta

def  multi(number_1, number_2):
  multi = number_1 * number_2
  return multi
def  div(number_1, number_2):
  div = number_1 / number_2
  return div
def  restp(number_1, number_2):
  restp = number_1 % number_2
  return restp




def func1():
  print('in the func1')
  return 0 
 
def func2():
  print ('en el func2')
  return 0
 
nro1 =1
nro2 =2

total = suma (int(nro1), int(nro2))
print(nro1, nro2, total)


nro1 = input("First number: ") 
nro2 = input("\nSecond number: ") 

sum_a = suma (int(nro1), int(nro2))
rest_a = resta (int(nro1), int(nro2))
multiplicacion = multi (int(nro1), int(nro2))
division =div (int(nro1), int(nro2))
modulo= restp(int(nro1), int(nro2))



print(nro1, nro2,'\n Suma', sum_a,'\n resta', rest_a,'\n Multiplicacion', multiplicacion,'\n Division', division,'\n Modulo', modulo)

rest_a = suma (int(nro1), int(nro2))

n1 = float(input("Intro número uno: "))
n2 = float(input("Intro numero dos: "))
suma = n1+n2
print("La suma es: ", suma)
n3 = float(input("la resuma: "))
l = suma+n3
print(" la resuma es: ", l)


x = func1()
y = func2()
 
print ('desde func1 return es %s '% x)
print('from func1 return is %s ' %y)
 
# result
"""
in the func1
in the func2
from func1 return is 0
from func1 return is None
"""