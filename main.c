#include <stdio.h>
// Estructura de boleto
#include <stdio.h>
#include <stdbool.h>
int compara(int J[],int K[], int m){
    int coincidencias =0;
    for (int x = 0; x<=6; x++){
                    for (int y = 0; y<=6 ; y++){
                        if (J[x]==K[y]){
                            coincidencias++;
                           
                        }
                    }
    }
    return coincidencias;
}
void imprime(int V[], int N) //
{
    printf("\n");
    printf(" ");
    for (int i=1; i<N; i++) //ciclo interaciones del array
         printf(" \t [%d] ",V[i]);
}

int * shell(int a[], int n){
    int ints, i, aux;
    bool band;
    
    ints = n;
    while(ints >1){
        ints = (ints/2);
        band = true;
        while(band == true){
            band = false;
            i = 0;
            while(i+ints <= n){
                if(a[i] > a[i+ints]){
                    aux = a[i];
                    a[i] = a[i+ints];
                    a[i+ints] = aux;
                    band = true;
                }
                i++;
            }
        }
    }
  
    return a;
}



struct Boleto{
    int id;
    int numeros[6];
    int aciertos;
};

int main()
{
    // VAR GLOBALES
    // base de datos de boletos
    struct Boleto boletos[200];
    // variable para llevar el conteo y el ID de boletos
    int boletoActualCapturar = 0;
    // flag para saber si repitieron numerosIngresados se usa en Case 1 y 2
    int flag = 0;
    
    // CASE 2 variables
    // Array para guardar numeros y comparar
    int oldNumbers[7];
    // Array para numeros de GANADOR melate
    int gMelate[7];
    // Array para GANADOR de revancha
    int gRevancha[6];
    // Array para GANADOR de revanchita
    int gRevanchita[6];
    
    // variable para elegir opcion de menu
    int opc;
    // Ciclo del menu
    
    int coincidencias=0;

    do{
        // elegir opcion
        printf("\n ======================== Melate, Revancha, Revanchita ========================");
        printf ("\n\n   1. Capturar boleta");
        printf ("\n\n   2. Realizar Sorteo");
        printf ("\n\n   3. Reporte de Boletas Capturadas");
        printf ("\n\n   4. Reporte de Boletas Ganadores");
        printf ("\n\n   5. Reinicio de la app");
        printf ("\n\n   6. Salir");
        printf("\n\n - Ingresa la opcion que deseas: ");
        scanf ("\n\n %d", &opc);
        switch (opc){
            // Captura de boleta
            case 1:
                printf("\nCaptura de Boleta\n");
                for(int i = 0; i < 6; i++){
                    int dato;
                    printf("\n - Ingrese el #%d numero a capturar que sea menor a 56: ", i+1);
                    scanf("%d", &dato);
                    if(dato <= 56){
                        // validacion si se repite numero
                        for(int e = 0; e <= i; e++){
                            if(boletos[boletoActualCapturar].numeros[e] == dato){
                                flag = 1;
                            }
                        }
                        if(flag == 0){
                            boletos[boletoActualCapturar].numeros[i] = dato;
                        }
                        else{
                            printf("\n + El numero %d esta repetido favor de intentar otro", dato);
                            flag = 0;
                            i--;
                        }
                        
                    }
                    else{
                        i--;
                    }
                }
               
         
                shell(boletos[boletoActualCapturar].numeros, 5);
               
                boletos[boletoActualCapturar].id = boletoActualCapturar;
                boletoActualCapturar++;
                // TODO falta acomodar los numeros despues de ingresarlos
                
                
                break;
                
            // Realizar sorteo
            case 2:
                // Genera 7 numeros aleatorios no repetidos del 1 al 56
                for(int i = 0; i < 7; i++){
                    int newNumber = rand()%((56+1)-1) + 1;
                    
                    if(i == 0){
                        oldNumbers[i] = newNumber;
                    }
                    else{
                        for(int e = 0; e < i; e++){
                            if(newNumber == oldNumbers[e]){
                                flag = 1;
                            }
                        }
                        if(flag == 1){
                            i--;
                        }
                        else{
                            oldNumbers[i] = newNumber;
                        }
                    }
                }
                // GANADOR melate
                // Genera 7 numeros aleatorios no repetidos del 1 al 56
                for(int i = 0; i < 7; i++){
                    int newNumber = rand()%((56+1)-1) + 1;
                    if(i == 0){
                        oldNumbers[i] = newNumber;
                    }
                    else{
                        for(int e = 0; e < i; e++){
                            if(newNumber == oldNumbers[e]){
                                flag = 1;
                            }
                        }
                        if(flag == 1){
                            i--;
                        }
                        else{
                            oldNumbers[i] = newNumber;
                        }
                    }
                }
                for(int i = 0; i < 7; i++){
                    gMelate[i] = oldNumbers[i];
                    oldNumbers[i] = 0;
                }
                shell(gMelate,7); // Ordena numeros ganadores
                // GANADOR revancha
                // Genera 6 numeros aleatorios no repetidos del 1 al 56
                for(int i = 0; i < 6; i++){
                    int newNumber = rand()%((56+1)-1) + 1;
                    if(i == 0){
                        oldNumbers[i] = newNumber;
                    }
                    else{
                        for(int e = 0; e < i; e++){
                            if(newNumber == oldNumbers[e]){
                                flag = 1;
                            }
                        }
                        if(flag == 1){
                            i--;
                        }
                        else{
                            oldNumbers[i] = newNumber;
                        }
                    }
                }
                for(int i = 0; i < 6; i++){
                    gRevancha[i] = oldNumbers[i];
                    oldNumbers[i] = 0;
                    
                }
                shell(gRevancha,6); // Ordena numeros ganadores
                // GANADOR revanchita
                // Genera 6 numeros aleatorios no repetidos del 1 al 56
                for(int i = 0; i < 6; i++){
                    int newNumber = rand()%((56+1)-1) + 1;
                    if(i == 0){
                        oldNumbers[i] = newNumber;
                    }
                    else{
                        for(int e = 0; e < i; e++){
                            if(newNumber == oldNumbers[e]){
                                flag = 1;
                            }
                        }
                        if(flag == 1){
                            i--;
                        }
                        else{
                            oldNumbers[i] = newNumber;
                        }
                    }
                }
                
                for(int i = 0; i < 6; i++){
                    gRevanchita[i] = oldNumbers[i];
                    oldNumbers[i] = 0;
                }
                shell(gRevanchita,6); // Ordena numeros ganadores
                // TODO falta ordenar los numeros ganadores y comparar
                printf("\n Numeros ganadores\n");
                printf("\n Melate :\t \n");
                
                imprime(gMelate,8);
                printf("\n Revancha :\t \n");
                imprime(gRevancha, 7);
                printf("\n Revanchita :\t \n");
                imprime(gRevanchita, 7);
                
                break;
            case 3:
            for(int j = 0; j < boletoActualCapturar; j++){
                    for(int k = 0; k < 7; k++){
                        
                        printf("[%i] %i \n",boletos[j].id,boletos[j].numeros[k]); 
                    }
                }
                
            break;

            case 4:
            printf("\n ======================== Ganador melate ========================\n");
            //Compara los numeros del boleto con los numeros de el sorteo
            for (int z = 0; z<boletoActualCapturar;z++){
                boletos[z].aciertos= compara(boletos[z].numeros,gMelate,7);
               
            }
            int temp;
            // ordena los boletos en base a sus aciertos en ascendente
            for(int i=1;i<boletoActualCapturar-1;i++)
            {
	        for(int j=1;j<boletoActualCapturar-i-1;j++)
        	{
		        if (boletos[j].aciertos> boletos[j+1].aciertos)
	        	{
		        temp=boletos[j].aciertos;
		        boletos[j].aciertos=boletos[j+1].aciertos;
		        boletos[j+1].aciertos=temp;
		        }
	        }
        }
        // imprime los resultados y devuelve los valores de aciertos a 0 para el siguiente sorteo
            for(int i=0;i<3;i++){
                printf("Num [%d], boleto [%d], aciertos[%d]\n",i+1,boletos[i].id+1,boletos[i].aciertos);
                boletos[i].aciertos=0;
            }
        printf("\n ======================== Ganador Revancha ========================\n");
        //Compara los numeros del boleto con los numeros de el sorteo
        
        for (int z = 0; z<boletoActualCapturar;z++){
                boletos[z].aciertos= compara(boletos[z].numeros,gRevancha,6);
                
                
            }
            // ordena los boletos en base a sus aciertos en ascendente
            for(int i=1;i<boletoActualCapturar-1;i++)
            {
	        for(int j=1;j<boletoActualCapturar-i-1;j++)
        	{
		        if (boletos[j].aciertos> boletos[j+1].aciertos)
	        	{
		        temp=boletos[j].aciertos;
		        boletos[j].aciertos=boletos[j+1].aciertos;
		        boletos[j+1].aciertos=temp;
		        }
	        }
        }
       
       for(int i=0;i<3;i++){
                printf("Num [%d], boleto [%d], aciertos[%d]\n",i+1,boletos[i].id+1,boletos[i].aciertos);
                boletos[i].aciertos=0;
            }
        printf("\n ======================== Ganador Revanchita ========================\n");
        //Compara los numeros del boleto con los numeros de el sorteo
         for (int z = 0; z<boletoActualCapturar;z++){
                boletos[z].aciertos= compara(boletos[z].numeros,gRevanchita,6);
               
            }
            // ordena los boletos en base a sus aciertos en ascendente
            for(int i=1;i<boletoActualCapturar-1;i++)
            {
	        for(int j=1;j<boletoActualCapturar-i-1;j++)
        	{
		        if (boletos[j].aciertos> boletos[j+1].aciertos)
	        	{
		        temp=boletos[j].aciertos;
		        boletos[j].aciertos=boletos[j+1].aciertos;
		        boletos[j+1].aciertos=temp;
		        }
	        }
        }
 
 
            // imprime los resultados y devuelve los valores de aciertos a 0 para el siguiente sorteo
            for(int i=0;i<3;i++){
                printf("Num [%d], boleto [%d], aciertos[%d]\n",i+1,boletos[i].id+1,boletos[i].aciertos);
                boletos[i].aciertos=0;
            }
 
            
             // BORRAR boletos ganadores
                for(int i = 0; i <= 6; i++){
                    if(i != 6){
                        gRevanchita[i] = 0;
                        gRevancha[i] = 0;
                    }
                    gMelate[i] = 0;
                }
                
            break;

            // Reinicio de la app
            case 5:
                printf("\nSe reiniciara la app, los datos se estan borrando");
                // BORRAR boletos capturados
                for(int i = 0; i <= boletoActualCapturar; i++){
                    for(int e = 0; e < 6; e++){
                        boletos[i].numeros[e] = 0;
                    }
                    boletos[i].id = 0;
                }
                // BORRAR boletos ganadores
                for(int i = 0; i <= 6; i++){
                    if(i != 6){
                        gRevanchita[i] = 0;
                        gRevancha[i] = 0;
                    }
                    gMelate[i] = 0;
                }
                boletoActualCapturar = 0;
                flag = 0;
                break;
        }
    } while (opc != 6);
    printf("Programa finalizado");

    return 0;
}
