#ifndef ROUTING_IO_H
#define ROUTING_IO_H

/*

This file is part of VROOM.

Copyright (c) 2015-2016, Julien Coupey.
All rights reserved (see LICENSE).

*/

#include<string>
#include<vector>
#include<list>
#include "../../include/rapidjson/document.h"
#include "../structures/abstract/matrix.h"
#include "../structures/vroom/location.h"
#include "../structures/vroom/solution/route.h"

template <class T>
class routing_io{

public:
  virtual matrix<T> get_matrix(const std::vector<location_t>& locs) const = 0;

  virtual void add_route_geometry(route_t& rte) const = 0;

  virtual ~routing_io() {}

protected:
  routing_io() {}
};

#endif
