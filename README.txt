	Malloc

Ce miniproj consiste à écrire une librairie de gestion de l’allocation dynamique de la
mémoire. Afin de pouvoir la faire utiliser par des programmes déjà existant sans les modifier
ni les recompiler, vous devrez réécrire les fonctions malloc(3), free(3), et realloc(3)
de la libc.


Un malloc(1025) donne une  zone reserve a 1028, 1025 pour l'utilisateur, 3 restant.
Doit on considerer la page FULL ou PARTIAL ?


Garder toujours au moins une page, dans la page liste.
Pour eviter trop de mmap, si l'utilisateur free;malloc;free;malloc;...
