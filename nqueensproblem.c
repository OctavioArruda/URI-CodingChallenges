#include <stdio.h>
#include <stdlib.h>

#define NMAX 100
#define MAXCANDIDATES 100

#define TRUE  1
#define FALSE 0

static int solution_count;

nqueens (int n)
{
  int a[NMAX];                  /* solution vector */

  solution_count = 0;
  backtrack (a, 0, n);
  printf ("n=%d solution_count=%d\n", n, solution_count);
}

void process_solution (int a[], int k, int n)
{
  int i;                        /* counter */
  solution_count++;
}

int is_a_solution (int a[], int k, int n)
{
  return (k == n);
}

construct_candidates (int a[], int k, int n, int c[], int *ncandidates)
{
  int i, j;                     /* counters */
  int legal_move;              /* might the move be legal? */

  *ncandidates = 0;
  for (i = 1; i <= n; i++)
    {
      legal_move = TRUE;
      for (j = 1; j < k; j++)
        {
          if (abs ((k) - j) == abs (i - a[j]))  /* diagonal threat */
            legal_move = FALSE;
          if (i == a[j])        /* column threat */
            legal_move = FALSE;
        }
      if (legal_move == TRUE)
        {
          c[*ncandidates] = i;
          *ncandidates = *ncandidates + 1;
        }
    }
}

int
backtrack (int a[], int k, int n)
{
  int c[MAXCANDIDATES];         /* candidates for next position */
  int ncandidates;              /* next position candidate count */
  int i;                        /* counter */

  if (is_a_solution (a, k, n))
    process_solution (a, k, n);
  else
    {
      k = k + 1;
      construct_candidates (a, k, n, c, &ncandidates);
      for (i = 0; i < ncandidates; i++)
        {
          a[k] = c[i];
          backtrack (a, k, n);
        }
    }
  return 0;
}

int
main (int argc, char **argv)
{
  nqueens (atoi(argv[1]));
  return 0;
}
