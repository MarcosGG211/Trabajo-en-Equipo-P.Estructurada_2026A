#include <stdio.h>

int main() {
    int tablero[5][5];
    int fila, columna;

    // Inicializar tablero
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            tablero[i][j] = 0;
        }
    }

    // Colocar barcos manualmente
    tablero[1][2] = 1;
    tablero[3][4] = 1;
    tablero[0][0] = 1;

    // Mostrar tablero inicial
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            printf("~ ");
        }
        printf("\n");
    }

    // Repetir durante varios turnos (punto 4)
    for(int turno = 0; turno < 5; turno++) {

        // Pedir disparo
        printf("\n--- Turno %d ---\n", turno + 1);
        printf("Fila: ");
        scanf("%d", &fila);
        printf("Columna: ");
        scanf("%d", &columna);

        // Punto 1: Evaluar si el disparo fue impacto o agua
        if(tablero[fila][columna] == 1) {
            printf("¡Impacto!\n");
            tablero[fila][columna] = 3;  // Punto 2: Cambiar valor a impacto
        } else {
            printf("Agua...\n");
            tablero[fila][columna] = 2;  // Punto 2: Cambiar valor a disparo fallido
        }

        // Punto 3: Mostrar nuevamente el tablero
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                if(tablero[i][j] == 0)      printf("~ ");
                else if(tablero[i][j] == 1) printf("~ ");
                else if(tablero[i][j] == 2) printf("O ");
                else if(tablero[i][j] == 3) printf("X ");
            }
            printf("\n");
        }
    }

    return 0;
}
