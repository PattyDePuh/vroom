#ifndef OUTPUT_JSON_H
#define OUTPUT_JSON_H

/*

This file is part of VROOM.

Copyright (c) 2015-2016, Julien Coupey.
All rights reserved (see LICENSE).

*/

#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <boost/log/trivial.hpp>
#include "../../include/rapidjson/document.h"
#include "../../include/rapidjson/writer.h"
#include "../../include/rapidjson/stringbuffer.h"
#include "../structures/vroom/solution/solution.h"
#include "./version.h"


rapidjson::Document to_json(const solution& sol, bool geometry);


rapidjson::Value to_json(const summary_t& summary,
                         bool geometry,
                         rapidjson::Document::AllocatorType& allocator);

rapidjson::Value to_json(const computing_times_t& computing_times,
                         bool geometry,
                         rapidjson::Document::AllocatorType& allocator);


rapidjson::Value to_json(const route_t& route,
                         rapidjson::Document::AllocatorType& allocator);


rapidjson::Value to_json(const step& s,
                         rapidjson::Document::AllocatorType& allocator);


rapidjson::Value to_json(const location_t& loc,
                         rapidjson::Document::AllocatorType& allocator);

void write_to_json(const solution& sol,
                   bool geometry,
                   const std::string& output_file);

#endif
