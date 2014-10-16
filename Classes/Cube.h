//
//  SixPointedStar.h
//  openglearning
//
//  Created by agile on 14-10-13.
//
//

#ifndef __openglearning__SixPointedStar__
#define __openglearning__SixPointedStar__

#include "cocos2d.h"

USING_NS_CC;

class Cube : public Node
{
public:
    virtual bool init();
    virtual void draw(Renderer *renderer, const Mat4 &transform, uint32_t flags) override;
    void onDraw(const Mat4 &transform, uint32_t flags);
    Cube();
    
public:
    CustomCommand _customCommand;
};
#endif /* defined(__openglearning__SixPointedStar__) */
