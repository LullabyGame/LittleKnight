//
//  MainMenuScene.cpp
//  LittleKnight
//
//  主菜单Scene实现
//
//

#include "MainMenuScene.h"

/**
 *  创建Scene
 *
 *  @return 创建的Scene
 */
Scene* MainMenuScene::createScene() {
    auto *scene = Scene::create();
    auto *layer = MainMenuScene::create();
    scene->addChild(layer);
    
    return scene;
}


/**
 * init方法
 * 定义各种菜单按钮
 */
bool MainMenuScene::init() {
    if(!Layer::init()) {
        return false;
    }
    
    Size visiableSize = Director::getInstance()->getVisibleSize();
    
    // 背景Layer
    auto backgroundLayer = LayerColor::create(Color4B(238, 222, 170, 255));
    this->addChild(backgroundLayer);

    // NormalMode按钮
    auto nomrmalModeLable = MenuItemLabel::create(LabelTTF::create("Normal Mode", "Futura.ttf", 32), CC_CALLBACK_1(MainMenuScene::menuNormalModeCallback, this));
    nomrmalModeLable->setTag(0);
    nomrmalModeLable->setAnchorPoint(Point(0, 0));
    nomrmalModeLable->setPosition(Point(visiableSize.width / 2 - 80, visiableSize.height / 2 + 90));
    auto normalModeMenu = Menu::create(nomrmalModeLable, NULL);
    normalModeMenu->setPosition(0, 0);
    this->addChild(normalModeMenu);
    
    return true;
}


/**
 *  NormalMode按钮回调
 *
 *  @param sender
 */
void MainMenuScene::menuNormalModeCallback(Ref *sender) {
    MenuItem* selectedMenu = (MenuItem*) sender;
    int tag = selectedMenu->getTag();
    Scene* normalModeScene = NormalModeScene::createScene(tag);
    TransitionFlipX *transition = TransitionFlipX::create(1.2, normalModeScene);
    Director::getInstance()->replaceScene(transition);
}