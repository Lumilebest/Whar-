#pragma once

enum AIM{
    Rusher
};
struct AIMType{
    AIM type;
    unsigned int state;
};

enum AIA{
    Slach
};
struct AIAType{
    AIA type;
    unsigned int state;
};

struct Velocity{
    float maxSpeed;
    float acceleration;
    float speed;
};

struct Health{
    float maxHealth;
    float health;
    float maxShield;
    float shield;
    float resistance;
};