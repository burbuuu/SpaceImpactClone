//
// Created by iris on 26/10/2025.
//

#ifndef SPACEIMPACT_HEALTHCONTAINER_H
#define SPACEIMPACT_HEALTHCONTAINER_H

#include <raylib.h>

class HealthContainer {
    public:
    void Init();
    void Draw(int playerHealth);
    void Unload();

    private:
    Texture2D heartTexture;
    Vector2 const POSITION{200,100};
    Vector2 const OFFSET{90};

};


#endif //SPACEIMPACT_HEALTHCONTAINER_H