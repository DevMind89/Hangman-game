/*Juego del ahorcado*/
/*Mario Guiberteau Lopez*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

char palabra[50],rep[80],temporal[80];
char letra,aux;
int longitud,i,j,inicial,acertado=0,temp=0,oportunidades=7;
int repetido=0,ganar=0;

int main() 
{   
  
   //Introduccion   
    printf("\n\tJuego del Ahorcado!\n\n");
    printf("Introduzca la palabra a adivinar: ");    
    i=0;
    do{
    	palabra[i]=getch();
    	i++;
	}while(palabra[i-1]!='\r');   	
	i--;
   	palabra[i]='\0';
   	temporal[i]='\0';
    system("cls");
   
    longitud=0;
    inicial=0;
   
   //Juego
    do{
        system("cls");
        temp=0;
        
        if(inicial==0) 
		{
	        for(i=0;i<strlen(palabra);i++) 
			{
		        if(palabra[i]==' ') 
				{
		            temporal[i]=' ';
		            longitud++;
		        }
		        else 
				{
		            temporal[i]='_';       
		            longitud++;
		        }
	        }
        }
   
        inicial=1;       
        temporal[longitud]='\0';
       
        for(i=0;i<strlen(rep);i++) 
		{
	        if(rep[i]==letra) 
			{
	            repetido=1;
	    	}
          	else 
			{
           		repetido=0;
         	}
        }
       
        if(repetido==0) 
		{
	        for(i=0;i<strlen(palabra);i++) 
			{
	        	if(palabra[i]==letra) 
				{
			        temporal[i]=letra;
			        acertado++;
			        temp=1;
	            }
	        }
        }
       
        if(repetido==0)
		{
	        if(temp==0)
			{
	           oportunidades--;
         	}
        }
       
        printf("\n");
       
       //Espacios entre barra baja _ _ _
       
        for(i=0;i<strlen(temporal);i++) 
		{
         	printf(" %c ",temporal[i]);
        }
       
        printf("\n");
       
        //Comprobacion
		if(strcmp(palabra,temporal)==0) 
		{
            ganar=1;
            break;
        }
       
       //Palabras acertadas y oportunidades restantes
        printf("\n");
        printf("Letras Acertadas: %d",acertado);
        printf("\n");
        printf("Oportunidades Restantes: %d",oportunidades);
        printf("\n");
       
        if(oportunidades==0)
        {
           break;
        }
     
	 	//Introducir letra
        printf("Introduzca una letra:");
        letra=getche();
        
      
    }while(oportunidades != 0 );
   
   	//Comprobar si ha ganado el jugador
    if(ganar==1) 
	{
        printf("\n\n");
        printf("Enhorabuena, has ganado.");
    }
    else 
	{
        printf("\n\n");
        printf("\tHas perdido :(");
        printf("\n\tLa palabra era: %s",palabra);
    }
   
    printf("\n\n");
    system("PAUSE");
    return 0;

} 
