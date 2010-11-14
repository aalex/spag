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
#ifndef __RULE_H__
#define __RULE_H__

#include <string>

namespace spag
{
    /** 
     * Rule: Conditions for a transition to which state.
     */
    class Rule
    {
        private:
            /** Name of the event that trigger this transition. */
            std::string event_;
            /** Name of the state we'll be after this transition happens. */
            std::string target_;
            /** Arguments to give to the slots */
            std::string args_;
            /** Special flags. For example, a transition can be a timeout after some time the state machine didn't switch to another state. */
            int flags_;
        public:
            Rule(std::string &event, std::string &target, std::string &args, int flags) :
                event_(event),
                target_(target),
                args_(args),
                flags_(flags)
            {}

            std::string &get_event() { return event_; }
            std::string &get_target() { return target_; }
            std::string &get_args() { return args_; }
            int get_flags() { return flags_; }
    };
}; // spag

#endif
