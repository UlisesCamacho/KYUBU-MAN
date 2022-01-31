#include <stdio.h>  
#include <graphics.h>
#include <time.h>
#define N 16 // numero de cubos
#define A  23
#define P  8
//portada
#define a  200


typedef struct
{
        int x,y;
        int color,existe;
}Cubo;


typedef struct{
        char nombre[30];
        int puntos;
        }Record;


Record jugador;
void portada();
void inicializa(Cubo contenedor[N][N][N]);
void dibuja_contenedor(int mov,Cubo contenedor[N][N][N]);
void dibuja_cubo(int x, int y, int color);

void dibuja_pacman_derecha_fillpoly(int x, int y, int color);
void dibuja_pacman_derecha_fillpoly_portada(int x, int y, int color);

void  dibuja_fantasma_fillpoly(int x,int y,int color);
void  dibuja_fantasma_fillpoly_portada(int x,int y,int color);

void dibuja_triangulo_fillpoly(int x,int y, int color);

void dibuja_pacman_arriba_fillpoly(int x, int y, int color);
void dibuja_pacman_abajo_fillpoly(int x, int y, int color);
void dibuja_pacman_izquierda_fillpoly(int x, int y, int color);

void lee_texto(int x,int y, char cadena[]);
void menu(Cubo contenedor[N][N][N]);
void mover_cubo(Cubo contenedor[N][N][N]);
void mover_izq(Cubo contenedor[N][N][N],int *marcador);
void mover_der(Cubo contenedor[N][N][N],int *marcador);
void mover_aba(Cubo contenedor[N][N][N],int *marcador);
void mover_arr(Cubo contenedor[N][N][N],int *marcador);
void mover_abajo_en_k(Cubo contenedor[N][N][N],int *marcador);
void mover_arriba_en_k(Cubo contenedor[N][N][N],int *marcador);
//magenta
void mover_izq_magenta(Cubo contenedor[N][N][N],int *vidas);
void mover_der_magenta(Cubo contenedor[N][N][N],int *vidas);
void mover_abajo_en_k_magenta(Cubo contenedor[N][N][N],int *vidas);
void mover_arriba_en_k_magenta(Cubo contenedor[N][N][N],int *vidas);
//verde
void mover_izq_verde(Cubo contenedor[N][N][N],int *vidas);
void mover_der_verde(Cubo contenedor[N][N][N],int *vidas);
void mover_abajo_en_k_verde(Cubo contenedor[N][N][N],int *vidas);
void mover_arriba_en_k_verde(Cubo contenedor[N][N][N],int *vidas);
//rosa
void mover_izq_rosa(Cubo contenedor[N][N][N],int *vidas);
void mover_der_rosa(Cubo contenedor[N][N][N],int *vidas);
void mover_abajo_en_k_rosa(Cubo contenedor[N][N][N],int *vidas);
void mover_arriba_en_k_rosa(Cubo contenedor[N][N][N],int *vidas);
char leeTecla();
void imprimirRecords();
void insertarRecord(Record al);
//void imprimeArchivos(char cadena[]);
int main( )
{
    Cubo contenedor [N][N][N];
	initwindow( 900 , 600); 
	inicializa(contenedor);
	portada();
	menu(contenedor);
	
	
    closegraph( );
}

void portada()
{
    int iTecla;  
  dibuja_pacman_derecha_fillpoly_portada(270,100,YELLOW);
  dibuja_fantasma_fillpoly_portada(500,100,13);
  setcolor(14);
  settextstyle(8,0,5); 
  outtextxy(400,370,"KYUBU_MAN");
  outtextxy(270,450,"Press start (enter)");

    do{
        iTecla=getch();
         cleardevice();
    }while(iTecla!=13);
}
void inicializa(Cubo contenedor[N][N][N])
{int i,j,k; 
  for(k=0;k<N;k++)
   for(i=N-1;i>=0;i--)
    for(j=0;j<N;j++)
    {
     contenedor[k][i][j].x=380+j*A-A/2*k;
     contenedor[k][i][j].y=400-(N-1-i)*A+P*k;               
     contenedor[k][i][j].color=BLACK;
    
      if(i==N-1)
     {
        contenedor[k][i][j].color=BLUE;
      contenedor[k][i][j].existe=1;
        
     }
     else if(i!=N-1 && i!=N-2 ) 
    {
        contenedor[k][i][j].existe=0;
    }  
  }   contenedor[13][N-2][6].existe=1;
        contenedor[13][N-2][6].color=YELLOW;
    
     contenedor[7][N-2][13].existe=1;//5 color magenta(morado)
        contenedor[7][N-2][13].color=5; 
        contenedor[3][N-2][11].existe=1;
        contenedor[3][N-2][11].color=5;
        contenedor[1][N-2][8].existe=1;
        contenedor[1][N-2][8].color=5;
        
        contenedor[11][N-2][13].existe=1;//rosa
        contenedor[11][N-2][13].color=13;
        contenedor[10][N-2][4].existe=1;
        contenedor[10][N-2][4].color=13;
        contenedor[1][N-2][7].existe=1;
        contenedor[1][N-2][7].color=13;
         contenedor[7][N-2][1].existe=1;
        contenedor[7][N-2][1].color=13;
        
        contenedor[8][N-2][5].existe=1;// verde
        contenedor[8][N-2][5].color=10;
        contenedor[8][N-2][3].existe=1;
        contenedor[8][N-2][3].color=10;        
        contenedor[3][N-2][13].existe=1;
        contenedor[3][N-2][13].color=10;
        contenedor[11][N-2][10].existe=1;
        contenedor[11][N-2][10].color=10;
        
        contenedor[1][N-2][13].existe=1;// COMIDA
        contenedor[1][N-2][13].color=RED;
         contenedor[1][N-2][1].existe=1;
        contenedor[1][N-2][1].color=RED;
        contenedor[11][N-2][1].existe=1;
        contenedor[11][N-2][1].color=RED;
        contenedor[6][N-2][6].existe=1;
        contenedor[6][N-2][6].color=RED;
         contenedor[11][N-2][13].existe=1;
        contenedor[11][N-2][13].color=RED;
        
        
             //LABERINTO
         contenedor[0][N-2][0].existe=1;
        contenedor[0][N-2][0].color=BLUE;
        contenedor[0][N-2][1].existe=1;
        contenedor[0][N-2][1].color=BLUE;
        contenedor[0][N-2][2].existe=1;
        contenedor[0][N-2][2].color=BLUE;
        contenedor[0][N-2][3].existe=1;
        contenedor[0][N-2][3].color=BLUE;
         contenedor[0][N-2][12].existe=1;
        contenedor[0][N-2][12].color=BLUE;
         contenedor[0][N-2][13].existe=1;
        contenedor[0][N-2][13].color=BLUE;
        contenedor[0][N-2][14].existe=1;
        contenedor[0][N-2][14].color=BLUE;
        contenedor[0][N-2][15].existe=1;
        contenedor[0][N-2][15].color=BLUE;
    
        contenedor[15][N-2][0].existe=1;
        contenedor[15][N-2][0].color=BLUE;
         contenedor[15][N-2][1].existe=1;
        contenedor[15][N-2][1].color=BLUE;
         contenedor[15][N-2][2].existe=1;
        contenedor[15][N-2][2].color=BLUE;
         contenedor[15][N-2][3].existe=1;
        contenedor[15][N-2][3].color=BLUE;
         contenedor[15][N-2][12].existe=1;
        contenedor[15][N-2][12].color=BLUE;
         contenedor[15][N-2][13].existe=1;
        contenedor[15][N-2][13].color=BLUE;
         contenedor[15][N-2][14].existe=1;
        contenedor[15][N-2][14].color=BLUE;
         contenedor[15][N-2][15].existe=1;
        contenedor[15][N-2][15].color=BLUE;
        //LATERAL
         contenedor[1][N-2][0].existe=1;
        contenedor[1][N-2][0].color=BLUE;
         contenedor[2][N-2][0].existe=1;
        contenedor[2][N-2][0].color=BLUE;
         contenedor[3][N-2][0].existe=1;
        contenedor[3][N-2][0].color=BLUE;
        //2DO LATERAL
         contenedor[1][N-2][15].existe=1;
        contenedor[1][N-2][15].color=BLUE;
         contenedor[2][N-2][15].existe=1;
        contenedor[2][N-2][15].color=BLUE;
         contenedor[3][N-2][15].existe=1;
        contenedor[3][N-2][15].color=BLUE;
        //LATERAL/2
         contenedor[3][N-2][10].existe=1;
        contenedor[3][N-2][10].color=BLUE;
         contenedor[4][N-2][10].existe=1;
        contenedor[4][N-2][10].color=BLUE;
         contenedor[5][N-2][10].existe=1;
        contenedor[5][N-2][10].color=BLUE;
         //LATERAL/2
         contenedor[3][N-2][3].existe=1;
        contenedor[3][N-2][3].color=BLUE;
         contenedor[4][N-2][3].existe=1;
        contenedor[4][N-2][3].color=BLUE;
         contenedor[5][N-2][3].existe=1;
        contenedor[5][N-2][3].color=BLUE;
        //EN MEDIO
        contenedor[3][N-2][6].existe=1;
        contenedor[3][N-2][6].color=BLUE;
         contenedor[4][N-2][6].existe=1;
        contenedor[4][N-2][6].color=BLUE;
         contenedor[5][N-2][6].existe=1;
        contenedor[5][N-2][6].color=BLUE;
        //EN MEDIO
        contenedor[12][N-2][6].existe=1;
        contenedor[12][N-2][6].color=BLUE;
         contenedor[11][N-2][6].existe=1;
        contenedor[11][N-2][6].color=BLUE;
         contenedor[10][N-2][6].existe=1;
        contenedor[10][N-2][6].color=BLUE;
        //
        contenedor[1][N-2][12].existe=1;
        contenedor[1][N-2][12].color=BLUE;
        contenedor[2][N-2][12].existe=1;
        contenedor[2][N-2][12].color=BLUE;
        
        contenedor[2][N-2][10].existe=1;
        contenedor[2][N-2][10].color=BLUE;
        contenedor[2][N-2][11].existe=1;
        contenedor[2][N-2][11].color=BLUE;
        
        contenedor[8][N-2][9].existe=1;
        contenedor[8][N-2][9].color=BLUE;
        contenedor[9][N-2][9].existe=1;
        contenedor[9][N-2][9].color=BLUE;
        contenedor[10][N-2][9].existe=1;
        contenedor[10][N-2][9].color=BLUE;
        
        contenedor[8][N-2][13].existe=1;
        contenedor[8][N-2][13].color=BLUE;
        contenedor[9][N-2][13].existe=1;
        contenedor[9][N-2][13].color=BLUE;
        contenedor[4][N-2][15].existe=1;
        contenedor[4][N-2][15].color=BLUE;
        contenedor[5][N-2][15].existe=1;
        contenedor[5][N-2][15].color=BLUE;
        contenedor[4][N-2][0].existe=1;
        contenedor[4][N-2][0].color=BLUE;
        contenedor[5][N-2][0].existe=1;
        contenedor[5][N-2][10].color=BLUE;
                
        //complemneto laberinto
         contenedor[5][N-2][0].existe=1;
         contenedor[5][N-2][0].color=BLUE;
         contenedor[6][N-2][0].existe=1;
         contenedor[6][N-2][0].color=BLUE;
         contenedor[7][N-2][0].existe=1;
         contenedor[7][N-2][0].color=BLUE;
         contenedor[8][N-2][0].existe=1;
         contenedor[8][N-2][0].color=BLUE;
         contenedor[9][N-2][0].existe=1;
         contenedor[9][N-2][0].color=BLUE;
         contenedor[10][N-2][0].existe=1;
         contenedor[10][N-2][0].color=BLUE;
         contenedor[11][N-2][0].existe=1;
         contenedor[11][N-2][0].color=BLUE;
         contenedor[12][N-2][0].existe=1;
         contenedor[12][N-2][0].color=BLUE;
         contenedor[13][N-2][0].existe=1;
         contenedor[13][N-2][0].color=BLUE;
         contenedor[14][N-2][0].existe=1;
         contenedor[14][N-2][0].color=BLUE;
         //complemento laberinto
         contenedor[6][N-2][15].existe=1;
         contenedor[6][N-2][15].color=BLUE;
         contenedor[7][N-2][15].existe=1;
         contenedor[7][N-2][15].color=BLUE;
         contenedor[8][N-2][15].existe=1;
         contenedor[8][N-2][15].color=BLUE;
         contenedor[9][N-2][15].existe=1;
         contenedor[9][N-2][15].color=BLUE;
         contenedor[10][N-2][15].existe=1;
         contenedor[10][N-2][15].color=BLUE;
         contenedor[11][N-2][15].existe=1;
         contenedor[11][N-2][15].color=BLUE;
         contenedor[12][N-2][15].existe=1;
         contenedor[12][N-2][15].color=BLUE;
         contenedor[13][N-2][15].existe=1;
         contenedor[13][N-2][15].color=BLUE;
         contenedor[14][N-2][15].existe=1;
         contenedor[14][N-2][15].color=BLUE;
         //complemento laberinto
         contenedor[0][N-2][4].existe=1;
         contenedor[0][N-2][4].color=BLUE;
         
      
         contenedor[15][N-2][4].existe=1;
         contenedor[15][N-2][4].color=BLUE;
         
}
void dibuja_contenedor(int mov,Cubo contenedor[N][N][N])
{int i,j,k;
 for(k=0;k<N;k++)
  for(i=N-1;i>=0;i--)
    for(j=0;j<N;j++)
     
           if(contenedor[k][i][j].existe==1 &&  contenedor[k][i][j].color==YELLOW)
            {      
                printf("mov = %d \n", mov);  
                   switch(mov)
                 { 
                  case 4:
                  dibuja_pacman_derecha_fillpoly(contenedor[k][i][j].x,
                       contenedor[k][i][j].y,
                      contenedor[k][i][j].color);
                    break;
                   case 3:  
                        dibuja_pacman_izquierda_fillpoly(contenedor[k][i][j].x,
                       contenedor[k][i][j].y,
                      contenedor[k][i][j].color);
                      break;
                   case 2:   
                        dibuja_pacman_arriba_fillpoly(contenedor[k][i][j].x,
                       contenedor[k][i][j].y,
                      contenedor[k][i][j].color);
                      break;
                  
                      }
                   }   
                     else  if(contenedor[k][i][j].existe==1 && contenedor[k][i][j].color==5 ||contenedor[k][i][j].color==10 || contenedor[k][i][j].color==13)
                       dibuja_fantasma_fillpoly(contenedor[k][i][j].x,
                       contenedor[k][i][j].y,
                      contenedor[k][i][j].color);
                      
                       else  if(contenedor[k][i][j].existe==1 && contenedor[k][i][j].color==RED)
                       dibuja_triangulo_fillpoly(contenedor[k][i][j].x,
                       contenedor[k][i][j].y,
                      contenedor[k][i][j].color);
                      
                   else  if(contenedor[k][i][j].existe==1) 
      dibuja_cubo(contenedor[k][i][j].x,
                  contenedor[k][i][j].y,
                  contenedor[k][i][j].color);
      setcolor(WHITE);
     line(210,0,210,680);
      
      

     
}
void dibuja_cubo(int x, int y, int color)
{
int poly[8]; // cuatro pares (x,y) de puntos

    setfillstyle(1,color);
    bar(x,y,x+A,y+A);
    rectangle(x,y,x+A,y+A);
    poly[0]=x;
    poly[1]=y;
    poly[2]=x+A/2;
    poly[3]=y-P;
    poly[4]=x+A+A/2;
    poly[5]=y-P;
    poly[6]=x+A;
    poly[7]=y;
    fillpoly(4,poly);
  
    poly[0]=x+A;
    poly[1]=y;
    poly[2]=x+A+A/2;
    poly[3]=y-P;
    poly[4]=x+A+A/2;
    poly[5]=y+A-P;
    poly[6]=x+A;
    poly[7]=y+A;
    fillpoly(4,poly);
}
char leeTecla()
{
     char tecla;
     tecla=getch ();
     if(tecla=='\0')
        tecla=getch();
        return tecla;
}
void dibuja_pacman_derecha_fillpoly(int x, int y, int color)
{
     

    int poly[10]; // cuatro pares (x,y) de puntos
    setfillstyle(1,color);
    poly[0]=x;
    poly[1]=y;
    poly[2]=x+A;
    poly[3]=y;
    poly[4]=x+A/2;
    poly[5]=y+A/2;
    poly[6]=x+A;
    poly[7]=y+A;
    poly[8]=x;
    poly[9]=y+A;
    fillpoly(5,poly);

}
void dibuja_pacman_derecha_fillpoly_portada(int x, int y, int color)
{
     

    int poly[10]; // cuatro pares (x,y) de puntos
    setfillstyle(1,color);
    poly[0]=x;
    poly[1]=y;
    poly[2]=x+a;
    poly[3]=y;
    poly[4]=x+a/2;
    poly[5]=y+a/2;
    poly[6]=x+a;
    poly[7]=y+a;
    poly[8]=x;
    poly[9]=y+a;
    fillpoly(5,poly);

}
void  dibuja_fantasma_fillpoly_portada(int x,int y,int color)
{
    int poly[14]; // cuatro pares (x,y) de puntos
    setfillstyle(1,color);
    poly[0]=x;
    poly[1]=y;
    poly[2]=x+a;
    poly[3]=y;
    poly[4]=x+a;
    poly[5]=y+a;
    poly[6]=x+a/2+a/2/2;
    poly[7]=y+a/2+10;
    poly[8]=x+a/2;
    poly[9]=y+a;
    poly[10]=x+a/2/2;
    poly[11]=y+a/2+10;
    poly[12]=x;
    poly[13]=y+a;
    fillpoly(7,poly);
    setcolor(WHITE);
    circle(x+a/2/2,y+a/2/2,25);//ojo izquierdo
    circle(x+a/2+a/2/2,y+a/2/2,25);//ojo derecho
    
    setfillstyle(1,15);
    floodfill(x+a/2/2,y+a/2/2,WHITE);//relleno ojo izquierdo
    floodfill(x+a/2+a/2/2,y+a/2/2,WHITE);//relleno ojo derecho*/ 
}      
void  dibuja_fantasma_fillpoly(int x,int y,int color)
{
    int poly[14]; // cuatro pares (x,y) de puntos
    setfillstyle(1,color);
    poly[0]=x;
    poly[1]=y;
    poly[2]=x+A;
    poly[3]=y;
    poly[4]=x+A;
    poly[5]=y+A;
    poly[6]=x+A/2+A/2/2;
    poly[7]=y+A/2+10;
    poly[8]=x+A/2;
    poly[9]=y+A;
    poly[10]=x+A/2/2;
    poly[11]=y+A/2+10;
    poly[12]=x;
    poly[13]=y+A;
    fillpoly(7,poly);
    setcolor(WHITE);
    circle(x+A/2/2,y+A/2/2,3);//ojo izquierdo
    circle(x+A/2+A/2/2,y+A/2/2,3);//ojo derecho
    setfillstyle(1,15);
    floodfill(x+A/2/2,y+A/2/2,WHITE);//relleno ojo izquierdo
    floodfill(x+A/2+A/2/2,y+A/2/2,WHITE);//relleno ojo derecho*/    
}
void dibuja_triangulo_fillpoly(int x,int y, int color)
{
     int poly[6]; // 3 pares (x,y) de puntos
    setfillstyle(1,color);
    poly[0]=x+A/2;
    poly[1]=y+A/2;
    poly[2]=x+A/2/2;
    poly[3]=y+A/2/2;
    poly[4]=x+A/2+A/2/2;
    poly[5]=y+A/2/2;
    fillpoly(3,poly);
}
//pacman movimientos
void dibuja_pacman_izquierda_fillpoly(int x, int y, int color)

{

int poly[8]; // cuatro pares (x,y) de puntos



    setfillstyle(1,color);

    //bar(x,y,x+A,y+A);

    //rectangle(x,y,x+A,y+A);

    poly[0]=x;
    poly[1]=y;
    poly[2]=x+A;
    poly[3]=y;
    poly[4]=x+A;
    poly[5]=y+A;
    poly[6]=x;
    poly[7]=y+A;
    poly[8]=x+A/2;
    poly[9]=y+A/2;
    fillpoly(5,poly);
}
void dibuja_pacman_arriba_fillpoly(int x, int y, int color)

{

int poly[8]; // cuatro pares (x,y) de puntos



    setfillstyle(1,color);

    //bar(x,y,x+A,y+A);

    //rectangle(x,y,x+A,y+A);

    poly[0]=x;
    poly[1]=y;
    poly[2]=x+A/2;
    poly[3]=y+A/2;
    poly[4]=x+A;
    poly[5]=y;
    poly[6]=x+A;
    poly[7]=y+A;
    poly[8]=x;
    poly[9]=y+A;
    fillpoly(5,poly);
}
void dibuja_pacman_abajo_fillpoly(int x, int y, int color)

{

int poly[8]; // cuatro pares (x,y) de puntos



    setfillstyle(1,color);

    //bar(x,y,x+A,y+A);

    //rectangle(x,y,x+A,y+A);

    poly[0]=x;
    poly[1]=y;
    poly[2]=x+A;
    poly[3]=y;
    poly[4]=x+A;
    poly[5]=y+A;
    poly[6]=x+A/2;
    poly[7]=y+A/2;
    poly[8]=x;
    poly[9]=y+A;
    fillpoly(5,poly);
}
void lee_texto(int x,int y, char cadena[])
{
char tecla;     
int contador=0;
cadena[0]='\0';
do{
      do{  //párpadeo
			 setcolor(14);
			 outtextxy(x+textwidth(cadena),y,"_");
			// retraso(50);
			 setcolor(0);
			 outtextxy(x+textwidth(cadena),y,"_");
			// retraso(50);
			 setcolor(15);
      }while(!kbhit());
      tecla=getch();
      if(tecla==0)  // si es código extendido
         tecla=getch();
        if(tecla==8 && contador > 0)  // se presiono <backspace>
			{
				 setcolor(BLACK);
				 outtextxy(x,y,cadena);  // se borra en la pantalla
				 cadena[--contador]='\0';  //se borro el ultimo caracter del arreglo
				 setcolor(14);
				 outtextxy(x,y,cadena);
			}
        else
			{  
              if(tecla!=13)
              {  
				 cadena[contador++]=tecla;
				 cadena[contador]='\0';
				 outtextxy(x,y,cadena);
              }
            }    
  }while(tecla!=13); 
}

void menu(Cubo contenedor[N][N][N])

{   //char tecla;
    int x,y,d3,d4;
    char sCad[30];
    int x1=100,x2=350,y1=100,y2=200,d1,d2;//jugar       
    int x3=100,x4=350,y3=300,y4=400;//record
    int x5=400,x6=650,y5=100,y6=200,d5,d6;//AYUDA
    int x7=400,x8=650,y7=300,y8=400,d7,d8;//salir
 
  
  do
  {
  setcolor(14);//Amarillo
  settextstyle(4,0,4);// tipo , direccion, tamaño
  // J U G A R
  rectangle(x1,y1,x2,y2);
  d1=textwidth("JUGAR");//largo
  d2=textheight("JUGAR");//altura
  outtextxy(x1+((x2-x1)/2-d1/2),
            y1+((y2-y1)/2-d2/2),"JUGAR");
  
 // R E C O R D S
  rectangle(x3,y3,x4,y4);
  d3=textwidth("RECORDS");//largo
  d4=textheight("RECORDS");//altura
   outtextxy(x3+((x4-x3)/2-d3/2), 
             y3+((y4-y3)/2-d4/2),"RECORDS"); 
  
  //A Y U D A
  rectangle(x5,y5,x6,y6);
  d5=textwidth("AYUDA");//largo
  d6=textheight("AYUDA");//altura
  outtextxy(x5+((x6-x5)/2-d5/2), y5+((y6-y5)/2-d6/2),"AYUDA");
  

  //S A L I R
  rectangle(x7,y7,x8,y8);
  d7=textwidth("SALIR");//largo
  d8=textheight("SALIR");//altura
  outtextxy(x7+((x8-x7)/2-d7/2), y7+((y8-y7)/2-d8/2),"SALIR");
    
    if(ismouseclick(WM_LBUTTONDOWN))   /* checa si se presionó dos veces botón derecho */
    {
       x=mousex();
       y=mousey();                             
       if(x>x1 && x<x2 && y>y1 && y<y2)
       {
                srand(time(NULL));
               cleardevice();
               setcolor(14);//amarillo
               outtextxy(250,100, "Nombre del Jugador");
               jugador.puntos=0;
               lee_texto(250,200,jugador.nombre);
               //inicializa
               //dibuja_contenedor
               
                mover_cubo(contenedor);
               insertarRecord(jugador);
                cleardevice();
               
                
       }
       if(x>x3 && x<x4 && y>y3 && y<y4)
       {
               cleardevice();
               imprimirRecords();
               cleardevice();
               
             
               
       }
       if(x>x5 && x<x6 && y>y5 && y<y6)
       { 
              
         cleardevice();
         int iTecla;  
  setcolor(14);
  settextstyle(8,0,2); 
  outtextxy(400,20,"CONTROLES");
  settextstyle(8,0,1);
   outtextxy(100,50,"Teclas de control");
   line(150,100,200,100);// derecha
   line(180,90,200,100);
  outtextxy(300,80,"Derecha");
  line(150,130,200,130);//izquierda
  line(170,120,150,130);
   outtextxy(300,120,"Izquierda");
   line(175,150,175,190);//arriba
   line(175,150,185,160);
    outtextxy(300,160,"Arriba");
    line(175,210,175,250);//abajo
    line(175,250,165,240);
    outtextxy(300,220,"Abajo");
     settextstyle(8,0,2);
     outtextxy(400,260,"OBJETIVO");
     settextstyle(8,0,1);
     outtextxy(70,290,"Tendras que ayudar a Kyubu_man a pasar por el laberinto sin ser");
     outtextxy(70,320,"atrapado por los fantasmas en busca de la comida.Al obtener");
     outtextxy(70,350,"la comida del laberinto tus puntos aumentarán.");
     setcolor(WHITE);
     dibuja_pacman_derecha_fillpoly(370,430,YELLOW);
     dibuja_fantasma_fillpoly(600,160,13);
     dibuja_fantasma_fillpoly(600,530,10);
     dibuja_fantasma_fillpoly(700,180,5);
     dibuja_triangulo_fillpoly(450,500,RED);
      dibuja_triangulo_fillpoly(100,500,RED);

    do{
        iTecla=getch();
         cleardevice();
    }while(iTecla!=13);
  

      }
       if(x>x7 && x<x8 && y>y7 && y<y8)
       {
               cleardevice();
               outtextxy(300,50, "GAME OVER");
               delay(1000);
               exit(1);        
       }
       clearmouseclick(WM_LBUTTONDOWN);   /* limpia la bandera que indica si se presionó un botón */
    }  
  }while (!ismouseclick(WM_LBUTTONDOWN));  /* checa si se presionó boton derecho dos veces o una tecla */
 
}
void mover_cubo(Cubo contenedor[N][N][N])
{
   int tecla,pag=0;
 int vidas=3;
 int marcador=0;
 int mov=4;
/* int m;
 int r;
 int l;
 int n;// moviminto de fantasmas
 m=72;
 r=73;
 l=74;
 n=75;*/
 char cadena[40];
  char cadena2[40];
  Cubo cont[N][N][N];
  inicializa(cont);
 do{
   do{
   setactivepage(pag);
  
    //PONER RECORD O MARCADOR oUUTEXT!!
   
   cleardevice();
    settextstyle(8,0,4);
   sprintf(cadena,"%d",vidas);
   outtextxy(60,80,cadena);
   outtextxy(40,50,"VIDAS");
   outtextxy(40,200,"PUNTOS");
   sprintf(cadena,"%d",vidas);
   sprintf(cadena2,"%d",marcador);
    outtextxy(60,230,cadena2);
   dibuja_contenedor(mov,cont);
   setvisualpage(pag);
   if(pag==0) pag=1; else pag=0;   
  
   
            
   
   if(rand()%23==1)    
   {
     mover_izq_magenta(cont,&vidas);
     mover_izq_verde(cont,&vidas);
     mover_izq_rosa(cont,&vidas);
   }
    if(rand()%21==1)
   {
    mover_abajo_en_k_magenta(cont,&vidas);
     mover_abajo_en_k_verde(cont,&vidas);
     mover_abajo_en_k_rosa(cont,&vidas);                        
   
   }
     if(rand()%20==1)    
    {
    mover_der_magenta(cont,&vidas);
     mover_der_verde(cont,&vidas);
     mover_der_rosa(cont,&vidas);                
    }
    if(rand()%10==1)   
    {
    mover_arriba_en_k_magenta(cont,&vidas);
     mover_arriba_en_k_verde(cont,&vidas);
     mover_arriba_en_k_verde(cont,&vidas);            
   
   }
    }while(!kbhit()&& vidas >0);      
   tecla=getch();
   if(tecla==0) // checa si es código extendido
     tecla=getch();
    switch(tecla)
    {
      case 77:  mover_der(cont,&marcador);
                mov=4;  //der
                break;
      case 75:  mover_izq(cont,&marcador);  //izq
                mov=3;
                break;   
      case 72: mover_arriba_en_k(cont,&marcador);
                mov=2;
                break; 
      case 80:  mover_abajo_en_k(cont,&marcador);
                break;
  
                            
    } 
 }while(tecla!=13 && vidas >0 );
             
}
//magenta morado
void mover_izq_magenta(Cubo contenedor[N][N][N],int *vidas)
{
     int i,j,k;
for(k=0;k<N;k++)
for(i=0;i<N;i++)
{  
  if( contenedor[k][i][0].existe==1 && contenedor[k][i][0].color==5 )
  {     contenedor[k][i][j].existe=0;
      contenedor[k][i][j].color=BLACK;
    contenedor[k][i][N-1].existe=1;
    contenedor[k][i][N-1].color=5;
    
  }
  else
   for(j=1;j<N;j++)
    if( contenedor[k][i][j].existe==1 && contenedor[k][i][j].color==5 )
    {
     if(contenedor[k][i][j-1].color!=BLUE && contenedor[k][i][j-1].color!=5 && contenedor[k][i][j-1].color!=10 && contenedor[k][i][j-1].color!=13 && contenedor[k][i][j-1].color!=RED )
     { 
      contenedor[k][i][j].existe=0;                      
      contenedor[k][i][j].color=BLACK;
    if(contenedor[k][i][j-1].color==YELLOW)
      {
           contenedor[13][N-2][6].existe=1;
        contenedor[13][N-2][6].color=YELLOW;
              (*vidas)--;
      }
       
         contenedor[k][i][j-1].existe=1; 
      contenedor[k][i][j-1].color=5;   
     }
    }
 }
}
void mover_der_magenta(Cubo contenedor[N][N][N],int *vidas)
{int i,j,k;
for(k=0;k<N;k++)
for(i=0;i<N;i++)
{
  if(contenedor[k][i][N-1].existe==1 && contenedor[k][i][N-1].color==5 )
  {
  contenedor[k][i][N-1].existe=0; 
  contenedor[k][i][N-1].color=BLACK;
  contenedor[k][i][0].existe=1; 
  contenedor[k][i][0].color=5;  
  }
  else
   for(j=N-2;j>=0;j--)
    if(contenedor[k][i][j].existe==1 && contenedor[k][i][j].color==5 )
    {
      if(contenedor[k][i][j].existe==1 &&contenedor[k][i][j+1].color!=RED &&  contenedor[k][i][j+1].color!=BLUE && contenedor[k][i][j+1].color!=5 && contenedor[k][i][j+1].color!=10 && contenedor[k][i][j+1].color!=13)
    {
       contenedor[k][i][j].existe=0;                                
      contenedor[k][i][j].color=BLACK;
        if(contenedor[k][i][j+1].color==YELLOW)
        {
         contenedor[13][N-2][6].existe=1;
        contenedor[13][N-2][6].color=YELLOW;
       (*vidas)--;
      }
            contenedor[k][i][j+1].existe=1; 
      contenedor[k][i][j+1].color=5;
    }
 }
}
}
 void mover_arriba_en_k_magenta(Cubo contenedor[N][N][N],int *vidas)
{
 int i,j,k;
  for(i=0;i<N;i++)
 for(j=0;j<N;j++)
{  
  if(contenedor[0][i][j].existe==1 && contenedor[0][i][j].color==5 )
  { 
    contenedor[0][i][j].existe=0;
   contenedor[0][i][j].color=BLACK;
    contenedor[N-1][i][j].existe=1;
    contenedor[N-1][i][j].color=5;
     
  }
  else
   for(k=1;k<N;k++)
    if(contenedor[k][i][j].existe==1 && contenedor[k][i][j].color==5 )
    {
    if(contenedor[k][i][j].existe==1 && contenedor[k-1][i][j].color!=RED && contenedor[k-1][i][j].color!=BLUE&& contenedor[k-1][i][j].color!=5 && contenedor[k-1][i][j].color!=10 && contenedor[k-1][i][j].color!=13 )
    {    
          contenedor[k][i][j].existe=0;    
      contenedor[k][i][j].color=BLACK;
      if(contenedor[k-1][i][j].color==YELLOW)
       {
      contenedor[13][N-2][6].existe=1;
        contenedor[13][N-2][6].color=YELLOW; 
        (*vidas)--;
   }
        
         contenedor[k-1][i][j].existe=1; 
      contenedor[k-1][i][j].color=5;
}
    
 }
}
      
}
void mover_abajo_en_k_magenta(Cubo contenedor[N][N][N],int *vidas)
{
 int i,j,k;
for(i=0;i<N;i++)
for(j=0;j<N;j++)
{
  if(contenedor[N-1][i][j].existe==1 && contenedor[N-1][i][j].color==5 )
  { 
  contenedor[N-1][i][j].existe=0;
  contenedor[N-1][i][j].color=BLACK;
    contenedor[0][i][j].existe=1;  
    contenedor[0][i][j].color=5;
                  
  }
   else
   for(k=N-2;k>=0;k--)
    if(contenedor[k][i][j].existe==1 && contenedor[k][i][j].color==5 )
    {
     if(contenedor[k][i][j].existe==1 &&contenedor[k+1][i][j].color!=RED && contenedor[k+1][i][j].color!=BLUE && contenedor[k+1][i][j].color!=5 && contenedor[k+1][i][j].color!=10 && contenedor[k+1][i][j].color!=13)
    {   
        contenedor[k][i][j].existe=0;                                 
      contenedor[k][i][j].color=BLACK; 
      if(contenedor[k+1][i][j].color==YELLOW)
      {     
         contenedor[13][N-2][6].existe=1;
    contenedor[13][N-2][6].color=YELLOW;                   
    (*vidas)--; 
    }
    
    contenedor[k+1][i][j].existe=1;
      contenedor[k+1][i][j].color=5;  
 }
 }
}
 }
//verde
 void mover_izq_verde(Cubo contenedor[N][N][N],int *vidas)
{
     int i,j,k;
for(k=0;k<N;k++)
for(i=0;i<N;i++)
{  
  if( contenedor[k][i][0].existe==1 && contenedor[k][i][0].color==10)
  {     contenedor[k][i][j].existe=0;
      contenedor[k][i][j].color=BLACK;
    contenedor[k][i][N-1].existe=1;
    contenedor[k][i][N-1].color=10;
    
  }
  else
   for(j=1;j<N;j++)
    if( contenedor[k][i][j].existe==1 && contenedor[k][i][j].color==10 )
    {
     if(contenedor[k][i][j].existe==1 && contenedor[k][i][j-1].color!=BLUE && contenedor[k][i][j-1].color!=RED && contenedor[k][i][j-1].color!=10 && contenedor[k][i][j-1].color!=13 && contenedor[k][i][j-1].color!=5)
     { 
      contenedor[k][i][j].existe=0;                      
      contenedor[k][i][j].color=BLACK;
     if (contenedor[k][i][j-1].color==YELLOW)
      {
      contenedor[13][N-2][6].existe=1;
    contenedor[13][N-2][6].color=YELLOW;        
    (*vidas)--;
      }
       contenedor[k][i][j-1].existe=1; 
      contenedor[k][i][j-1].color=10;
     }
    }
 }
}
void mover_der_verde(Cubo contenedor[N][N][N],int *vidas)
{int i,j,k;
for(k=0;k<N;k++)
for(i=0;i<N;i++)
{
  if(contenedor[k][i][N-1].existe==1 && contenedor[k][i][N-1].color==10 )
  {
  contenedor[k][i][N-1].existe=0; 
  contenedor[k][i][N-1].color=BLACK;
  contenedor[k][i][0].existe=1; 
  contenedor[k][i][0].color=10;  
  }
  else
   for(j=N-2;j>=0;j--)
    if(contenedor[k][i][j].existe==1 && contenedor[k][i][j].color==10 )
    {
      if(contenedor[k][i][j].existe==1 &&contenedor[k][i][j+1].color!=RED && contenedor[k][i][j+1].color!=BLUE&& contenedor[k][i][j+1].color!=10 && contenedor[k][i][j+1].color!=13 && contenedor[k][i][j+1].color!=5)
    {
       contenedor[k][i][j].existe=0;                                
      contenedor[k][i][j].color=BLACK;
       if (contenedor[k][i][j+1].color==YELLOW)
      {
      contenedor[13][N-2][6].existe=1;
    contenedor[13][N-2][6].color=YELLOW;   
    (*vidas)--;     
      }
       contenedor[k][i][j+1].existe=1; 
      contenedor[k][i][j+1].color=10;
                     
    }
 }
}
}
 void mover_arriba_en_k_verde(Cubo contenedor[N][N][N],int *vidas)
{
 int i,j,k;
  for(i=0;i<N;i++)
 for(j=0;j<N;j++)
{  
  if(contenedor[0][i][j].existe==1 && contenedor[0][i][j].color==10 )
  { 
    contenedor[0][i][j].existe=0;
   contenedor[0][i][j].color=BLACK;
    contenedor[N-1][i][j].existe=1;
    contenedor[N-1][i][j].color=10;
     
  }
  else
   for(k=1;k<N;k++)
    if(contenedor[k][i][j].existe==1 && contenedor[k][i][j].color==10 )
    {
    if(contenedor[k][i][j].existe==1 && contenedor[k-1][i][j].color!=BLUE && contenedor[k-1][i][j].color!=RED  && contenedor[k-1][i][j].color!=10 && contenedor[k-1][i][j].color!=13 && contenedor[k-1][i][j].color!=5)
    {    
          contenedor[k][i][j].existe=0;    
      contenedor[k][i][j].color=BLACK;
      if (contenedor[k-1][i][j].color==YELLOW)
      {
      contenedor[13][N-2][6].existe=1;
    contenedor[13][N-2][6].color=YELLOW;        
    (*vidas)--;
      }
       contenedor[k-1][i][j].existe=1; 
      contenedor[k-1][i][j].color=10;
   }
    
 }
}
      
}
void mover_abajo_en_k_verde(Cubo contenedor[N][N][N],int *vidas)
{
 int i,j,k;
for(i=0;i<N;i++)
for(j=0;j<N;j++)
{
  if(contenedor[N-1][i][j].existe==1 && contenedor[N-1][i][j].color==10 )
  { 
  contenedor[N-1][i][j].existe=0;
  contenedor[N-1][i][j].color=BLACK;
    contenedor[0][i][j].existe=1;  
    contenedor[0][i][j].color=10;
                  
  }
   else
   for(k=N-2;k>=0;k--)
    if(contenedor[k][i][j].existe==1 && contenedor[k][i][j].color==10 )
    {
     if(contenedor[k][i][j].existe==1 && contenedor[k+1][i][j].color!=BLUE && contenedor[k+1][i][j].color!=RED && contenedor[k+1][i][j].color!=10 && contenedor[k+1][i][j].color!=13 && contenedor[k+1][i][j].color!=5  )
    {   
        contenedor[k][i][j].existe=0;                                 
      contenedor[k][i][j].color=BLACK;
        if (contenedor[k+1][i][j].color==YELLOW)
      {
      contenedor[13][N-2][6].existe=1;
    contenedor[13][N-2][6].color=YELLOW;        
      (*vidas)--;
      }
       contenedor[k+1][i][j].existe=1; 
      contenedor[k+1][i][j].color=10;                    
    }
 }
}
 }
//rosa
void mover_izq_rosa(Cubo contenedor[N][N][N],int *vidas)
{
     int i,j,k;
for(k=0;k<N;k++)
for(i=0;i<N;i++)
{  
  if( contenedor[k][i][0].existe==1 && contenedor[k][i][0].color==13 )
  {     contenedor[k][i][j].existe=0;
      contenedor[k][i][j].color=BLACK;
    contenedor[k][i][N-1].existe=1;
    contenedor[k][i][N-1].color=13;
    
  }
  else
   for(j=1;j<N;j++)
    if( contenedor[k][i][j].existe==1 && contenedor[k][i][j].color==13 )
    {
     if(contenedor[k][i][j].existe==1 && contenedor[k][i][j-1].color!=BLUE&& contenedor[k][i][j-1].color!=RED && contenedor[k][i][j-1].color!=5 && contenedor[k][i][j-1].color!=10 && contenedor[k][i][j-1].color!=13 )
     { 
      contenedor[k][i][j].existe=0;                      
      contenedor[k][i][j].color=BLACK;
      if (contenedor[k][i][j-1].color==YELLOW)
      {
      contenedor[13][N-2][6].existe=1;
    contenedor[13][N-2][6].color=YELLOW;        
    (*vidas)--;
      }
       contenedor[k][i][j-1].existe=1; 
      contenedor[k][i][j-1].color=13;                    
    }             
     }
    }
 }

void mover_der_rosa(Cubo contenedor[N][N][N],int *vidas)
{int i,j,k;
for(k=0;k<N;k++)
for(i=0;i<N;i++)
{
  if(contenedor[k][i][N-1].existe==1 && contenedor[k][i][N-1].color==13 )
  {
  contenedor[k][i][N-1].existe=0; 
  contenedor[k][i][N-1].color=BLACK;
  contenedor[k][i][0].existe=1; 
  contenedor[k][i][0].color=13;  
  }
  else
   for(j=N-2;j>=0;j--)
    if(contenedor[k][i][j].existe==1 && contenedor[k][i][j].color==13 )
    {
      if(contenedor[k][i][j].existe==1 && contenedor[k][i][j+1].color!=BLUE && contenedor[k][i][j+1].color!=RED && contenedor[k][i][j+1].color!=5 && contenedor[k][i][j+1].color!=10 && contenedor[k][i][j+1].color!=13)
    {
       contenedor[k][i][j].existe=0;                                
      contenedor[k][i][j].color=BLACK;
       if (contenedor[k][i][j+1].color==YELLOW)
      {
      contenedor[13][N-2][6].existe=1;
    contenedor[13][N-2][6].color=YELLOW;        
    (*vidas)--;
      }
       contenedor[k][i][j+1].existe=1; 
      contenedor[k][i][j+1].color=13;      
    }
 }
}
}
 void mover_arriba_en_k_rosa(Cubo contenedor[N][N][N],int *vidas)
{
 int i,j,k;
  for(i=0;i<N;i++)
 for(j=0;j<N;j++)
{  
  if(contenedor[0][i][j].existe==1 && contenedor[0][i][j].color==13 )
  { 
    contenedor[0][i][j].existe=0;
   contenedor[0][i][j].color=BLACK;
    contenedor[N-1][i][j].existe=1;
    contenedor[N-1][i][j].color=13;
     
  }
  else
   for(k=1;k<N;k++)
    if(contenedor[k][i][j].existe==1 && contenedor[k][i][j].color==13)
    {
    if(contenedor[k][i][j].existe==1 && contenedor[k-1][i][j].color!=BLUE && contenedor[k-1][i][j].color!=RED && contenedor[k-1][i][j].color!=5 && contenedor[k-1][i][j].color!=10 && contenedor[k-1][i][j].color!=13 )
    {    
          contenedor[k][i][j].existe=0;    
      contenedor[k][i][j].color=BLACK;
      if (contenedor[k-1][i][j].color==YELLOW)
      {
      contenedor[13][N-2][6].existe=1;
    contenedor[13][N-2][6].color=YELLOW;        
    (*vidas)--;
      }
       contenedor[k-1][i][j].existe=1; 
      contenedor[k-1][i][j].color=13;   
   }
    
 }
}
      
}
void mover_abajo_en_k_rosa(Cubo contenedor[N][N][N],int *vidas)
{
 int i,j,k;
for(i=0;i<N;i++)
for(j=0;j<N;j++)
{
  if(contenedor[N-1][i][j].existe==1 && contenedor[N-1][i][j].color==13 )
  { 
  contenedor[N-1][i][j].existe=0;
  contenedor[N-1][i][j].color=BLACK;
    contenedor[0][i][j].existe=1;  
    contenedor[0][i][j].color=13;
                  
  }
   else
   for(k=N-2;k>=0;k--)
    if(contenedor[k][i][j].existe==1 && contenedor[k][i][j].color==13 )
    {
     if(contenedor[k][i][j].existe==1 && contenedor[k+1][i][j].color!=BLUE && contenedor[k+1][i][j].color!=RED && contenedor[k+1][i][j].color!=5 && contenedor[k+1][i][j].color!=10 && contenedor[k+1][i][j].color!=13)
    {   
        contenedor[k][i][j].existe=0;                                 
      contenedor[k][i][j].color=BLACK;
       if (contenedor[k+1][i][j].color==YELLOW)
      {
      contenedor[13][N-2][6].existe=1;
    contenedor[13][N-2][6].color=YELLOW;        
    (*vidas)--;
      }
       contenedor[k+1][i][j].existe=1; 
      contenedor[k+1][i][j].color=13;                    
    }
 }
}
 }

//pacman
void mover_izq(Cubo contenedor[N][N][N],int *marcador)
{int i,j,k;
for(k=0;k<N;k++)
for(i=0;i<N;i++)
{  
  if(contenedor[k][i][0].existe==1 && contenedor[k][i][0].color==YELLOW )
  { contenedor[k][i][0].existe=0;
     contenedor[k][i][0].color=BLACK;
    contenedor[k][i][N-1].existe=1;
    contenedor[k][i][N-1].color=YELLOW;
    
  }
  else
   for(j=1;j<N;j++)
    if(contenedor[k][i][j].existe==1 && contenedor[k][i][j].color==YELLOW )
    {
    if(contenedor[k][i][j-1].color!=BLUE && contenedor[k][i][j-1].color!=10 && contenedor[k][i][j-1].color!=13 && contenedor[k][i][j-1].color!=5 )
     {
      contenedor[k][i][j].existe=0;
      contenedor[k][i][j].color=BLACK;
      if(contenedor[k][i][j-1].color==RED)
       {
        (*marcador)+=100;   
        jugador.puntos+=100;                               
       }
       contenedor[k][i][j-1].existe=1;   //ANTES DEL MOVIMIENTO VERIFICAR SI ES COMIDA Y AUMENTAR MARCADOR
      contenedor[k][i][j-1].color=YELLOW;
      }          
    }
 }

}
void mover_der(Cubo contenedor[N][N][N],int *marcador)
{int i,j,k;
for(k=0;k<N;k++)
for(i=0;i<N;i++)
{
  if(contenedor[k][i][N-1].existe==1 && contenedor[k][i][N-1].color==YELLOW )
  {  
     contenedor[k][i][N-1].existe=0;
    contenedor[k][i][N-1].color=BLACK;
    contenedor[k][i][0].existe=1; 
    contenedor[k][i][0].color=YELLOW;
                  
  }
  else
   for(j=N-2;j>=0;j--)
    if(contenedor[k][i][j].existe==1 && contenedor[k][i][j].color==YELLOW )
    {
      if(contenedor[k][i][j].existe==1 && contenedor[k][i][j+1].color!=BLUE && contenedor[k][i][j+1].color!=10 && contenedor[k][i][j+1].color!=13 && contenedor[k][i][j+1].color!=5)
    {
      contenedor[k][i][j].existe=0;
      contenedor[k][i][j].color=BLACK;
      if(contenedor[k][i][j+1].color==RED)
      {
       (*marcador)+=100; 
           jugador.puntos+=100;                              
      }
      contenedor[k][i][j+1].existe=1; 
      contenedor[k][i][j+1].color=YELLOW;
                    
    }
 }
}
}
void mover_abajo_en_k(Cubo contenedor[N][N][N],int *marcador)
{
     int i,j,k;
for(i=0;i<N;i++)
for(j=0;j<N;j++)
{
  if( contenedor[N-1][i][j].existe==1 && contenedor[N-1][i][j].color==YELLOW)
  { contenedor[N-1][i][j].existe=0;
  contenedor[N-1][i][j].color=BLACK;
  contenedor[0][i][j].existe=1; 
    contenedor[0][i][j].color=YELLOW;
                   
  }
   else
   for(k=N-2;k>=0;k--)
    if(contenedor[k][i][j].existe==1 && contenedor[k][i][j].color==YELLOW )
    {
     if(contenedor[k][i][j].existe==1 && contenedor[k+1][i][j].color!=BLUE && contenedor[k+1][i][j].color!=10 && contenedor[k+1][i][j].color!=13 && contenedor[k+1][i][j].color!=5)
    {     
        contenedor[k][i][j].existe=0;                               
      contenedor[k][i][j].color=BLACK;
      if(contenedor[k+1][i][j].color==RED)
      {
      (*marcador)+=100;
      jugador.puntos+=100;
      }
     contenedor[k+1][i][j].existe=1; 
      contenedor[k+1][i][j].color=YELLOW;
                    
    }
 }
}
}
void mover_arriba_en_k(Cubo contenedor[N][N][N],int *marcador)
{
     int i,j,k;
for(i=0;i<N;i++)
for(j=0;j<N;j++)
{  
  if(contenedor[0][i][j].existe==1 && contenedor[0][i][j].color==YELLOW )
  {   contenedor[0][i][j].existe=0;
  contenedor[0][i][j].color=BLACK;
  contenedor[N-1][i][j].existe=1;
    contenedor[N-1][i][j].color=YELLOW;
   
  }
  else
   for(k=1;k<N;k++)
    if(contenedor[k][i][j].existe==1 && contenedor[k][i][j].color==YELLOW )
    {
    if(contenedor[k][i][j].existe==1 && contenedor[k-1][i][j].color!=BLUE && contenedor[k-1][i][j].color!=10 && contenedor[k-1][i][j].color!=13 && contenedor[k-1][i][j].color!=5 )
    {    
       contenedor[k][i][j].existe=0;    
      contenedor[k][i][j].color=BLACK;
      if(contenedor[k-1][i][j].color==RED)
      {
       (*marcador)+=100; 
       jugador.puntos+=100;                           
      } 
       contenedor[k-1][i][j].existe=1; 
      contenedor[k-1][i][j].color=YELLOW;
   }    
 }
}
}
void insertarRecord(Record al)
{
     FILE *pt;
     Record p[5],aux[5];
     char records[30]="Record.dat";
     int i;
     
     pt=fopen(records,"rb+");
     if(pt==NULL)//El archivo no existe
     {
       pt=fopen(records,"wb");
       strcpy(p[0].nombre,al.nombre);
       p[0].puntos=al.puntos;
       for(i=1;i<5;i++)
       {
       strcpy(p[i].nombre,"________________");
       p[i].puntos=0;
       }
       fwrite(p,sizeof(jugador),5,pt);
     }
     else
     {
         fread(p,sizeof(jugador),5,pt);
         fseek(pt,0,SEEK_SET);
         if(al.puntos > p[0].puntos)
         {
         strcpy(aux[0].nombre,al.nombre);
         aux[0].puntos=al.puntos;
           for(i=0;i<4;i++)
           {
           strcpy(aux[i+1].nombre,p[i].nombre);
           aux[i+1].puntos=p[i].puntos;
           }
         }
         else
         {
             i=0;
             do
             {
                 strcpy(aux[i].nombre,p[i].nombre);
                 aux[i].puntos=p[i].puntos;
                 i++;
                 if(i==5)
                 break;
             }while(p[i].puntos > al.puntos);
         if(i!=5)
         {
         strcpy(aux[i].nombre,al.nombre);
         aux[i].puntos=al.puntos;
         
           for(;i<4;i++)
           {
                        strcpy(aux[i+1].nombre,p[i].nombre);
                        aux[i+1].puntos=p[i].puntos;
           }
          }
         }
         fwrite(aux,sizeof(jugador),5,pt);
     }
     fclose(pt);
}

void imprimirRecords()
{
            FILE *pt;
            Record ma[5];
            char cpuntos[20];
            int i;
            char op, nom[30]="Record.dat";

            pt=fopen(nom,"rb");


            cleardevice();
            setcolor(YELLOW);
            settextstyle(8,0,1);


          do{
                if(pt==NULL) 
                {
                  settextstyle(6,0,3);
                  outtextxy(300,450,"Presiona Enter para regresar al Menu ");
                  outtextxy(30,60,"No hay Records ");
                }
                else
                {
                 settextstyle(6,0,3);
                 outtextxy(300,450,"Presiona Enter para regresar al Menu");
                 settextstyle(8,0,3);
                 outtextxy(40,60,"Records: ");
  
                  fread(ma,sizeof(jugador),5,pt);
                  for(i=0;i<5;i++)
                  {
                   itoa(ma[i].puntos,cpuntos,10);
                   outtextxy(50,100+(i+1)*30,ma[i].nombre);
                   outtextxy(500,100+(i+1)*30,cpuntos);
                  }
                 }
                 op=getch();
              }while(op!=13);//ESC
         fclose(pt);
}


