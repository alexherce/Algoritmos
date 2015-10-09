#include <iostream>

/*

Ejercicio 3. LA SUBSECUENCIA COMÚN MÁXIMA

Dada una secuencia X={x1 x2 ... xm}, se dice que Z={z1 z2 ... zk} es una subsecuencia
de X (siendo k ≤ m) si existe una secuencia creciente {i1 i2 ... ik} de índices de X tales
que para todo j = 1, 2, ..., k tenemos xij = zj.
Dadas dos secuencias X e Y, se dice que Z es una subsecuencia común de X e Y si es
subsecuencia de X y subsecuencia de Y.
Diseñe un algoritmo que permita determinar la subsecuencia de longitud máxima
común a dos secuencias.

*/

using namespace std;

int aux[100][100];
int tmp[100][100];

void LCS(char * x, char * y, int sizeX, int sizeY);
void imprimir(char * x, int i, int j);


int main() {

    const int sizeX = 10;
    const int sizeY = 8;
    char xchar[sizeX] = {'s','p','r','i','n','g','t','i','m','e'};
    char ychar[sizeY] = {'p','r','i','n','t','i','n','g'};

    cout << "Complejidad O(n^2)" << endl << endl;

    LCS(xchar, ychar, sizeX, sizeY);
    cout << "Resultado: ";
    imprimir(xchar, sizeX-1, sizeY-1);
    cout << endl;

    return 0;
}

void LCS(char * X, char * Y, int sizeX, int sizeY)
{
    int m,n;
    m = sizeX;
    n = sizeY;

    for(int i = 1; i <= m; i++)
         tmp[i][0] = 0;

    for(int j = 0; j <= n; j++)
        tmp[0][j] = 0;

    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if (X[i] == Y[j])
            {
                tmp[i][j] = tmp[i-1][j-1] + 1;
                aux[i][j] = 1;
            } else {
                if (tmp[i-1][j] >= tmp[i][j-1])
                {
                    tmp[i][j] = tmp[i-1][j];
                    aux[i][j] = 2;
                } else {
                    tmp[i][j] = tmp[i][j-1];
                    aux[i][j] = 3;
                }
            }
        }
    }
}

void imprimir(char * x, int i, int j)
{
    if (i == 0 || j == 0)
        return;

    if (aux[i][j] == 1)
    {
        imprimir(x, i - 1, j - 1);
        cout << x[i];
    } else {
        if (aux[i][j] == 2)
            imprimir(x, i - 1, j);
        else
            imprimir(x, i, j -1);
    }
}
