	Malloc

Ce miniproj consiste à écrire une librairie de gestion de l’allocation dynamique de la
mémoire. Afin de pouvoir la faire utiliser par des programmes déjà existant sans les modifier
ni les recompiler, vous devrez réécrire les fonctions malloc(3), free(3), et realloc(3)
de la libc.

---- Memo ----

	 Chunk
	 Chunk_Size
	 State
	 Next

Liste chainee contenant l'addresse d'un chunk, sa taille, son etat (Empty, Partial, Full)
et un pointeur vers le chunk suivant.

Besoin de la taille reserve en plus de la taille du chunk ?

Trier les chunk par ordre croissant, premier trouver = premier suffisamment grand.

---- Pseudo Code ----

Malloc(size)
{
Si size > 4096
   Large_handler(size)
Si Liste Vide creation Premier Maillon
Parcours de la liste a la recherche d'un chunk empty ou mid.
Si chunk == Empty
   Si Size == Chunk_Size
   	  mettre State a Full
	  return adr de Chunk
   Sinon
	  Split_Chunk(Chunk, size)
	  return adr de Chunk
}

