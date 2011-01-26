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
#include <boost/bind.hpp>
#include <boost/signals2.hpp>
#include <iostream>
#include <string>
#include <vector>
#include "state.h"
/**
 * SPAG is a Finite State Machine library.
 */
namespace spag
{

State *State::find_default_child()
{
    StateIterator iter;
    for (iter = children_.begin(); iter < children_.end(); ++iter)
    {
        if ((*iter).get()->get_flags() & DEFAULT_FLAG)
            return (*iter).get();
    }
    return 0;
}
bool State::add_child(State *child)
{
    children_.push_back(StatePtr(child));
    return true; // FIXME
}
State *State::find_child(const std::string &name)
{
    StateIterator iter;
    for (iter = children_.begin(); iter < children_.end(); ++iter)
    {
        if ((*iter).get()->get_name() == name)
            return (*iter).get();
    }
    return 0;
}
bool State::has_child(const std::string &name)
{
    return find_child(name) != 0;
}
Rule *State::find_rule(const std::string &event)
{
    RuleIterator rule;
    for (rule = rules_.begin(); rule < rules_.end(); ++rule)
    {
        if ((*rule).get()->get_event() == event)
            return (*rule).get();
    }
    StateIterator child;
    for (child = children_.begin(); child < children_.end(); ++child)
    {
        if ((*child).get()->is_currently_in())
            return ((*child).get()->find_rule(event));
    }
    return 0;
}
bool State::add_rule(Rule *rule)
{
    rules_.push_back(RulePtr(rule));
    return true; // FIXME
}
const std::string &State::apply_event(const std::string &event)
{
    static const std::string none("");
    Rule *rule = find_rule(event);
    if (rule != 0)
    {
        // TODO            
    }
    return none; // FIXME
}
const std::string &State::enter()
{
    currently_in_ = true;
    on_enter_signal_();
    State *default_child = find_default_child();
    if (default_child != 0)
        return default_child->enter();
    return name_;
}
void State::leave()
{
    StateIterator iter;
    for (iter = children_.begin(); iter < children_.end(); ++iter)
    {
        if ((*iter).get()->is_currently_in())
        {
            (*iter)->leave(); 
            break; // we cannot be in more than a child
        }
    }
    currently_in_ = false;
    on_leave_signal_();
}

}; // end of namespace

