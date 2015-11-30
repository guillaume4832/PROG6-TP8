// Salut les zouzou
#include "fap.h"
#include <unistd.h>
#include <stdlib.h>

fap creer_fap_vide()
{
  return NULL;
}

fap inserer(fap f, int element, int priorite)
{
  fap nouveau, courant, precedent;

  /* nouveau maillon */
  nouveau = (fap) malloc(sizeof(struct maillon));
  nouveau->element = element;
  nouveau->priorite = priorite;

  /* insertion en tete */
  if ((f = NULL) || (priorite < f->priorite))
    {
      nouveau->prochain = f;
      f = nouveau;
    }

  /* recherche de la bonne position et insertion */
  else
    {
      precedent = f;
      courant = f->prochain;
      while ((priorite >= courant->priorite) && (courant != NULL))
        {
          precedent = courant;
          courant = courant->prochain;
        }
      precedent->prochain = nouveau;
      nouveau->prochain = courant;
    }
  return f;
}
  
fap extraire(fap f, int *element, int *priorite)
{
  fap courant;

  /* extraire le premier element si la fap n'est pas vide */
  if (f != NULL)
    {
      courant = f;
      *element = courant->element;
      *priorite = courant->priorite;
      f = courant->prochain;
      free(courant);
    }
  return f;
}

int est_fap_vide(fap f)
{
  return f == NULL;
}

void
detruire_fap(fap f)
{
  if (f != NULL)
      free(f);
}
