#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include <random> // Librería moderna para aleatoriedad en C++
#include <string>

using namespace std;

// Función que define el comportamiento de cada hilo
void tarea_hilo(int id) {
    // Configuramos el generador de números aleatorios para cada hilo
    random_device rd;
    mt19937 gen(rd());
    
    // Definimos rangos: de 2 a 6 repeticiones y de 500 a 2000ms de pausa
    uniform_int_distribution<> dist_veces(2, 6);
    uniform_int_distribution<> dist_pausa(500, 2000);

    int total_veces = dist_veces(gen);

    for (int i = 1; i <= total_veces; ++i) {
        int pausa = dist_pausa(gen);
        
        // Salida por consola indicando el ID del hilo y su estado
        cout << "Soy el hilo " << id << " (Iteracion " << i << "/" << total_veces << " - Espera: " << pausa << "ms)" << endl;
        
        // El hilo entra en estado "timed-waiting" (suspensión con temporización)
        this_thread::sleep_for(chrono::milliseconds(pausa));
    }
}

int main() {
    const int NUM_HILOS = 15;
    vector<thread> mis_hilos;

    cout << "--- Iniciando ejecucion de 15 hilos aleatorios ---" << endl;

    try {
        // Fase de creación y lanzamiento (Estado: "new" a "ready-to-run")
        for (int i = 1; i <= NUM_HILOS; ++i) {
            mis_hilos.emplace_back(tarea_hilo, i);
        }

        // Fase de sincronización (Estado: "waiting")
        for (auto& th : mis_hilos) {
            if (th.joinable()) {
                th.join();
            }
        }
        
        cout << "--- Todos los hilos finalizaron exitosamente (Estado: dead) ---" << endl;
    } 
    catch (const exception& e) {
        // Tratamiento de errores requerido por la rúbrica
        cerr << "ERROR CRITICO del sistema: " << e.what() << endl;
        return 1;
    }

    return 0;
}