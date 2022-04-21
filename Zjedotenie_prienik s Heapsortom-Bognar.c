#include <stdio.h>
#include <stdlib.h>

void uspor(int a[], int dlzka, int i){
    int center = 0;
    int prava = 0;
    int lava = 0;

    center = i;
    prava = (2 * i) + 2;
    lava = (2 * i) + 1;

    if (a[lava] > a[center] && dlzka > lava)
    {
        center = lava;
    }
    if (a[prava] > a[center] && dlzka > prava)
    {
        center = prava;
    }
    if (center != i)
    {
        zmena(&a[i], &a[center]);
        uspor(a, dlzka, center);
    }
}


void zmena(int *i, int *center){
    int x;
    x = *i;
    *i = *center;
    *center = x;
}


void heapsort(int a[], int dlzka){
    int i=0;

    for(i=dlzka/2-1; i>=0; i--){
        uspor(a,dlzka,i);
     }

    for(i=dlzka-1; i>=0; i --){
        zmena(&a[0], &a[i]);
        uspor(a,i,0);
        }
    }


void zadaj_hodnoty(int a[], int dlzka){
    int i;
    for(i=0;i<dlzka;i++){
        printf("Zadajte %d. prvok pola: \n", i);
        scanf("%d", &a[i]);
    }
}

void vypis(int a[], int dlzka){
    int i;
    for(i=0;i<dlzka;i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

int PRIENIK(int a[], int b[], int prienik[], int dlzka){
    int i,j,m;
    i=0;
    j=0;
    m=0;

    while((i < dlzka) && (j < dlzka)){
        if(a[i] < b[j]){
            i++;
        }
        else if(a[i] > b[j]){
            j++;
        }
        else{
            prienik[m] = a[i];
            i++;
            j++;
            m++;
        }
    }
    return(m);
}


int ZJEDNOTENIE(int a[], int b[], int zjednotenie[], int dlzka){
    int i,j,m;
    i=0;
    j=0;
    m=0;

    while((i < dlzka) && (j < dlzka)){
        if(a[i] < b[j]){
            zjednotenie[m] = a[i];
            i++;
            m++;
            }
        else if(a[i] > b[j]){
            zjednotenie[m] = b[j];
            j++;
            m++;
            }
        else{
            zjednotenie[m] = a[i];
            i++;
            j++;
            m++;
            }
        }

    if (i == dlzka){
        while(j < dlzka){
            zjednotenie[m] = b[j];
            j++;
            m++;
        }
    }
    else{
        while(i < dlzka){
            zjednotenie[m] = a[i];
            i++;
            m++;  
        }
    }

    return(m);

}


int main() {

    int dlzka, dlzka_prienik, dlzka_zjednotenie;
    printf("Zadajte dlzky listoch: ");
    scanf("%d", &dlzka);

    int a[dlzka], b[dlzka];
    int prienik[dlzka], zjednotenie[dlzka];

    printf("Prvky prveho pola: \n");
    zadaj_hodnoty(a,dlzka);
    printf("Prvky druheho pola: \n");
    zadaj_hodnoty(b,dlzka);

    heapsort(a, dlzka);
    heapsort(b, dlzka);

    printf("1. Sortovane pole: \n");
    vypis(a, dlzka);
    printf("2. Sortovane pole: \n");
    vypis(b, dlzka);

    dlzka_prienik = PRIENIK(a,b,prienik,dlzka);
    printf("Prienik dvoch mnozin je: \n");
    vypis(prienik, dlzka_prienik);

    dlzka_zjednotenie = ZJEDNOTENIE(a,b,zjednotenie,dlzka);
    printf("Zjednotenie dvoch mnozin je: \n");
    vypis(zjednotenie, dlzka_zjednotenie);
}