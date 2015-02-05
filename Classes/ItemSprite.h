//
//  ItemSprite.h
//  LittleKnight
//
//  Created by JinTongyao on 1/22/15.
//
//

#ifndef __LittleKnight__ItemSprite__
#define __LittleKnight__ItemSprite__

#include "cocos2d.h"

USING_NS_CC;

// tile中的元素类型,根据类型生成不同元素
enum ItemType {
    sword,
    health,
    mana,
    conis,
    shield,
    monster1
};

class ItemSprite : public Sprite {
    
public:
    CREATE_FUNC(ItemSprite);
    virtual bool init();
    static ItemSprite* create(ItemType elementType);
    
    int getItemType();
    void setItemType(int itemType);
    
private:
    int itemType;
    
};

#endif /* defined(__LittleKnight__ItemSprite__) */
