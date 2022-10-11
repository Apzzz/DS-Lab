// program to add two polynomials 

#include <stdio.h>

struct poly
{
  int ex, co;
} ob[100], g, h;

int
addp (int af, int al, int bf, int bl, int x)
{
  int sum, y;
  while (af <= al && bf <= bl)
    {
      if (ob[af].ex == ob[bf].ex)
	{
	  sum = ob[af].co + ob[bf].co;
	  if (sum != 0)
	    {
	      ob[x].ex = ob[af].ex;
	      ob[x].co = sum;
	      x++;
	    }
	  af++;
	  bf++;
	}

      else if (ob[af].ex > ob[bf].ex)
	{
	  ob[x].ex = ob[af].ex;
	  ob[x].co = ob[af].co;
	  x++;
	  af++;
	}

      else if (ob[af].ex < ob[bf].ex)
	{
	  ob[x].ex = ob[bf].ex;
	  ob[x].co = ob[bf].co;
	  x++;
	  bf++;
	}
    }

 // if (af <= al)
   // {
      while (af <= al)
	{
	  ob[x].ex = ob[af].ex;
	  ob[x].co = ob[af].co;
	  x++;
	  af++;
	}
    //}
//  if (bf <= bl)
  //  {
      while (bf <= bl)
	{
	  ob[x].ex = ob[bf].ex;
	  ob[x].co = ob[bf].co;
	  x++;
	  bf++;
	}
  //  }
  y = x - 1;
  return y;
}

void
main ()
{
  int i = -1, j, p = 0, q, r, s, f, e, m, n, a, b, x, y, k, l;

  printf ("Enter the no of terms in 1st polynomial ");
  scanf ("%d", &x);

  printf ("Enter the first polynomial ");
  for (k = 0; k < x; k++)
    {
      i++;
      scanf ("%d %d", &ob[i].co, &ob[i].ex);
    }

  q = i;
  r = i + 1;

  for (m = 0; m < i; m++)
    {
      for (n = 1; n <= i; n++)
	{
	  if (ob[n].ex > ob[n - 1].ex)
	    {
	      g = ob[n - 1];
	      ob[n - 1] = ob[n];
	      ob[n] = g;
	    }
	}
    }

  printf ("Enter the no of terms in 2nd polynomial ");
  scanf ("%d", &y);

  printf ("Enter the second polynomial ");
  for (l = 0; l < y; l++)
    {
      i++;
      scanf ("%d %d", &ob[i].co, &ob[i].ex);
    }
  s = i;
  f = i + 1;

  for (a = r; a < s; a++)
    {
      for (b = r + 1; b <= s; b++)
	{
	  if (ob[b].ex > ob[b - 1].ex)
	    {
	      h = ob[b - 1];
	      ob[b - 1] = ob[b];
	      ob[b] = h;
	    }
	}
    }

  e = addp (p, q, r, s, f);

  printf ("The first polynomial is \n");
  for (i = 0; i <= q; i++)
    {
        if(ob[i].co!=0)
        {
      if (i == q)
	printf ("%dx^%d", ob[i].co, ob[i].ex);
      else
	printf ("%dx^%d + ", ob[i].co, ob[i].ex);
    }
    }

  printf ("\nThe second polynomial is \n");
  for (i = r; i <= s; i++)
    {
        if(ob[i].co!=0)
        {
      if (i == s)
	printf ("%dx^%d", ob[i].co, ob[i].ex);
      else
	printf ("%dx^%d + ", ob[i].co, ob[i].ex);
    }
    }

  printf ("\nThe sum polynomial is \n");
  for (i = f; i <= e; i++)
    {
      if (i == e)
	printf ("%dx^%d", ob[i].co, ob[i].ex);
      else
	printf ("%dx^%d + ", ob[i].co, ob[i].ex);
    }

}
