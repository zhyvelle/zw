#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/MenuLayer.hpp>
class $modify(MyMenuLayer, MenuLayer) {
	bool init() {
		if (!MenuLayer::init()) {
			return false;
		}
		auto spr = CCSprite::create("gay.png"_spr);

		auto enableValue = Mod::get()->getSettingValue<bool>("enable");

		auto menu = this->getChildByID("bottom-menu");

		auto zw = CCMenuItemSpriteExtra::create(spr, this, menu_selector(MyMenuLayer::onZw));

		zw->setID("zw");

		if (enableValue == true) {
			menu->addChild(zw);
			menu->updateLayout();
		}

		return true;
	}

	void onZw(CCObject*) {
		FLAlertLayer::create("message", "im gay", "ok")->show();
	}
};