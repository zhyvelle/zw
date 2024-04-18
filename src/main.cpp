#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/MenuLayer.hpp>
class $modify(MyMenuLayer, MenuLayer) {
	bool init() {
		if (!MenuLayer::init()) {
			return false;
		}
		// gay
		auto spr = CCSprite::create("gay.png"_spr);

		auto enableValue = Mod::get()->getSettingValue<bool>("enable");

		auto menu = this->getChildByID("bottom-menu");

		auto zw = CCMenuItemSpriteExtra::create(spr, this, menu_selector(MyMenuLayer::onZw));

		zw->setID("zw");

		if (enableValue == true) {
			menu->addChild(zw);
			menu->updateLayout();
		}

		// not gay
		auto goodSpr = CCSprite::create("good.png"_spr);

		auto enableValueGood = Mod::get()->getSettingValue<bool>("good");

		auto good = CCMenuItemSpriteExtra::create(goodSpr, this, menu_selector(MyMenuLayer::onGood));

		good->setID("good");

		if (enableValueGood == true) {
			menu->addChild(good);
			menu->updateLayout();
		}

		//bad
		auto badSpr = CCSprite::create("bad.png"_spr);

		auto enableValueBad = Mod::get()->getSettingValue<bool>("bad");

		auto bad = CCMenuItemSpriteExtra::create(badSpr, this, menu_selector(MyMenuLayer::onBad));

		bad->setID("bad");

		if (enableValueBad == true) {
			menu->addChild(bad);
			menu->updateLayout();
		}

		return true;
	}

	void onZw(CCObject*) {
		FLAlertLayer::create("message", "im gay", "ok")->show();
	}

	void onGood(CCObject*) {
		FLAlertLayer::create("messgae", "not  gay", "ok")->show();
	}

	void onBad(CCObject*) {
		FLAlertLayer::create("message", "im bad", "ok");
	}
};