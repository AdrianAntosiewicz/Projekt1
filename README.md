# Strzelanka
- Gra z kamerą z góry. Zadaniem gracza będzie ustrzelenie wszystkich przeciwników w pokoju. Jeśli mu się uda otworzy się przejście do następnego pomieszczenia 
- Przeciwnicy pojawiają się w losowych miejscach i poruszają w losowym kierunku. Po przejściu do następnego pomieszczenia pojawiają się trudniejsi przeciwnicy, np. potrafią strzelać. 
- Sterowanie postacią za pomocą WSAD, strzał za pomocą spacji w kierunku ostatniego wcisniętego klawisza ruchu (tekstura postaci będzie przedstawiała jej zwrot, czyli kierunek w jakim padnie strzał).\

Gra będzie zawierała klasy:
1. **cScena** - Odpowiedzialna za rysowanie planszy z postaciami
2. **cBohater** - Zawiera informacje o bohaterze: ilość jego życia, liczbe naboi itp.
3. **cPrzeciwnik** - Klasa bazowa przeciwników, zawiera informacje : stan życia, ich położenie itp.
4. **cStrzelec** - Klasa przeciwnika dziedzicząca z klasy bazowej, jest od niej rozszerzona o metode strzał. 
5. **cPszeszkoda** - Klasa bazowa pszeszkód, z której potem będą dziedziczyć klasy: cMurek, cOgień itp.
