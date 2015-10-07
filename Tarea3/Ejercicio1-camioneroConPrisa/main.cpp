#include <iostream>

/*

Ejercicio 1. EL CAMIONERO CON PRISA

Un camionero conduce desde DF a Acapulco siguiendo una ruta dada y llevando un
camión que le permite, con el tanque de gasolina lleno, recorrer n kilómetros sin parar.
El camionero dispone de un mapa de carreteras que le indica las distancias entre las
gasolineras que hay en su ruta. Como va con prisa, el camionero desea detenerse a
abastecer gasolina el menor número de veces posible.
Diseñe un algoritmo eficiente que determine en qué gasolineras tiene que parar el
camionero.

*/

using namespace std;

int truckStops(int distanciaViaje, int tamTanque, const int nGasolineras, int * arrayGasolineras);

int main()
{

    int distanciaViaje = 1000;
    int tamTanque = 300;
    const int nGasolineras = 10;
    int arrayGasolineras[nGasolineras] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000};

    cout << "Numero de paradas: " << truckStops(distanciaViaje, tamTanque, nGasolineras, arrayGasolineras) << endl;
    cout << "Si el resultado es -1, el camion no pudo completar el viaje ya que no hay gasolineras suficientes." << endl;

    return 0;
}


int truckStops(int distanciaViaje, int tamTanque, const int nGasolineras, int * arrayGasolineras)
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
