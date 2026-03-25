#include <iostream>
#include <thread>
#include <string>
#include <chrono>

using namespace std;

void misaludo(string m, int demora, int veces) {
    for(int i = 1; i <= veces ; i++){
        cout << m + "\n";
        this_thread::sleep_for(chrono::milliseconds(demora));
    }
}

int main(){
    // Uso de un vector de threads para mayor conveniencia 
    thread P[3]; // vector de thread

    P[0] = thread(&misaludo, "Soy A", 100, 10);
    P[1] = thread(&misaludo, "\t\tSoy B ", 150, 15);
    P[2] = thread(&misaludo, "\t\t\t\tSoy C ", 50, 5);

    // Sincronización indexada [cite: 17, 319]
    P[0].join();
    P[1].join();
    P[2].join();

    cout << "Fin \n";
    return 0;
}