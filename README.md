# PvZ

## 遊戲流程
1. 玩家移動先
   1. 空的地: 要不要種植物
   2. 有植物: 看植物是啥(Coin, Horn, Bomb, Heal), 帶來功效之後, 無法再種植物
2. 殭屍移動
   1. 空的地: nothing happens
   2. 有植物: 攻擊性植物(Horn, Bomb)先攻擊, 若殭屍與植物都存活, 換殭屍攻擊
3. 遊戲結束
   1. 玩家殺死所有殭屍, 且還有植物存活(Bomb的數量不多於一半)
   2. 若所有植物死光, 玩家lose

## class 設計
> 當玩家碰到攻擊行植物時, 會印出 `Your flower is guarding your land. `
- 植物 (Plant.h)
  - `const int& getHP()`: 植物的血量
  - `const int& getCost()`: 植物的花費
  <!-- - const int& countOfPlant(): 植物的數量(死掉+活著的) -->
  <!-- - const int& countOfPlant("TYPE"): -->
  <!-- - const int& countOfExistPlant(): 活著的植物 -->
  <!-- - const int& countOfExistPlant("TYPE"): -->
  - `void beHealed( healPoint )`: 增加植物的血量
  - `void beInjured( injuryPoint )`: 減少植物的血量
  - `bool isAlive()`: 植物還活著嗎?
- Horn
  - `int getDamage()`: 帶來的傷害
- Bomb
- Coin
- Heal