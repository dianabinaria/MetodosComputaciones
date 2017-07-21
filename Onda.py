import numpy as np
import matplotlib.pyplot as plt
import numpy.ma as ma
import sys
import os

lx=ly=300
u=np.zeros((lx,ly))
#alfa = 0.5
#t=280

#eq de onda en dos dimensiones diferencias finitas
#variables
#segundos=60
c=1.0
x=30.0
y=2.0

#alfa menor o igual a 0.5 estabilidad
alfa=0.5

# dt
dx=x/(lx-1)
dy=y/(ly-1)
dt=(alfa*dx*dx/c*c)

#se calculo este t y dio 280
#t=int(segundos/(np.sqrt(dt)))
# se reemplaza 
t=1200

for i in range(lx):
    for j in range(ly):
        if(i==0 or j==0 or i==lx-1 or j==ly-1 or i==int(lx*2/3)) :
            if((j>(lx*3/7)) and (j<=(lx*4/7)) and (i==(lx*2/3))):
                u[i,j]=u[i,j]
            else:
                u[i,j]=0
        if (i==lx*1/3 and j==ly/2):
            u[i,j]=-0.5

def rec(u_l_i_j,u_lm1_i_j,u_l_ip1_j,u_l_im1_j,u_l_i_jp1,u_l_i_jm1,alfa):
    return 2*u_l_i_j-u_lm1_i_j+alfa**2*(u_l_ip1_j+u_l_im1_j+u_l_i_jp1+u_l_i_jm1-4*u_l_i_j)

def u1(u_0_i_j,u_0_ip1_j,u_0_im1_j,u_0_i_jp1,u_0_i_jm1,alfa):
    return u_0_i_j+0.5*alfa**2*(u_0_ip1_j+u_0_im1_j+u_0_i_jp1+u_0_i_jm1-4*u_0_i_j)

u_1 = u.copy()

for i in range(lx-1):
    for j in range(ly-1):
        if((i==0) or (j==0) or (i==lx-1) or (j==ly-1) or (i==int(lx*2/3)) ):
            if((j>int(lx*3/7)) and (j<=int(lx*4/7)) and (i==int(lx*2/3))):
                u_1[i,j]=u1(u[i,j],u[i+1,j],u[i-1,j],u[i,j+1],u[i,j-1],alfa)
            else:
                u_1[i,j]=0
        else:
             u_1[i,j]=u1(u[i,j],u[i+1,j],u[i-1,j],u[i,j+1],u[i,j-1],alfa)

n=2
u_lp1=u.copy()
u_lm1=u.copy()
u_l=u_1.copy()
while(n<=t):
    for i in range(lx-1):
        for j in range(ly-1):
            if((i==0) or (j==0) or (i==lx-1) or (j==ly-1) or (i==int(lx*2/3)) ):
                if((j>int(lx*3/7)) and (j<=int(lx*4/7)) and (i==int(lx*2/3))):
                    u_lp1[i,j]=rec(u_l[i,j],u_lm1[i,j],u_l[i+1,j],u_l[i-1,j],u_l[i,j+1],u_l[i,j-1],alfa)
                else:
                    u_lp1[i,j]=0
            else:
                u_lp1[i,j]=rec(u_l[i,j],u_lm1[i,j],u_l[i+1,j],u_l[i-1,j],u_l[i,j+1],u_l[i,j-1],alfa)
    u_lm1=u_l.copy()
    u_l=u_lp1.copy()
    if ( n==int(t*1/10) or n==int(t*2/10)  or n==int(t*3/10)  or n==int(t*4/10) or n==int(t*5/10) or n==int(t*6/10) or n==int(t*7/10) or n==int(t*8/10) or n==int(t*9/10) or n==int(t*10/10)):
        plt.imshow(u_lp1)
        plt.colorbar()
        plt.savefig('onda%s.png'%(n),format='png')
        plt.close()
    n+=1

os.system('convert -delay 60 loop -1 $(ls -v onda*.png) onda.gif')