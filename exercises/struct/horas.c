// Escribir una función que reciba 2 horas h1 y h2 (hora, minutos y segundos)
// y devuelva la diferencia entre ambas (en horas, minutos y segundos). Se sabe que h2 es posterior a h1

#include<stdio.h>

typedef struct{
    int hours;
    int min;
    int sec;
}time;

int main()
{
    time h1, h2, dif;

    printf("Enter start time: (h m s) \n");
    scanf("%d %d %d", &h1.hours,&h1.min, &h1.sec);

    printf("Enter stop time: (h m s) \n");
    scanf("%d %d %d", &h2.hours,&h2.min, &h2.sec);

    if(h1.sec > h2.sec){
        h2.sec += 60;
        h2.min--;
    }

    if(h1.min > h2.min){
        h2.min += 60;
        h2.hours--;
    }

    dif.sec = h2.sec - h1.sec;
    dif.min = h2.min - h1.min;
    dif.hours = h2.hours - h1.hours;

    printf("Difference: %d : %d : %d", dif.hours, dif.min, dif.sec);
    return 0;
}
