	Malloc

Ce miniproj consiste à écrire une librairie de gestion de l’allocation dynamique de la
mémoire. Afin de pouvoir la faire utiliser par des programmes déjà existant sans les modifier
ni les recompiler, vous devrez réécrire les fonctions malloc(3), free(3), et realloc(3)
de la libc.

./maintest (Test perso)
cd ./maintest
make -C ../ re
./mainX.sh


./test (Test provenant de bwyyoung & gbersac)
cd ./test
make -C ../ re
gcc -o bin/testX testX.c; ./run.sh /usr/bin/time -l ./bin/testX

Pour les test utilisant les fonctions show_alloc_mem(), show_alloc_mem_ex()
Rajouter le link de la lib malloc
gcc -o bin/testX testX.c -L ../ -lft_malloc ; ./run.sh ./bin/testX



Pour le test1:
Soustraire le nombre de page reclaims du test0 au test1 si le resultat est:
- a moins de 255 pages, la mémoire réservée est insuffisante
- a 1023 pages et plus, le malloc fonctionne mais consomme une page minimum à chaque allocation
- entre 513 pages et 1022 pages, le malloc fonctionne mais l'overhead est trop important
- entre 313 pages et 512 pages, le malloc fonctionne mais l'overhead est très important
- entre 273 pages et 312 pages, le malloc fonctionne mais l'overhead est important
- entre 255 et 272 pages, le malloc fonctionne et l'overhead est raisonnable

Pour le test2:
Le nombre de page reclaims doit etre inferieur au nombre du test1.
Et idealement ne doit pas depasser plus de 3 pages en plus du test0.
