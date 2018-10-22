# JNP1_2_
Biblioteka standardowa jÄzyka C++ udostÄpnia bardzo przydatne kontenery
(np. unordered_map i set), ktĂłrych nie ma w bibliotece C. CzÄsto teĹź
potrzebujemy ĹÄczyÄ kod w C++ z kodem w C.

Celem tego zadania jest napisanie w C++ dwĂłch moduĹĂłw obsĹugujÄcych zbiory
ciÄgĂłw znakĂłw, tak aby moĹźna ich byĹo uĹźywaÄ w C. KaĹźdy moduĹ skĹada siÄ z pliku
nagĹĂłwkowego (z rozszerzeniem h) i pliku z implementacjÄ (z rozszerzeniem cc).

ModuĹ strset (pliki strset.h i strset.cc) powinien udostÄpniaÄ nastÄpujÄce
funkcje:

unsigned long strset_new();

      Tworzy nowy zbiĂłr i zwraca jego identyfikator.

void strset_delete(unsigned long id);

      JeĹźeli istnieje zbiĂłr o identyfikatorze id, usuwa go, a w przeciwnym
      przypadku nie robi nic.

size_t strset_size(unsigned long id);

      JeĹźeli istnieje zbiĂłr o identyfikatorze id, zwraca liczbÄ jego elementĂłw,
      a w przeciwnym przypadku zwraca 0.

void strset_insert(unsigned long id, const char* value);

      JeĹźeli istnieje zbiĂłr o identyfikatorze id i element value nie naleĹźy do
      tego zbioru, to dodaje element do zbioru, a w przeciwnym przypadku nie
      robi nic.

void strset_remove(unsigned long id, const char* value);

      JeĹźeli istnieje zbiĂłr o identyfikatorze id i element value naleĹźy do tego
      zbioru, to usuwa element ze zbioru, a w przeciwnym przypadku nie robi nic.

int strset_test(unsigned long id, const char* value);

      JeĹźeli istnieje zbiĂłr o identyfikatorze id i element value naleĹźy do tego
      zbioru, to zwraca 1, a w przeciwnym przypadku 0.

void strset_clear(unsigned long id);

      JeĹźeli istnieje zbiĂłr o identyfikatorze id, usuwa wszystkie jego elementy,
      a w przeciwnym przypadku nie robi nic.

int strset_comp(unsigned long id1, unsigned long id2);

      PorĂłwnuje zbiory o identyfikatorach id1 i id2. Niech sorted(id) oznacza
      posortowany leksykograficznie zbiĂłr o identyfikatorze id. Takie ciÄgi juĹź
      porĂłwnujemy naturalnie: pierwsze miejsce, na ktĂłrym siÄ rĂłĹźniÄ, decyduje
      o relacji wiÄkszoĹci. JeĹli jeden ciÄg jest prefiksem drugiego, to ten
      bÄdÄcy prefiks jest mniejszy. Funkcja strset_comp(id1, id2) powinna zwrĂłciÄ
      -1, gdy sorted(id1) < sorted(id2),
      0, gdy sorted(id1) = sorted(id2),
      1, gdy sorted(id1) > sorted(id2).
      JeĹźeli zbiĂłr o ktĂłrymĹ z identyfikatorĂłw nie istnieje, to jest traktowany
      jako rĂłwny zbiorowi pustemu.

ModuĹ strsetconst (pliki strsetconst.h i strsetconst.cc) powinien udostÄpniaÄ
funkcjÄ:

unsigned long strset42();

    Zwraca identyfikator zbioru, ktĂłrego nie moĹźna modyfikowaÄ i ktĂłry zawiera
    jeden element: napis "42". ZbiĂłr jest tworzony przy pierwszym wywoĹaniu tej
    funkcji i wtedy zostaje ustalony jego numer.

NaleĹźy ukryÄ przed Ĺwiatem zewnÄtrznym wszystkie zmienne globalne i funkcje
pomocnicze nie naleĹźÄce do wyspecyfikowanych interfejsĂłw moduĹĂłw.

ModuĹy strset i strsetconst powinny wypisywaÄ na standardowy strumieĹ bĹÄdĂłw
informacje diagnostyczne. ModuĹy te mogÄ sprawdzaÄ poprawnoĹÄ wykonania funkcji
za pomocÄ asercji. Kompilowanie z parametrem -DNDEBUG powinno wyĹÄczaÄ
wypisywanie i asercje. ObsĹuga standardowego wyjĹcia diagnostycznego powinna byÄ
realizowana z uĹźyciem strumienia C++ (tzn. iostream).

Parametr value o wartoĹci NULL jest niepoprawny.

Oczekiwane rozwiÄzanie powinno korzystaÄ z kontenerĂłw i metod udostÄpnianych
przez standardowÄ bibliotekÄ C++. Nie naleĹźy definiowaÄ wĹasnych struktur lub
klas. W szczegĂłlnoĹci nie naleĹźy przechowywaÄ przekazanych przez uĹźytkownika
wskaĹşnikĂłw const char* bezpoĹrednio, bowiem uĹźytkownik moĹźe po wykonaniu
operacji modyfikowaÄ dane pod uprzednio przekazanym wskaĹşnikiem lub zwolniÄ
pamiÄÄ. Na przykĹad poniĹźszy kod nie powinien przerwaÄ siÄ z powodu
niespeĹnionej asercji:

    unsigned long s;
    char buf[4] = "foo";
    s = strset_new();
    strset_insert(s, buf);
    buf[0] = 'b';
    assert(strset_test(s, "foo"));
    assert(!strset_test(s, "boo"));

W rozwiÄzaniu nie naleĹźy naduĹźywaÄ kompilacji warunkowej. Fragmenty tekstu
ĹşrĂłdĹowego realizujÄce wyspecyfikowane operacje na zbiorach nie powinny zaleĹźeÄ
od sposobu kompilowania â parametr -DNDEBUG lub jego brak (inaczej wersja
diagnostyczna nie miaĹaby sensu).

PrzykĹad uĹźycia znajduje siÄ w pliku strset_test1.c. PrzykĹad informacji
diagnostycznych wypisywanych przez powyĹźszy przykĹad uĹźycia znajduje siÄ
w pliku strset_test1.err.

Aby umoĹźliwiÄ uĹźywanie moduĹĂłw strset oraz strsetconst w jÄzyku C++, przy
kompilowaniu plikĂłw nagĹĂłwkowych strset.h i strsetconst.h w C++ interfejsy
moduĹĂłw strset i strsetconst majÄ znaleĹşÄ siÄ w przestrzeni nazw jnp1.
PrzykĹady uĹźycia znajdujÄ siÄ w plikach strset_test2a.cc i strset_test2b.cc.
PrzykĹad informacji diagnostycznych wypisywanych przez powyĹźsze przykĹady
uĹźycia znajduje siÄ w plikach strset_test2a.err i strset_test2b.err.

PrzykĹady moĹźna skompilowaÄ za pomocÄ poleceĹ:

gcc -Wall -Wextra -O2 -std=c11 -c strset_test1.c -o strset_test1.o
g++ -Wall -Wextra -O2 -std=c++17 -c strset.cc -o strset.o
g++ -Wall -Wextra -O2 -std=c++17 -c strsetconst.cc -o strsetconst.o
g++ strset_test1.o strsetconst.o strset.o -o strset1
g++ -Wall -Wextra -O2 -std=c++17 -c strset_test2a.cc -o strset_test2a.o
g++ -Wall -Wextra -O2 -std=c++17 -c strset_test2b.cc -o strset_test2b.o
g++ strset_test2a.o strsetconst.o strset.o -o strset2a
g++ strset_test2b.o strsetconst.o strset.o -o strset2b

RozwiÄzanie powinno zawieraÄ pliki strset.h, strset.cc, strsetconst.h,
strsetconst.cc, ktĂłre naleĹźy umieĹciÄ w repozytorium w katalogu

grupaN/zadanie2/ab123456+cd123456

lub

grupaN/zadanie2/ab123456+cd123456+ef123456

gdzie N jest numerem grupy, a ab123456, cd123456, ef123456 sÄ identyfikatorami
czĹonkĂłw zespoĹu umieszczajÄcego to rozwiÄzanie. Katalog z rozwiÄzaniem nie
powinien zawieraÄ innych plikĂłw, ale moĹźe zawieraÄ podkatalog prywatne, gdzie
moĹźna umieszczaÄ rĂłĹźne pliki, np. swoje testy. Pliki umieszczone w tym
podkatalogu nie bÄdÄ oceniane. Nie wolno umieszczaÄ w repozytorium plikĂłw
duĹźych, binarnych, tymczasowych (np. *.o) ani innych zbÄdnych.
