/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** ProgressBar header file
*/

#ifndef PROGRESS_BAR_HPP
#define PROGRESS_BAR_HPP

#include <irrlicht.h>
#include <vector>

#define IRR_BLACK 255,0,0,0
#define IRR_WHITE 255,255,255,255
#define IRR_RED 255,255,0,0

class ProgressBar : public irr::gui::IGUIElement {
	public:
		ProgressBar(irr::gui::IGUIEnvironment *env, irr::video::IVideoDriver *driver, irr::core::rect<irr::s32> dimensions, irr::gui::IGUIElement *parent = 0);
		~ProgressBar() override = default;

		irr::u32 getProgress();
		void setProgress(irr::u32);
		void setColor(irr::video::SColor);
		void setEmptyColor(irr::video::SColor);
		void setPosition(irr::core::rect<irr::s32>);
		void addBorder(const irr::s32& size, irr::video::SColor color = irr::video::SColor(IRR_RED));
		void setBorderColor(irr::video::SColor);
		void setBorderPosition(irr::core::rect<irr::s32>);

		void draw() override;
	private:
		irr::u32 _progress;
		irr::u32 _max;
		irr::core::rect<irr::s32> _bar;
		irr::core::rect<irr::s32> _border;
		irr::core::rect<irr::s32> _position;
		irr::core::rect<irr::s32> _borderPosition;
		irr::video::SColor _color;
		irr::video::SColor _emptyColor;
		irr::video::SColor _borderColor;
		irr::core::rect<irr::s32> _toFill;
		irr::core::rect<irr::s32> _nonFilled;
		irr::gui::IGUIEnvironment *_env;
		irr::video::IVideoDriver *_driver;
};

#endif