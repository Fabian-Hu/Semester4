# Übungsaufgabe Scheduling

### Shortest Job First

| Prozesse       |  A   |  B   |  C   |  D   |  E   | Verweilzeit |
| :------------- | :--: | :--: | :--: | :--: | :--: | :---------: |
| Laufzeit       |  30  |  20  |  25  |  28  |  18  |             |
| Erster fertig  |  30  |  20  |  25  |  28  |  -   |    E:18     |
| Zweiter fertig |  30  |  -   |  25  |  28  |  -   |    B:38     |
| Dritter fertig |  30  |  -   |  -   |  28  |  -   |    C:63     |
| Vierter fertig |  30  |  -   |  -   |  -   |  -   |    D:91     |
| Fünfter fertig |  -   |  -   |  -   |  -   |  -   |    A:121    |

Mittlere Verweilzeit:
$$
\frac{18 + 38 + 63 + 91 + 121}{5}  = 66.2
$$

### First Come First Serve

| Prozesse       |  A   |  B   |  C   |  D   |  E   | Verweilzeit |
| :------------- | :--: | :--: | :--: | :--: | :--: | :---------: |
| Laufzeit       |  30  |  20  |  25  |  28  |  18  |             |
| Erster fertig  |  -   |  20  |  25  |  28  |  18  |    A:30     |
| Zweiter fertig |  -   |  -   |  25  |  28  |  18  |    B:50     |
| Dritter fertig |  -   |  -   |  -   |  28  |  18  |    C:75     |
| Vierter fertig |  -   |  -   |  -   |  -   |  18  |    D:103    |
| Fünfter fertig |  -   |  -   |  -   |  -   |  -   |    E:121    |

Mittlere Verweilzeit:
$$
\frac{30 + 50 + 75 + 103 + 121}{5}  = 75.8
$$

### Prioritätsgesteuertes Scheduling

| Prozesse       | A(2) | B(1) | C(5) | D(4) | E(3) | Verweilzeit |
| :------------- | :--: | :--: | :--: | :--: | :--: | :---------: |
| Laufzeit       |  30  |  20  |  25  |  28  |  18  |             |
| Erster fertig  |  30  |  20  |  -   |  28  |  18  |    C:25     |
| Zweiter fertig |  30  |  20  |  -   |  -   |  18  |    D:53     |
| Dritter fertig |  30  |  20  |  -   |  -   |  -   |    E:71     |
| Vierter fertig |  -   |  20  |  -   |  -   |  -   |    A:101    |
| Fünfter fertig |  -   |  -   |  -   |  -   |  -   |    E:121    |

Mittlere Verweilzeit:
$$
\frac{25 + 53 + 71 + 101 + 121}{5}  = 74.2
$$

### Round Robin mit konstanter Zeitscheibe unabhängig von der Priorität

| Prozesse       |  A   |  B   |  C   |  D   |  E   | Verweilzeit |
| :------------- | :--: | :--: | :--: | :--: | :--: | :---------: |
| Laufzeit       |  30  |  20  |  25  |  28  |  18  |             |
| Erster fertig  |  12  |  2   |  7   |  10  |  -   |    E:90     |
| Zweiter fertig |  10  |  -   |  5   |  8   |  -   |    B:98     |
| Dritter fertig |  5   |  -   |  -   |  3   |  -   |    C:113    |
| Vierter fertig |  2   |  -   |  -   |  -   |  -   |    D:119    |
| Fünfter fertig |  -   |  -   |  -   |  -   |  -   |    A:121    |

Mittlere Verweilzeit:
$$
\frac{90 + 98 + 113 + 119 + 121}{5}  = 108.2
$$

### Round Robin mit Zeitscheibendauer proportional zur Priorität

| Prozesse       | A(2) | B(1) | C(5) | D(4) | E(3) | Verweilzeit |
| :------------- | :--: | :--: | :--: | :--: | :--: | :---------: |
| Laufzeit       |  30  |  20  |  25  |  28  |  18  |             |
| Erster fertig  |  20  |  15  |  -   |  8   |  3   |    E:75     |
| Zweiter fertig |  18  |  14  |  -   |  4   |  -   |    B:85     |
| Dritter fertig |  16  |  13  |  -   |  -   |  -   |    C:92     |
| Vierter fertig |  -   |  5   |  -   |  -   |  -   |    D:116    |
| Fünfter fertig |  -   |  -   |  -   |  -   |  -   |    A:121    |

Mittlere Verweilzeit:
$$
\frac{75 + 85 + 92 + 116 + 121}{5}  = 97.8
$$
