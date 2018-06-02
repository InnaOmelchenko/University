import pylab
import sympy
from math import cos
from numpy import arange

def func(x):
    return x*cos(x)/2

def f(ind1, ind2, xs, ys):
    if(ind1 == 1):
        return (ys[ind1 + ind2] - ys[ind2])/(xs[ind1 + ind2] - xs[ind2])
    else:
        return (f(ind1-1, ind2+1, xs, ys) - f(ind1-1, ind2, xs, ys))/(xs[ind1 + ind2] - xs[ind2])

def polinoms(xs, ys):
    x = sympy.Symbol('x')#введення символу для символьного обчислення
    
    L = 0
    for i in range(len(ys)):
        temp = 1
        for j in range(len(xs)):
            if(i != j):
                temp*=(x-xs[j])/(xs[i]-xs[j])
        L+=ys[i]*temp

    print("===Lagrange polynom===\n")
    sympy.pprint(L.expand())

    P = ys[0]
    for i in range(len(ys) - 1):
        temp = 1
        for j in range(i+1):
            temp*=(x-xs[j])
        temp*=f(i+1, 0, xs, ys)
        P+=temp

    print("\n\n===Newton polynom===")
    sympy.pprint(P.expand())

    polx=[]
    lagy=[]
    newy=[]
    for i in arange(xs[0], xs[len(xs)-1], 0.005):
        polx.append(i)
        lagy.append(L.subs(x,i))
        newy.append(P.subs(x,i))

    pylab.plot(polx, lagy, "y--")
    pylab.plot(polx, newy, "b--")

    #щоб знайти значення поліному в точці, замінити ??? на потрібне число  
    #print('L(x) =', L.subs(x, ???))
    #print('P(x) =', P.subs(x, ???))


    #щоб знайти значення заданої функції для порівняння
    #print('f(x) =', func(???))
    
def progonka(xs, ys, matrix):
    A = matrix[0]
    B = matrix[1]
    C = matrix[2]
    D = matrix[3]
    h = matrix[4]
    #метод прогонки
    C[0] /= B[0]
    for i in range(len(C)-1):
        C[i+1] /= (B[i+1] - C[i]*A[i+1])

    D[0] /= B[0]
    for i in range(len(D)-1):
        D[i+1] = (D[i+1] - D[i]*A[i+1])/(B[i+1] - C[i]*A[i+1])

    #__________________________________
    #знаходження коефіцієнтів рівняння
    a = [ys[i] for i in range(len(ys) - 1)]

    c = [D[len(D) - 1]]
    for i in range(len(D) - 2, -1, -1):
        c.insert(0, D[i] - C[i]*c[0])
    c.insert(0, 0)
    c.append(0)
        
    d = [(c[i+1]-c[i])/(3*h[i]) for i in range(len(c) - 1)]
    d.append(-c[len(c)-1]/(3*h[len(h)-1]))

    b = [(ys[i+1] - ys[i])/h[i] - h[i]*(c[i+1] + 2*c[i])/3 for i in range(len(c)-1)]
    b.append((ys[len(ys)-1] - ys[len(ys)-2])/h[len(h)-1] - 2*h[len(h)-1]*c[len(c)-1]/3)

    return [a, b, c, d, h]

def cubic(xs, ys, koef):
    a = koef[0]
    b = koef[1]
    c = koef[2]
    d = koef[3]
    h = koef[4]
    
    x = sympy.Symbol('x')
    F = []
    for i in range(len(h)):
        F.append(a[i] + b[i]*(x - xs[i]) + (c[i])*(x - xs[i])**2 + (d[i])*(x - xs[i])**3)
        print('\nF[{}] ='.format(i+1), F[i], '\n')
        interx = []
        intery = []
        for j in arange(xs[i], xs[i]+h[i], 0.005):
            interx.append(j)
            intery.append(F[i].subs(x, j))
        pylab.plot(interx, intery, "g--")

#______________________________________________________________________________
file = open("file.txt")
x = file.read().split()
file.close()
y = []
for i in range(len(x)):
    x[i] = int(x[i])
    y.append(func(x[i]))

#побудова точного графіку функції
xs = arange(x[0], x[len(x)-1], 0.005)
ys = [func(xs[i]) for i in range(len(xs))]
pylab.plot(xs, ys, "r--")

polinoms(x, y)#знаходження поліномів

#побудова матриці
h = [(x[i] - x[i-1]) for i in range(1, len(x))]

A = [h[i] for i in range(1, len(h) - 1)]
B = [2 * (h[i] + h[i+1]) for i in  range(1, len(h) - 1)]
C = [h[i+1] for i in range(1, len(h) - 1)]
D = [3*((y[i+1]-y[i])/h[i+1] - (y[i]-y[i-1])/h[i]) for i in range(1,  len(h) - 1)]

matrix = [A, B, C, D, h]

print("\n\n===Cubic interpolation===")
cubic(x, y, progonka(x, y, matrix))

pylab.legend(["formula", "lagrange", "newton", "interpolation"])
pylab.show()
