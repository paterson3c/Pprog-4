/**
 * @brief Implements the functions defined in enemy.h
 * @name enemy.c
 * @author Ignacio Serena
 * @date 10-02-2022
 * @copyright GNU Public License
 */

#include "enemy.h"

struct _Enemy
{
    Id id;                    /*Structure enemy's id*/
    char name[WORD_SIZE + 1]; /*Enemy's name*/
    Id location;              /*Where the enemy is*/
    int health;               /*Health of te enemy*/
};

/*----------------------------------------------------------------------------------------------------*/
Enemy *enemy_create()
{
    Enemy *aux = NULL;

    aux = (Enemy *)malloc(sizeof(Enemy));
    if (!aux)
        return NULL;

    /*initialization of Enemy Struct*/
    aux->id = 0;
    aux->name[0] = 0;
    aux->health = 5;

    return aux;
}

/*----------------------------------------------------------------------------------------------------*/
Id enemy_getId(Enemy *e)
{
    if (!e)
        return NO_ID;

    return e->id;
}

/*----------------------------------------------------------------------------------------------------*/
STATUS enemy_setId(Enemy *e, Id id)
{
    if (!e || id < 0)
        return ERROR;

    e->id = id;
    return OK;
}

/*----------------------------------------------------------------------------------------------------*/
char *enemy_getName(Enemy *e)
{
    if (!e)
        return NULL;

    return e->name;
}

/*----------------------------------------------------------------------------------------------------*/
STATUS enemy_setName(Enemy *e, char *name)
{
    if (!e || !name)
        return ERROR;

    strcpy(e->name, name);
    return OK;
}

/*----------------------------------------------------------------------------------------------------*/
Id enemy_getLocation(Enemy *e)
{
    if (!e)
        return NO_ID;

    return e->location;
}

/*----------------------------------------------------------------------------------------------------*/
STATUS enemy_setLocation(Enemy *e, Id id)
{
    if (!e)
        return ERROR;

    e->location = id;
    return OK;
}

/*----------------------------------------------------------------------------------------------------*/
int enemy_getHealth(Enemy *e)
{
    if (!e)
        return -1;

    return e->health;
}

/*----------------------------------------------------------------------------------------------------*/
STATUS enemy_setHealth(Enemy *e, int h)
{
    if (!e)
        return ERROR;

    e->health = h;
    return OK;
}
/*----------------------------------------------------------------------------------------------------*/
STATUS enemy_destroy(Enemy *e)
{
    if (!e)
        return ERROR;

    free(e);
    e = NULL;
    return OK;
}

/*----------------------------------------------------------------------------------------------------*/
int enemy_print(Enemy *e)
{
    int n = 0;

    if (!e)
        return -1;

    /*prints enemy's id, name and location*/
    n += printf("Enemy(Id: %ld, Name: %s, Location: %ld)\n", enemy_getId(e), enemy_getName(e), enemy_getLocation(e));

    return n;
}