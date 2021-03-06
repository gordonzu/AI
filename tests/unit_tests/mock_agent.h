// gordon zuehlke 2/10/2020

#ifndef AICPP_MOCKAGENT_H
#define AICPP_MOCKAGENT_H

#include <ostream>
#include "agent/agent.h"

class MockAgent : public Agent {
public:

    MockAgent() { 
        hashval = hash_it();
    }

    virtual ~MockAgent() {}

    ActionPtr execute(Percept& percept) override {
        if (percept.has_value()) {
            ActionPtr a = std::make_shared<Action>("value");
            return a;
        }
            
        ActionPtr a = std::make_shared<Action>();
        return a;
    }

    bool set_program(ProgramPtr p) override {
        if (p == nullptr) 
            return false;
        return true;
    }

    bool is_wall() const override {
        return isWall;
    }

    bool operator==(const EnvironmentObj& other) const {
        if (!EnvironmentObj::operator==(other))
            return false;

        auto p = dynamic_cast<const MockAgent*>(&other);
        if (!p) return false;

        return hashval == p->hashval;
    }

    size_t hash_it() {
        hashval = reinterpret_cast<uint64_t>(this);
        return hashval;
    }

    bool is_alive() {
        return alive;
    }

    void set_alive(bool a) {
        alive = a;
    }

protected:
    bool alive;
    bool isWall{false};
    size_t hashval{0};

};
#endif //AICPP_MOCKAGENT_H
