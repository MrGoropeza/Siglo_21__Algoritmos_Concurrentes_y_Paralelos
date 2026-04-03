#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <random>

using namespace std;

int Compartida = 0;

void ejecutar_proceso(int tipo, int id) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, 2);

    if (tipo == 1) {
        cout << "Instancia " << id << " del proceso 1" << endl;
        sleep(dist(gen));
        Compartida++;
    } else {
        cout << "Instancia " << id << " del proceso 2" << endl;
        sleep(dist(gen));
        cout << Compartida << endl;
    }
    exit(0);
}

int main(int argc, char* argv[]) {
    if (argc != 3) return 1;

    int N = stoi(argv[1]);
    int M = stoi(argv[2]);

    for (int i = 0; i < N; i++) {
        if (fork() == 0) ejecutar_proceso(1, i);
    }
    for (int j = 0; j < M; j++) {
        if (fork() == 0) ejecutar_proceso(2, j);
    }

    for (int k = 0; k < (N + M); k++) {
        wait(NULL);
    }

    cout << "Se ha finalizado la ejecución" << endl;
    return 0;
}