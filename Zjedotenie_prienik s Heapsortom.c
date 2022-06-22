#include <stdio.h>
#include <stdlib.h>


void uspor(int *a, int dlzka, int i);
void zmena(int *i, int *center);
void heapsort(int *a, int dlzka);
void zadaj_hodnoty(int *a, int dlzka);
void vypis(int *a, int dlzka);
int PRIENIK(int *a, int *b, int *prienik, int dlzka1, int dlzka2);
int ZJEDNOTENIE(int *a, int *b, int *zjednotenie, int dlzka1, int dlzka2);

    void zmena(int *i, int *center)
{
    int x;
    x = *i;
    *i = *center;
    *center = x;
}


void uspor(int *a, int dlzka, int i){
    int center = 0;
    int prava = 0;
    int lava = 0;

    center = i;
    prava = (2 * i) + 2;
    lava = (2 * i) + 1;

    if ( *(a + lava) > *(a + center) && dlzka > lava)
    {
        center = lava;
    }
    if (*(a + prava) > *(a + center) && dlzka > prava)
    {
        center = prava;
    }
    if (center != i)
    {
        zmena((a+i), (a + center));
        uspor(a, dlzka, center);
    }
}


void heapsort(int *a, int dlzka){
    int i=0;

    for(i=dlzka/2-1; i>=0; i--){
        uspor(a,dlzka,i);
     }

    for(i=dlzka-1; i>=0; i --){
        zmena((a + 0), (a + i));
        uspor(a,i,0);
        }
    }


void zadaj_hodnoty(int *a, int dlzka){
    int i;
    for(i=0;i<dlzka;i++){
        printf("Zadajte %d. prvok pola: \n", i);
        scanf("%d", &a[i]);
    }
}

void vypis(int *a, int dlzka){
    int i;
    for(i=0;i<dlzka;i++){
        printf("%d ", *(a + i));
    }
    printf("\n");
}

int PRIENIK(int *a, int *b, int *prienik, int dlzka1, int dlzka2){
    int i,j,m;
    i=0;
    j=0;
    m=0;

    while((i < dlzka1) && (j < dlzka2)){
        if( *(a + i) < *(b + j)){
            i++;
        }
        else if (*(a + i) > *(b + j))
        {
            j++;
        }
        else{
            *(prienik + m) = *(a + i);
            i++;
            j++;
            m++;
        }
    }
    return(m);
}


int ZJEDNOTENIE(int *a, int *b, int *zjednotenie, int dlzka1, int dlzka2){
    int i,j,m;
    i=0;
    j=0;
    m=0;

    while((i < dlzka1) && (j < dlzka2)){
        if(*(a + i) < *(b + j)){
            *(zjednotenie + m) = *(a + i);
            i++;
            m++;
            }
            else if (*(a + i) > *(b + j))
            {
                *(zjednotenie + m) = *(b + j);
                j++;
                m++;
            }
        else{
            *(zjednotenie + m) = *(a + i);
            i++;
            j++;
            m++;
            }
        }

    if (i == dlzka1){
        while(j < dlzka2){
            *(zjednotenie + m) = *(b + j);
            j++;
            m++;
        }
    }
    else{
        while(i < dlzka1){
            *(zjednotenie + m) = *(b + j);
            i++;
            m++;  
        }
    }

    return(m);

}


int main() {

    int dlzka1=0, dlzka2=0, dlzka_prienik, dlzka_zjednotenie;
    printf("Zadajte dlzku prveho lista: ");
    scanf("%d", &dlzka1);

    printf("Zadajte dlzku druheho lista: ");
    scanf("%d", &dlzka2);

    int a[dlzka1], b[dlzka2];
    int maxdlzka = dlzka1+dlzka2;
    int zjednotenie[maxdlzka];
    int prienik[dlzka1];
    
    if(dlzka1 <= dlzka2){
        int prienik[dlzka2];
    }

    printf("Prvky prveho pola: \n");
    zadaj_hodnoty(a,dlzka1);
    printf("Prvky druheho pola: \n");
    zadaj_hodnoty(b,dlzka2);

     int *po1 = a;
     int *po2 = b;
     int *po3 = prienik;
     int *po4 = zjednotenie;

    heapsort(po1, dlzka1);
    heapsort(po2, dlzka2);

    printf("1. Sortovane pole: \n");
    vypis(a, dlzka1);
    printf("2. Sortovane pole: \n");
    vypis(b, dlzka2);

    dlzka_prienik = PRIENIK(po1, po2, po3, dlzka1, dlzka2);
    printf("Prienik dvoch mnozin je: \n");
    vypis(prienik, dlzka_prienik);

    dlzka_zjednotenie = ZJEDNOTENIE(po1,po2,po4,dlzka1, dlzka2);
    printf("Zjednotenie dvoch mnozin je: \n");
    vypis(zjednotenie, dlzka_zjednotenie);
}
