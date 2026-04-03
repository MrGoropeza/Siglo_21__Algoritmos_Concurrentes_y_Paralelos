#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <vector>
#include <random>

using namespace std;

int Compartida = 0;

struct datos_hilo {
    int id;
};

void* hilo_tipo1(void* arg) {
    datos_hilo* d = (datos_hilo*)arg;

    cout << "Instancia " << d->id << " del hilo 1" << endl;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, 2);
    sleep(dist(gen));

    Compartida++;
    pthread_exit(NULL);
}

void* hilo_tipo2(void* arg) {
    datos_hilo* d = (datos_hilo*)arg;
    
    cout << "Instancia " << d->id << " del hilo 2" << endl;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, 2);
    sleep(dist(gen));

    cout << Compartida << endl; 
    pthread_exit(NULL);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Error: Ingrese N y M" << endl;
        return 1;
    }

    int N = stoi(argv[1]);
    int M = stoi(argv[2]);

    vector<pthread_t> hilos(N + M);
    vector<datos_hilo> datos(N + M);

    try {
        for (int i = 0; i < N; i++) {
            datos[i].id = i;
            pthread_create(&hilos[i], NULL, hilo_tipo1, &datos[i]);
        }
        for (int j = 0; j < M; j++) {
            datos[N + j].id = j;
            pthread_create(&hilos[N + j], NULL, hilo_tipo2, &datos[N + j]);
        }
        for (int k = 0; k < N + M; k++) {
            pthread_join(hilos[k], NULL);
        }

        cout << "Se ha finalizado la ejecución" << endl;
    } catch (...) {
        return 1;
    }
    return 0;
}