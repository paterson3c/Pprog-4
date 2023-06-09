/**
 * @brief Defines the player's interface
 * @name player.h
 * @author Miguel Paterson
 * @date 16-02-2022
 * @copyright GNU Public License
*/

#ifndef PLAYER_H
#define PLAYER_H

#include "types.h"
#include "object.h"
#include "inventory.h"
#include "xp.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct _Player Player;

/**
 * @brief It allocates memory for a structure Player, it initialize location
 * and name to 0, and object to NULL.
 * @param id Id for the new player.
 * @author Miguel Paterson.
 * @return returns a Pointer to the allocated memory Player if it goes without errors,
 * else, it returns NULL.
*/
Player *player_create(Id id);

/**
 * @brief It gives you the Player's Id.
 * @param p Pointer to structure Player.
 * @author Miguel Paterson.
 * @return returns the Player's id, else, it returns NO_ID.
*/
Id player_getId(Player *p);

/**
 * @brief It changes the Player's Id.
 * @param p Pointer to structure Player.
 * @param id new Id for the player.
 * @author Miguel Paterson.
 * @return returns OK if it runned without errors, else, it returns ERROR.
*/
STATUS player_setId(Player *p, Id id);

/**
 * @brief It gives the Player's name.
 * @param p Pointer to structure Player.
 * @author Miguel Paterson.
 * @return returns the Player's name, else, it returns NULL.
*/
char *player_getName(Player *p);

/**
 * @brief It changes the Player's name.
 * @param p Pointer to structure Player.
 * @param name new name for the player.
 * @author Miguel Paterson.
 * @return returns OK if it runned without errors, else, it returns ERROR.
*/
STATUS player_setName(Player *p, char *name);

/**
 * @brief It gives the Player's Location.
 * @param p Pointer to structure Player.
 * @author Miguel Paterson.
 * @return returns the Player's location Id, else, it returns NO_ID.
*/
Id player_getLocation(Player *p);

/**
 * @brief It changes the Player's location.
 * @param p Pointer to structure Player.
 * @param id new Location Id.
 * @author Miguel Paterson.
 * @return returns OK if it runned without errors, else, it returns ERROR.
*/
STATUS player_setLocation(Player *p, Id id);

/**
 * @brief It gets wether the player has an object or not
 * @param p Pointer to structure Player.
 * @param id Id for the Object.
 * @author Miguel Paterson.
 * @return returns TRUE or FALSE wether the player has that object or not
*/
BOOL player_hasObject(Player *p, Id id);

/**
 * @brief It adds an Object to be weared by the Player.
 * @param p Pointer to structure Player.
 * @param id Id for the Object we want to add.
 * @author Miguel Paterson.
 * @return OK, if everything goes well or ERROR if there was some mistake
*/
STATUS player_addObject(Player *p, Id id);

/**
  * @brief It deletes an object weared by the player
  * @author Miguel Paterson
  *
  * @param p Pointer to structure Player.
  * @param id id of the object we want to delete
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS player_deleteObject(Player *p, Id id);

/**
  * @brief It givess the list of objects weared by the player
  * @author Miguel Paterson
  *
  * @param p Pointer to structure Player.
  * @return a dinamic array with the obects's ids that are weared by the player
  */
 Id *player_getObjects(Player *p);

/**
 * @brief It gives the Player's hp.
 * @param p Pointer to structure Player.
 * @author Miguel Paterson.
 * @return returns the Player's hp
*/
int player_getHealth(Player *p);

/**
 * @brief It changes the Player's hp.
 * @param p Pointer to structure Player.
 * @param hp New player's hp.
 * @author Miguel Paterson.
 * @return returns OK if it runned without errors, else, it returns ERROR.
*/
STATUS player_setHealth(Player *p, int hp);

/**
 * @brief it frees the memory allocated for the Player's Object and the Player.
 * @param p Pointer to structure Player.
 * @author Miguel Paterson.
 * @return returns OK if it runned correctly, else, it returns ERROR.
*/
STATUS player_destroy(Player *p);

/**
 * @brief displays on screen the Player's id, name, location, and it's
 * object's id and name (if weared).
 * @param pf File where the info is printed.
 * @param p Pointer to structure Player.
 * @return returns the number of characters printed.
*/
int player_print(FILE *pf, Player *p);


/**
 * @brief It sets the Player's inventory.
 * @param p Pointer to structure Player.
 * @param inv Pointer to structure Inventory.
 * @author Javier Agüero.
 * @return returns the status (OK/ERROR) of the action.
*/
STATUS player_setInventory(Player *p, Inventory *inv);

/**
 * @brief It sets the Player's attack.
 * 
 * @param p Pointer to structure Player.
 * @param value New attack value.
 * @return returns the status (OK/ERROR) of the action.q
*/
STATUS player_setAttack(Player *p, int value);

/**
 * @brief It gets the Player's attack.
 * 
 * @param p Pointer to structure Player.
 * @return returns the Player's attack.
*/
int player_getAttack(Player *p);

/**
 * @brief It sets the Player's defense.
 * 
 * @param p Pointer to structure Player.
 * @param value New defense value.
 * @return returns the status (OK/ERROR) of the action.
*/
STATUS player_setDefense(Player *p, int value);

/**
 * @brief It gets the Player's defense.
 * 
 * @param p Pointer to structure Player.
 * @return returns the Player's defense.
*/
int player_getDefense(Player *p);

/**
 * @brief It sets the Player's xp.
 * 
 * @param p Pointer to structure Player.
 * @param xp Pointer to structure XP.
 * @return returns the status (OK/ERROR) of the action.
*/
STATUS player_setXP(Player *p, XP *xp);

/**
 * @brief It gets the Player's xp.
 * 
 * @param p Pointer to structure Player.
 * @return returns the Player's xp.
*/
int player_getXP(Player *p);

/**
 * @brief It gets the Player's max xp.
 * 
 * @param p Pointer to structure Player.
 * @return returns the Player's max xp.
*/
int player_getMaxXP(Player *p);

/**
 * @brief It sets the Player's max xp.
 * 
 * @param p Pointer to structure Player.
 * @param xp Pointer to structure XP.
 * @return returns the status (OK/ERROR) of the action.
*/
STATUS player_setMaxXP(Player *p, XP *xp);

STATUS player_levelUp(Player *p);

/**
 * @brief It gives the Player's inventory.
 * @param p Pointer to structure Player.
 * @return returns the Player's inventory, else, it returns NULL.
*/
Inventory *player_getInventory(Player *p);

/**
 * @brief It sets the Player's position.
 * @param p Pointer to structure Player.
 * @param x New x coordinate.
 * @param y New y coordinate.
 * @return returns the status (OK/ERROR) of the action.
*/
STATUS player_setPosition(Player *p, int x, int y);

/**
 * @brief It says if the player is in a given position.
 * @param p Pointer to structure Player.
 * @param x Coordinate x.
 * @param y Coordinate y.
 * @return returns TRUE if the player is in that position, else, it returns FALSE.
 */
BOOL player_isHere(Player *p, int x, int y);

/**
 * @brief It resets the player's position to the initial one.
 * @param p Pointer to structure Player.
 * @return returns the status (OK/ERROR) of the action.
 */
STATUS player_resetPosition(Player *p);

/**
 * @brief It gives the Player's J coordinate.
 * @param p Pointer to structure Player.
 * @return returns the Player's J coordinate.
*/
int player_getPositionJ(Player *p);

/**
 * @brief It gives the Player's I coordinate.
 * @param p Pointer to structure Player.
 * @return returns the Player's I coordinate.
*/
int player_getPositionI(Player *p);

/**
 * @brief It sets the Player's I coordinate.
 * @param p Pointer to structure Player.
 * @param i New I coordinate.
 * @return returns the status (OK/ERROR) of the action.
*/
STATUS player_setPositionI(Player *p, int i);

/**
 * @brief It sets the Player's J coordinate.
 * @param p Pointer to structure Player.
 * @param j New J coordinate.
 * @return returns the status (OK/ERROR) of the action.
*/
STATUS player_setPositionJ(Player *p, int j);

#endif