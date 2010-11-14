/*
 * This file is part of SPAG.
 * 
 * Copyright 2010 Alexandre Quessy <alexandre@quessy.net>
 * http://alexandre.quessy.net
 * 
 * SPAG is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * SPAG is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with SPAG.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __MACHINE_H__
#define __MACHINE_H__

#include <boost/bind.hpp>
#include <string>
#include "rule.h"
#include "state.h"

namespace spag
{
    /**
     * Finite state machine.
     *
     * Transitions between states are triggered by events.
     */
    class Machine
    {
        private:
            State *root_;
        public:
            Machine(State *root) :
                root_(root)
            { }
            const std::string &startup();
            bool trigger(std::string &event);
    };
}; // spag

#endif
