/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** ProgressBar
*/

#include "ProgressBar.hpp"

ProgressBar::ProgressBar(irr::gui::IGUIEnvironment *env, irr::video::IVideoDriver *driver, irr::core::rect<irr::s32> dimensions, irr::gui::IGUIElement *parent) : _env(env), _driver(driver),
	irr::gui::IGUIElement(irr::gui::EGUIET_ELEMENT, env, parent, -1, dimensions), _progress(0), _max(dimensions.LowerRightCorner.X - dimensions.UpperLeftCorner.X), _bar(dimensions), _color(IRR_WHITE),
	_emptyColor(IRR_BLACK), _borderColor(IRR_RED)
{
	if (parent == nullptr)
		env->getRootGUIElement()->addChild(this);
}

void ProgressBar::setProgress(irr::u32 progress)
{
	_progress += progress;
	if (_progress > 100)
		_progress = 100;
	else if (_progress < 0)
		_progress = 0;

	irr::u32 percent = (progress * _max) / 100;
	_toFill.UpperLeftCorner.set(_bar.UpperLeftCorner.X, _bar.UpperLeftCorner.Y);
	_toFill.LowerRightCorner.set(_bar.UpperLeftCorner.X + percent, _bar.LowerRightCorner.Y);
	_nonFilled.UpperLeftCorner.set(_toFill.LowerRightCorner.X, _toFill.UpperLeftCorner.Y);
	_nonFilled.LowerRightCorner.set(_bar.LowerRightCorner.X, _bar.LowerRightCorner.Y);
	draw();
}

void ProgressBar::setColor(irr::video::SColor color)
{
	_color = color;
}

void ProgressBar::setEmptyColor(irr::video::SColor color)
{
	_emptyColor = color;
}

void ProgressBar::setPosition(irr::core::rect<irr::s32> pos)
{
	_position = pos;
}

void ProgressBar::addBorder(const irr::s32 &size, irr::video::SColor color)
{
	_border = _bar;
	_border.UpperLeftCorner.X -= size;
	_border.UpperLeftCorner.Y -= size;
	_border.LowerRightCorner.X += size;
	_border.LowerRightCorner.Y += size;
	_borderColor = color;
}

void ProgressBar::setBorderColor(irr::video::SColor color)
{
	_borderColor = color;
}

void ProgressBar::setBorderPosition(irr::core::rect<irr::s32> pos)
{
	_borderPosition = pos;
}

void ProgressBar::draw()
{
	if (!IsVisible)
		return;
	_driver->draw2DRectangle(_borderColor, _border);
	_driver->draw2DRectangle(_color, _toFill);
	_driver->draw2DRectangle(_emptyColor, _nonFilled);
}
