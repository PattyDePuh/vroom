#ifndef COMPUTING_TIMES_H
#define COMPUTING_TIMES_H

/*

This file is part of VROOM.

Copyright (c) 2015-2016, Julien Coupey.
All rights reserved (see LICENSE).

*/

struct computing_times{
  // Computing times in milliseconds.
  duration_t loading;
  duration_t solving;
  duration_t routing;
};

#endif