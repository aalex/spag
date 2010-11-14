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
            int flags;
        public:
            std::string &get_event() { return event_; }
            Rule(std::string &event, std::string &target, std::string &args, int flags) :
                event_(event),
                target_(target),
                args_(args),
                flags_(flags)
            {}

            std::string &get_event() { return event_; }
            std::string &get_target() { return target_; }
            std::string &get_args() { return args_; }
    };
}; // spag
