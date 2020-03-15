#pragma once

struct Statistics {
    double correct; /* odpowiedzi poprawne */
    double wrong; /* odpowiedzi bledne */
    double max; /* maksymalna ilosc punktow do uzyskania */
};

void Show( Statistics  stat );

