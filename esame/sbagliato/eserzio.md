# Esercizio di Calcolo Numerico

## Descrizione dell'esercizio
Data la funzione:
$$ f(x) = \frac{1 + 2x \cos(x)}{1 + \sqrt{x}} $$

Svolgere i seguenti esercizi.

---

## Attività richieste

### 1. Determinazione degli zeri con il metodo della bisezione.
Trovare ( x1, x2, x3), che si trovano negli intervalli:
- [1,2] per x1
- [4,5] per x2
- [7,8] per x3

con precisione (D=0.001), ricavandosi il numero di iterazioni richieste, per il calcolo di ciascuno zero.


### 2. Calcolo dell'integrale con il metodo dei trapezoidi.
Calcolare l'integrale definito:
$$ I = \int_{x_1}^{x_2} \frac{1 + 2x \cos(x)}{1 + \sqrt{x}} dx $$

con il metodo dei trapezi utilizzando (N=4) intervalli.

### 3. Stima dell'errore ε1 nel calcolo dell'integrale.
Stimare l'errore ε1 nel calcolo dell'integrale con il metodo dei trapezoidi con (N=4) intervalli.

### 4. Stima dell'errore ε2 dovuto alla precisione degli estremi.
Effettuare 10000 ripetizioni del calcolo dell'integrale campionando x1 e x2 da distribuzioni uniformi in:
- [x1+Δ, x1-Δ]
- [x2+Δ, x2-Δ]

(Dove Δ=D/2)

Utilizzare la deviazione standard dei valori ottenuti per stimare ε2.

### 5. Stima del numero di intervalli necessari per ottenere precisione ε2.
Determinare quanti intervalli sarebbero necessari nel metodo dei trapezi per ottenere un errore pari a ε2.

### 6. Calcolo della funzione integrale.
Tabulare o graficare con passi di (Δt=0.1) la funzione integrale:
$$ F(x) = \int_{x_1}^{x} \frac{1 + 2x \cos(x)}{1 + \sqrt{x}} dx $$
per x ∈ [x1, x3], usando il metodo dei trapezoidi con (N=4) intervalli.