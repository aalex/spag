#include "spag.h"
#include <string>

int main(int argc, char *argv[])
{
    spag::State root("root");
    spag::Machine machine(&root);

    std::string event("spam");
    machine.trigger(event);
    return 0;
}
