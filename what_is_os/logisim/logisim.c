#include <logisim.h>
#include <stdio.h>

// Wire and registers in the circuit
wire W, X, Y, Z, W1, X1, Y1, Z1, A, B, C, D, E, F, G, S;
reg b0 = {.in = &W1, .out = &W};
reg b1 = {.in = &X1, .out = &X};
reg b2 = {.in = &Y1, .out = &Y};
reg b3 = {.in = &Z1, .out = &Z};

int main() {
    CLOCK_CYCLE {
        // 1. Propagate wire values through combinatorial logic
        W1 = AND(W, AND(NOT(Y), NOT(Z))) | !W&X&Y&Z | W&!X&!Y&Z | W&!X&Y&!Z;
        X1 = X&!Y&!Z | !W&!X&Y&!Z | W&!X&Y&!Z;
        Y1 = X&!Y&!Z | !W&!X&!Y&Z | W&!X&!Y&Z;
        Z1 = !Y&!Z;
        E = !W&!X&!Z | W&X&!Y&!Z | W&!X&!Y&Z;
        F = X&Y&Z | !X&!Y&!Z | W&X&!Y&!Z | W&!X&!Y&Z ;
        G = X&!Y&!Z | W&!X&!Y | X&Y&Z | !W&!X&Y&!Z ;
        D = !Y&!Z | !W&!X&Y&!Z | W&X&Y&Z | W&!X&!Y&Z ;
        A = !Y&!Z | !X&Y&!Z | W&X&Y&Z | W&!X&!Y&Z;
        B = !W&!X&!Y | X&!Y&!Z | X&Y&Z | !X&Y&!Z;
        C = !Y&!Z | !X&!Y&Z | X&Y&Z | W&!X&Y&!Z;

        // 2. Edge triggering: Lock values in the flip-flops
        b0.value = *b0.in;
        b1.value = *b1.in;
        b2.value = *b2.in;
        b3.value = *b3.in;
        *b0.out = b0.value;
        *b1.out = b1.value;
        *b2.out = b2.value;
        *b3.out = b3.value;

        // 3. End of a cycle; display output wire values
        #define PRINT(X) printf(#X " = %d; ", X)
        // PRINT(W);
        // PRINT(X);
        // PRINT(Y);
        // PRINT(Z);
        PRINT(A);
        PRINT(B);
        PRINT(C);
        PRINT(D);
        PRINT(E);
        PRINT(F);
        PRINT(G);
        printf("\n");
        fflush(stdout);
        sleep(1);
    }
}
