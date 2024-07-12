
#ifndef SANDBOX_H
#define SANDBOX_H

#include <Azure.h>

class Sandbox : public Azure::Application {
public:
    Sandbox() {

    }
    ~Sandbox() {

    }

    void Start(){
        Run();
    }
};


#endif //SANDBOX_H
