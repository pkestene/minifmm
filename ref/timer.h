#pragma once

#include <sys/time.h>
#include <stdio.h>

double wtime();

struct Timer
{
  double tick;
  double tock;
  double elapsed;

  Timer() : tick(0.0), tock(0.0), elapsed(0.0) {}

  inline void start()
  {
    tick = wtime();
  }

  inline void stop()
  {
    tock    = wtime();
    elapsed = tock - tick;
  }

  inline double timer_seconds()
  {
    return elapsed;
  }
  
  inline void timer_print(const char* timer_string)
  {
    if (timer_string != NULL) 
      printf("----- %s -----\n", timer_string);
    else 
      printf("----------\n");
    printf("Total elapsed time = %f\n", timer_seconds());
    printf("----------\n");
  }
  
}; // struct Timer

