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
#ifndef __STATE_H__
#define __STATE_H__

#include <boost/bind.hpp>
#include <boost/signals2.hpp>
#include <iostream>
#include <string>
#include <vector>

#include "rule.h"
/**
 * SPAG is a Finite State Machine library.
 */
namespace spag
{
    class State; // forward declaration
    /**
     * State: A state in which the machine can be.
     */
    class State
    {
        public:
            // flags:
            static const int DEFAULT_FLAG = 1;
            // typedefs:
            typedef boost::signals2::signal<void ()> OnEnterSignal;
            typedef boost::signals2::signal<void ()> OnLeaveSignal;
            typedef boost::shared_ptr< State > StatePtr;
            typedef boost::shared_ptr< Rule > RulePtr;
            typedef std::vector< StatePtr >::iterator StateIterator;
            typedef std::vector< RulePtr >::iterator RuleIterator;

            OnEnterSignal on_enter_signal_;
            OnLeaveSignal on_leave_signal_;

            State(std::string &name, int flags) : 
                name_(name),
                flags_(flags)
            {}
            State(std::string &name) : 
                name_(name),
                flags_(0)
            {}
            ~State() {}
            bool add_child(State *child);
            std::string &get_name()
            {
                return name_;
            }
            State *find_child(std::string &name);
            bool has_child(std::string &name);
            Rule *find_rule(std::string &event);
            bool add_rule(Rule *rule);
            std::string &apply_event(std::string &event);
            std::string &enter();
            void leave();
            bool is_currently_in()
            {
                return currently_in_;
            }
        private:
            std::string name_;
            int flags_;
            std::vector<StatePtr> children_;
            std::vector<RulePtr> rules_;
            bool currently_in_;
            State *find_default_child();
    };
}; // spag

#endif
