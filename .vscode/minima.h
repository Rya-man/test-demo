#ifndef MINIMA_H
#define MINIMA_H

// Function prototype
#define minima(a, b) ({ \
    __typeof__(a) _a = (a); \
    __typeof__(b) _b = (b); \
    (_a < _b) ? _a : _b; \
})

#endif /* MINIMA_H */
