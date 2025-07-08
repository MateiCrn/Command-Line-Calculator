Acest proiect implementează un calculator de buzunar în C++, cu funcționalități de bază și o memorie care salvează ultimele 10 operații efectuate.
Clasa Calculator reține intern numărul curent (de tip double) și permite efectuarea operațiilor aritmetice clasice (adunare, scădere, înmulțire, împărțire),
precum și operații avansate (ridicare la putere, radical, invers 1/x, negație).

Memoria este gestionată automat: la fiecare calcul, se salvează rezultatul și expresia asociată (ca string), păstrându-se doar ultimele 10.
Sunt implementate funcții pentru afișarea memoriei, curățarea acesteia, resetarea numărului curent și reîncărcarea unui rezultat anterior.

Proiectul exemplifică utilizarea principiilor de programare orientată pe obiect (POO), inclusiv:

          constructor de copiere și operator de atribuire

          vectori alocați dinamic

          supraîncărcarea operatorilor +, -, *, /, !, []

          metode pentru operații matematice complexe

Clasa este testată într-un main() care simulează comportamentul unui utilizator real de calculator.
