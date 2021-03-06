#ifndef CLAYMAN_H_
#define CLAYMAN_H_

#include "ClayAnims.h"

#include <libeng/Graphic/Object/2D/Sprite2D.h>

#define CLAY_MAX_SPEED          100 // Maximum speed provided by the scrolling (in pixel)

#define TEXTURE_ID_CLAYMAN      21
#define CLAY_TEXTURE_WIDTH      512.0f
#define CLAY_TEXTURE_HEIGHT     512.0f

// Anims index definitions
enum {

    DOWN = 0, DOWN1, DOWN2, DOWN3, DOWN4, DOWN5, DOWN6, DOWN7, DOWN8,
    DR, DR1, DR2, DR3, DR4, DR5, DR6, DR7, DR8,
    RIGHT, RIGHT1, RIGHT2, RIGHT3, RIGHT4, RIGHT5, RIGHT6, RIGHT7, RIGHT8,
    UR, UR1, UR2, UR3, UR4, UR5, UR6, UR7, UR8,
    UP, UP1, UP2, UP3, UP4, UP5, UP6, UP7, UP8

};
#define CLAY_ANIM_COUNT         (UP8 + 1)

typedef struct {

    unsigned char velocity; // [0;CLAY_MAX_SPEED]

    unsigned char direction; // 0: DOWN; 1: DR; 2: RIGHT; 3: UR; 4: UP
    bool backward; // TRUE: ClayMan goes on the left; FALSE: ClayMan goes on the right

} ClayManMove;

static const float gs_ClayTexCoords[CLAY_ANIM_COUNT][8] = {
    { CLAY_NONE_X0/CLAY_TEXTURE_WIDTH,    CLAY_NONE_Y0/CLAY_TEXTURE_HEIGHT,   CLAY_NONE_X0/CLAY_TEXTURE_WIDTH,   CLAY_NONE_Y2/CLAY_TEXTURE_HEIGHT,
      CLAY_NONE_X2/CLAY_TEXTURE_WIDTH,    CLAY_NONE_Y2/CLAY_TEXTURE_HEIGHT,   CLAY_NONE_X2/CLAY_TEXTURE_WIDTH,   CLAY_NONE_Y0/CLAY_TEXTURE_HEIGHT },
    { CLAY_DOWN1_X0/CLAY_TEXTURE_WIDTH,   CLAY_DOWN1_Y0/CLAY_TEXTURE_HEIGHT,  CLAY_DOWN1_X0/CLAY_TEXTURE_WIDTH,  CLAY_DOWN1_Y2/CLAY_TEXTURE_HEIGHT,
      CLAY_DOWN1_X2/CLAY_TEXTURE_WIDTH,   CLAY_DOWN1_Y2/CLAY_TEXTURE_HEIGHT,  CLAY_DOWN1_X2/CLAY_TEXTURE_WIDTH,  CLAY_DOWN1_Y0/CLAY_TEXTURE_HEIGHT },
    { CLAY_DOWN2_X0/CLAY_TEXTURE_WIDTH,   CLAY_DOWN2_Y0/CLAY_TEXTURE_HEIGHT,  CLAY_DOWN2_X0/CLAY_TEXTURE_WIDTH,  CLAY_DOWN2_Y2/CLAY_TEXTURE_HEIGHT,
      CLAY_DOWN2_X2/CLAY_TEXTURE_WIDTH,   CLAY_DOWN2_Y2/CLAY_TEXTURE_HEIGHT,  CLAY_DOWN2_X2/CLAY_TEXTURE_WIDTH,  CLAY_DOWN2_Y0/CLAY_TEXTURE_HEIGHT },
    { CLAY_DOWN3_X0/CLAY_TEXTURE_WIDTH,   CLAY_DOWN3_Y0/CLAY_TEXTURE_HEIGHT,  CLAY_DOWN3_X0/CLAY_TEXTURE_WIDTH,  CLAY_DOWN3_Y2/CLAY_TEXTURE_HEIGHT,
      CLAY_DOWN3_X2/CLAY_TEXTURE_WIDTH,   CLAY_DOWN3_Y2/CLAY_TEXTURE_HEIGHT,  CLAY_DOWN3_X2/CLAY_TEXTURE_WIDTH,  CLAY_DOWN3_Y0/CLAY_TEXTURE_HEIGHT },
    { CLAY_DOWN4_X0/CLAY_TEXTURE_WIDTH,   CLAY_DOWN4_Y0/CLAY_TEXTURE_HEIGHT,  CLAY_DOWN4_X0/CLAY_TEXTURE_WIDTH,  CLAY_DOWN4_Y2/CLAY_TEXTURE_HEIGHT,
      CLAY_DOWN4_X2/CLAY_TEXTURE_WIDTH,   CLAY_DOWN4_Y2/CLAY_TEXTURE_HEIGHT,  CLAY_DOWN4_X2/CLAY_TEXTURE_WIDTH,  CLAY_DOWN4_Y0/CLAY_TEXTURE_HEIGHT },
    { CLAY_DOWN5_X0/CLAY_TEXTURE_WIDTH,   CLAY_DOWN5_Y0/CLAY_TEXTURE_HEIGHT,  CLAY_DOWN5_X0/CLAY_TEXTURE_WIDTH,  CLAY_DOWN5_Y2/CLAY_TEXTURE_HEIGHT,
      CLAY_DOWN5_X2/CLAY_TEXTURE_WIDTH,   CLAY_DOWN5_Y2/CLAY_TEXTURE_HEIGHT,  CLAY_DOWN5_X2/CLAY_TEXTURE_WIDTH,  CLAY_DOWN5_Y0/CLAY_TEXTURE_HEIGHT },
    { CLAY_DOWN6_X0/CLAY_TEXTURE_WIDTH,   CLAY_DOWN6_Y0/CLAY_TEXTURE_HEIGHT,  CLAY_DOWN6_X0/CLAY_TEXTURE_WIDTH,  CLAY_DOWN6_Y2/CLAY_TEXTURE_HEIGHT,
      CLAY_DOWN6_X2/CLAY_TEXTURE_WIDTH,   CLAY_DOWN6_Y2/CLAY_TEXTURE_HEIGHT,  CLAY_DOWN6_X2/CLAY_TEXTURE_WIDTH,  CLAY_DOWN6_Y0/CLAY_TEXTURE_HEIGHT },
    { CLAY_DOWN7_X0/CLAY_TEXTURE_WIDTH,   CLAY_DOWN7_Y0/CLAY_TEXTURE_HEIGHT,  CLAY_DOWN7_X0/CLAY_TEXTURE_WIDTH,  CLAY_DOWN7_Y2/CLAY_TEXTURE_HEIGHT,
      CLAY_DOWN7_X2/CLAY_TEXTURE_WIDTH,   CLAY_DOWN7_Y2/CLAY_TEXTURE_HEIGHT,  CLAY_DOWN7_X2/CLAY_TEXTURE_WIDTH,  CLAY_DOWN7_Y0/CLAY_TEXTURE_HEIGHT },
    { CLAY_DOWN8_X0/CLAY_TEXTURE_WIDTH,   CLAY_DOWN8_Y0/CLAY_TEXTURE_HEIGHT,  CLAY_DOWN8_X0/CLAY_TEXTURE_WIDTH,  CLAY_DOWN8_Y2/CLAY_TEXTURE_HEIGHT,
      CLAY_DOWN8_X2/CLAY_TEXTURE_WIDTH,   CLAY_DOWN8_Y2/CLAY_TEXTURE_HEIGHT,  CLAY_DOWN8_X2/CLAY_TEXTURE_WIDTH,  CLAY_DOWN8_Y0/CLAY_TEXTURE_HEIGHT },
    { CLAY_DR_X0/CLAY_TEXTURE_WIDTH,      CLAY_DR_Y0/CLAY_TEXTURE_HEIGHT,     CLAY_DR_X0/CLAY_TEXTURE_WIDTH,     CLAY_DR_Y2/CLAY_TEXTURE_HEIGHT,
      CLAY_DR_X2/CLAY_TEXTURE_WIDTH,      CLAY_DR_Y2/CLAY_TEXTURE_HEIGHT,     CLAY_DR_X2/CLAY_TEXTURE_WIDTH,     CLAY_DR_Y0/CLAY_TEXTURE_HEIGHT },
    { CLAY_DR1_X0/CLAY_TEXTURE_WIDTH,     CLAY_DR1_Y0/CLAY_TEXTURE_HEIGHT,    CLAY_DR1_X0/CLAY_TEXTURE_WIDTH,    CLAY_DR1_Y2/CLAY_TEXTURE_HEIGHT,
      CLAY_DR1_X2/CLAY_TEXTURE_WIDTH,     CLAY_DR1_Y2/CLAY_TEXTURE_HEIGHT,    CLAY_DR1_X2/CLAY_TEXTURE_WIDTH,    CLAY_DR1_Y0/CLAY_TEXTURE_HEIGHT },
    { CLAY_DR2_X0/CLAY_TEXTURE_WIDTH,     CLAY_DR2_Y0/CLAY_TEXTURE_HEIGHT,    CLAY_DR2_X0/CLAY_TEXTURE_WIDTH,    CLAY_DR2_Y2/CLAY_TEXTURE_HEIGHT,
      CLAY_DR2_X2/CLAY_TEXTURE_WIDTH,     CLAY_DR2_Y2/CLAY_TEXTURE_HEIGHT,    CLAY_DR2_X2/CLAY_TEXTURE_WIDTH,    CLAY_DR2_Y0/CLAY_TEXTURE_HEIGHT },
    { CLAY_DR3_X0/CLAY_TEXTURE_WIDTH,     CLAY_DR3_Y0/CLAY_TEXTURE_HEIGHT,    CLAY_DR3_X0/CLAY_TEXTURE_WIDTH,    CLAY_DR3_Y2/CLAY_TEXTURE_HEIGHT,
      CLAY_DR3_X2/CLAY_TEXTURE_WIDTH,     CLAY_DR3_Y2/CLAY_TEXTURE_HEIGHT,    CLAY_DR3_X2/CLAY_TEXTURE_WIDTH,    CLAY_DR3_Y0/CLAY_TEXTURE_HEIGHT },
    { CLAY_DR4_X0/CLAY_TEXTURE_WIDTH,     CLAY_DR4_Y0/CLAY_TEXTURE_HEIGHT,    CLAY_DR4_X0/CLAY_TEXTURE_WIDTH,    CLAY_DR4_Y2/CLAY_TEXTURE_HEIGHT,
      CLAY_DR4_X2/CLAY_TEXTURE_WIDTH,     CLAY_DR4_Y2/CLAY_TEXTURE_HEIGHT,    CLAY_DR4_X2/CLAY_TEXTURE_WIDTH,    CLAY_DR4_Y0/CLAY_TEXTURE_HEIGHT },
    { CLAY_DR5_X0/CLAY_TEXTURE_WIDTH,     CLAY_DR5_Y0/CLAY_TEXTURE_HEIGHT,    CLAY_DR5_X0/CLAY_TEXTURE_WIDTH,    CLAY_DR5_Y2/CLAY_TEXTURE_HEIGHT,
      CLAY_DR5_X2/CLAY_TEXTURE_WIDTH,     CLAY_DR5_Y2/CLAY_TEXTURE_HEIGHT,    CLAY_DR5_X2/CLAY_TEXTURE_WIDTH,    CLAY_DR5_Y0/CLAY_TEXTURE_HEIGHT },
    { CLAY_DR6_X0/CLAY_TEXTURE_WIDTH,     CLAY_DR6_Y0/CLAY_TEXTURE_HEIGHT,    CLAY_DR6_X0/CLAY_TEXTURE_WIDTH,    CLAY_DR6_Y2/CLAY_TEXTURE_HEIGHT,
      CLAY_DR6_X2/CLAY_TEXTURE_WIDTH,     CLAY_DR6_Y2/CLAY_TEXTURE_HEIGHT,    CLAY_DR6_X2/CLAY_TEXTURE_WIDTH,    CLAY_DR6_Y0/CLAY_TEXTURE_HEIGHT },
    { CLAY_DR7_X0/CLAY_TEXTURE_WIDTH,     CLAY_DR7_Y0/CLAY_TEXTURE_HEIGHT,    CLAY_DR7_X0/CLAY_TEXTURE_WIDTH,    CLAY_DR7_Y2/CLAY_TEXTURE_HEIGHT,
      CLAY_DR7_X2/CLAY_TEXTURE_WIDTH,     CLAY_DR7_Y2/CLAY_TEXTURE_HEIGHT,    CLAY_DR7_X2/CLAY_TEXTURE_WIDTH,    CLAY_DR7_Y0/CLAY_TEXTURE_HEIGHT },
    { CLAY_DR8_X0/CLAY_TEXTURE_WIDTH,     CLAY_DR8_Y0/CLAY_TEXTURE_HEIGHT,    CLAY_DR8_X0/CLAY_TEXTURE_WIDTH,    CLAY_DR8_Y2/CLAY_TEXTURE_HEIGHT,
      CLAY_DR8_X2/CLAY_TEXTURE_WIDTH,     CLAY_DR8_Y2/CLAY_TEXTURE_HEIGHT,    CLAY_DR8_X2/CLAY_TEXTURE_WIDTH,    CLAY_DR8_Y0/CLAY_TEXTURE_HEIGHT },
    { CLAY_RIGHT_X0/CLAY_TEXTURE_WIDTH,   CLAY_RIGHT_Y0/CLAY_TEXTURE_HEIGHT,  CLAY_RIGHT_X0/CLAY_TEXTURE_WIDTH,  CLAY_RIGHT_Y2/CLAY_TEXTURE_HEIGHT,
      CLAY_RIGHT_X2/CLAY_TEXTURE_WIDTH,   CLAY_RIGHT_Y2/CLAY_TEXTURE_HEIGHT,  CLAY_RIGHT_X2/CLAY_TEXTURE_WIDTH,  CLAY_RIGHT_Y0/CLAY_TEXTURE_HEIGHT },
    { CLAY_RIGHT1_X0/CLAY_TEXTURE_WIDTH,  CLAY_RIGHT1_Y0/CLAY_TEXTURE_HEIGHT, CLAY_RIGHT1_X0/CLAY_TEXTURE_WIDTH, CLAY_RIGHT1_Y2/CLAY_TEXTURE_HEIGHT,
      CLAY_RIGHT1_X2/CLAY_TEXTURE_WIDTH,  CLAY_RIGHT1_Y2/CLAY_TEXTURE_HEIGHT, CLAY_RIGHT1_X2/CLAY_TEXTURE_WIDTH, CLAY_RIGHT1_Y0/CLAY_TEXTURE_HEIGHT },
    { CLAY_RIGHT2_X0/CLAY_TEXTURE_WIDTH,  CLAY_RIGHT2_Y0/CLAY_TEXTURE_HEIGHT, CLAY_RIGHT2_X0/CLAY_TEXTURE_WIDTH, CLAY_RIGHT2_Y2/CLAY_TEXTURE_HEIGHT,
      CLAY_RIGHT2_X2/CLAY_TEXTURE_WIDTH,  CLAY_RIGHT2_Y2/CLAY_TEXTURE_HEIGHT, CLAY_RIGHT2_X2/CLAY_TEXTURE_WIDTH, CLAY_RIGHT2_Y0/CLAY_TEXTURE_HEIGHT },
    { CLAY_RIGHT3_X0/CLAY_TEXTURE_WIDTH,  CLAY_RIGHT3_Y0/CLAY_TEXTURE_HEIGHT, CLAY_RIGHT3_X0/CLAY_TEXTURE_WIDTH, CLAY_RIGHT3_Y2/CLAY_TEXTURE_HEIGHT,
      CLAY_RIGHT3_X2/CLAY_TEXTURE_WIDTH,  CLAY_RIGHT3_Y2/CLAY_TEXTURE_HEIGHT, CLAY_RIGHT3_X2/CLAY_TEXTURE_WIDTH, CLAY_RIGHT3_Y0/CLAY_TEXTURE_HEIGHT },
    { CLAY_RIGHT4_X0/CLAY_TEXTURE_WIDTH,  CLAY_RIGHT4_Y0/CLAY_TEXTURE_HEIGHT, CLAY_RIGHT4_X0/CLAY_TEXTURE_WIDTH, CLAY_RIGHT4_Y2/CLAY_TEXTURE_HEIGHT,
      CLAY_RIGHT4_X2/CLAY_TEXTURE_WIDTH,  CLAY_RIGHT4_Y2/CLAY_TEXTURE_HEIGHT, CLAY_RIGHT4_X2/CLAY_TEXTURE_WIDTH, CLAY_RIGHT4_Y0/CLAY_TEXTURE_HEIGHT },
    { CLAY_RIGHT5_X0/CLAY_TEXTURE_WIDTH,  CLAY_RIGHT5_Y0/CLAY_TEXTURE_HEIGHT, CLAY_RIGHT5_X0/CLAY_TEXTURE_WIDTH, CLAY_RIGHT5_Y2/CLAY_TEXTURE_HEIGHT,
      CLAY_RIGHT5_X2/CLAY_TEXTURE_WIDTH,  CLAY_RIGHT5_Y2/CLAY_TEXTURE_HEIGHT, CLAY_RIGHT5_X2/CLAY_TEXTURE_WIDTH, CLAY_RIGHT5_Y0/CLAY_TEXTURE_HEIGHT },
    { CLAY_RIGHT6_X0/CLAY_TEXTURE_WIDTH,  CLAY_RIGHT6_Y0/CLAY_TEXTURE_HEIGHT, CLAY_RIGHT6_X0/CLAY_TEXTURE_WIDTH, CLAY_RIGHT6_Y2/CLAY_TEXTURE_HEIGHT,
      CLAY_RIGHT6_X2/CLAY_TEXTURE_WIDTH,  CLAY_RIGHT6_Y2/CLAY_TEXTURE_HEIGHT, CLAY_RIGHT6_X2/CLAY_TEXTURE_WIDTH, CLAY_RIGHT6_Y0/CLAY_TEXTURE_HEIGHT },
    { CLAY_RIGHT7_X0/CLAY_TEXTURE_WIDTH,  CLAY_RIGHT7_Y0/CLAY_TEXTURE_HEIGHT, CLAY_RIGHT7_X0/CLAY_TEXTURE_WIDTH, CLAY_RIGHT7_Y2/CLAY_TEXTURE_HEIGHT,
      CLAY_RIGHT7_X2/CLAY_TEXTURE_WIDTH,  CLAY_RIGHT7_Y2/CLAY_TEXTURE_HEIGHT, CLAY_RIGHT7_X2/CLAY_TEXTURE_WIDTH, CLAY_RIGHT7_Y0/CLAY_TEXTURE_HEIGHT },
    { CLAY_RIGHT8_X0/CLAY_TEXTURE_WIDTH,  CLAY_RIGHT8_Y0/CLAY_TEXTURE_HEIGHT, CLAY_RIGHT8_X0/CLAY_TEXTURE_WIDTH, CLAY_RIGHT8_Y2/CLAY_TEXTURE_HEIGHT,
      CLAY_RIGHT8_X2/CLAY_TEXTURE_WIDTH,  CLAY_RIGHT8_Y2/CLAY_TEXTURE_HEIGHT, CLAY_RIGHT8_X2/CLAY_TEXTURE_WIDTH, CLAY_RIGHT8_Y0/CLAY_TEXTURE_HEIGHT },
    { CLAY_UR_X0/CLAY_TEXTURE_WIDTH,      CLAY_UR_Y0/CLAY_TEXTURE_HEIGHT,     CLAY_UR_X0/CLAY_TEXTURE_WIDTH,     CLAY_UR_Y2/CLAY_TEXTURE_HEIGHT,
      CLAY_UR_X2/CLAY_TEXTURE_WIDTH,      CLAY_UR_Y2/CLAY_TEXTURE_HEIGHT,     CLAY_UR_X2/CLAY_TEXTURE_WIDTH,     CLAY_UR_Y0/CLAY_TEXTURE_HEIGHT },
    { CLAY_UR1_X0/CLAY_TEXTURE_WIDTH,     CLAY_UR1_Y0/CLAY_TEXTURE_HEIGHT,    CLAY_UR1_X0/CLAY_TEXTURE_WIDTH,    CLAY_UR1_Y2/CLAY_TEXTURE_HEIGHT,
      CLAY_UR1_X2/CLAY_TEXTURE_WIDTH,     CLAY_UR1_Y2/CLAY_TEXTURE_HEIGHT,    CLAY_UR1_X2/CLAY_TEXTURE_WIDTH,    CLAY_UR1_Y0/CLAY_TEXTURE_HEIGHT },
    { CLAY_UR2_X0/CLAY_TEXTURE_WIDTH,     CLAY_UR2_Y0/CLAY_TEXTURE_HEIGHT,    CLAY_UR2_X0/CLAY_TEXTURE_WIDTH,    CLAY_UR2_Y2/CLAY_TEXTURE_HEIGHT,
      CLAY_UR2_X2/CLAY_TEXTURE_WIDTH,     CLAY_UR2_Y2/CLAY_TEXTURE_HEIGHT,    CLAY_UR2_X2/CLAY_TEXTURE_WIDTH,    CLAY_UR2_Y0/CLAY_TEXTURE_HEIGHT },
    { CLAY_UR3_X0/CLAY_TEXTURE_WIDTH,     CLAY_UR3_Y0/CLAY_TEXTURE_HEIGHT,    CLAY_UR3_X0/CLAY_TEXTURE_WIDTH,    CLAY_UR3_Y2/CLAY_TEXTURE_HEIGHT,
      CLAY_UR3_X2/CLAY_TEXTURE_WIDTH,     CLAY_UR3_Y2/CLAY_TEXTURE_HEIGHT,    CLAY_UR3_X2/CLAY_TEXTURE_WIDTH,    CLAY_UR3_Y0/CLAY_TEXTURE_HEIGHT },
    { CLAY_UR4_X0/CLAY_TEXTURE_WIDTH,     CLAY_UR4_Y0/CLAY_TEXTURE_HEIGHT,    CLAY_UR4_X0/CLAY_TEXTURE_WIDTH,    CLAY_UR4_Y2/CLAY_TEXTURE_HEIGHT,
      CLAY_UR4_X2/CLAY_TEXTURE_WIDTH,     CLAY_UR4_Y2/CLAY_TEXTURE_HEIGHT,    CLAY_UR4_X2/CLAY_TEXTURE_WIDTH,    CLAY_UR4_Y0/CLAY_TEXTURE_HEIGHT },
    { CLAY_UR5_X0/CLAY_TEXTURE_WIDTH,     CLAY_UR5_Y0/CLAY_TEXTURE_HEIGHT,    CLAY_UR5_X0/CLAY_TEXTURE_WIDTH,    CLAY_UR5_Y2/CLAY_TEXTURE_HEIGHT,
      CLAY_UR5_X2/CLAY_TEXTURE_WIDTH,     CLAY_UR5_Y2/CLAY_TEXTURE_HEIGHT,    CLAY_UR5_X2/CLAY_TEXTURE_WIDTH,    CLAY_UR5_Y0/CLAY_TEXTURE_HEIGHT },
    { CLAY_UR6_X0/CLAY_TEXTURE_WIDTH,     CLAY_UR6_Y0/CLAY_TEXTURE_HEIGHT,    CLAY_UR6_X0/CLAY_TEXTURE_WIDTH,    CLAY_UR6_Y2/CLAY_TEXTURE_HEIGHT,
      CLAY_UR6_X2/CLAY_TEXTURE_WIDTH,     CLAY_UR6_Y2/CLAY_TEXTURE_HEIGHT,    CLAY_UR6_X2/CLAY_TEXTURE_WIDTH,    CLAY_UR6_Y0/CLAY_TEXTURE_HEIGHT },
    { CLAY_UR7_X0/CLAY_TEXTURE_WIDTH,     CLAY_UR7_Y0/CLAY_TEXTURE_HEIGHT,    CLAY_UR7_X0/CLAY_TEXTURE_WIDTH,    CLAY_UR7_Y2/CLAY_TEXTURE_HEIGHT,
      CLAY_UR7_X2/CLAY_TEXTURE_WIDTH,     CLAY_UR7_Y2/CLAY_TEXTURE_HEIGHT,    CLAY_UR7_X2/CLAY_TEXTURE_WIDTH,    CLAY_UR7_Y0/CLAY_TEXTURE_HEIGHT },
    { CLAY_UR8_X0/CLAY_TEXTURE_WIDTH,     CLAY_UR8_Y0/CLAY_TEXTURE_HEIGHT,    CLAY_UR8_X0/CLAY_TEXTURE_WIDTH,    CLAY_UR8_Y2/CLAY_TEXTURE_HEIGHT,
      CLAY_UR8_X2/CLAY_TEXTURE_WIDTH,     CLAY_UR8_Y2/CLAY_TEXTURE_HEIGHT,    CLAY_UR8_X2/CLAY_TEXTURE_WIDTH,    CLAY_UR8_Y0/CLAY_TEXTURE_HEIGHT },
    { CLAY_UP_X0/CLAY_TEXTURE_WIDTH,      CLAY_UP_Y0/CLAY_TEXTURE_HEIGHT,     CLAY_UP_X0/CLAY_TEXTURE_WIDTH,     CLAY_UP_Y2/CLAY_TEXTURE_HEIGHT,
      CLAY_UP_X2/CLAY_TEXTURE_WIDTH,      CLAY_UP_Y2/CLAY_TEXTURE_HEIGHT,     CLAY_UP_X2/CLAY_TEXTURE_WIDTH,     CLAY_UP_Y0/CLAY_TEXTURE_HEIGHT },
    { CLAY_UP1_X0/CLAY_TEXTURE_WIDTH,     CLAY_UP1_Y0/CLAY_TEXTURE_HEIGHT,    CLAY_UP1_X0/CLAY_TEXTURE_WIDTH,    CLAY_UP1_Y2/CLAY_TEXTURE_HEIGHT,
      CLAY_UP1_X2/CLAY_TEXTURE_WIDTH,     CLAY_UP1_Y2/CLAY_TEXTURE_HEIGHT,    CLAY_UP1_X2/CLAY_TEXTURE_WIDTH,    CLAY_UP1_Y0/CLAY_TEXTURE_HEIGHT },
    { CLAY_UP2_X0/CLAY_TEXTURE_WIDTH,     CLAY_UP2_Y0/CLAY_TEXTURE_HEIGHT,    CLAY_UP2_X0/CLAY_TEXTURE_WIDTH,    CLAY_UP2_Y2/CLAY_TEXTURE_HEIGHT,
      CLAY_UP2_X2/CLAY_TEXTURE_WIDTH,     CLAY_UP2_Y2/CLAY_TEXTURE_HEIGHT,    CLAY_UP2_X2/CLAY_TEXTURE_WIDTH,    CLAY_UP2_Y0/CLAY_TEXTURE_HEIGHT },
    { CLAY_UP3_X0/CLAY_TEXTURE_WIDTH,     CLAY_UP3_Y0/CLAY_TEXTURE_HEIGHT,    CLAY_UP3_X0/CLAY_TEXTURE_WIDTH,    CLAY_UP3_Y2/CLAY_TEXTURE_HEIGHT,
      CLAY_UP3_X2/CLAY_TEXTURE_WIDTH,     CLAY_UP3_Y2/CLAY_TEXTURE_HEIGHT,    CLAY_UP3_X2/CLAY_TEXTURE_WIDTH,    CLAY_UP3_Y0/CLAY_TEXTURE_HEIGHT },
    { CLAY_UP4_X0/CLAY_TEXTURE_WIDTH,     CLAY_UP4_Y0/CLAY_TEXTURE_HEIGHT,    CLAY_UP4_X0/CLAY_TEXTURE_WIDTH,    CLAY_UP4_Y2/CLAY_TEXTURE_HEIGHT,
      CLAY_UP4_X2/CLAY_TEXTURE_WIDTH,     CLAY_UP4_Y2/CLAY_TEXTURE_HEIGHT,    CLAY_UP4_X2/CLAY_TEXTURE_WIDTH,    CLAY_UP4_Y0/CLAY_TEXTURE_HEIGHT },
    { CLAY_UP5_X0/CLAY_TEXTURE_WIDTH,     CLAY_UP5_Y0/CLAY_TEXTURE_HEIGHT,    CLAY_UP5_X0/CLAY_TEXTURE_WIDTH,    CLAY_UP5_Y2/CLAY_TEXTURE_HEIGHT,
      CLAY_UP5_X2/CLAY_TEXTURE_WIDTH,     CLAY_UP5_Y2/CLAY_TEXTURE_HEIGHT,    CLAY_UP5_X2/CLAY_TEXTURE_WIDTH,    CLAY_UP5_Y0/CLAY_TEXTURE_HEIGHT },
    { CLAY_UP6_X0/CLAY_TEXTURE_WIDTH,     CLAY_UP6_Y0/CLAY_TEXTURE_HEIGHT,    CLAY_UP6_X0/CLAY_TEXTURE_WIDTH,    CLAY_UP6_Y2/CLAY_TEXTURE_HEIGHT,
      CLAY_UP6_X2/CLAY_TEXTURE_WIDTH,     CLAY_UP6_Y2/CLAY_TEXTURE_HEIGHT,    CLAY_UP6_X2/CLAY_TEXTURE_WIDTH,    CLAY_UP6_Y0/CLAY_TEXTURE_HEIGHT },
    { CLAY_UP7_X0/CLAY_TEXTURE_WIDTH,     CLAY_UP7_Y0/CLAY_TEXTURE_HEIGHT,    CLAY_UP7_X0/CLAY_TEXTURE_WIDTH,    CLAY_UP7_Y2/CLAY_TEXTURE_HEIGHT,
      CLAY_UP7_X2/CLAY_TEXTURE_WIDTH,     CLAY_UP7_Y2/CLAY_TEXTURE_HEIGHT,    CLAY_UP7_X2/CLAY_TEXTURE_WIDTH,    CLAY_UP7_Y0/CLAY_TEXTURE_HEIGHT },
    { CLAY_UP8_X0/CLAY_TEXTURE_WIDTH,     CLAY_UP8_Y0/CLAY_TEXTURE_HEIGHT,    CLAY_UP8_X0/CLAY_TEXTURE_WIDTH,    CLAY_UP8_Y2/CLAY_TEXTURE_HEIGHT,
      CLAY_UP8_X2/CLAY_TEXTURE_WIDTH,     CLAY_UP8_Y2/CLAY_TEXTURE_HEIGHT,    CLAY_UP8_X2/CLAY_TEXTURE_WIDTH,    CLAY_UP8_Y0/CLAY_TEXTURE_HEIGHT } };

using namespace eng;

//////
class ClayMan : public Sprite2D {

private:
    unsigned char mPrevDirection;

    inline void updateAnim(bool backward) {

        animVertices(mCurAnim);
        animTexCoords(gs_ClayTexCoords, mCurAnim, backward);

        // BUG: Code below avoid a bug when displaying DR3/RIGHT5 with backward request (a pixel lag in the texture)
        if ((backward) && ((mCurAnim == DR3) || (mCurAnim == RIGHT5))) {

            mVertices[0] -= 0.003421f;
            mVertices[2] = mVertices[0];
            mVertices[4] -= 0.003421f;
            mVertices[6] = mVertices[4];
            // "centerVertices(mVertices[4] / 2.0f, ..." instead of "centerVertices(mVertices[4] / 1.9f, ..." in 'fillVerticesAnims' method
        }
    }
    inline void walk(unsigned char fromAnim, unsigned char toAnim, bool backward) {

        if (mCurAnim < toAnim)
            ++mCurAnim;
        else
            mCurAnim = fromAnim;
        updateAnim(backward);
    }

protected:
    void fillVerticesAnims(unsigned char animIdx);

public:
    ClayMan();
    virtual ~ClayMan();

    //
    void start();

    //////
    void update(const Game* game, const Level* level);

    bool checkCollision(const Bounds* bounds, unsigned char boundsId) { return false; }
    bool checkCollision(const Object* object, unsigned char objectId) { return false; }

};

#endif // CLAYMAN_H_
