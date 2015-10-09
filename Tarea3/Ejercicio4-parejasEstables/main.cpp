#include <iostream>

/*

Ejercicio 4. LAS PAREJAS ESTABLES

Supongamos que tenemos n hombres y n mujeres y dos matrices M y H que contienen
las preferencias de los unos por los otros. Más concretamente, la fila M[i,·] es una
ordenación (de mayor a menor) de las mujeres según las preferencias del i-ésimo
hombre y, análogamente, la fila H[i,·] es una ordenación (de mayor a menor) de los
hombres según las preferencias de la i-ésima mujer.

Diseñe un algoritmo que encuentre, si es que existe, un emparejamiento de hombres y
mujeres tal que todas las parejas formadas sean estables. Una pareja (h,m) es estable si
no se da ninguna de estas dos circunstancias:
    • Existe una mujer m’ (que forma la pareja (h’,m’)) tal que el hombre h la prefiere
sobre la mujer m y además la mujer m’ también prefiere a h sobre h’.
    • Existe un hombre h” (que forma la pareja (h”,m”)) tal que la mujer m lo prefiere
sobre el hombre h y además el hombre h” también prefiere a m sobre la mujer m”.

*/
const int nPersonas = 5;
int preferenciasMujeres[nPersonas][nPersonas] = {
        {4,3,2,1,0},
        {3,2,1,0,4},
        {2,1,0,4,3},
        {1,0,4,3,2},
        {0,4,3,2,1}
        };
int preferenciasHombres[nPersonas][nPersonas] = {
        {0,4,3,2,1},
        {1,0,4,3,2},
        {2,1,0,4,3},
        {3,2,1,0,4},
        {4,3,2,1,0}
        };

int ordenMujeres[nPersonas][nPersonas] = {
        {4,3,2,1,0},
        {3,2,1,0,4},
        {2,1,0,4,3},
        {1,0,4,3,2},
        {0,4,3,2,1}
        };
int ordenHombres[nPersonas][nPersonas] = {
        {0,4,3,2,1},
        {1,0,4,3,2},
        {2,1,0,4,3},
        {3,2,1,0,4},
        {4,3,2,1,0}
        };


int x[nPersonas];
int y[nPersonas];

bool libre[nPersonas] = {true};

bool estable (int h, int m, int p);
void parejas (int hombre, bool exito, int n);

using namespace std;

int main()
{

    bool exito = false;
    parejas(1, exito, nPersonas);

    cout << "Complejidad O(log n)" << endl << endl;

    for (int i = 0; i < nPersonas; i++)
    {
        cout << "Hombre " << i << " con mujer " << x[i] << endl;
        cout << "Mujer " << i << " con hombre " << y[i] << endl;
    }



    return 0;
}

bool estable (int h, int m, int p)
{
    int mejormujer, mejorhombre, i, limite;
    bool s = true;
    i = 0;

    while (i < p && s)
    {
        mejormujer = preferenciasMujeres[h][i];
        if (libre[mejormujer] == false)
        {
            if (ordenMujeres[mejormujer][h] > ordenMujeres[mejormujer][y[mejormujer]])
            {
                s = true;
            } else {
                s = false;
            }
        }
        i++;
    }

    i =0;
    limite = preferenciasHombres[m][h];
    while ((i<limite) && s)
    {
        mejorhombre = preferenciasHombres[m][i];
        if (mejorhombre < h)
        {
            if (ordenHombres[mejorhombre][m] > ordenHombres[mejorhombre][x[mejorhombre]])
            {
                s= true;
            } else {
                s = false;
            }
        }
        i++;
    }
    return s;
}

void parejas (int hombre, bool exito, int n)
{
    int mujer, prefiere, preferencias;
    prefiere = 0;
    while (prefiere < n && exito != true)
    {
        mujer = preferenciasMujeres[hombre][prefiere];
        if (libre[mujer] && estable(hombre,mujer,prefiere))
        {
            x[hombre] = mujer;
            y[mujer] = hombre;
            libre[mujer] = false;
            if (hombre < n)
            {
                parejas(hombre+1,exito, n);
                if (!exito)
                    libre[mujer] = true;
            } else {
                exito = true;
            }
        }
        prefiere++;
    }
}
