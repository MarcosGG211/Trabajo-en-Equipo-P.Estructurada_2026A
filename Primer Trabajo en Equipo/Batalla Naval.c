Version 1

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

hola 

______________________________________________________________________________________________________________________________________________________

Version 2

#include <stdio.h>
#include <string.h>

int main() {
    int tablero[5][5];
    int fila, columna;

    // Nombre del jugador
    char jugador[20];
    printf("Nombre: ");
    fgets(jugador, sizeof(jugador), stdin);

    // Nombres de barcos
    char barcos[3][15] = {"Fragata", "Destructor", "Submarino"};

    // Inicializar tablero
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            tablero[i][j] = 0;
        }
    }

    // Colocar barcos manualmente
    tablero[0][1] = 1;
    tablero[2][3] = 1;
    tablero[4][4] = 1;

    // Mostrar tablero inicial
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            printf("~ ");
        }
        printf("\n");
    }

    int barcosEncontrados = 0;

    // Repetir durante varios turnos
    for(int turno = 0; turno < 5; turno++) {

        // Mostrar nombre en cada turno
        printf("\nTurno de %s\n", jugador);
        printf("Fila (1-5): ");
        scanf("%d", &fila);
        printf("Columna (1-5): ");
        scanf("%d", &columna);

        // Convertir entrada del usuario (1-5) a índice interno (0-4)
        int f = fila - 1;
        int c = columna - 1;

        // Evaluar si el disparo fue impacto o agua
        if(tablero[f][c] == 1) {
            tablero[f][c] = 3;
            printf("%s impacto un %s\n", jugador, barcos[barcosEncontrados]);
            barcosEncontrados++;
        } else {
            printf("Agua...\n");
            tablero[f][c] = 2;
        }

        // Mostrar nuevamente el tablero
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

    // Mensaje final
    if(barcosEncontrados == 3) {
        printf("\n%sgano la partida\n", jugador);
    } else {
        printf("\n%sno logró hundir todos los barcos\n", jugador);
    }

    return 0;
}
