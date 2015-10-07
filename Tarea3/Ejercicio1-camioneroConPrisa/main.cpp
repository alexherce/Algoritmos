#include <iostream>

/*

Ejercicio 1. EL CAMIONERO CON PRISA

Un camionero conduce desde DF a Acapulco siguiendo una ruta dada y llevando un
cami�n que le permite, con el tanque de gasolina lleno, recorrer n kil�metros sin parar.
El camionero dispone de un mapa de carreteras que le indica las distancias entre las
gasolineras que hay en su ruta. Como va con prisa, el camionero desea detenerse a
abastecer gasolina el menor n�mero de veces posible.
Dise�e un algoritmo eficiente que determine en qu� gasolineras tiene que parar el
camionero.

*/

using namespace std;

int truckStops(int distanciaViaje, int tamTanque, const int nGasolineras, int * arrayGasolineras, bool * arrayParadas);

int main()
{

    int distanciaViaje = 1000;
    int tamTanque = 300;
    const int nGasolineras = 10;
    int arrayGasolineras[nGasolineras] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000};
    bool arrayParadas[nGasolineras] = {false};
    int resultado = truckStops(distanciaViaje, tamTanque, nGasolineras, arrayGasolineras, arrayParadas);

    cout << "Numero de paradas: " << resultado << endl;

    if (resultado > -1)
    {
        for(int i = 0; i < nGasolineras; i++)
        {
            if (arrayParadas[i] == true)
            {
                cout << "Parada en la gasolinera del KM " << arrayGasolineras[i] << endl;
            }
        }
    } else {
        cout << "Si el resultado es -1, el camion no pudo completar el viaje ya que no hay gasolineras suficientes." << endl;
    }

    return 0;
}


int truckStops(int distanciaViaje, int tamTanque, const int nGasolineras, int * arrayGasolineras, bool * arrayParadas)
{
    int i = 0;
    int kmRecorridos = 0;
    int paradas = 0;
    int ultimaParada = 0;

    if (tamTanque < arrayGasolineras[0])
        return -1;

    while((ultimaParada + tamTanque < distanciaViaje) && (i <= nGasolineras - 1))
    {
        kmRecorridos = arrayGasolineras[i] - ultimaParada;
        if(kmRecorridos > tamTanque)
        {
            ultimaParada = arrayGasolineras[i-1];
            arrayParadas[i-1] = true;
            paradas++;
            kmRecorridos = 0;
        }
        i++;
    }

    if (ultimaParada + tamTanque >= distanciaViaje)
    {
        return paradas;
    } else {
        return -1;
    }
}
