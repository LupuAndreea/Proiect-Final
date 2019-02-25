# Proiect-Final
Line Follower

Robotul a re in fata un vector de 8 senzori dintre care am folosit doar senzorii D2-D7. Fiecare senzor are o un receptor de luminca IR astfel ficare senzor in parte emite lumina IR si apoi observa cat primeste inapoi. Fiecare senzor returneaza un semnal analog care poate fi mai mic de 900 daca se afla pe fundal alb si mai mare de 900 daca intalneste dunga neagra.

In functia loop verific valoare primita de fiecare senzor in parte iar daca < 900 apelez functia turndRight(), daca este > 900 apelez functia turnLeft().
