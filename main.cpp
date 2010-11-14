#include "spag.h"

int main(int argc, char *argv[])
{
    spag::State root = spag::State("root");
    spag::Machine machine = spag::Machine(&root);
    spag::Machine.trigger("spam");
    return 0;
}
