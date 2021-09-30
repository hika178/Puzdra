#include "type.h"

/* プロトタイプ宣言 */
int goDungeon(Party* pParty, Dungeon* pDungeon);

int doBattle(Party* pParty, Monster* pEnemy);

Party organizeParty(char*,Monster*,int);

void showParty(Party*);

void printMonsterName(Monster* monster);

void onPlayerTurn(Party * pParty, Monster* pEnemy);

void doAttack(Monster* pEnemy);

void onEnemyTurn(Party * pParty, Monster* pEnemy);

void doEnemyAttack(Party* pParty);