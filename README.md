Descriere
Aţi fost aleşi de către o platformă de social-media pentru a efectua un studiu asupra scorurilor videoclipurilor postate.

Pentru fiecare videoclip se cunosc următoarele informaţii:

ID - un șir ce caracterizează în mod unic fiecare videoclip;
Categorie - categoriile existente sunt ”Animale”, ”Sport” și ”Studiu”
Numărul de like-uri, notat ”L”
Numărul de dislike-uri, notat ”D”
Numărul de vizualizări, notat ”V”
Pentru fiecare videoclip se pot calcula două scoruri: unul simplu și unul avansat. Scorul simplu se calculează pentru fiecare videoclip conform formulei LD+1−1V

Scorul avansat (SA) se calculează în funcție de scorul simplu (SS) și categorie, astfel:

Categoria ”Studiu” -  SA = SS x 2
Categoria ”Animale” - SA = SS x 0.75
Categoria ”Sport” -  SA = SS x 0.5
Cerinţe
Structură
Să se creeze următoarele elemente:
 Clasa abstractă Video cu următorii membri:
Un câmp mVideoId de tip std::string, și trei câmpuri mLikes, mDislikes și mViews, toate de tip uint32_t.
Un constructor protejat care să aibă argumente de tip const std::string &, uint32_t, uint32_t, uint32_t corespunzătoare câmpurilor clasei, în aceeași ordine ca mai sus, care să inițializeze câmpurile.
O metodă publică, apelabilă pentru obiecte const, numită getId, care să întoarcă id-ul videclipului.
O metodă publică, apelabilă pentru obiecte const, numită getDislikes, care să întoarcă numărul de dislike-uri (D).
O metodă publică, apelabilă pentru obiecte const, numită getSimpleScore, care să calculeze și să întoarcă scorul simplu.
O metodă publică, pur virtuală, apelabilă pentru obiecte const, numită getAdvancedScore, care să întoarcă scorul avansat.
O metodă publică void print(bool simple) const care să afișeze pe ecran ID-ul videoclipului și, dacă simple e true, scorul simplu, iar dacă e false, scorul avansat, așa cum se cere la ieșire (valoarea scorului cu două zecimale), iar la final un caracter newline.
 Clasa StudyVideo care să extindă clasa Video cu următorii membri:
Un constructor public care să aibă argumente de tip const std::string &, uint32_t, uint32_t, uint32_t corespunzătoare câmpurilor superclasei, în aceeași ordine ca mai sus, care să apeleze constructorul superclasei.
Implementarea metodei pur virtuale din superclasă care să întoarcă calculeze și să întoarcă scorul avansat pentru acest tip de video.
 Clasa AnimalVideo care să extindă clasa Video cu următorii membri:
Un constructor public care să aibă argumente de tip const std::string &, uint32_t, uint32_t, uint32_t corespunzătoare câmpurilor superclasei, în aceeași ordine ca mai sus, care să apeleze constructorul superclasei.
Implementarea metodei pur virtuale din superclasă care să întoarcă calculeze și să întoarcă scorul avansat pentru acest tip de video.
 Clasa SportsVideo care să extindă clasa Video cu următorii membri:
Un constructor public care să aibă argumente de tip const std::string &, uint32_t, uint32_t, uint32_t corespunzătoare câmpurilor superclasei, în aceeași ordine ca mai sus, care să apeleze constructorul superclasei.
Implementarea metodei pur virtuale din superclasă care să întoarcă calculeze și să întoarcă scorul avansat pentru acest tip de video.
 Clasa VideoFactory care să extindă clasa Video cu următorii membri:
Constructorul implicit șters (inaccesibil).
O metodă statică createVideo care să primească ca argumente const std::string & id, const std::string & type, uint32_t likes, uint32_t dislikes, uint32_t views unde type este tipul video-ului, așa cum este citit de la tastatură, și care întoarce un obiect nou creat corespunzător, ca pointer la Video. Dacă tipul este necunoscut, metoda trebuie să arunce o excepție de tip std::invalid_argument.

Cerinţa (a) 
Să se sorteze crescător videoclipurile în funcţie de scorul simplu. Videoclipurile cu acelaşi scor vor fi sortate descrescător în funcţie de parametrul D.
În urma sortării, se vor afişa separate prin spaţiu ID-ul şi scorul fiecărui videoclip. După fiecare pereche se afişează newline. Scorul va fi afişat cu exact două zecimale!

Cerinţa (b) 
Să se calculeze scorul simplu mediu al videoclipurilor. Se vor afişa doar videoclipurile cu scorul simplu mai mare decât media calculată, în ordniea în care au fost citite de la tastatură.

Cerinţa (c) 
Se vor citi în continuare videoclipuri până la EOF.
Dacă exista deja un videoclip cu acelaşi ID, se vor actualiza informatiile existente cu cele citite. Dacă nu există un videoclip cu acelaşi ID, acesta va fi adaugat.

La final se vor afişa videoclipurile ordonate în același fel ca la punctul a).

Cerinţa (d) 
Să se ordoneze crescător videoclipurile în funcţie de scorul avansat.
Afişarea va cuprinde ID si scorul avansat (afişat cu două zecimale) 

Bonus 
Dacă tipul oricărui video este necunoscut, atunci se va afişa mesajul ”EROARE” şi se va opri execuţia programului.

Date de intrare
Pe prima linie se află un număr întreg n, reprezentând numărul de videoclipuri ce urmează a fi citite.
Pe următoarele n linii se află informaţii despre videoclip, în formatul:

<ID film> <Tip Videoclip> <numar de vizionari> <numar de like-uri> <numar de dislike-uri>

Pe ultima linie se află un caracter din intervalul [a-d] ce reprezintă cerinţa care va fi tratată.
