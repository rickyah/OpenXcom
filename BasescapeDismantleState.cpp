/*
 * Copyright 2010 Daniel Albano
 *
 * This file is part of OpenXcom.
 *
 * OpenXcom is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * OpenXcom is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with OpenXcom.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "BasescapeDismantleState.h"

/**
 * Initializes all the elements in a Basescape Dismantle window.
 * @param game Pointer to the core game.
 * @param base Pointer to the base to get info from.
 * @param fac Pointer to the facility to dismantle.
 */
BasescapeDismantleState::BasescapeDismantleState(Game *game, Base *base, BaseFacility *fac) : State(game), _base(base), _fac(fac)
{
	_screen = false;

	// Create objects
	_window = new Window(152, 80, 20, 60);
	_btnOk = new Button(game->getResourcePack()->getFont("BIGLETS.DAT"), game->getResourcePack()->getFont("SMALLSET.DAT"), 44, 16, 36, 115);
	_btnCancel = new Button(game->getResourcePack()->getFont("BIGLETS.DAT"), game->getResourcePack()->getFont("SMALLSET.DAT"), 44, 16, 112, 115);
	_txtTitle = new Text(game->getResourcePack()->getFont("BIGLETS.DAT"), game->getResourcePack()->getFont("SMALLSET.DAT"), 142, 9, 25, 75);
	_txtFacility = new Text(game->getResourcePack()->getFont("BIGLETS.DAT"), game->getResourcePack()->getFont("SMALLSET.DAT"), 142, 9, 25, 85);
	
	// Set palette
	_game->setPalette(_game->getResourcePack()->getPalette("BACKPALS.DAT")->getColors(Palette::blockOffset(6)), Palette::backPos, 16);

	add(_window);
	add(_btnOk);
	add(_btnCancel);
	add(_txtTitle);
	add(_txtFacility);

	// Set up objects
	_window->setColor(Palette::blockOffset(15)+4);
	_window->setBg(game->getResourcePack()->getSurface("BACK13.SCR"));

	_btnOk->setColor(Palette::blockOffset(15)+9);
	_btnOk->setText(_game->getResourcePack()->getLanguage()->getString(STR_OK));
	_btnOk->onMouseClick((EventHandler)&BasescapeDismantleState::btnOkClick);

	_btnCancel->setColor(Palette::blockOffset(15)+9);
	_btnCancel->setText(_game->getResourcePack()->getLanguage()->getString(STR_CANCEL));
	_btnCancel->onMouseClick((EventHandler)&BasescapeDismantleState::btnCancelClick);

	_txtTitle->setColor(Palette::blockOffset(13)+10);
	_txtTitle->setAlign(ALIGN_CENTER);
	_txtTitle->setText(_game->getResourcePack()->getLanguage()->getString(STR_DISMANTLE));

	_txtFacility->setColor(Palette::blockOffset(13)+10);
	_txtFacility->setAlign(ALIGN_CENTER);
	_txtFacility->setText(_game->getResourcePack()->getLanguage()->getString(_fac->getRules()->getType()));
}

/**
 *
 */
BasescapeDismantleState::~BasescapeDismantleState()
{
	
}

/**
 * Dismantles the facility and returns
 * to the previous screen.
 * @param ev Pointer to the SDL_Event.
 * @param scale Scale of the screen.
 */
void BasescapeDismantleState::btnOkClick(SDL_Event *ev, int scale)
{
	for (vector<BaseFacility*>::iterator i = _base->getFacilities()->begin(); i != _base->getFacilities()->end(); i++)
	{
		if (*i == _fac)
		{
			_base->getFacilities()->erase(i);
			delete _fac;
			break;
		}
	}
	_game->popState();
}

/**
 * Returns to the previous screen.
 * @param ev Pointer to the SDL_Event.
 * @param scale Scale of the screen.
 */
void BasescapeDismantleState::btnCancelClick(SDL_Event *ev, int scale)
{
	_game->popState();
}