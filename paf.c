/*
prueba final acumulativa
Nelson Andrés González Guerra
rut:19084305
este programa solo funciona para 5 variables ingresadas por archivo
*/
#include <stdio.h>

int main(){
	//se definen variables y punteros a utilizar
	FILE *entrada;
	FILE *salida;
	char entra[6];
	int i,j,aux=0,diferencia[4];
	int p=1;
	int suma1=0,suma2=0;
	int *subarr1,*subarr2;
	//se abre el archivo para extraer los numeros a un arreglo
	if (!(entrada=fopen("entrada.ent","r")))
		printf("Error al abrir el fichero");
		else{
		//se guardan los numeros como char en un arreglo de caracteres	
		fgets(entra,6,entrada);
		fclose(entrada); //se cierra el archivo ya que no se usara mas
	}
	int arreglo[6]; //a pesar de que se ingresan 5 valores hay que considerar el caracter nulo
	for ( i = 0; i < 5; ++i)
		arreglo[i]=(int)entra[i]-48; // se transforman los numeros char a numeros enteros y se pasan a otro arreglo
	subarr1=&arreglo[0];    //se define el punto de partida de los punteros
	subarr2=&arreglo[p];	
	for (i=0;i<p;++i){       //se hacen los subarreglos mediante la variable p 
		suma1=suma1+(*subarr1);   //se hace la suma de los elementos de un subarreglo variando la direccion del elemento
		subarr1++;
	}
	for (i=p;i<5;++i){
		suma2=suma2+(*subarr2);   //lo mismo para el segundo subarreglo
		subarr2++;
	}
	diferencia[0]=suma1-suma2;
	if (diferencia[0]<0)            //se calcula la diferencia de la primera subdivision de arreglos
		diferencia[0]=diferencia[0]*-1;	
	suma1=0;
	suma2=0;
	p++;  //se aumenta en 1 el punto de corte para cambiar el indice de los subarreglos
	subarr1=&arreglo[0];     //comienza todo el proceso de nuevo
	subarr2=&arreglo[p];	 // se establecen los nuevos valores iniciales para la aritmetica de punteros
	for (i=0;i<p;++i){
		suma1=suma1+(*subarr1);
		subarr1++;
	}
	for (i=p;i<5;++i){
		suma2=suma2+(*subarr2);
		subarr2++;
	}
	diferencia[1]=suma1-suma2;
	if (diferencia[1]<0)
		diferencia[1]=diferencia[1]*-1;	
	suma1=0;
	suma2=0;
	p++;
	subarr1=&arreglo[0];
	subarr2=&arreglo[p];	
	for (i=0;i<p;++i){
		suma1=suma1+(*subarr1);
		subarr1++;
	}
	for (i=p;i<5;++i){
		suma2=suma2+(*subarr2);
		subarr2++;
	}
	diferencia[2]=suma1-suma2;
	if (diferencia[2]<0)
		diferencia[2]=diferencia[2]*-1;	
	suma1=0;
	suma2=0;
	p++;
	subarr1=&arreglo[0];
	subarr2=&arreglo[p];	
	for (i=0;i<p;++i){
		suma1=suma1+(*subarr1);
		subarr1++;
	}
	for (i=p;i<5;++i){
		suma2=suma2+(*subarr2);
		subarr2++;
	}
	diferencia[3]=suma1-suma2;
	if (diferencia[3]<0)
		diferencia[3]=diferencia[3]*-1;	
	for(i=0;i<4;++i){                     //se meten los diferencias positivas de todos los subarreglos y se ordenan de mayor a menor
		for (j=0;j<3;++j){                //luego se selecciona el menor de ellos y se guarda en el archivo salida.sal
			if (diferencia[j]<diferencia[j+1]){
				aux=diferencia[j];
				diferencia[j]=diferencia[j+1];
				diferencia[j+1]=aux;
			}	
		}
	}
	printf("%d\n",diferencia[3]);
	salida=fopen("salida.sal","w");       //se abre el archivo para depositar la menor diferencia de subarreglos
	fprintf(salida,"%d",diferencia[3]);
	fclose(salida);                      //se cierra el archivo salida.sal
}